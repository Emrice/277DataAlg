//
//  Assignment_5.cpp
//  Assignment #5
//
//  Created by Bernin A. Uben on 2/9/16.
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
  string element;
  Node*  next;                              // Pointer to the next node
  Node*  prev;                              // Pointer to the prev node
  
public:
  Node(){};                                 // Constructor
  string getFName()  { return element; };   // accesses the 'firstName' variable to return the 'firstName' value
  Node*  getNext()   { return next; };      // accesses the 'next' variable to return the 'next' value
  Node*  getPrev()   { return prev; };      // accesses the 'prev' variable to return the 'prev' value
  void   SetNextNode(Node* aNext) { next = aNext; };   // Sets the next node private pointer
  void   SetPrevNode(Node* aPrev) { prev = aPrev; };   // Sets the prev node private pointer
  void   SetNode( string elem )   { element = elem; }; // Sets the nodes private variables
};

class Stack{                  // DLinkList class
  Node *head;                 // sets the start of the node linked list
public:
  Stack() { head = NULL;};    // sets the head to point to NULL or the end of the list
  void push();                // Adds the user to input the nodes
  void pop();
  void top();
  bool is_empty();
};

int main(){
  Stack List;                 // Initialize a Stack called 'List'
  bool answer = true;         // Initialize 'answer' variable with 'true';
  string again = "y", confirm;// Initialize variable 'again' with "y" to let the while loop run the first time and 'confirm'
  
  while (answer){
    cout << "OPTIONS:\n1) Push\n2) Pop\n3) Top\n4) Check if the Stack is empty\n\n";
    int choice; cin >> choice;
    switch (choice) {
      case 1:
        List.push();
        break;
      case 2:
        List.pop();
        break;
      case 3:
        List.top();
        break;
      case 4:
        List.is_empty();
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

bool Stack::is_empty(){
  bool retVal;
  retVal = (head == NULL) ? true : false;
  return retVal;
}

void Stack::push(){                     // Append a node to the Stack
  Node   *newNode = new Node();         // Create a new node
  
  string elem;                     // Initializes and Gets the data for the elem variable
  cout << "Enter te value:";
  getline(cin, elem);
  
  // use the derefrencer, '->', instead of the dot operator to use class methods/functions
  newNode->SetNode(elem); // Set the default values as the nodes values
  newNode->SetNextNode(NULL);                               // Set the nodes 'next' pointer value as 'NULL', the end of the list
  Node *cNode = head;                   // Set the 'cNode' pointer variable of type Node equal to the head of the list... ->
  // So that 'cNode' is used as an alias for 'head' in the DLinkList class and is not tampered with while the program executes
  
  if ( cNode != NULL ){                 // If the head is pointing to the end (If there aren't any nodes in the list)
    head = newNode;                     // Set the new 'head' to point to the newNode which is now at the top of Stack
    newNode->SetNextNode(cNode);        // Set the new nodes 'next' pointer variable to the head of Stack.
    newNode->SetPrevNode(cNode);        // Set the newNode nodes 'prev' pointer to the old last node()
    tail = newNode;                     // Set the newNode as the new tail
  } else {                              // 'if (cNode == NULL)' the head is pointing to the end of the list and there are no nodes in the list
    tail = newNode;                     // after the node has been added to the empty array, its not empty anymore, we set it as the tail because there is nothing behind it so its 'prev' variable is set to NULL
    head = newNode;                     // Set the node, that was just made, as the head of the list since the head is pointing to NULL (Empty List)
  }
}
