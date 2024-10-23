// Day09.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>


class base
{
private:
	int mNum;
	static int numberOfBases_;//value shared by ALL instances of base
public:
	base(int num) : mNum(num)
	{
		numberOfBases_++;
	}
	//non-static method
	//	has a hidden parameter called 'this'
	//	can access non-static AND static members
	virtual void print()//base* this)
	{
		std::cout << "Hello base " << mNum << "\n";
		std::cout << "Number of bases: " << numberOfBases_ << "\n";
	}
	//static method
	//	they do NOT have a 'this' parameter
	//	can ONLY access other static members(fields and methods)
	//	cannot access non-static members (fields and methods)
	static void BaseReport()
	{
		//std::cout << "Hello base " << mNum << "\n";
		std::cout << "Number of bases: " << numberOfBases_ << "\n";
	}
};
int base::numberOfBases_ = 0;//initialize static fields outside of class

class derived : public base
{
private:
	std::string mStr;
public:
	derived(std::string str, int num) : 
		base(num), 
		mStr(str)
	{ }

	void print() override
	{
		base::print();//EXTEND the base
		std::cout << "\tHello derived " << mStr << "\n";
	}
};


int main()
{
	std::cout << (int)'1' << "\n";
	int num = 5;//stack variable
	int* pNum = &num;
	std::cout << &num << "\n" << pNum << "\n";
	std::cout << num << "\n" << *pNum << "\n";

	{
		int* pHeapNum = new int(5);//Heap variable
		delete pHeapNum;//release the heap space to be used for something else
	}//pHeapNum variable is gone 

	base b1(5);//stack instance
	b1.print();
	base* pBase = new base(10);//heap instance
	base* pBase2 = pBase;
	pBase->print();
	(*pBase).print();
	delete pBase;//clean up the heap
	pBase = nullptr;

	base::BaseReport();
	//pBase2->print();

	if(pBase != nullptr)
		pBase->print();

	{
		std::vector<base*> bases;
		bases.push_back(new base(15));
		bases.push_back(new derived("PG2", 25));
		for (auto& ptrBase : bases)
		{
			ptrBase->print();//runtime polymorphism
		}

		for (size_t i = 0; i < bases.size(); i++)
		{
			delete bases[i];
		}
	}

	int iNum = 10;
	long lNum = iNum;//implicit cast
	iNum = lNum;
	double dNum = 10;
	iNum = (int)dNum;//explicit cast

	std::cin.get();

	/*
		╔════════════╗
		║ Unique_ptr ║
		╚════════════╝

		Using unique pointers w/ overridden methods


		╔═══════════╗
		║ UPCASTING ║ - casting a derived type variable to a base type variable
		╚═══════════╝

		This is ALWAYS safe.


		To maintain the original object, we need a pointer though. If not, then we're just calling the copy constructor of the base class and lose all the info of the derived.

		Unique pointers owns and manages an object through a pointer.
		std::unique_ptr<derived> pDerived = std::make_unique<derived>("Gotham", 5);


		You can upcast by using the base type in the unique_ptr.
		std::unique_ptr<base> pBase = std::make_unique<derived>("Gotham", 5);
		  OR
		std::unique_ptr<base> pBase = std::move(pDerived); https://learn.microsoft.com/en-us/cpp/standard-library/utility-functions?view=msvc-170&redirectedfrom=MSDN&f1url=%3FappId%3DDev16IDEF1%26l%3DEN-US%26k%3Dk(std%253A%253Amove)%3Bk(move)%3Bk(DevLang-C%252B%252B)%3Bk(TargetOS-Windows)%26rd%3Dtrue#move



		Lecture Code:
			use make_unique and unique_ptr to create a derived instance
			use std::move to upcast it to a base
	*/
	derived der1("Gotham", 1);
	//calls the assignment operator of base therefore you lose all the derived parts. 
	// base1 is JUST a base object.
	base base1 = der1; 
	der1.print();
	std::cout << "\n";
	base1.print();

	std::unique_ptr<base> uPtrBase = 
		std::make_unique<base>(420);

	uPtrBase->print();

	std::unique_ptr<base> uPtrBase2 = std::move(uPtrBase);//reassign ownership

	{
		std::vector<std::unique_ptr<base>> uPtrBases;
		uPtrBases.push_back(std::move(uPtrBase2));
		uPtrBases.push_back(std::make_unique<base>(425));
		uPtrBases.push_back(std::make_unique<derived>("The Answer", 42));
		std::cout << "\n\nUnique Ptrs\n";
		for (auto& uPtr : uPtrBases)
		{
			uPtr->print();
		}
	}
	//uPtrBase->print();

	//Severity	Code	Description	Project	File	Line	Suppression State	Details
	//Error	C2280	'std::unique_ptr<base,std::default_delete<base>>::unique_ptr(const std::unique_ptr<base,std::default_delete<base>> &)': attempting to reference a deleted function	Day09	C : \Program Files\Microsoft Visual Studio\2022\Enterprise\VC\Tools\MSVC\14.40.33807\include\xmemory	700




	/*
		╔*************╗
		║  CHALLENGE  ║
		╚*************╝

		Create a vector that holds unique pointers of Weapon.
		Create instances of Weapon and Pistol using make_unique.
		Add them to the vector.

		Loop over the vector and call showMe on each weapon.

	*/
}