// Author: Billy Gauldin
// Date: 11-23-21
// File: main.cpp
// Description: Drives the program using a user interface and a menu
#include <iostream>
#include <string>
#include "library.h"
using namespace std;

/*
 * Description: Prints a menu for the user to select options from
 */
void printMenu();

int main(){
  library lib;
  printMenu();

  int userChoice;
  cout << "Please enter your choice now: ";
  cin >> userChoice;

  while(userChoice != 6){
    switch(userChoice){
    case 1:{
      string file;
      cout << "Please enter a file to read from: ";
      cin >> file;
      lib.read_file(file);
      break;
    }
    case 2:{
      string file;
      cout << "Please enter a file to save to: ";
      cin >> file;
      lib.save_file(file);
      break;
    }
    case 3:
      lib.print();
      break;
    case 4:{
      string substr;
      cout << "Please enter a substring to search with: ";
      getline(cin, substr);
      lib.find_node(substr);
      break;
    }
    case 5:{
      string substr;
      cout << "Please enter a substring to delete books with: ";
      getline(cin, substr);
      lib.delete_node(substr);
      break;
    }
    default:
      cout << "Invalid choise! Please choose another option." << endl;
      break;
    }
    
    printMenu();
    cout << "Please enter your choice now: ";
    cin >> userChoice;
  }
  cout << "Thank you for using the BookStore Inventory! Have a nice day!"
       <<endl;
  return 0;
}

void printMenu(){
  cout << "Welcome to the BookStore Inventory!" // too long, splitting it up
    << " You may select one of the following options:\n"
    << "1 Build an inventory from a file\n"
    << "2 Write the inventory to a file\n"
    << "3 Print the inventory\n"
    << "4 Search the stock for the books whos titles match a substring"
    << "5 Delete a book or books from the inventory whose titles match a substring\n"
    << "6 Exit this program\n"
    << endl;
}
