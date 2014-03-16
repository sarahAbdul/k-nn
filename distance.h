#ifndef DISTANCE_H
#define DISTANCE_H

#include <string>
#include <sstream>
using namespace std;

/*
int StringTONumber ( string String )
{
	istringstream ss(String);
	int Integers;
	ss >> Integers;
	//cout << Integers;
	return Integers;
}
*/
class Distance: public Feature {

	enum DistanceRange {
		LessThanTwo,
		TwoToFive,
		FiveToTen,
		TenToTwenty,
		TwentyToFifty,
		FiftyToHundred,
		Unknown
	};

private:
    DistanceRange distance;

public:
    Distance(): Feature("Distance"){}

    Distance(DistanceRange distance): Feature("Distance")
    {

		this->distance = distance;
	}

	void setDistance(DistanceRange distance) {
		this->distance = distance;
	}

	DistanceRange getDistance() {
		return distance;
	}

	static DistanceRange determineDistance(string distance) {
		if(StringTONumber(distance) <= 2) {
			return LessThanTwo;
		}
		else if(StringTONumber(distance) > 2 && StringTONumber(distance) <= 5) {
			return TwoToFive;
		}
		else if(StringTONumber(distance) > 5 && StringTONumber(distance) <= 10) {
			return FiveToTen;
		}
		else if(StringTONumber(distance) > 10 && StringTONumber(distance) <= 20) {
			return TenToTwenty;
		}
		else if(StringTONumber(distance) > 20 && StringTONumber(distance) <= 50) {
			return TwentyToFifty;
		}
		else if(StringTONumber(distance) > 50) {
			return FiftyToHundred;
		}
		else {
			return Unknown;
		}
	}

};

#endif
