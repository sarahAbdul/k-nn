#ifndef  FILE_H
#define FILE_H
#include <fstream>
#include <string>
#include <vector>
#include <cstring>

#include "feature.h"
#include "category.h"
#include "distance.h"
#include "expiry.h"
#include "handset.h"
#include "offer.h"
using namespace std;
extern int WSACTION_INDEX;
class FileReader
{
private:
    string dataFilePath;

public:
    FileReader()
    {
        this->dataFilePath = "";
    }
    FileReader(string dataFilePath)
    {
        this->dataFilePath = dataFilePath;
    }

    vector<Instance> *buildInstances( int NUM_ATTRS)
    {
        //reader.open(PATH_TO_DATA_FILE);
        ifstream reader;
        //DataInputStream dis = null;
        vector<Instance> *instances = new vector<Instance>();

        try
        {
            char Filename[100];
            int TempNumOne=dataFilePath.size();

            for (int a=0; a<TempNumOne; a++)
            {
                Filename[a]=dataFilePath[a];
            }
            Filename[TempNumOne] = '\0';
            reader.open(Filename);

            // read the first Instance of the file
            string line;

            Instance* instance;
            vector<Feature* > * attributes;
            if (reader.is_open())
            {
                char * stt;
                char linec [600];
                while ( getline (reader,line) )
                {
                    int numa= 0; //tokens counter
                    //convert line to char array
                    int lineSize=line.size();
                    attributes = new vector<Feature*>();
                    instance = new Instance();
                    //convert to char array
                    for (int a=0; a<lineSize; a++)
                    {
                        linec[a]=line[a];
                    }
                    linec[lineSize] = '\0';
                    //tokenize line
                    stt = strtok(linec, ",");

                    string sessionId = "1"; // the session Id for the client.  we only want to consider
                    // classification for the same person (uuid) in the same session
                    numa++;
                    string uuid = strtok(linec, ","); // the actual person redeeming the coupon
                    numa++;
                    string os = strtok(linec, ","); // the OS that is running on the device
                    numa++;
                    string device = strtok(linec, ","); // the device the person is using
                    numa++;
                    string offer = strtok(linec, ",");
                    numa++;
                    string expiry = strtok(linec, ",");
                    numa++;
                    string category = strtok(linec, ",");
                    numa++;
                    string distance = strtok(linec, ",");
                    numa++;
                    string wsAction = strtok(linec, ",");// what happened in the session, redeem or hit
                    numa++;
                    //Check number of tokens in the line are correct
                    if((NUM_ATTRS) != numa)
                    {
                        cout <<("LINE: " + numa--);
                        throw("Unknown number of attributes!");
                    }

                    /*Category cat(cat.determineCategory(category));
                    attributes->push_back(cat);

                    Distance dist(dist.determineDistance(distance));
                    attributes->push_back(dist);

                    Expiration exp(exp.determineExpiration(expiry));
                    attributes->push_back(exp);

                    Handset hand (hand.determineDevice(device), hand.determineOS(os));
                    attributes->push_back(hand);

                    Offer off(off.parseOfferText(offer));
                    attributes->push_back(off);
                    */

                    WSAction * ws =  new WSAction(WSAction::determineAction(wsAction));
                    attributes->push_back(ws);

                    if(((WSAction*)(attributes->at(WSACTION_INDEX)))->getAction() == Action::Redeem)
                    {
                        instance->setRedeemed(true);
                    }
/*                    else
                    {
                    instance.setRedeemed(false);
                    }
                    instance.setUuid(uuid);
                    instance.setSessionID(sessionId);

                    instance.setAttributes(attributes);
                    instances.add(instance);
                    */
                }
                reader.close();
            }

            else throw ("Unable to open file");



        }
        catch (int e)
        {
            cout << ("Uh oh, got an IOException error: ");
        }
        catch (int e)
        {
            cout << ("Uh oh, got an Exception error: ");
        }

        return instances;
    }

    void setDataFilePath(string dataFilePath)
    {
        this->dataFilePath = dataFilePath;
    }

    string getDataFilePath()
    {
        return dataFilePath;
    }
};

#endif
