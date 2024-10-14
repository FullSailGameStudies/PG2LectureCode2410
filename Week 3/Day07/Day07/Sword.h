#pragma once

//class declaration
//	what the object can DO (methods)
//	what describes the object (data/fields)
class Sword
{
	//data: damage, two-handed, cost, length
	//		durability, material
	//DO: attack, block

	//public: means everyone can see it
	//private(default): means ONLY THIS CLASS can see it
	//protected: this class and all descendent classes can see it
public:

public:
	//constructors
	//		MUST be named the same as the class
	//		CANNOT have any kind of return type specified (not even void)
	//		can have any number of them
	//		can be public, private, or protected
	//	IF you do not provide a ctor, the compiler will give you 
	//		an empty default ctor
	//		a default ctor has no parameters
	//	IFF we write our own ctor, the compiler's version is no longer available
	Sword(bool isTwoHanded, double damage);

	//DECLARATION goes in the header


	/// <summary>
	/// Calculates the damage using the modifier.
	/// </summary>
	/// <param name="modifier">The modifier that is added to the sword's damage.</param>
	/// <returns>The damage for the attack.</returns>
	double CalculateDamage(double modifier) const;

	//getters (accessors)
	//	const methods
	//	return type matches the type of the field
	bool GetIsTwoHanded() const { return isTwoHanded_; }
	double Damage() const { return damage_; }

	//setters (mutators)
	//	change the object so they CANNOT be const
	//	no data is returned
	//	parameter type matches the field type
	void SetIsTwoHanded(bool isTwoHanded)
	{
		isTwoHanded_ = isTwoHanded;
	}
	void Damage(double newDamage)
	{
		if (newDamage > 0 && newDamage < 1000)
			damage_ = newDamage;
	}


private:
	bool isTwoHanded_;
	double damage_;
};

