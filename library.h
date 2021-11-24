// Billy Gauldin
// Date: 11-23-21
// File: library.h
// Description: Declares the library class, its members, its methods, and the
// Node struct

#ifndef LIBRARY_H
#define LIBRARY_H
#include <string>
#include <fstream>

struct Node{
  Node *left, *right;
  std::string title;
  std::string isbn;
  int amount;
};

class library{
 private:
  Node *head;

  /*
   * Description: A helper function that helps the destructor deallocate the
   * Binary Search Tree's memory
   * 
   * Inputs:
   *         Node *current:
   *             The current node being accessed
   */
  void destruct_helper(Node *current);
  
  /*
   * Description: A helper function that helps insert insert a node into the
   * Binary Search Tree
   * 
   * Inputs:
   *         Node *current:
   *             the current node being accessed
   *         Node *newNode:
   *             the node being inserted
   */   
  void insert_helper(Node *current, Node *newNode);

  /*
   * Description: A helper function that helps print to print all nodes
   * 
   * Inputs:
   *         Node *current:
   *             the current node being accessed
   */
  void print_helper(Node *current);

  /*
   * Description: A helper function that helps find_node find the node it's
   * looking for
   * 
   * Inputs:
   *         string title:
   *             the book title to be found
   */
  void find_helper(Node *current, std::string title);
  
  /*
   * Description: A helper function that helps delete_node delete the node it
   * wants to delete
   * 
   * Inputs:
   *         Node *current:
   *             the current node being accessed
   *         string title
   *             the title of the book being deleted
   */
  void delete_helper(Node *current, std::string title);
  
  /*
   * Description: A helper function that helps save_file access and save all
   * nodes
   *
   * Inputs:
   *         Node *current:
   *             the current node being accessed
   *         ofstream &fout:
   *             the current filestream writing the data
   */
  void save_helper(Node *current, std::ofstream &fout);
  
 public:
 /*
 * Description: Constructor; initiates the head node
 */
  library();
  
  /*
   * Description: Destructor; deallocates all memory
   */
  ~library();
  
  /*
   * Description: Inserts a new node into the Binary Search Tree
   * 
   * Inputs:
   *         Node *newNode:
   *             the node being inserted
   */
  void insert(Node *newNode);

  /*
   * Description: prints the contents of the Binary Search Tree using in-order
   * traversal
   */
  void print();

  /*
   * Description: Reads in a file and turns the data into a Binary Search Tree
   * 
   * Inputs:
   *         string fileName: the filename to open and read from
   */
  void read_file(std::string fileName);

  /*
   * Description: Finds a node or nodes in the Binary Search Tree using a
   * book's title
   * 
   * Inputs:
   *         string title:
   *             the book title to be found
   * 
   * Returns: A node containing the data of the book
   */
  void find_node(std::string title);

  /*
   * Description: Deletes a node or nodes in the Binary Search Tree using a
   * book's title
   * 
   * Inputs:
   *         string title
   *             the title of the book being deleted
   */
  void delete_node(std::string title);

  /*
   * Description: Saves the data in the Binary Search Tree to a file
   * 
   * Inputs:
   *         string fileName:
   *             the file the data is being saved to
   */
  void save_file(std::string fileName);
};

#endif //LIBRARY_H
