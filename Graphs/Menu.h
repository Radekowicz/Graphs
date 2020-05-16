#pragma once
#include <string>

class Menu
{
	char opt;
	std::string fileName;
	int vertexAmount, value;

public:

	void displayMenu(std::string info);

	void displayMenu2(std::string info);


	void MSTMenu();

	void SciezkaMenu();

};

