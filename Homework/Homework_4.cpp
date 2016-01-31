//
//  Homework_4.cpp
//  homework #4
//
//  Created by Bernin A. Uben on 1/29/16.
//  Copyright © 2016 Bernin A. Uben. All rights reserved.
//
//  This assignment is an enhancement of the example provided in the textbook for linking airports.  Assume the user provides you with the following 2 items of information for as many different airports as they desire:
//  1.  Standard 3 character airport code ///   2.  Distance from New York City's LaGuardia
//  Airport to the specified airport, in miles.
//  The head of the list should be represented with an element whose value is 'LGA' and whose distance is 0.
//  Airport codes will be provided in order of closest to furthest away.
//  Create a singly linked list to house each of the airports as a node in the same order in which it was provided (nearest to furthest).
//  Each node should contain both the airport code and the entered distance.
//  Once the list is built, develop an additional function which allows the user to search for a user-specified code and then output all other codes and distances which follow it in the list.
//
//  Test Data: 1 JFK 5 1 TBR 21 1 NWK 28 1 AWK 32 2 JFK 2 TBR 2 NWK 2 AWK 2 lol 2 random 3 4

#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

class Node {   // Node class
  int    miles;// number of miles from La Guardia Airport
  string code; // Code for the airport
  Node*  next; // Pointer to the next airport 
  
public:
  Node(){};  // Constructor
  int    getMiles() { return miles;};   // accesses the mile variable to return the miles value 
  string getCode()  { return code; };   // accesses the code variable to return the codes value
  Node*  getNext()  { return next; };   // accesses the next variable to return the nexts value
  void   SetNextNode(Node* aNext) { next = aNext; };  // Sets the next node private pointer
  void   SetNodeData(string aCode, int aMiles) { code = aCode; miles = aMiles; };  // sets the code and the miles private variables
};

class SLinkList { // SLinkList class
  Node *head;  // sets the start of the node linked list
public:
  SLinkList() { head = NULL; }; // sets the head to point to NULL or the end of the list
  void Insert(string, int);     // sets the default LGA and 0 for code and miles respectivley in a node
  void Insert();  // lests the user to input the nodes
  void Search();  // lets the user search through the list until it finds the node is looking for and prints out all nodes after it in the list as well
  void Display(); // Shows all the nodes in the linked list with its code and mile values
};

int main() {
  int choice;
  SLinkList List; // Initialize a list called 'List'
  List.Insert("LGA", 0); // Set the default variable as 'LGA' & '0' as the first node
  
  while (1) {
    cout << "\n-------------------------\n";
    cout << "|       Options         |\n";
    cout << "-------------------------\n";
    cout << "1.Insert Airport\n";
    cout << "2.Search for an Airport\n";
    cout << "3.Show all airports\n";
    cout << "4.Exit\n";
    cout << "Enter your choice : ";
    cin >> choice;
    
    switch(choice){
      case 1:
        cout << "Inserting Airport\n";
        List.Insert();
        cout << endl;
        break;
      case 2:
        cout << "Search for an Airport\n";
        List.Search();
        cout << endl;
        break;
      case 3:
        cout << "\n\nShowing all airports:\n";
        List.Display();
        cout << endl;
        break;
      case 4:
        cout << "Terminating....\n";
        exit(EXIT_SUCCESS);
        break;
      default:
        cout << "Not Valid\n\n";
        break;
    }
  }
  return EXIT_SUCCESS;
}

void SLinkList::Insert(string value = "LGA", int dist = 0) { // Initialize LGA w/ 0
  Node* newNode = new Node(); // Create a new node (the node is still a class)

  // use the derefrencer, '->', instead of the dot operator to use class methods/functions
  newNode->SetNodeData(value, dist); // Set the default values as the nodes values
  newNode->SetNextNode(NULL); // Set the nodes next value as 'NULL', the end of the list
  
  Node *temp = head; // Create a temp pointer, Set the 'temp' pointer variable of type Node equal to the head of the list... ->
                     // so that 'temp' is used as an alias for 'head' in the SLinkedList class
  
  if ( temp != NULL ) { // If the head is pointing to the end (If there are any nodes in the list)
    while ( temp->getNext() != NULL ) { // While the 'next' pointer variable isnt pointing to NULL / end of the list
      temp = temp->getNext(); //  Get the next node and set it as the current node
    }
    temp->SetNextNode(newNode); // As soon as the while loop ends b/c the current 'next' pointer is pointing to NULL/the end of list... ->
  }                             // Set the current nodes 'next' pointer to the recently made node
  else {
    head = newNode; // 'if (temp == NULL)' if the head is pointing to the end of the list, there are no nodes in the list so... ->
  }                 // Set the node, that was just made, as the head of the list if NULL is the first thing after the head.
}

void SLinkList::Insert() {  // Append a node to the linked list
  Node* newNode = new Node(); // Create a new node
  int dist;
  string value;

  cout << "Enter the 3 character airport code to be added: "; cin >> value;
  if (3 < value.length()) {
    while (3 < value.length()){
      cout << "Wrong value number. Please only 3 characters for the airport code.\n";
      cout << "Enter the 3 character airport code to be added: ";
      cin >> value;
      if (3 >= value.length()){
        break;
      }
    }
  }
  cout << "Enter the distance, in miles, from La Guardia Airport: "; cin >> dist;

  // use the derefrencer, '->', instead of the dot operator to use class methods/functions
  newNode->SetNodeData(value, dist); // Set the default values as the nodes values
  newNode->SetNextNode(NULL); // Set the nodes next value as 'NULL', the end of the list
  
  Node *temp = head; // Create a temp pointer, Set the 'temp' pointer variable of type Node equal to the head of the list... ->
                     // so that 'temp' is used as an alias for 'head' in the SLinkedList class
  
  if ( temp != NULL ) { // If the head is pointing to the end (If there are any nodes in the list)
    while ( temp->getNext() != NULL ) { // While the 'next' pointer variable isnt pointing to NULL / end of the list
      temp = temp->getNext(); //  Get the next node and set it as the current node
    }
    temp->SetNextNode(newNode); // As soon as the while loop ends b/c the current 'next' pointer is pointing to NULL/the end of list... ->
  } else {                      // Set the current nodes 'next' pointer to the recently made node
    head = newNode; // 'if (temp == NULL)' if the head is pointing to the end of the list, there are no nodes in the list so... ->
  }                 // Set the node, that was just made, as the head of the list if NULL is the first thing after the head.
}

void SLinkList::Search(){ // Search for a node in the linked list
  string value;
  bool found = false; // to be used later as a way to tell if the value has been found(true) or not(false)
  Node *temp = head;  // Create a temp pointer, Set the 'temp' pointer variable of type Node equal to the head of the list... ->
                      // so that 'temp' is used as an alias for 'head' in the SLinkedList class
  
  if(temp == NULL){ // If the head alias variable, 'temp', is equal to NULL, then there are no nodes in the linked list
    cout << "\nNo Airports in the list.\n";
    return; // ends the function/method since there are no nodes in the list
  }

  cout << "\nEnter the value to be searched: ";
  cin >> value;
  while (found == false){ // As long as the node hasnt been found
    if (value == temp->getCode()){ // if the value is == getCode()
      found = true; // Then the 'found' variable is set to true
    } else if (temp->getNext() == NULL) { // Else if the nodes 'next' pointer == NULL or the end of the list, print the message and break out of the loop
      cout << "\nThe airport code '" << value << "' was not found...\n\n";
      break; 
    } else {
      temp = temp->getNext();  // Get the next node and set it as the current node
    }
  }
  
  if(found){ // if the variable has been found (found == true)
    while (temp != NULL) { // as long as 'temp' doesnt equal to NULL
      cout << "\nCode: " << temp->getCode() << " - " << temp->getMiles() << " Miles ---> "; // print this with the airport code and the miles
      temp = temp->getNext(); // set the current node to the next node (get the next node in the list)
    }
    cout << "NULL\n";
  }
}

void SLinkList::Display() { // Print the contents of the list
  Node *temp = head; // Create a temp pointer, Set the 'temp' pointer variable of type Node equal to the head of the list... ->
                     // so that 'temp' is used as an alias for 'head' in the SLinkedList class
  if ( temp == NULL ) {  // If the list is empty then end the function/method
    cout << "No Airports Found. \n";
    return;
  }
  
  if ( temp->getNext() == NULL ) {  // If theres only one node in the list print this out
    cout << "Code: " << temp->getCode() << " - " << temp->getMiles() << " Miles ---> NULL\n";
  } else {
    while ( temp != NULL ) {  // If there are multiple nodes in the list, then we print out its information
      cout << "\nCode: " << temp->getCode() << " - " << temp->getMiles() << " Miles ---> "; // print current node
      temp = temp->getNext(); // get the next node
    }
    cout << "NULL" << endl;
  }
}
