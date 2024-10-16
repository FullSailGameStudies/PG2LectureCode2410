#include "FlyingCar.h"


//base ctor first, then derived ctors

FlyingCar::FlyingCar(int year, std::string make, std::string model, int maxAlt, int maxSpeed) :
	Car(year,make,model), //call the base ctor
	maxAirspeed_(maxSpeed), //initialize the derived fields
	maxAltitude_(maxAlt)
{
	//mModelYear = year;//don't duplicate what the base does! BAD!
	mFuelLevel = 10;
}
