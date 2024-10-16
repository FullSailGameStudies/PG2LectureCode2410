// Day08.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>
#include "Inheritance.h"
#include "Polymorphism.h"
#include "Car.h"
#include "FlyingCar.h"
#include "Pistol.h"
#include <vector>


int main()
{
	Car myRide(1988, "Ford", "Mustang GT 5.0");
	FlyingCar cyberPlane(2025,"Tesla","CyberPlane",500,200);

	//std::cout << myRide.vehicleInformation() << "\n";
	//std::cout << cyberPlane.vehicleInformation() << "\n";

	std::vector<Car> garage;
	garage.push_back(myRide);
	garage.push_back(cyberPlane);//what happens here?? copies the CAR parts to an object in the vector

	for (auto& car : garage)
	{
		std::cout << car.vehicleInformation() << "\n";
	}
	/*
        ╔═══════════════╗
        ║  Inheritance  ║
        ╚═══════════════╝

								╔═════════╗     ╔══════════╗
				         class  ║SomeClass║  :  ║OtherClass║
								╚═════════╝     ╚══════════╝
									 │                │
									 └──┐             └──┐
								   ┌────▼────┐      ┌────▼────┐
								   │ Derived │      │  Base   │
								   │  Class  │      │  Class  │
								   └─────────┘      └─────────┘

			Access modes:
				public inheritance:
				protected inheritance:
				private inheritance: (default if not specified)
	


				CONSTRUCTORS: the derived constructor must call a base constructor
				public SomeClass(.....) : baseClass(....)


			Lecture Code: add a FlyingCar class that derives from Car
             
    */



	/*
        ╔*************╗
        ║  CHALLENGE  ║
        ╚*************╝

            add a new class, Pistol, that derives from Weapon.
            Pistol should have fields with getters/setters for rounds and magCapacity.
            Add a constructor that calls the base constructor
	
	*/
	Pistol pewpew(50, 100, 10, 20);
	Pistol p2(50, 100, 10, 20);

	int rounds = pewpew.Rounds();//which Rounds method to call?
	pewpew.Rounds(15);//which Rounds method to call?
	pewpew.Rounds("20");//which Rounds method to call?

	Pistol p50 = pewpew + p2;



	/*
        ╔═════════════════════════════╗
        ║  COMPILE-TIME Polymorphism  ║
        ╚═════════════════════════════╝

		Method Overloading:
			- changing the number of parameters
			- changing the types of the parameters

		Lecture Code: Overload the refuel method in Car

	*/



	/*
        ╔*************╗
        ║  CHALLENGE  ║
        ╚*************╝

			Add an OVERLOAD of the calcDamage method in the Weapon class.
			The overload should take an int parameter called modifier
			to increase the damage when calculating the damage.

	*/





	/*
        ╔═════════════════════════════╗
        ║  COMPILE-TIME Polymorphism  ║
        ╚═════════════════════════════╝

		Operator Overloading

		Lecture Code: overload the + operator in Account

	*/



	/*
        ╔*************╗
        ║  CHALLENGE  ║
        ╚*************╝

		overload the + in the Pistol class to add 2 pistols
			- it sets the magCapacity to the max of the 2 pistols
			- adds the # of rounds from both pistols. should not exceed the magCapacity.
	*/






	/*
        ╔════════════════════════╗
        ║  RUNTIME Polymorphism  ║
        ╚════════════════════════╝

		╔═════════════╗
		║ OVERRIDING  ║ - changing the behavior of a base method
		╚═════════════╝

		1) add 'virtual' to the base method
		2) add a method to the derived class that has the same signature as the base.
			OPTIONALLY put 'override' on the derived method


		FULLY OVERRIDING:
			not calling the base method from the derived method

		EXTENDING:
			calling the base method from the derived method
			to call the base method...  baseClassName::method(...)



		Lecture Code: override the print method in the base/derived classes in the Polymorphism.h file

	*/



	/*
        ╔*************╗
        ║  CHALLENGE  ║
        ╚*************╝

			Override Weapon's showMe method in the Pistol class.
			In Pistol's version, call the base version then print out the rounds and magCapacity



	*/



}

