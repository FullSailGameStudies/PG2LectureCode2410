#include "Car.h"
#include <sstream>

std::string Car::vehicleInformation()
{
	return std::to_string(mModelYear) + " " + mMake + " " + mModel;
}

Car::Car(std::string carCSVData, char delimiter)
{
	DeserializeCSV(carCSVData, delimiter);
}

void Car::SerializeCSV(std::ostream& outStream, char delimiter)
{
	outStream << mModelYear << delimiter << mMake << delimiter << mModel << "\n";
}

void Car::DeserializeCSV(const std::string& carCSVData, char delimiter)
{
	std::stringstream carStream(carCSVData);
	std::string data;
	std::getline(carStream, data, delimiter);
	mModelYear = std::stoi(data);
	std::getline(carStream, mMake, delimiter);
	std::getline(carStream, mModel, delimiter);
}
