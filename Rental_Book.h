#pragma once



/*
Abenezer Tadesse
CSCI 2312 Final Project
12/06/16
Meets all requirement. Compiles successfully on cse grid


Renatl Store Inventory Management Program

Description:	This is a header file for Rental_Book class.
It is derived from Rental_Item class. Definitions for pure
functions is given here

This class is used to handle Book rentals

*/



#ifndef RENTAL_BOOK_
#define RENTAL_BOOK_

#include"Rental_Item.h"

namespace csci2312
{

	class Rental_Book :public Rental_Item
	{
	private:
		string author;
		int numOfPages;

	public:
		Rental_Book();
		~Rental_Book();
		Rental_Book(Rental_Book& Book);

		virtual string identify();
		virtual void print();

		string getAuthor();
		int getNumOfPages();
		void setAuthor(string iAuthor);
		void setNumOfPages(int iNumOfPages) throw (NegativeNumber);

	};

}//end namespace csci2312








#endif // !RENTAL_BOOK_