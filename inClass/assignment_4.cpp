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
  string firstName, lastName, address, phoneNum; // node elements / variables
  Node*  next;                              // Pointer to the next node
  Node*  prev;                              // Pointer to the prev node
    
public:
  Node(){};  // Constructor
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
  bool answer;
  string again = "y", confirm;
  while (answer){
    cout << "Options:\n1) Search by last name\n2) Show all information(First to last)\n3) Show all information(Last to first)\n\n";
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
    }
    answer = (again == "y") ? true : false; // if the user wants to go through the loop again, set answer to true else false to end the while loop
  }
  cout << "Terminating...\n";
  return EXIT_SUCCESS;
}

void DLinkList::Insert(){                            // Append a node to the linked list
  Node*  newNode = new Node();                       // Create a new node
  Node*  prevNode = NULL;                            // Previous node pointer for node
  string fName, lName, address, phoneNum;            // variables to be used as placeholders for node variable insertion
  cout << "Enter First Name:"; getline(cin, fName);  // Get all the information needed for the new node from the user
  cout << "Enter Last Name:"; getline(cin, lName);
  cout << "Enter Address:"; getline(cin, address);
  cout << "Enter Phone Number:"; getline(cin, phoneNum);
                                                     // use the derefrencer, '->', instead of the dot operator to use class methods/functions
  newNode->SetNode(fName, lName, address, phoneNum); // Set the default values as the nodes values
  newNode->SetPrevNode(NULL);                        // Set the nodes 'prev' pointer value as 'NULL', and will stay like that if at the start of a doubly linked list to mark an end
  newNode->SetNextNode(NULL);                        // Set the nodes 'next' pointer value as 'NULL', the end of the list
  
  Node *temp = head;                    // Create a temp pointer, Set the 'temp' pointer variable of type Node equal to the head of the list... ->
                                        // so that 'temp' is used as an alias for 'head' in the DLinkList class and is not tampered with while the program executes
  if ( temp != NULL ){                  // If the head is pointing to the end (If there are any nodes in the list)
    while ( temp->getNext() != NULL ){  // While the 'next' pointer variable isnt pointing to NULL / end of the list
      prevNode = temp;                  // Set the current node as the old node as preperation for the next line
      temp = temp->getNext();           // Get the next node and set it as the current node
    }
    temp->SetNextNode(newNode);  // As soon as the while loop ends b/c the current 'next' pointer is pointing to NULL/the end of list... ->
                                 // Set the current nodes 'next' pointer to the recently made node
    temp->SetPrevNode(prevNode); // sets the node address in mem before the current node as the pointer 'prev' in the current node
    
    // under here we have to set the newly added node as the tail and set the current node as its previious node so it can go back to the beginning.
    while ( temp->getNext() != NULL ){
      prevNode = temp;        // set the current node as the node before the next node AGAIN
      temp = temp->getNext(); // new node was set after the current node so we go through to the end of the list AGAIN
    }
    if ( temp->getNext() == NULL ){
      temp->SetPrevNode(prevNode); // sets the node address in mem before the current node as the pointer 'prev' in the current node
      tail = temp;                 // Sets the tail of the doubly linked list to make it possible to look through the list in reverse
    }                              // could also be '{ tail = newNode}'
  } else {
      tail = newNode; // after the node has been added to the empty array, its not empty anymore, we set it as the tail becuase thier is nothing behind it so its 'prev' variable is set to NULL
      head = newNode; // 'if (temp == NULL)' if the head is pointing to the end of the list, there are no nodes in the list so... ->
  }                   // Set the node, that was just made, as the head of the list if NULL is the first thing after the head.
}

void DLinkList::Search(){
  string last;                               // Ask the user for the last name the program will look for in the list
  cout << "Enter the Last name to search for: ";
  cin >> last;
  Node *temp = head;                        // Create a temp pointer, Set the 'temp' pointer variable of type Node equal to the head of the list... ->
                                            // so that 'temp' is used as an alias for 'head' in the DLinkList class and is not tampered with while the program executes
  if ( temp != NULL ){                      // If the list isnt empty
    if ( temp->getLName() != last ){        // If the current nodes 'lastName' variable isnt equal to the User specified 'last' variable
      while ( temp->getLName() != last ){   // While the content of the nodes 'lastName' variable doesnt equal the 'last' variable
        if ( temp->getNext() == NULL ){     // If the current nodes 'next' points to NULL / end of list
          cout << "No data matching this name.\n\n";
          break;                            // Print the line above out and break out of this while loop
        }
        temp = temp->getNext();             // Set the next node in the list as the current node which the 'temp' variable represents
      }
      while ( temp != NULL ){               // As long as we didnt reach the end of the list
        if ( temp->getLName() == last ){    // If the content of the nodes 'lastName' variable is the same as the 'last' variable
          cout << temp->getLName() << " " << temp->getFName() << ",\n" << temp->getAddress() << ",\n" << temp->getNum() << "\n\n"; // Print out the current nodes data
          if ( temp->getNext() == NULL ){   // If there arent any nodes after this one
            break;                          // Break out and stop printing data (stops it before error)
          }
          temp = temp->getNext();           // Get the next node and set it as the current node
        }
      }
    } else if ( temp->getLName() == last ){ // Else if the current nodes 'lastName' variable IS equal to the User specified 'last' variable
      while ( temp != NULL ){               // As long as we didnt reach the end of the list
        if ( temp->getLName() == last ){    // If the content of the nodes 'lastName' variable is the same as the 'last' variable
          cout << temp->getLName() << " " << temp->getFName() << ",\n" << temp->getAddress() << ",\n" << temp->getNum() << "\n\n"; // Print out the current nodes data
          if ( temp->getNext() == NULL ){   // If there arent any nodes after this one
            break;                          // Break out and stop printing data (stops it before error)
          }
          temp = temp->getNext();           // Get the next node and set it as the current node
        }
      }
    }
  } else {                                  // If theres nothing in the list then
    cout << "There's nothing in the list D:\n\n";
  }
}

void DLinkList::Display(){                // Print the contents of the list
  Node *temp = head;                      // Create a temp pointer, Set the 'temp' pointer variable of type Node equal to the head of the list... ->
                                          // so that 'temp' is used as an alias for 'head' in the DLinkList class and is not tampered with while the program executes operations
  cout << "\n\nList Contents: \n";
  if ( temp == NULL ){                    // If the list is empty
    cout << "There's nothing in the list D:\n\n";
  } else if ( temp->getNext() == NULL ){  // If theres only one node in the list print this out
    cout << temp->getLName() << ", " << temp->getFName() << endl << temp->getAddress() << endl << temp->getNum() << "  --->  NULL\n\n";
  } else {
    while ( temp != NULL ){               // If there are multiple nodes in the list, then we print out its information
      cout << temp->getLName() << ", " << temp->getFName() << endl << temp->getAddress() << endl << temp->getNum() << "  --->\n\n"; // Print out the current nodes data
      temp = temp->getNext();             // Get the next node and set it as the current node
    }
    cout << "NULL\n\n" << endl;
  }
}

void DLinkList::ReverseDisplay(){
  Node *temp = tail;                      // Create a temp pointer, Set the 'temp' pointer variable of type Node equal to the head of the list... ->
                                          // so that 'temp' is used as an alias for 'tail' in the DLinkList class and is not tampered with while the program executes
  cout << "\n\nList Contents: \n";
  if ( temp == NULL ){                    // If the list is empty print this out
    cout << "There's nothing in the list D:\n\n";
  } else if ( temp->getPrev() == NULL ) { // Else if theres only one node in the list, print this out and because we're already at the tail, No need to check if temp is == NULL because the first 'if' already did
    cout << temp->getLName() << ", " << temp->getFName() << endl << temp->getAddress() << endl << temp->getNum() << "  --->  NULL\n\n";
  } else {
    while ( temp->getPrev() != NULL || head == temp ) {  // While there is a node before the current node in the list OR the current node is the head THEN continue the loop
      cout << temp->getLName() << ", " << temp->getFName() << endl << temp->getAddress() << endl << temp->getNum() << "  --->\n\n"; // Print out the current nodes data
        if (head == temp) {               // If the current node is the head
          break;                          // Then break the while loop
        }
      temp = temp->getPrev();             // Get the next(prev) node and set it as the current node
    }
    cout << "NULL\n\n" << endl;
  }
}
