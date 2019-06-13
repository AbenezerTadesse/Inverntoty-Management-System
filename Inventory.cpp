






/*
Abenezer Tadesse
CSCI 2312 Final Project
12/06/16
Meets all requirement. Compiles successfully on cse grid


Renatl Store Inventory Management Program

Description:	This is a implemetation file for Inventory class.


*/











#include "Inventory.h"

namespace csci2312
{



	//******************* toLowerCase (string inWord)*****************************
	//
	//	Descripton: Converts all the letters in string to lower case letters
	//				
	//	PRECONDITION: string must be letters only
	//
	//	POSTCONDITION: a string containing all lower case letters is returned
	//
	//***************************************************************************
	string toLowerCase(string inWord)
	{
		string outWord;
		outWord.clear(); //clear the outWord so that we can add lower case letters from inWord

		for (size_t i = 0; i < inWord.length(); i++)  //iterate over each letter, covert to lowercase
		{														//and add to outWord
			outWord.push_back(tolower(inWord[i]));
		}
		//cout << outWord << endl;   //just to test functions
		return outWord;
	}



	//Sorting Comp Functions that we will use with generic algorithm sort
	//Shelf is Rental_ItemPtr type and using these customized comparison functions 
	//we can compare elements in Shelf
	
	//****************************************************************
	//							compID
	//
	//	Description: Using the passed in pointers it compares the ID value of the objects
	//					the two pointers are pointing to
	//
	//****************************************************************


	bool compID(Rental_ItemPtr ItemPtr1, Rental_ItemPtr ItemPtr2)
	{
		return (ItemPtr1->getID() < ItemPtr2->getID());
	}

	//****************************************************************
	//							compTitle
	//
	//	Description: Using the passed in pointers it compares the title values 
	//					of the objects the two pointers are pointing to
	//
	//****************************************************************

	bool compTitle(Rental_ItemPtr ItemPtr1, Rental_ItemPtr ItemPtr2)
	{
		return (ItemPtr1->getTitle() < ItemPtr2->getTitle());
	}

	//****************************************************************
	//							compPrice
	//
	//	Description: Using the passed in pointers it compares the price values 
	//					of the objects the two pointers are pointing to
	//
	//****************************************************************

	bool compPrice(Rental_ItemPtr ItemPtr1, Rental_ItemPtr ItemPtr2)
	{
		return (ItemPtr1->getPrice() < ItemPtr2->getPrice());
	}

	//****************************************************************
	//							compType
	//
	//	Description: Using the passed in pointers it compares the type values.
	//				 Since type is not something we would compare the real use of this
	//				 function is to sort the vector by Item, although we would not really
	//				 say one item is greater than the other, the identify() function of
	//				 Rental_Movie and Rental_Book class returns "Movie" and "Retal"
	//				This means we can actually sort the vector to all Books first
	//				and then all Movies/
	//					
	//
	//****************************************************************
	bool compItemType(Rental_ItemPtr ItemPtr1, Rental_ItemPtr ItemPtr2)
	{
		return (ItemPtr1->identify() < ItemPtr2->identify());
	}

	//Binary predicate that compares ID values of two items 
	bool predID(Rental_ItemPtr ItemPtr2, int iID)
	{
		return (iID == ItemPtr2->getID());
	}

	bool predTitle(Rental_ItemPtr ItemPtr1, string iTitle)
	{
		//when comparing two strigs for title match we convers 
		//all the characters to lowercase that way out predicate is not case sensitive
		//thus eg. 'The Book of life' is the same as 'The Book Of Life'
		return (toLowerCase(ItemPtr1->getTitle()) == iTitle);
	}

	

	//************************************************
	//				Default Constructor 
	//************************************************

	Inventory::Inventory() 
	{
		Shelf.clear();
		
	}

	//************************************************
	//				Default Destructor
	//************************************************
	Inventory::~Inventory()
	{
		for (size_t pos = 0; pos != Shelf.size(); pos++)
		{
								//All elements fo vector Shelp will be dynamic so
			delete Shelf[pos]; //we loop over each element and delete the new the dynamic memeory
		}

		//clear the vector
		Shelf.clear();
	}

	//************************************************
	//				addItem
	//	Description: Simply addes Rental_Item pointer to Shelf
	//************************************************
	void Inventory::addItem(Rental_ItemPtr ItemPtr)
	{
		Shelf.push_back(ItemPtr);
	}


	//************************************************
	//				removeItem
	//	Description: Search and remove itemPtr
	//************************************************
	void Inventory::removeItem(Rental_ItemPtr ItemPtr)
	{
		for (size_t pos = 0; pos!= Shelf.size(); pos++)
		{//iterate over each Shelf element and when itemPtr that points to target item is found
			if (Shelf[pos] == ItemPtr) //if ItemPtr that points to target item is found remove it
			{
				delete Shelf[pos];
				Shelf.erase(Shelf.begin() + pos);
				break;
			}
		}
	}

	//************************************************
	//				sort functions
	//	Description: Simply sorts elements of Shelf using generic sort algorithm
	//					
	//************************************************

	void Inventory::sortByID()
	{
		sort(Shelf.begin(), Shelf.end(), compID);
	}

	void Inventory::sortByPrice()
	{
		sort(Shelf.begin(), Shelf.end(), compPrice);
	}

	void Inventory::sortByTitle()
	{
		sort(Shelf.begin(), Shelf.end(), compTitle);
	}

	//************************************************
	//				sortByType
	//	Description: Simply sorts elements of Shelf using generic sort algorithm
	//	PostCondition:	Shelf is sorted by Item. Books first then Movies			
	//************************************************
	void Inventory::sortByType()
	{
		sort(Shelf.begin(), Shelf.end(), compItemType);
	}



	//************************************************
	//				SearchInventory(int)
	//	Description: Shelf is searched using generic search algorithm
	//
	//	PostCondition:	Returns a nullptr or if found
	//					ItemPtr with address of item 
	//************************************************
	
	Rental_ItemPtr Inventory::searchInventory(int iID)
	{
		Rental_ItemPtr ItemPtr = nullptr;

		//use the generic algorith to search using ID
		//we have a binary predicate predID that returns true only when IDs of two items are equal
		ShelfItr = search_n(Shelf.begin(), Shelf.end(), 1,  iID, predID);

		if (ShelfItr != Shelf.end())
		{
			ItemPtr = *ShelfItr;
		}

		return ItemPtr;
	}



	//************************************************
	//				SearchInventory(string)
	//	Description: Shelf is searched using generic search algorithm
	//
	//  PreConditon:	Search is Not case sensitive. i.e 'the' is the same as 'The'
	//
	//	PostCondition:	Returns a nullptr or if found
	//					ItemPtr with address of item 
	//************************************************
	Rental_ItemPtr Inventory::searchInventory(string iTitle)
	{
		Rental_ItemPtr ItemPtr = nullptr;

		//use the generic algorith to search using ID
		//we have a binary predicate predID that returns true only when two items have the same title
		
		//we change the input target title to all lowercase so that out search is not case sensitive

		ShelfItr = search_n(Shelf.begin(), Shelf.end(), 1, toLowerCase(iTitle), predTitle);

		if (ShelfItr != Shelf.end())
		{
			ItemPtr = *ShelfItr;
		}

		return ItemPtr;
	}

	//check if Shelf is empty
	bool Inventory::empty()
	{
		return Shelf.empty();
	}

	size_t Inventory::size() const
	{
		return Shelf.size();
	}


	//************************************************
	//				print
	//	Description: Invokes each items class specific funtion print
	//	PostCondition:	All member of Shelf including class specific details are printed to screen			
	//************************************************
	void Inventory::print()
	{
		for (size_t pos = 0; pos < Shelf.size(); pos++)
		{
			Shelf[pos]->print();
		}
	}

	
	//OVERLOADED OPERATORS
	//Precondition: If out/in is file output/input stream, then out/in has already been
	//connected to a file.
	ostream & operator<<(ostream & out, Inventory & Inventory1)
	{
		
		for (size_t pos = 0; pos < Inventory1.size(); pos++)
		{
			
			//stream out all the common parent class attributes 
				out << Inventory1.Shelf[pos]->identify() << endl
					<< Inventory1.Shelf[pos]->getID() << endl
					<< Inventory1.Shelf[pos]->getTitle() << endl
					<< Inventory1.Shelf[pos]->getNumOfCopy() << endl
					<< Inventory1.Shelf[pos]->getPrice() << endl;

				if (Inventory1.Shelf[pos]->identify() == "Movie") //check if movie and use dynamic casting to   
				{//access Movie object added member variables
					out
						<< dynamic_cast<Rental_MoviePtr>(Inventory1.Shelf[pos])->getMovieDirector() << endl
						<< dynamic_cast<Rental_MoviePtr>(Inventory1.Shelf[pos])->getRunTime() << endl;
				}

				else if (Inventory1.Shelf[pos]->identify() == "Book")
				{//Check if object is book and use dynamic casting (down casting) to access Book member variables
					out
						<< dynamic_cast<Rental_BookPtr>(Inventory1.Shelf[pos])->getAuthor() << endl
						<< dynamic_cast<Rental_BookPtr>(Inventory1.Shelf[pos])->getNumOfPages() << endl;
				}
		}
			return out;
	}



	//PRECONDITION: File must be txt type. The Item attributes must be in a specific order each on a new line
	//				Each item should either start with the word Movie or Book depending on what it is
	//		ORDER: movie/book -> ID -> Title -> numOfCopy -> Price -> Author/Director ->pageNum/runTime
	//			see input.txt submitted with assignment 		


	istream & operator >> (istream & in, Inventory & Inventory1)
	{
		Rental_ItemPtr newItem;
		Rental_BookPtr newBook;
		Rental_MoviePtr newMovie;
		string inWord;
		int inInt = 0;
		double inDouble = 0;

		while (in >> inWord)
		{
			if (toLowerCase(inWord) == "movie") //check if item is Movie
			{
				newMovie = new Rental_Movie; //create a new Movie item
				in >> inInt;

				//set Movie item's ID
				newMovie->setID(inInt);
				in.ignore();
				inWord.clear();
				getline(in, inWord); //read in the entire line for title
				newMovie->setTile(inWord);

				in >> inInt; //read in number of copies
				newMovie->setNumOfCopy(inInt);

				in >> inDouble;  //read in price
				newMovie->setPrice(inDouble);
				string dir;
				in.ignore();
				getline(in, dir);  //read in movie director full name
				newMovie->setMovieDirector(dir);

				in >> inInt; //read in movie run time
				newMovie->setRunTime(inInt);

				//now that we have set all the attributes we can use the parent class ptr to 
				//add it to the inventory
				newItem = newMovie;
				Inventory1.addItem(newItem);

			}//end if movie

			else if (toLowerCase(inWord) == "book")// if item is book
			{
				newBook = new Rental_Book;
				in >> inInt;

				//set Book item's ID
				newBook->setID(inInt);

				in.ignore();
				inWord.clear();
				getline(in, inWord); //read in the entire line for title
				newBook->setTile(inWord);

				in >> inInt; //read in number of copies
				newBook->setNumOfCopy(inInt);

				in >> inDouble;  //read in price
				newBook->setPrice(inDouble);

				in.ignore();
				inWord.clear();
				getline(in, inWord);  //read in book author's full name
				newBook->setAuthor(inWord);

				in >> inInt; //read in total page numbers
				newBook->setNumOfPages(inInt);

				//now that we have set all the attributes we can use the parent class ptr to 
				//add it to the inventory
				newItem = newBook;
				Inventory1.addItem(newItem);
			}//end book
		}//end while

		return in;
	}


}
