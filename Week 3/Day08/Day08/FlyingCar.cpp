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

std::string FlyingCar::vehicleInformation() const
{
	//do I EXTEND or FULLY override the base version?
	//to EXTEND, call the base version
	std::string baseInfo = Car::vehicleInformation();//call the base
	std::string flyingInfo = "\n\tMax Airspeed: " + std::to_string(maxAirspeed_) +
		"\tMax Altitude: " + std::to_string(maxAltitude_);
	return baseInfo + flyingInfo;
}
