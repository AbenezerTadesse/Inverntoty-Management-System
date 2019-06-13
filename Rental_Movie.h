#pragma once




/*
Abenezer Tadesse
CSCI 2312 Final Project
12/06/16
Meets all requirement. Compiles successfully on cse grid


Renatl Store Inventory Management Program

Description:	This is a header file for Rental_Movie class. 
				It is derived from Rental_Item class. Definitions for pure 
				functions is given here

				This class is used to handle Movie rentals

*/





#ifndef RENTAL_MOVIE_
#define RENTAL_MOVIE_

#include"Rental_Item.h"


namespace csci2312
{
	class Rental_Movie : public Rental_Item
	{
	private:
		string movieDirector;  //specific to this class. name of movie director
		int runTime;      //specific to this class. Movie run time

	public:
		Rental_Movie(); //default constructor
		~Rental_Movie();  //defualt destructor
		Rental_Movie(Rental_Movie& Movie); //copy constructor

		virtual string identify(); //identifies the object 
		virtual void print();  //prints Movie obj details

		//setters and getters
		string getMovieDirector();
		int getRunTime();
		void setMovieDirector(string iMovieDirector);
		void setRunTime(int iRunTime) throw (NegativeNumber);

		
	};
}//end namespace csci2312


#endif