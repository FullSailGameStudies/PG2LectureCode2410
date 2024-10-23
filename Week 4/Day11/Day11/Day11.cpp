// Day11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Car.h"
#include <vector>
#include <fstream>

int main()
{
    std::cout << "Gone in 60 Seconds!\n";//https://carbuzz.com/features/beyond-eleanor-gone-in-60-seconds-car-names#:~:text=The%20Complete%20List%20Of%20Gone%20In%2060%20Seconds,8%201961%20Porsche%20Speedster%20-%20%22Natalie%22%20More%20items

    Car myRide(1967, "Ford", "Shelby Mustang GT500");
    //1. open the file
    std::string filename = "gone.csv";
    std::string path = "";
    std::string fullPath = path + filename;
    std::ofstream outFile(fullPath);
    char delim = '*';
    if (outFile.is_open())
    {
        //2. write/read the file
        myRide.SerializeCSV(outFile, delim);
    }
    else
        std::cout << "Error opening " << fullPath << "\n";

    //3. close the file
    outFile.close();

    std::ifstream inFile(fullPath);
    if (inFile.is_open())
    {
        std::string carLine;
        std::getline(inFile, carLine);
        Car fridaysRide(carLine, delim);
        std::cout << fridaysRide.vehicleInformation() << "\n";
    }
    else
        std::cout << "Error opening " << fullPath << "\n";
    inFile.close();



    std::vector<Car> garage;
    garage.push_back(Car(1967, "Ford", "Shelby Mustang GT500"));
    garage.push_back(Car(1956, "Ford", "T Bird"));
    garage.push_back(Car(1961, "Porsche", "Speedster"));
    garage.push_back(Car(1965, "Pontiac", "GTO"));
    garage.push_back(Car(1969, "Plymouth", "Hemi Cuda"));

    //serialize the vector to a file

    //1. open the file
    filename = "gone60.csv";
    fullPath = path + filename;
    std::ofstream outFileFull(fullPath);
    
    if (outFileFull.is_open())
    {
        //2. write/read the file
        //for (auto& car : garage)
        //{
        //    car.SerializeCSV(outFileFull, delim);
        //}
        for (auto it = garage.begin(); it != garage.end(); ++it)
        {
            it->SerializeCSV(outFileFull, delim);
        }
    }
    else
        std::cout << "Error opening " << fullPath << "\n";

    //3. close the file
    outFileFull.close();

    //deserialize all the cars from the file and put them in a vector
    //then loop and print all the vehicle infos
    std::ifstream garageInFile(fullPath);
    std::vector<Car> myGarage;
    if (garageInFile.is_open())
    {
        std::string line;
        while (!garageInFile.eof())
        {
            std::getline(garageInFile, line);
            if(!line.empty())
                myGarage.push_back(Car(line, delim));
        }
    }
    else
        std::cout << "Error opening " << fullPath << "\n";
    garageInFile.close();

    std::cout << "Deserialized Garage:\n";
    for (auto& myCar : myGarage)
    {
        std::cout << myCar.vehicleInformation() << "\n";
    }

    std::cout << "Jay's Garage\n";
    for (auto& car : garage)
    {
        car.SerializeCSV(std::cout, '\t');
    }


    /*
        ╔═════════════╗
        ║ Serializing ║
        ╚═════════════╝

        Saving the state (data) of objects

        Lecture Code: serialize the vector of Cars to a file.
            Data Format:
                separates cars. EX: car1|car2|car3
                separates data inside a car. EX: 1967;Ford;Shelby Mustang GT500

    */



    /*
        ╔═══════════════╗
        ║ Deserializing ║
        ╚═══════════════╝

        Recreating the objects from the saved state (data) of objects

        Lecture Code:
            Open the file
            Read in each line
            split each line to get each car
            split each car to get the car details

    */
}