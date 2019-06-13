#pragma once



/*
Abenezer Tadesse
CSCI 2312 Final Project
12/06/16
Meets all requirement. Compiles successfully on cse grid


Renatl Store Inventory Management Program

Description:	Inventory Class header file

				Inventory is an ADT that has a vector as a private member. The vector is of type
				pointer to Renatl_Item. We use pointers to Rental_Item to access all objects of 
				classes that are derived from Rental_Item such as Rental_Movie and Rental_Book
				
				Inventory class has memeber function that can sort the vector by Title, ID, Price 
				and also Item type. Custom comparison and search predicate functions are defined in this 
				class so that we can make user of the generic sort and search algorithms for vector STL

				This class also has a template fuction that can be used to sort and print all items of 
				the same drived class whatever the derived class may be as long as it is a derived from
				Rental_Item. To avoid compilaion error the template function definition is also included here

				Inventory Class has overloaded operators for file IO operations
*/




#ifndef INVENTORY_
#define INVENTORY_

#include"Rental_Item.h"
#include"Rental_Movie.h"
#include"Rental_Book.h"
#include<vector>
#include<cctype>
#include<fstream>

using std::vector;
using std::search_n;
using std::getline;
using std::ifstream;
using std::ofstream;


namespace csci2312
{
	typedef Rental_Item* Rental_ItemPtr;
	typedef Rental_Movie* Rental_MoviePtr;
	typedef Rental_Book* Rental_BookPtr;

	class Inventory
	{
	private:
		vector<Rental_ItemPtr>Shelf;  //contains pointers to item locations
		vector<Rental_ItemPtr>::iterator ShelfItr; //what is it for????	use it in search_n algorithm
		
	public:
		Inventory();
		~Inventory();
	
		void addItem(Rental_ItemPtr ItemPtr);  
		void removeItem(Rental_ItemPtr ItemPtr);
		void sortByID();
		void sortByPrice();
		void sortByTitle();
		void sortByType();
		template <class ItemType>void printByItemType();
		Rental_ItemPtr searchInventory(int iID);
		Rental_ItemPtr searchInventory(string iTitle);
		bool empty();
		size_t size() const;
		void print();

		//Sorting comparison functions
		friend bool compTitle(Rental_ItemPtr ItemPtr1, Rental_ItemPtr ItemPtr2);
		friend bool compPrice(Rental_ItemPtr ItemPtr1, Rental_ItemPtr ItemPtr2);
		friend bool compItemType(Rental_ItemPtr ItemPtr1, Rental_ItemPtr ItemPtr2);

		//predicate functions for generic search algorithm
		friend bool compID(Rental_ItemPtr ItemPtr1, Rental_ItemPtr ItemPtr2);
		friend bool predID(Rental_ItemPtr ItemPtr2, int iID);
		friend bool predTitle(Rental_ItemPtr ItemPtr1, string iTitle);
		friend string toLowerCase(string inWord);

		friend ostream& operator << (ostream& out, Inventory& Inventory1);
		friend istream& operator >> (istream& in, Inventory& Inventory1);
		

	};

	//template definition
	template<class ItemType>
	inline void Inventory::printByItemType()
	{
		ItemType* ItemPtr = nullptr; //get a pointer to Item type

		for (size_t pos = 0; pos < Shelf.size(); pos++) //loop over each element in Shelf
		{	//Runtime type Identification
			ItemPtr = dynamic_cast<ItemType*>(Shelf[pos]); //check each pointer if it points to the same 
			if (ItemPtr != nullptr)							//same derived class as ItemType
			{
				ItemPtr->print(); //envoke the print only for those that are of same derived class as Item
			}
		}
	}

}






#endif // !INVENTORY_
