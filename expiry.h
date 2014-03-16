#ifndef EXPIRY_H
#define EXPIRY_H

#include <string>

using namespace std;

class Expiration: public Feature {

	enum Expiry {
		Date,
		Uses,
		Unknown,
		None
	};

private:
    Expiry expiry;

public:
    Expiration(): Feature("Expiration"){}

	 Expiration(Expiry expiry): Feature("Expiration"){
		this->expiry = expiry;
	}

	 void setExpiry(Expiry expiry) {
		this->expiry = expiry;
	}

	 Expiry getExpiry() {
		return expiry;
	}

	 static Expiry determineExpiration(string expiry) {
		return Date;
	}

	 static Expiry parseExpirationText(string offer) {
		return Unknown;
	}
};
#endif // EXPIRY_H
