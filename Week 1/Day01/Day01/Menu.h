#pragma once
#include <vector>
#include <string>
class Menu
{
	//declarations
public:
	// returnType Name([parameter list])
	//  AddMenuItem
	//		parameters: item to add (string)
	//		return type: no (void)
	void AddMenuItem(std::string itemToAdd);//no { }

	//ShowMenu
	//		parameters: no? string?
	//		return type: no (void)
	void ShowMenu();

	//RemoveMenuItem
	//		parameters: item to remove (string)
	//		return type: bool (was it removed or not)
	bool RemoveMenuItem(std::string itemToRemove);


private:
	std::vector<std::string> menuItems_;
	//vector methods: push_back, size, erase, front, back, at(), [ ]
};

