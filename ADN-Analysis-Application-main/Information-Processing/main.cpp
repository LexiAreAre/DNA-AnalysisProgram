#include<iostream>
#include<vector>
#include "Menu.h"
#include"Patient.h"
#include"CSVReader.h"
#include "JSONReader.h"

int main() {
	try
	{
		Menu::MenuPrincipal();
	}


	catch (std::invalid_argument& a)
	{
		std::cout << a.what();
		system("PAUSE");
	}
}