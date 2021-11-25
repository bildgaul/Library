// Author: Billy Gauldin
// Date: 11-23-21
// File: library.cpp
// Creates and implements all library functions and members

#include "library.h"
#include <iostream>
#include <fstream>
using namespace std;

library::library(){
  head = nullptr;
}

library::~library(){
  destruct_helper(head);
}

void library::destruct_helper(Node *current){
  if (current != NULL){
    destruct_helper(current->left);
    destruct_helper(current->right);
    delete current;
    current = nullptr;
  }
}

void library::insert(Node newNode){
  if (head == NULL){
    head = new Node(newNode);
  }
  else{
    insert_helper(head, newNode);
  }
}

void library::insert_helper(Node *current, Node newNode){
  if (newNode.title < current->title){ // class code
    if (current->left == NULL)
      current->left = new Node(newNode);
    else
      insert_helper(current->left, newNode);
  }
  else if (newNode.title > current->title){
    if (current->right == NULL)
      current->right = new Node(newNode);
    else
      insert_helper(current->right, newNode);
  }
  else // overwrite if the titles are the same
    current = new Node(newNode);
}

void library::print(){
  print_helper(head);
}

void library::print_helper(Node *current){
  if (current != NULL){
    print_helper(current->left);
    cout << current->title << "\n\tISBN: " << current->isbn
	 << "\n\tAmount Left: " << current->amount << endl;
    print_helper(current->right);
  }
}

void library::read_file(string fileName){
  ifstream fin;
  fin.open(fileName);
  Node newNode;
  getline(fin, newNode.title);
  while(fin){
    fin >> newNode.isbn >> newNode.amount;
    fin.get();
    insert(newNode);

    getline(fin, newNode.title);
  }
  fin.close();
}

void library::find_node(string title){
  find_helper(head, title); 
}

void library::find_helper(Node *current, string title){
  if (current != NULL){
    if (current->title.find(title) != string::npos){
      cout << current->title << "\n\tISBN: " << current->isbn
	   << "\n\tAmount Left: " << current->amount << endl;
    }
    find_helper(current->left, title);
    find_helper(current->right, title);
  }
}

void library::delete_node(string title){
  delete_helper(head, title);
}

void library::delete_helper(Node *current, string title){
  if (current == NULL)
    return;
  else if (current->title.find(title) != string::npos){
    Node *temp;
    if (current->left == NULL && current->right != NULL){
      temp = current->right;
      delete current;
      current = temp;
    }
    else if (current->right == NULL && current->left != NULL){
      temp = current->left;
      delete current;
      current = temp;
      }
    else if (current->left == NULL && current->right == NULL){
      delete current;
      current = nullptr;
      return;
    }
    else{
      temp = current->right;

      Node *parent = NULL;
      while (temp->left != NULL){
	parent = temp;
	temp = temp->left;
      }
      current->title = temp->title;
      if (parent != NULL)
	delete_helper(parent->left, parent->left->title);
      else
	delete_helper(current->right, current->right->title);
    }
  }

  delete_helper(current->left, title);
  delete_helper(current->right, title);
}

void library::save_file(string fileName){
  ofstream fout;
  fout.open(fileName);
  save_helper(head, fout);
}

void library::save_helper(Node *current, ofstream &fout){
  if (current != NULL){
    fout << current->title << "\n" << current->isbn << "\n" << current->amount
	 << endl;
    save_helper(current->left, fout);
    save_helper(current->right, fout);
  }
}
