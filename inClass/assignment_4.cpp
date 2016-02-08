//
//  Assignment_4.cpp
//  Assignment #4
//
//  Created by Bernin A. Uben on 2/5/16.
//  Copyright © 2016 Bernin A. Uben. All rights reserved.
//
// Write a program to build a doubly linked list whose nodes contain:
// -First Name
// -Last Name
// -Address
// -Phone Number
// Add 5 nodes to the list
// Provide a capability to search for a node based on last name
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

class Node {                                // Node class
  string firstName;                         // node elements / variables
  string lastName;
  string address;
  string phoneNum;
  Node*  next;                              // Pointer to the next node
  Node*  prev;                              // Pointer to the prev node
  
public:
  Node(){};                                 // Constructor
  string getFName()  { return firstName; }; // accesses the 'firstName' variable to return the 'firstName' value
  string getLName()  { return lastName; };  // accesses the 'lastName' variable to return the 'lastName' value
  string getAddress(){ return address; };   // accesses the 'address' variable to return the 'address' value
  string getNum()    { return phoneNum; };  // accesses the 'phoneNum' variable to return the 'phoneNum' value
  Node*  getNext()   { return next; };      // accesses the 'next' variable to return the 'next' value
  Node*  getPrev()   { return prev; };      // accesses the 'prev' variable to return the 'prev' value
  void   SetNextNode(Node* aNext) { next = aNext; }; // Sets the next node private pointer
  void   SetPrevNode(Node* aPrev) { prev = aPrev; }; // Sets the prev node private pointer
  void   SetNode( string nFName, string nLName, string nAddress, string nPhoneNum){ // Sets the nodes private variables
    firstName = nFName;
    lastName = nLName;
    address = nAddress;
    phoneNum = nPhoneNum;
  };
};

class DLinkList{         // DLinkList class
  Node *head;            // sets the start of the node linked list
  Node *tail;            // Sets the end of the node linked list
public:
  DLinkList() { head = NULL; tail = NULL;}; // sets the head to point to NULL or the end of the list
  void Insert();         // lests the user to input the nodes
  void Search();         // Searches through all the nodes for a specific lastName and displays its information
  void Display();        // Shows all the nodes in the linked list with its code and mile values
  void ReverseDisplay(); // IN REVERSE Shows all the nodes in the linked list with its code and mile values
};

int main(){
  DLinkList List; // Initialize a list called 'List'
  cout << "Enter information on five unique individuals:\n\n";
  for (int x = 0; x < 5; x++) {
    cout << "Person #"<< x+1 << ":\n";
    List.Insert(); // Make a new node and add in all the information in this function
    cout << endl;
  }
  bool answer = true;
  string again = "y", confirm;
  while (answer){
    cout << "OPTIONS:\n1) Search by last name\n2) Show all information(First to last)\n3) Show all information(Last to first)\n\n";
    int choice; cin >> choice;
    switch (choice) {
      case 1:
        List.Search();
        break;
      case 2:
        List.Display();
        break;
      case 3:
        List.ReverseDisplay();
        break;
      default:
        cout << "INVALID OPTION\n\n";
        break;
    }
    cout << "Do you want to do anything else?('y' or 'n'): ";
    cin >> again;
    
    if (again != "y"){
      cout << "Are you sure you want to exit?('y' or 'n'): ";
      cin >> confirm;
      if (confirm != "y"){
        again = "y";
      }
    } // If the user wants to go through the loop again, set answer to true else false to end the while loop
    if (again == "y"){ answer = true; } else { answer = false; }
  }
  cout << "Terminating...\n";
  return EXIT_SUCCESS;
}

void DLinkList::Insert(){               // Append a node to the linked list
  Node   *newNode = new Node();         // Create a new node
  Node   *prevNode = NULL;              // Previous node pointer for node
  string firstName; cout << "Enter First Name:";   getline(cin, firstName); // Initializes and Gets the data for the firstName variable
  string lastName;  cout << "Enter Last Name:";    getline(cin, lastName);  // Initializes Gets the data for the lastName variable
  string address;   cout << "Enter Address:";      getline(cin, address);   // Initializes Gets the data for the address variable
  string phoneNum;  cout << "Enter Phone Number:"; getline(cin, phoneNum);  // Initializes Gets the data for the phoneNum variable
  // use the derefrencer, '->', instead of the dot operator to use class methods/functions
  newNode->SetNode(firstName, lastName, address, phoneNum); // Set the default values as the nodes values
  newNode->SetPrevNode(NULL);                               // Set the nodes 'prev' pointer value as 'NULL', and will stay like that if at the start of a doubly linked list to mark an end
  newNode->SetNextNode(NULL);                               // Set the nodes 'next' pointer value as 'NULL', the end of the list
  Node *cNode = head;                   // Set the 'cNode' pointer variable of type Node equal to the head of the list... ->
  // So that 'cNode' is used as an alias for 'head' in the DLinkList class and is not tampered with while the program executes
  if ( cNode != NULL ){                 // If the head is pointing to the end (If there aren't any nodes in the list)
    while ( cNode->getNext() != NULL ){ // While the 'next' pointer variable isnt pointing to NULL / (next item in the list is a node, not the end)
      prevNode = cNode;                 // Set the current node as the old node as preperation for the next line
      cNode = cNode->getNext();         // Get the next node and set it as the current node
    }
    cNode->SetPrevNode(prevNode);       // Set the current nodes 'prev' pointer to the node before it (1 node from NULL)
    cNode->SetNextNode(newNode);        // Set the current nodes 'next' pointer to the recently made node
    newNode->SetPrevNode(cNode);        // Set the newNode nodes 'prev' pointer to the old last node(old tail)
    tail = newNode;                     // Set the newNode as the new tail
  } else {                              // 'if (cNode == NULL)' the head is pointing to the end of the list and there are no nodes in the list
    tail = newNode;                     // after the node has been added to the empty array, its not empty anymore, we set it as the tail because there is nothing behind it so its 'prev' variable is set to NULL
    head = newNode;                     // Set the node, that was just made, as the head of the list since the head is pointing to NULL (Empty List)
  }
}

void DLinkList::Search(){
  bool match = false; string last;            // Set 'noMatch' boolean to tell if there was a match && 'last' name string to find the data
  cout << "Enter the Last name to search for: ";
  cin >> last;                                // Ask the user for the last name the program will look for in the list
  Node *cNode = head;                         // Set the 'cNode' pointer variable, of type Node, == to the head of the list... ->
  // So that 'cNode' is used as an alias for 'head' in the DLinkList class and is not tampered with while the program executes
  if ( cNode != NULL){                        // If the header isn't pointing to the end of the list
    while (cNode != NULL){                    // While the header isn't pointing to the end of the list
      if( cNode->getLName() == last){         // If  the content of the nodes 'lastName' variable isnt equal to the User specified 'last' variable
        cout << cNode->getLName() << ", " << cNode->getFName() << endl << cNode->getAddress() << endl << cNode->getNum() << "\n\n"; // Print current node
        match = true;                         // Set match boolean to 'true', indicating that there was data found with the User specified last name variable 'last'
        cNode = cNode->getNext();             // Get the next node and set it as the current node
      } else if (cNode->getLName() != last){  // Else if the content of the nodes 'lastName' variable isnt equal to the User specified 'last' variable
        cNode = cNode->getNext();             // Get the next node and set it as the current node
      }
    }
    if (!match){                              // If !match(match == false / not match / no match) then
      cout << "Didn't find any data matching the name " << last << ".\n\n"; // Print this out
    }
  }
}

void DLinkList::Display(){                   // Print the contents of the list
  Node *cNode = head;                        // Set the 'cNode' pointer variable, of type Node, == to the head of the list... ->
  // So that 'cNode' is used as an alias for 'head' in the DLinkList class and is not tampered with while the program executes
  cout << "\n\nList Contents: \n";
  if ( cNode == NULL ){                      // If the list is empty
    cout << "There's nothing in the list D:\n\n";
  } else if ( cNode->getNext() == NULL ){    // If theres only one node in the list print this out
    cout << "NULL <---  "<< cNode->getLName() << ", " << cNode->getFName() << endl << cNode->getAddress() << endl << cNode->getNum() << "  --->  NULL\n\n";
  } else {
    cout << "NULL <---  \n\n";
    while ( cNode != NULL ){                 // If there are multiple nodes in the list, then we print out its information
      cout << cNode->getLName() << ", " << cNode->getFName() << endl << cNode->getAddress() << endl << cNode->getNum() << "  --->\n\n"; // Print out the current nodes data
      cNode = cNode->getNext();              // Get the next node and set it as the current node
    }
    cout << "--> NULL\n\n" << endl;
  }
}

void DLinkList::ReverseDisplay(){
  Node *cNode = tail;                        // Set the 'cNode' pointer variable, of type Node, == to the head of the list... ->
  // So that 'cNode' is used as an alias for 'head' in the DLinkList class and is not tampered with while the program executes
  cout << "\n\nList Contents: \n";
  if ( cNode == NULL ){                      // If the list is empty print this out
    cout << "There's nothing in the list D:\n\n";
  } else if ( cNode->getPrev() == NULL ) {   // Else if theres only one node in the list, print this out and because we're already at the tail, No need to check if cNode... -->
    cout << "NULL <---  "<< cNode->getLName() << ", " << cNode->getFName() << endl << cNode->getAddress() << endl << cNode->getNum() << "  --->  NULL\n\n"; // is == NULL because the first 'if' already did
  } else {
    cout << "NULL <---  \n\n";
    while ( cNode->getPrev() != NULL || head == cNode ) {  // While there is a node before the current node in the list OR the current node is the head THEN continue the loop
      cout << cNode->getLName() << ", " << cNode->getFName() << endl << cNode->getAddress() << endl << cNode->getNum() << "  --->\n\n"; // Print out the current nodes data
      if (head == cNode) {                   // If the current node is the head
        break;                               // Then break the while loop
      }
      cNode = cNode->getPrev();              // Get the next(prev) node and set it as the current node
    }
    cout << "--> NULL\n\n" << endl;
  }
}
