


/*
Abenezer Tadesse
CSCI 2312 Final Project
12/06/16
Meets all requirement. Compiles successfully on cse grid


Renatl Store Inventory Management Program

Description:	Rental_Book class definition file

*/



#include "Rental_Book.h"

namespace csci2312
{
	//************************************************
	//				Default Constructor 
	//************************************************
	Rental_Book::Rental_Book() :Rental_Item()
	{
		author = " ";
		numOfPages = 0;
	}


	//************************************************
	//				Default Destructor
	//************************************************
	Rental_Book::~Rental_Book()
	{
		//no dynamic memory
	}


	//************************************************
	//				Copy Constructor (Deep Copy)
	//************************************************
	Rental_Book::Rental_Book(Rental_Book & Book) : Rental_Item(Book)
	{
		this->author = Book.getAuthor();
		this->numOfPages = Book.getNumOfPages();
	}


	//************************************************
	//				Identify()
	//
	//Descripton:	returns the string 'Book' which we can use to 
	//				identify Rental_Movie objects
	//
	//************************************************

	string Rental_Book::identify()
	{
		return "Book";
	}


	//************************************************
	//				print()
	//
	//Descripton:	Prints Book class specifics
	//
	//************************************************
	void Rental_Book::print()
	{
		cout <<
			"\n\tBook****\n"
			<< "ID number:\t" << ID << endl
			<< "Titel:\t\t" << title << endl
			<< "Stock:\t\t" << numOfCopy <<" copies"<< endl
			<< "Author:\t\t" << author << endl
			<< "Book size:\t" << numOfPages << " pages" << endl
			<< "Price:\t\t" << "$" << setprecision(2) << fixed<< price << endl;
	}


	//************************************************
	//				Getters and setters
	//************************************************

	string Rental_Book::getAuthor()
	{
		return author;
	}

	int Rental_Book::getNumOfPages()
	{
		return numOfPages;
	}

	void Rental_Book::setAuthor(string iAuthor)
	{
		author = iAuthor;
	}

	void Rental_Book::setNumOfPages(int iNumOfPages) throw (NegativeNumber)
	{
		if (iNumOfPages < 0)
		{
			throw NegativeNumber("Number of pages");
		}
		numOfPages = iNumOfPages;
	}

}//end namespace
