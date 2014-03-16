#ifndef HANDSET_H
#define HANDSET_H

#include <string>
#include <locale>
string toLow (string  str)
{
     //to lower equivalent code
         std::locale loc;
        for (std::string::size_type i=0; i<str.length(); ++i)
        str[i] = std::tolower(str[i],loc);
        return str;
}
class Handset: public Feature {

	enum Device {
		iPhone,
		iPod,
		G1,
		Droid,
		MyTouch,
		Hero,
		Unknown
	};

	enum OS {
		Android,
		iPhon,
		Unknow
	};

private:
    Device device;
	OS os;

public:
    Handset(): Feature("Handset"){}

	Handset(Device device, OS os): Feature("Handset"){
		this->os = os;
		this->device = device;
	}

	void setOs(OS os) {
		this->os = os;
	}

	OS getOs() {
		return os;
	}

	void setDevice(Device device) {
		this->device = device;
	}

	Device getDevice() {
		return device;
	}

	static OS determineOS(string os) {
	    string o = toLow(os);

        std::size_t found = o.find("iphoneos");
        std::size_t found1 = o.find("android");
		if(found != std::string::npos) {
			return iPhon;
		}

		else if(found1 != std::string::npos) {
			return Android;
		}
		else {
			return Unknow;
		}
	}

	static Device determineDevice(string device) {
	    string dev = toLow(device);

        std::size_t found = dev.find("iphone");
        std::size_t found1 = dev.find("ipod");
        std::size_t found2 = dev.find("droid");
        std::size_t found3 = dev.find("g1");
        std::size_t found4 = dev.find("mytouch");
        std::size_t found5 = dev.find("hero");



		if(found != std::string::npos) {
			return iPhone;
		}
		else if(found1 != std::string::npos) {
			return iPod;
		}
		else if(found2 != std::string::npos) {
			return Droid;
		}
		else if(found3 != std::string::npos) {
			return G1;
		}
		else if(found4 != std::string::npos) {
			return MyTouch;
		}
		else if(found5 != std::string::npos) {
			return Hero;
		}
		else {
			return Unknown;
		}
	}

};

#endif // HANDSET_H

