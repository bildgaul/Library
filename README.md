Author: Billy Gauldin
Date: 11-23-21
File: README

This program is a BookStoreInventory program called library! In order to use
the program you must first select the "Build an inventory from a file" option
and specify the file you want to read in (preferably a .dat fle). The program
will build an inventory using the file that quickly searches for a book using
its title!
Features:
	- library allows you to add files to the current inventory by selecting
	the "Build an inventory from a file" feature and providing a file name
	(preferably a .dat file). If no inventory exists,
	library will build a new inventory, and will insert any new data on top
	of the already existing inventory!
	- library lets you save the current inventory to your computer. You can
	do this by selecting the "Write the inventory to a file" option on the
	menu and then typing the filename of the file you wish to save
	(preferably a .dat file).
	- You can print the current inventory by selecting the "Print the
	inventory" feature on the menu.
	- You can search for a book using a substring of the book by selecting
	the "Search the stock of the books whos titles match a substring"
	option on the menu and providing a substring to search with. If a book
	title contains the substring, it's details will be printed.
	- You can delete a book from the inventory using a substring by
	selecting the "Delete a book or books from the inventory whos titles
	match a substring" option on the menu and providing a substring. If a
	book title contains the substring, it will be deleted.
	- You can exit the program by selecting the "Exit this program" option.
	You will recieve a nice, happy message on the way out.

Bugs: The delete function will "delete" a node, but the node is still
accessible in other methods for some reason, even after being made null.
-In the provided test case, a random node to the right of the "War and Peace"
node exists with an empty title. It says it's right node is null when deleted,
but randomly isn't when the right node itself is asked if its null. It's not
being inserted after, but for some reason it exists.

I learned to not wait until your partner is done to ask if it's OK to be the
third person in their group. I have no partner and am doing this by myself
on the last day.