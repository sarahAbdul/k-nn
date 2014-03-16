#ifndef OFFER_H
#define OFFER_H

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Offer: public Feature
{

private:
    class MutableInteger
    {
    public:
        int value = 1;

        void inc()
        {
            value++;
        }
        int get()
        {
            return value;
        }
    };

    enum OfferType
    {
        PercentageDiscount,
        DollarDiscount,
        PayForFree,
        Unknown
    };

    OfferType offerType;

public:
    Offer(): Feature("Offer") {}


    Offer(OfferType offerType): Feature("Offer")
    {
        this->setOfferType(offerType);
    }

    static OfferType parseOfferText(string offer)
    {

        std::unordered_map<string,MutableInteger> words;
        char *charoffer = 0;
        int offerSize = offer.size();
        //convert to char array
        for (int a=0; a<offerSize; a++)
        {
            charoffer[a]=offer[a];
        }
        charoffer[offerSize] = '\0';
        char* token;

        token = strtok(charoffer, " ");
        while (token != NULL)
        {
            if (words.count(token)> 0)
            {
                MutableInteger value = words.at(token);
                value.inc();
                std::pair<std::string,MutableInteger> offerPair (string(token),value);
                words.insert(offerPair);
            }
            else
            {
                MutableInteger value;
                std::pair<std::string,MutableInteger> offerPair (string(token),value);
                words.insert(offerPair);
            }
            token = strtok(charoffer, " ");

        }
        //Naive Bayes classifier
        vector<string> sortedWords;
        int highest = 0;

        cout << words.size();
        for(int i = 0; i < words.size(); i++)
        {
            for ( auto it: words )
            {
                //          cout << " " << it.first << ":" << it.second << endl;
                int value = it.second.value;
                if (value > highest)
                {
                    highest = value;
                    words.erase(words.find(it.first));
                    sortedWords.push_back(it.first);
                    break;
                }
            }
        }

        if(find(sortedWords.begin(), sortedWords.end(), "free")!=sortedWords.end()) {
           return PayForFree;
        }
        if(find(sortedWords.begin(), sortedWords.end(), "percent")!=sortedWords.end()
           || find(sortedWords.begin(), sortedWords.end(), "percentage")!=sortedWords.end()
           || find(sortedWords.begin(), sortedWords.end(), "%")!=sortedWords.end()) {
           return PercentageDiscount;
        }
        if(find(sortedWords.begin(), sortedWords.end(), "dollar")!=sortedWords.end()
           ||find(sortedWords.begin(), sortedWords.end(), "dollars")!=sortedWords.end()
           || find(sortedWords.begin(), sortedWords.end(), "$")!=sortedWords.end()) {
           return DollarDiscount;
        }
        else
        return Unknown;

    }

    void setOfferType(OfferType offerType)
    {
        this->offerType = offerType;
    }

    OfferType getOfferType()
    {
        return offerType;
    }
};
#endif // OFFER_H

