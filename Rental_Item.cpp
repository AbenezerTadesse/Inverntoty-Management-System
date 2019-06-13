

/*
Abenezer Tadesse
CSCI 2312 Final Project
12/06/16
Meets all requirement. Compiles successfully on cse grid


Renatl Store Inventory Management Program

Description:	This is Rental_Item class definition


*/



#include "Rental_Item.h"

namespace csci2312
{
	//************************************************
	//				Default Constructor
	//************************************************
	Rental_Item::Rental_Item()
	{
		ID = 0;
		title = " ";
		numOfCopy = 0;
		price = 0;
	}

	//************************************************
	//				Default Destructor
	//************************************************

	Rental_Item::~Rental_Item()
	{
		//no dynamic memory
	}


	//************************************************
	//				Copy Constructor (Deep Copy)
	//************************************************

	Rental_Item::Rental_Item(Rental_Item & Item1)
	{
		this->ID = Item1.getID();
		this->title = Item1.getTitle();
		this->numOfCopy = Item1.getNumOfCopy();
		this->price = Item1.getPrice();
	}


	
	//************************************************
	//				Getters and setters
	//************************************************

	void Rental_Item::setID(int iID) throw (NegativeNumber)
	{
		if (iID < 0) //if ID is negative number throw Exception
		{
			throw NegativeNumber("ID number");
		}
				//else set ID
		ID = iID;
	}

	void Rental_Item::setTile(string iTitle)
	{
		title = iTitle;
	}

	void Rental_Item::setNumOfCopy(int amount) throw(NegativeNumber)
	{
		if (amount < 0) //if number of copies is negative throw exception
		{
			throw NegativeNumber("Number of Copies");
		}
		numOfCopy = amount;
	}


	//decrement amount from copy. Reduce number of copies by amount
	void Rental_Item::removeAcopy(int amount)
	{
		if (amount <= numOfCopy)  //Only decrement the available amount
		{
			numOfCopy -= amount;
		}
		else  //Not enough copies are available. Print error message 
		{
			cout << "\nOnly " << numOfCopy << " copies available for check out\n";
		}
		
	}

	//increase number of copies by amount.
	void Rental_Item::addAcopy(int amount)
	{
		numOfCopy += amount;
	}

	void Rental_Item::setPrice(double iPrice)
	{
		price = iPrice;
	}

	int Rental_Item::getID()
	{
		return ID;
	}

	string Rental_Item::getTitle()
	{
		return title;
	}

	int Rental_Item::getNumOfCopy()
	{
		return numOfCopy;
	}

	double Rental_Item::getPrice()
	{
		return price;
	}



	//************************************************
	//				Overloaded ostream operator
	//Descrition: Only prints the Parent Class attributes
	//************************************************
	
	ostream & operator<<(ostream & out, Rental_Item & Item)
	{
		out
			<< Item.getID() << endl
			<< Item.getTitle() << endl
			<< Item.getNumOfCopy() << endl
			<< Item.getPrice() << endl;
		return out;
	}

}//end namespace
