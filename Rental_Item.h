#pragma once


/*
Abenezer Tadesse
CSCI 2312 Final Project
12/06/16
Meets all requirement. Compiles successfully on cse grid


Renatl Store Inventory Management Program

Description:	This is a header file for the base class rental items. It is an abstract class
				with pure functions therefor, no objects of ths class will be created
				
				But we will use this class to derive Movie and Book classes.
				
				We will also use Rental_Class type pointer to access derived classes Movie and Book

				This class has exception handling capabilities. Exception handling classes and their
				definition is also included in this file

Exceltion Handling Class
				FileIOException: This class handles input/output file operation exceptions

				NegativeNumber: This class handles user inputs that set members to a negative int
								e.g number of copies in stock can not be negative
									

*/




#ifndef RENTAL_ITEM_
#define RENTAL_ITEM_


#include<string>
#include<iostream>
#include<algorithm>
#include<iomanip>

using std::string;
using std::istream;
using std::ostream;
using std::sort;   //generic sort
using std::cout;
using std::cin;
using std::endl;
using std::setprecision; //printing price digit
using std::fixed;  //printing price digit in money format


namespace csci2312
{


	class FileIOException
	{
		//left empty on purpose
	};

	class NegativeNumber
	{
	private:
		string message; //negative value that was set
	public:
		NegativeNumber(string iMessage) { message = iMessage; }; //constuctor with message
		void getMessage() const { cout << endl << message << " can not be a negative number\n"; };
		//print the error message before gracefully exit program
	};



	//*****************************************
	//				Rental Item Class (Parent Abstract Class)
	//*****************************************

	class Rental_Item
	{
	protected:

		int ID;     //unique 4 digit ID for each Rental Item object
		string title;  //Title of the Item
		int numOfCopy; //number of copies in stock available for rent
		double price;  //Price of Rental 


	public:
		Rental_Item();  //Default constructor
		~Rental_Item(); //Default destuctor
		Rental_Item(Rental_Item& Item1); //copy Constructor

		//pure virtual functions. No definition needed.
		virtual string identify() = 0;    //Prints Derived class indentity. e.g Movie or Book
		virtual void print() = 0;         //Prints Specifics unique to derived class
		//getters and setters
		void setID(int iID) throw (NegativeNumber); 
		void setTile(string iTitle);
		void setNumOfCopy(int amount) throw (NegativeNumber);
		void setPrice(double iPrice);
		int getID();
		string getTitle();
		int getNumOfCopy();
		double getPrice();

		void removeAcopy(int amount); //used when we remove a copy from stock. Process rental
		void addAcopy(int amount);    //used when a copy is returned. Process return 
		 
		//overloaded operator
		friend ostream& operator << (ostream& out, Rental_Item& Item);
	};


}//end namespace



#endif // !RENTAL_ITEM_
