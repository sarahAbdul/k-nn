#ifndef CATEGORY_H
#define CATEGORY_H

#include <string>
#include <sstream>
using namespace std;


int StringTONumber ( string String )
{
	istringstream ss(String);
	int Integers;
	ss >> Integers;
	//cout << Integers;
	return Integers;
}



class Category :public Feature {

	enum Categories {
		Entertainment,
		Automotive,
		FoodAndDining,
		HealthAndBeauty,
		Retail,
		SportsAndRecreation,
		Travel,
		ClothingAndApparel,
		ElectronicsAndAppliances,
		FurnitureAndDecor,
		Grocery,
		HobbiesAndCrafts,
		HomeServices,
		HotelsAndLodging,
		NightlifeAndBars,
		NonProfitsAndYouth,
		OfficeSupplies,
		Other,
		PetServices,
		ProfessionalServices,
		RealEstate,
		Unknown
	};

private:
    Categories category;

public:
    Category():Feature("Category"){}

	Category(Categories category):Feature("Category")
	{

		this->category = category;
	}

	void setCategory(Categories category) {
		this->category = category;
	}

	 Categories getCategory() {
		return category;
	}

	static Categories determineCategory(string category) {
		if(StringTONumber (category) == 0) {
			return Entertainment;
		}
		else if(StringTONumber(category) == 1) {
			return Automotive;
		}
		else if(StringTONumber(category) == 2) {
			return FoodAndDining;
		}
		else if(StringTONumber(category) == 3) {
			return HealthAndBeauty;
		}
		else if(StringTONumber(category) == 4) {
			return Retail;
		}
		else if(StringTONumber(category) == 5) {
			return SportsAndRecreation;
		}
		else if(StringTONumber(category) == 6) {
			return Travel;
		}
		else if(StringTONumber(category) == 7) {
			return ClothingAndApparel;
		}
		else if(StringTONumber(category) == 8) {
			return ElectronicsAndAppliances;
		}
		else if(StringTONumber(category) == 9) {
			return FurnitureAndDecor;
		}
		else if(StringTONumber(category) == 10) {
			return Grocery;
		}
		else if(StringTONumber(category) == 11) {
			return HobbiesAndCrafts;
		}
		else if(StringTONumber(category) == 12) {
			return HomeServices;
		}
		else if(StringTONumber(category) == 13) {
			return HotelsAndLodging;
		}
		else if(StringTONumber(category) == 14) {
			return NightlifeAndBars;
		}
		else if(StringTONumber(category) == 15) {
			return NonProfitsAndYouth;
		}
		else if(StringTONumber(category) == 16) {
			return OfficeSupplies;
		}
		else if(StringTONumber(category) == 17) {
			return Other;
		}
		else if(StringTONumber(category) == 18) {
			return PetServices;
		}
		else if(StringTONumber(category) == 19) {
			return ProfessionalServices;
		}
		else if(StringTONumber(category) == 20) {
			return RealEstate;
		}
		else if(StringTONumber(category) == 21) {
			return Unknown;
		}
		else {
			return Unknown;
		}
	}

};
#endif
