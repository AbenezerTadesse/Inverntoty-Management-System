


/*
Abenezer Tadesse
CSCI 2312 Final Project
12/06/16
Meets all requirement. Compiles successfully on cse grid


Renatl Store Inventory Management Program

Description:	This is the driver file for the program. This program is menu driven. The user
				will make choices from a menu printed to the screen using num keys. The program 
				prompts the user to read in an inventory from file. Sample input file input.txt is 
				submitted with this program. 
				
				Once data is read-in the user has options to read in more data ot add Items manually

				The Inventory Items in this program are Movie and Books. This program allows the user
				to keep track of these items. Each item is assigned a unique digit ID number. All items 
				have title, price, and numbe of copies in stock. In addition all movies have director's full name 
				and run time, whereas Books have author full name and total number of pages od the book

				The user can sort the Inventory by Title, ID, Price, or Itemtype(Book/Movie)
				Seaching can be done using Title or ID of the Item. When searching by Title, the seach field
				is not case sensitive therefore, "the fall" is a match for "The Fall"

				Program also alows the user to only print all Books or Movies in inventory 
				Check_in and Check_out functionalities allow the user to process rental and return transactions
				
				When an Item is no longer needed in the inventory, the user can remove it from the inventory.
				All other fields are not editable. 

 PRECONDITION: File input must follow the file input guidlines.
				User input range is validated by the program. But user input type is not. All menu choices are
				integers. The program can only validate integer inputs. Character input will crush the program

				Invalid input file name throws an exception.
				Inputing negative number for price, number of pages or runtime throws an exception


*/


#include "MenuFunctions.h"
using namespace csci2312;


enum menu
{
	ADD = 1, REMOVE = 2, CHECK_IN = 3, CHECK_OUT = 4,
	SORT = 5, SEARCH = 6, PRINT = 7, EXPORT = 8, EXIT = 9
};


int main()
{
	Inventory Inventory1; 
	string fileName;
	int mainMenuPick, subMenuPick;


	//print a welcome message
	cout << "\n\n\tWelcome to Rental store Inventory Management Program\t"
		<< "\n\nPlease enter a txt file name to read Inventory from\n"
		<< "e.g fileName.txt\n";
	//read-in fileName and run the program
	cin >> fileName;
	
	try
	{
		//Inport data from file and print main menu 
		addInventory(Inventory1, fileName);
		cout << "Please pick from the menu below. Enter numbers 1 - 9" << endl;
		
		printMainMenu();
		cin >> mainMenuPick;

		mainMenuPick = menuInputValidator(1, 9, mainMenuPick); //validate input

		while (mainMenuPick) //Loop main menu
		{
			if (mainMenuPick == ADD) //************************************ Add *********************************
			{
				cout << "nHow would you like to add Rental Item\n"
					<< "1: Manually\n"
					<< "2: From file\n";
				cin >> subMenuPick;

				subMenuPick = menuInputValidator(1, 2, subMenuPick); //validate input

				if (subMenuPick == 1) //add Items manully
				{
					addInventory(Inventory1); //this function handles manual input and user interface
					printMainMenu();//print main menu and loop
					cin >> mainMenuPick;
					mainMenuPick = menuInputValidator(1, 9, mainMenuPick); //validate
				}//end manually add
				else
				{//add from file. Prompt user for a file name
					cout 
						<< "\n\nPlease enter a txt file name to read Inventory from\n"
						<< "e.g fileName.txt\n";
					cin >> fileName;
					addInventory(Inventory1, fileName);//handles importing from file. Throws exeption
													 //if file operation fails
					//print main menu and loop
					printMainMenu();
					cin >> mainMenuPick;
					mainMenuPick = menuInputValidator(1, 9, mainMenuPick); //validate
				}//end add Item from file
			}//END ADD new item

			else if (mainMenuPick == REMOVE) //******************************** REMOVE ***********************************
			{
				cout << "\nHow would you like to search for item to be removed\n";
				printSearchField();
				cin >> subMenuPick;
				subMenuPick = menuInputValidator(1, 2, subMenuPick);

				if (subMenuPick == 1) //search by ID and remove
				{
					int iID;
					cout << "Enter ID: ";
					cin >> iID;
					if (Inventory1.searchInventory(iID) == nullptr)//Item not found
					{
						cout << "\nNo such item found\n";
					}

					else
					{//item is found
						cout << "\nThe following Item is deleted successfully\n";
						Inventory1.searchInventory(iID)->print();
						Inventory1.removeItem(Inventory1.searchInventory(iID));
					}
				}//end search and remove by ID

				else //search and remove by Title
				{
					string iTitle;
					cout << "\nEnter Title: ";
					cin.ignore();
					getline(cin, iTitle);

					if (Inventory1.searchInventory(iTitle) == nullptr)
					{
						cout << "\nNo such item found\n";
					}

					else
					{
						cout << "\nThe following Item is deleted successfully\n";
						Inventory1.searchInventory(iTitle)->print();
						Inventory1.removeItem(Inventory1.searchInventory(iTitle));
					}
				}//end search and remove by Title

				printMainMenu();
				cin >> mainMenuPick;
				mainMenuPick = menuInputValidator(1, 9, mainMenuPick);

			}//END REMOVE item

			else if (mainMenuPick == CHECK_IN) //********************** CHECK IN *****************************
			{
				int repeat = 1;
				while (repeat == 1) //repeat loop until user is done checking in items
				{//print search fields to search for item to be checked in 
					cout << "\nHow would you like to search for item to check_in\n";
					printSearchField();
					cin >> subMenuPick;
					subMenuPick = menuInputValidator(1, 2, subMenuPick);//validate

					if (subMenuPick == 1) //search by ID and check in
					{
						int iID, amount;
						cout << "Enter ID: ";
						cin >> iID;
						if (Inventory1.searchInventory(iID) == nullptr)
						{
							cout << "\nNo such item found\n";
						}

						else
						{//item is found. Print item and prompt for check in
							cout << "\nThe following Item was found\n";
							Inventory1.searchInventory(iID)->print();

							cout << "\nHow many copies would you like yo check_in\n";
							cin >> amount;
							Inventory1.searchInventory(iID)->addAcopy(amount);

							cout << "\nItem updated successfully\n";
						}
					}//end search and check in by ID

					else //search and check in by Title
					{
						string iTitle;
						int amount;
						cout << "\nEnter Title: ";
						cin.ignore();
						getline(cin, iTitle);

						if (Inventory1.searchInventory(iTitle) == nullptr)
						{
							cout << "\nNo such item found\n";
						}

						else
						{
							cout << "\nThe following Item was found\n";
							Inventory1.searchInventory(iTitle)->print();

							cout << "\nHow many copies would you like yo check_in\n";
							cin >> amount;
							Inventory1.searchInventory(iTitle)->addAcopy(amount);

							cout << "\nItem updated successfully\n";
						}
					}//end search and check in by Title

					cout << "\nWould you like to check in another item\n"
						<< "1: Yes\n"
						<< "2: No. Return to main menu\n";
					cin >> repeat;
					repeat = menuInputValidator(1, 2, repeat);
			}// end repeat check in loop

				printMainMenu();
				cin >> mainMenuPick;
				mainMenuPick = menuInputValidator(1, 9, mainMenuPick);

			}//END CHECK IN item

			else if (mainMenuPick == CHECK_OUT) //***********************CHECK OUT *****************************
			{
				int repeat = 1;
				while (repeat == 1)
				{

					cout << "\nHow would you like to search for item to check_out\n";
					printSearchField();
					cin >> subMenuPick;
					subMenuPick = menuInputValidator(1, 2, subMenuPick);

					if (subMenuPick == 1) //search by ID and check out
					{
						int iID, amount;
						cout << "Enter ID: ";
						cin >> iID;
						if (Inventory1.searchInventory(iID) == nullptr)
						{
							cout << "\nNo such item found\n";
						}

						else
						{
							cout << "\nThe following Item was found\n";
							Inventory1.searchInventory(iID)->print();

							cout << "\nHow many copies would you like yo check_out\n";
							cin >> amount;
							Inventory1.searchInventory(iID)->removeAcopy(amount);

							cout << "\nItem updated successfully\n";
						}
					}//end search and check out by ID

					else //search and check out by Title
					{
						string iTitle;
						int amount;
						cout << "\nEnter Title: ";
						cin.ignore();
						getline(cin, iTitle);

						if (Inventory1.searchInventory(iTitle) == nullptr)
						{//search and if not fouund print a message
							cout << "\nNo such item found\n";
						}

						else
						{//item is found. Print item details 
							cout << "\nThe following Item was found\n";
							Inventory1.searchInventory(iTitle)->print();
							//process check out
							cout << "\nHow many copies would you like yo check_out\n";
							cin >> amount;
							Inventory1.searchInventory(iTitle)->removeAcopy(amount);

							cout << "\nItem updated successfully\n";
						}
					}//end search and check out by Title

					cout << "\nWould you like to check out another item\n"
						<< "1: Yes\n"
						<< "2: No. Return to main menu\n";
					cin >> repeat;
					repeat = menuInputValidator(1, 2, repeat);
				}// end repeat check out loop

				printMainMenu();
				cin >> mainMenuPick;
				mainMenuPick = menuInputValidator(1, 9, mainMenuPick);
			}//END CHECK OUT item

			else if (mainMenuPick == SORT) //****************************** SORT *****************************
			{
				printSortField();
				cin >> subMenuPick;
				subMenuPick = menuInputValidator(1, 4, subMenuPick);

				switch (subMenuPick)
				{
				case 1:
					Inventory1.sortByID();
					break;
				case 2:
					Inventory1.sortByTitle();
					break;
				case 3:
					Inventory1.sortByPrice();
					break;
				case 4:
					Inventory1.sortByType();
					break;
				}
				cout << "Inventory sorted successfully\n";

				printMainMenu();
				cin >> mainMenuPick;
				mainMenuPick = menuInputValidator(1, 9, mainMenuPick);
			}//END SORT item

			else if (mainMenuPick == SEARCH)//**************************************SEARCH ***********************************
			{
				cout << "\nHow would you like to search\n";
				printSearchField();
				cin >> subMenuPick;
				subMenuPick = menuInputValidator(1, 2, subMenuPick);

				if (subMenuPick == 1)//Search using ID
				{
					int iID;
					cout << "Please inter ID: ";
					cin >> iID;

					if (Inventory1.searchInventory(iID) == nullptr)
					{
						cout << "\nNo such item found\n";
					}

					else
					{
						cout << "\nThe following Item was found\n";
						Inventory1.searchInventory(iID)->print();

					}
				}//end Search by ID

				else //search by Title
				{
					string iTitle;
					cout << "\nEnter Title: ";
					cin.ignore();
					getline(cin, iTitle);

					if (Inventory1.searchInventory(iTitle) == nullptr)
					{
						cout << "\nNo such item found\n";
					}

					else
					{
						cout << "\nThe following Item was found\n";
						Inventory1.searchInventory(iTitle)->print();
					}
				}//end search by Title

				printMainMenu();
				cin >> mainMenuPick;
				mainMenuPick = menuInputValidator(1, 9, mainMenuPick);
			}//END search for Item

			else if (mainMenuPick == PRINT) //***********************************Print INVENTORY******************************
			{
				cout << "\nPlease choose fromt the following\n"
					<< "\t1: Print All Books Only\n"
					<< "\t2: Print All Movies Only\n"
					<< "\t3: Print Everything\n";
				cin >> subMenuPick;

				subMenuPick = menuInputValidator(1, 3, subMenuPick);

				if (subMenuPick == 1) //use template function to print books only
				{
					
					Inventory1.printByItemType<Rental_Book>();
				}

				else if (subMenuPick == 2)//use template function to print books only
				{
					
					Inventory1.printByItemType<Rental_Movie>();
				}

				else if (subMenuPick == 3) //print everything in Inventory
				{
					Inventory1.print();
				}
				

				printMainMenu();
				cin >> mainMenuPick;
				mainMenuPick = menuInputValidator(1, 9, mainMenuPick);
			}//END PRINT item

			else if (mainMenuPick == EXPORT) //******************************** EXPORT ********************************
			{
				cout << "\nPlease enter file name. Save as: ";
				cin >> fileName;
				ofstream outFile;

				outFile.open(fileName);
				outFile << Inventory1;
				outFile.close();

				cout << "Inventory exported to " << fileName << " Successfuly" << endl;

				printMainMenu();
				cin >> mainMenuPick;
				
				mainMenuPick = menuInputValidator(1, 9, mainMenuPick);
			}//END EXPORT inventory

			else if (mainMenuPick == EXIT) //************************************ EXIT **********************************
			{
				cout << "\n\n\tTHANK YOU FOR USING INVENTORY MANAGMENT\n"
					<< "Good Bye!!!\n\n";
				break;
			}//END EXIT program
		}//end main menu loop
		

	}//END try
	
	catch(FileIOException) //catch if file operation exception is thrown
	{
		cout << "\n\tFile open error!\n\n"; //print error message
		cin.ignore();
		cin.ignore();
		exit(0);
	}
	catch (NegativeNumber e) //catch if negative numbers are set to none negative variables
	{
		e.getMessage(); //print error message
		cin.ignore();
		exit(0);
	}


	cin.ignore();
	cin.ignore();
	return 0;
}