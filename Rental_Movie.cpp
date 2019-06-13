


/*
Abenezer Tadesse
CSCI 2312 Final Project
12/06/16
Meets all requirement. Compiles successfully on cse grid


Renatl Store Inventory Management Program

Description:	Rental_Movie class definition file

*/



#include "Rental_Movie.h"

namespace csci2312
{
	//************************************************
	//				Default Constructor 
	//************************************************
	Rental_Movie::Rental_Movie():Rental_Item()  //envok base class constructor
	{
		
		movieDirector = " ";
		runTime = 0;
	}


	//************************************************
	//				Default Destructor
	//************************************************
	Rental_Movie::~Rental_Movie()
	{								//No need to envok base class destuctor. It is automatic
		//no dynamic memory
	}

	//************************************************
	//				Copy Constructor (Deep Copy)
	//************************************************
	Rental_Movie::Rental_Movie(Rental_Movie & Movie):Rental_Item(Movie)
	{											//envoke base class copy constructor
		this->movieDirector = Movie.getMovieDirector();
		this->runTime = Movie.getRunTime();
	}


	//************************************************
	//				Identify()
	//
	//Descripton:	returns the string 'Movie' which we can use to 
	//				identify Rental_Movie objects
	//
	//************************************************
	
	string Rental_Movie::identify()
	{
		return "Movie";
	}

	
	//************************************************
	//				print()
	//
	//Descripton:	Prints movie class specifics
	//
	//************************************************
		
	void Rental_Movie::print()
	{
		cout <<
			"\n\tMovie****\n"
			<< "ID number:\t" << ID << endl
			<< "Titel:\t\t" << title << endl
			<< "Stock:\t\t" << numOfCopy << " copies" << endl
			<< "Directed by:\t" << movieDirector << endl
			<< "Run time:\t" << runTime << "min" << endl
			<< "Price:\t\t" << "$" << setprecision(2) << fixed << price << endl;
	}


	//************************************************
	//				Getters and setters
	//************************************************

	string Rental_Movie::getMovieDirector()
	{
		return movieDirector;
	}

	int Rental_Movie::getRunTime()
	{
		return runTime;
	}

	void Rental_Movie::setMovieDirector(string iMovieDirector)
	{
		movieDirector = iMovieDirector;
	}

	void Rental_Movie::setRunTime(int iRunTime) throw (NegativeNumber)
	{
		if (iRunTime < 0)
		{
			throw NegativeNumber("Movie run time");
		}
		runTime = iRunTime;
	}


}
