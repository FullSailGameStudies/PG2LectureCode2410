#include "Menu.h"
#include <iostream>
#include "Console.h"

//definitions
void Menu::AddMenuItem(std::string itemToAdd)
{
	menuItems_.push_back(itemToAdd);
}
void Menu::ShowMenu()
{
	Console::WriteLine("Burgers Inc.", ConsoleColor::Red);
	Console::WriteLine("------------", ConsoleColor::Yellow);
	for (size_t i = 0; i < menuItems_.size(); i++)
	{
		std::cout << menuItems_[i] << "\n";
	}

	Console::WriteLine("Burgers Inc. (range-based)", ConsoleColor::Red);
	Console::WriteLine("------------", ConsoleColor::Yellow);
	for (auto& menuItem : menuItems_)
	{
		std::cout << menuItem << "\n";
	}

	Console::WriteLine("Burgers Inc. (iterator for)", ConsoleColor::Red);
	Console::WriteLine("------------", ConsoleColor::Yellow);
	for (auto iter = menuItems_.begin(); iter != menuItems_.end(); iter++)
	{
		//pointer notation
		//"dereference"
		std::string menuItem = *iter;//go to the object that iter "points" to
		//int length = iter->size();
		std::cout << menuItem << "\n";
	}
}

bool Menu::RemoveMenuItem(std::string itemToRemove)
{
	bool result = false;
	//for (int i = 0; i < menuItems_.size(); i++)
	//{
	//	//try to find itemToRemove
	//	if (menuItems_[i] == itemToRemove)
	//	{
	//		//erase the item
	//		menuItems_.erase(menuItems_.begin() + i);
	//		result = true;
	//		//stop looping
	//		break;
	//	}
	//}
	for (std::vector<std::string>::iterator i = menuItems_.begin(); i != menuItems_.end(); i++)
	{
		//_stricmp
		// <0 means less than
		// == 0 means equal to
		// >0 means greater than
		int compResult = _stricmp(itemToRemove.c_str(), i->c_str());
		//if (itemToRemove == *i)//== is case sensitive
		if(compResult == 0)
		{
			menuItems_.erase(i);
			result = true;
			break;
		}
	}
	return result;
}
