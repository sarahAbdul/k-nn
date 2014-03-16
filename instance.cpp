#ifndef INSTANCE_H
#define INSTANCE_H

#include"feature.cpp"
class Instance
{
private:
    Feature* attributes;
    bool redeemed;
    std::string sessionID;
    std::string uuid;

public:
    void setAttributes(Feature* attributes)
    {
        this->attributes = attributes;
    }

    Feature* getAttributes()
    {
        return attributes;
    }

    void setRedeemed(bool redeemed)
    {
        this->redeemed = redeemed;
    }

    bool isRedeemed()
    {
        return redeemed;
    }

    void setSessionID(std::string sessionID)
    {
        this->sessionID = sessionID;
    }

    std::string getSessionID()
    {
        return sessionID;
    }

    void setUuid(std::string uuid)
    {
        this->uuid = uuid;
    }

    std::string getUuid()
    {
        return uuid;
    }
};

#endif // INSTANCE_H
