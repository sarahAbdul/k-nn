#ifndef FEATURE_H
#define FEATURE_H

#include <string>

class Feature {
//private:
    std::string name;

public:
    Feature(std::string name) {
		this->name = name;
	}

	void setName(std::string name) {
		this->name = name;
	}
	std::string getName() {
		return name;
	}
};

#endif
