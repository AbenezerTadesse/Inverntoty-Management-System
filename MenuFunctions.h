#pragma once





/*
Abenezer Tadesse
CSCI 2312 Final Project
12/06/16
Meets all requirement. Compiles successfully on cse grid


Renatl Store Inventory Management Program

Description:	This is header file for menu functions that will be used to to drive
				the Inventory program

				Included are functions that print the menu and also a template input validator

				

*/









#include"Inventory.h"
#include <random>


#ifndef MENUFUNCTIONS_
#define MENUFUNCTIONS_

namespace csci2312
{
	void printMainMenu();  //prints main menu 
	void printSearchField(); //prints search menu
	void printSortField(); //prints sort menu

	template<class T>
	T menuInputValidator(T min, T max, T& input); //user input validator 

	void addInventory(Inventory& Inventory1, string fileName) throw (FileIOException); //read in from file
	void addInventory(Inventory& Inventory1); //handles user adding inventory item manually
	
	int randomIDnumber(); //Generates a random 4 digit number that will be used to assign as an ID number



	//template function definition
	//PRECONDITION: parameters must all be same data type 
	//				<, >, = operators must be able to operate on the data types
	//				The user must input the same data type. eg. if T is int then the user must enter numbers
	//				The function only checks if the input is with in a valid range.
	template<typename T>
	T menuInputValidator(T min, T max, T& input)
	{
	
		while (input < min || input > max) //we make sure the input is in the desired range
		{								//if not print an error message and loop until valid input
			cout << "\nPlease enter keys between " << min << " and " << max << endl;
			cin >> input;
		}
		return input;
	}

}//end namespace csci2312





#endif // !MENUFUNCTIONS_
