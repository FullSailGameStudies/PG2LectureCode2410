#include "Car.h"

std::string Car::vehicleInformation() const
{
	return std::to_string(mModelYear) + " " + mMake + " " + mModel;
}
