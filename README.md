# Inverntoty-Management-System

The Inventory Items in this program are Movie and Books. This program allows the user to keep track of these items. Each item is assigned a unique digit ID number. All items have title, price, and numbe of copies in stock. In addition all movies have director's full name and run time, whereas Books have author full name and total number of pages.

The user can sort the Inventory by Title, ID, Price, or Itemtype(Book/Movie) Seaching can be done using Title or ID of the Item. When searching by Title, the seach field is not case sensitive.
Check_in and Check_out functionalities allow the user to process rental and return transactions
When an Item is no longer needed in the inventory, the user can remove it from the inventory. All other fields are not editable. 

File i/O options are alse available. The program can read-in a database in text file form or write to a text file. The read in file format has to be in the following order with only one item per line. The phrases "Book" and "Movie" are how the program identifies the item and hence required.
  - For books
      - Book
      - ID number
      - Title
      - number of copies
      - price
      - author full name
      - number of pages
  - For movies:
      - Movie
      - ID number
      - Title
      - number of copies
      - price
      - director's full name
      - total run time in min

All the required files and source code along with an example input file are provided in this repo
