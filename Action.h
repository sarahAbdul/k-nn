#ifndef  WSACTION_H
#define WSACTION_H
#include <locale>         // std::locale, std::tolower
#include <string>
using namespace std;

enum Action
{
    Hit,
    Redeem,
    Unknown
};


class WSAction: public Feature
{


private:
    Action action;

public:
    WSAction() :Feature("WSAction"){}


    WSAction(Action action): Feature("WSAction")
    {
        this->action = action;
    }

    void setAction(Action action)
    {
        this->action = action;
    }

    Action getAction()
    {
        return action;
    }

    static Action determineAction(std::string action)
    {
        //to lower equivalent code
         std::locale loc;
        for (std::string::size_type i=0; i<action.length(); ++i)
        action[i] = std::tolower(action[i],loc);


        std::size_t found = action.find("hit");
        std::size_t found1 = action.find("redemption");
        if(found!=std::string::npos)
        {
            return Hit;
        }
        else if(found1!=std::string::npos)
        {
            return Redeem;
        }
        else
        {
            return Unknown;
        }
    }
};

#endif
