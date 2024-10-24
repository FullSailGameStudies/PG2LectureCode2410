#pragma once
#include "Car.h"
class FlyingCar : public Car
{
public:
	//all derived ctors must call a base ctors
	//code snippets
	FlyingCar(int year, std::string make, std::string model, int maxAlt, int maxSpeed);

	std::string vehicleInformation() const override;//overriding the base version
private:
	int maxAltitude_, maxAirspeed_;
};

