



/*
Abenezer Tadesse
CSCI 2312 Final Project
12/06/16
Meets all requirement. Compiles successfully on cse grid


Renatl Store Inventory Management Program

Description:	This is implementation file for menu functions that will be used to to drive
				the Inventory program

*/ 





#include "MenuFunctions.h"

namespace csci2312
{
	void printMainMenu()  //Simply prints the main menu of the program.
	{
		cout
			<< "\n\t1: Add a new Item\n"
			<< "\t2: Remove an Item\n"
			<< "\t3: Check in an Item\n"
			<< "\t4: Check out an Item\n"
			<< "\t5: Sort Invetory\n"
			<< "\t6: Search\n"
			<< "\t7: Print Inventory\n"
			<< "\t8: Export Inventory to File\n"
			<< "\t9: Exit Program\n";
	}

	void printSearchField() //Searchable fields 
	{
		cout
			<< "\t1: Search by ID number\n"
			<< "\t2: Search by Title\n";
	}

	void printSortField() //sortable fields
	{
		cout
			<< "\t1: Sort by ID number\n"
			<< "\t2: Sort by Title\n"
			<< "\t3: Sort by Price\n"
			<< "\t4: Sort by Item Type (all books first then movies)\n";
	}



	//***************************************************************
	//						addInventory(Inventory&, string)
	// Handles reading in from file and populating the inventory with Retal itmes
	// Throws an exception if input file could not be opened
	//
	// PRECONDITION: overloaded >> operator is used. Input File must have data 
	//				 in the order specified. Each Item attribute must be on
	//				 a seperate line. And the first word befor each new Item should be
	//				 Movie or Book. 
	//				See precondition of >> operator oveload function
	//
	//*******************************************************************


	void addInventory(Inventory & Inventory1, string fileName) throw (FileIOException)
	{
		ifstream inFile;
		inFile.open(fileName); //open file 
		
		if (!(inFile)) //if file operation fail
		{
			throw FileIOException();
		}

		inFile >> Inventory1; //read in data from file using the overloaded operators

		cout << "Inventory successfully updated\n"
			<< Inventory1.size() << " Items in inventory\n";
	}


	//***************************************************************
	//						addInventory(Inventory&)
	// Handles adding Items to Inventory manually
	//
	// PRECONDITION: User must enter valid data. Input is not validated. 
	//				 Input is saved as typed
	//
	//*******************************************************************

	void addInventory(Inventory & Inventory1)
	{
		int typePick, repeat = 1;
		double inPrice;
		string inWord;
		int inNum;

		Rental_BookPtr newBookPtr;
		Rental_MoviePtr newMoviePtr;
		Rental_ItemPtr newItemPtr;

		while (repeat == 1) //repeat until user is done adding 
		{
			cout << "\nPlease choose type of Item to be added\n"
				<< "1: Movie\n"
				<< "2: Book\n";
			cin >> typePick;

			typePick = menuInputValidator(1, 2, typePick); //validated the menu choice

			if (typePick == 1) //new movie item
			{
				newMoviePtr = new Rental_Movie;

				inNum = randomIDnumber();  //generate a random ID number
				//make sure ID number is unique

				//we search the inventory and make sure no other item has the ID we generated
				//If ID is already in use we generate an new one until a unique ID is generated
				while (Inventory1.searchInventory(inNum) != nullptr)
				{
					inNum = randomIDnumber();
				}

				newMoviePtr->setID(inNum); //Assign ID number
				cout << "\nPlease enter Title: ";
				cin.ignore();
				getline(cin, inWord); //Title can be more than one word. Read in the whole line
				newMoviePtr->setTile(inWord);

				//prompt and read in all attributes
				cout << "\nPlease enter number of copies: ";
				cin >> inNum;
				newMoviePtr->setNumOfCopy(inNum);

				cout << "\nPlease enter price: ";
				cin >> inPrice;
				newMoviePtr->setPrice(inPrice);

				cout << "\nPlease enter movie director's full name: ";
				cin.ignore();
				getline(cin, inWord);
				newMoviePtr->setMovieDirector(inWord);

				cout << "\nPlease enter moive run time: ";
				cin >> inNum;
				newMoviePtr->setRunTime(inNum);


				//no slicing. add Item to inventory
				newItemPtr = newMoviePtr;
				Inventory1.addItem(newItemPtr);

				//prompt repeat or main menu
				cout << "\nWould you like to add more\n"
					<< "1: Yes add more\n"
					<< "2: No return to main menu\n";
				cin >> repeat;

				repeat = menuInputValidator(1, 2, repeat);
				
			}//end new movie

			else if (typePick == 2) //new book
			{
				newBookPtr = new Rental_Book;

				inNum = randomIDnumber();  //generate a random ID number
										   //make sure ID number is unique

				while (Inventory1.searchInventory(inNum) != nullptr)
				{
					inNum = randomIDnumber();
				}

				newBookPtr->setID(inNum);
				cout << "\nPlease enter Title: ";
				cin.ignore();
				getline(cin, inWord);
				newBookPtr->setTile(inWord);
				
				//prompt and read in all attributes

				cout << "\nPlease enter number of copies: ";
				cin >> inNum;
				newBookPtr->setNumOfCopy(inNum);

				cout << "\nPlease enter price: ";
				cin >> inPrice;
				newBookPtr->setPrice(inPrice);

				cout << "\nPlease enter book author's full name: ";
				cin.ignore();
				getline(cin, inWord);
				newBookPtr->setAuthor(inWord);

				cout << "\nPlease enter total number of pages: ";
				cin >> inNum;
				newBookPtr->setNumOfPages(inNum);

				//no slicing. add Item to inventory
				newItemPtr = newBookPtr;
				Inventory1.addItem(newItemPtr);

				//prompt repeat or main menu
				cout << "\nWould you like to add more\n"
					<< "1: Yes add more\n"
					<< "2: No return to main menu\n";
				cin >> repeat;

				repeat = menuInputValidator(1, 2, repeat);
			}//end new book
		}
		
			
	}


	//******************************************************************
	//						randomIDnumber()
	// Generates a digit random number
	//
	//	Sorce: http://stackoverflow.com/questions/5008804/generating-random-integer-from-a-range
	//*******************************************************************

	int randomIDnumber()
	{
		std::random_device rd;     // only used once to initialise (seed) engine
		std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister)
		std::uniform_int_distribution<int> uni(1000, 9999); // guaranteed unbiased

		long int ID = uni(rng);

		return ID;
	}

}