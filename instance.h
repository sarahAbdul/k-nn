#ifndef INSTANCE_H
#define INSTANCE_H
#include "feature.h"

class Instance {
private:
    std::vector<Feature> attributes;
	bool redeemed;
	std::string sessionID;
	std::string uuid;

public:
    void setAttributes(std::vector<Feature> attributes) {
		this->attributes = attributes;
	}

	std::vector<Feature> getAttributes() {
		return attributes;
	}

	void setRedeemed(bool redeemed) {
		this->redeemed = redeemed;
	}

	bool isRedeemed() {
		return redeemed;
	}

	void setSessionID(std::string sessionID) {
		this->sessionID = sessionID;
	}

	std::string getSessionID() {
		return sessionID;
	}

	void setUuid(std::string uuid) {
		this->uuid = uuid;
	}

	std::string getUuid() {
		return uuid;
	}
};

#endif // INSTANCE_H
