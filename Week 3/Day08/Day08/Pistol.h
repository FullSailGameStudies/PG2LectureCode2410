#pragma once
#include "Weapon.h"
#include <string>
class Pistol : public Weapon
{
public:
	Pistol(int range, int damage, int rounds, int magCapacity) :
		Weapon(range, damage),
		rounds_(rounds), magCapacity_(magCapacity)
	{
	}

	Pistol operator+(const Pistol& otherGun)
	{
		int newROunds = rounds_ + otherGun.Rounds();
		int newCapacity = std::max<int>(magCapacity_, otherGun.MagCapacity());
		Pistol newGun(range(), damage(), newROunds, newCapacity);
		return newGun;
	}

	int Rounds() const { return rounds_; }
	void Rounds(int newRounds) {
		if (newRounds >= 0 && newRounds <= magCapacity_)
			rounds_ = newRounds;
	}
	void Rounds(std::string roundsString)
	{

	}

	int MagCapacity() const { return magCapacity_; }
	void MagCapacity(int newCapacity) {
		if (newCapacity > 0 && newCapacity <= 20)
			magCapacity_ = newCapacity;
	}

private:
	int rounds_, magCapacity_;
};

