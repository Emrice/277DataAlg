//
//  Homework_6.cpp
//  homework #6
//
//  Created by Bernin A. Uben on 3/20/16.
//  Copyright © 2016 Bernin A. Uben. All rights reserved.
//
//  Using a singly linked list, support the ability to add the following information about an airport:
//  airport code, distance from the last entered airport code to the current one.
//  Provide a sentinel header which represents LGA, with a distance of zero.
//  Allow the user to provide 3 types of input:
//  1.  Enter new airport information
//  2.  Specify an existing airport code and calculate the distance from LGA to the selected airport using recursion.
//  3.  Specify an existing airport code and calculate the distance from LGA to the selected airport by looping thru the nodes in standard fashion.
//
//  Test Data: 1 JFK 5 1 TBA 26 1 NWK 30

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
  Node* head;                           // sets the start of the node linked list
public:
  SLinkList() { head = NULL; };         // Sets the head to point to NULL or the end of the list
  Node* getHead(){ return head; }       // Returns the head pointer
  void  Insert(string, int);            // Sets the default LGA and 0 for code and miles respectivley in a node
  void  Insert();                       // Lets the user to input the nodes
  void  Display();                      // Shows all the nodes in the linked list with its code and mile values
  void  standardSearch();               // Lets the user search through the list until it finds the node is looking for and prints out all nodes after it in the list as well -- LOOP
  int   recursiveSearch(Node*, string); // Lets the user search through the list until it finds the node is looking for and prints out all nodes after it in the list as well -- RECURSIVE
};

int main() {
  int choice;
  string airport;
  SLinkList List;         // Initialize a list called 'List'
  List.Insert("LGA", 0);  // Set the default variable as 'LGA' & '0' as the first node
  
  while(true){
    cout << "CHOICES:\n";
    cout << "1. Add an Airport\n";
    cout << "2. Find an Airport - Recursively\n";
    cout << "3. Find an Airport - Standard Looping\n";
    cout << "4. Show all Airports\n";
    cout << "5. Exit Program\n";
    cout << "Enter your choice: ";
    cin >> choice; cout << "\n\n";
    
    switch(choice){
      case 1:  cout << "Inserting Airport\n";
               List.Insert();            break;
      case 2:  cout << "Finding Airport\n";
               cout << "Enter the 3 character code to be searched: "; cin >> airport;
               cout << List.recursiveSearch(List.getHead(), airport) << " miles away from La Guardia Airport\n\n";
               break;
      case 3:  cout << "Finding Airport\n";
               List.standardSearch();   break;
      case 4:  cout << "Showing Airports\n";
               List.Display();           break;
      case 5:  cout << "Terminating......\n";
               exit(EXIT_SUCCESS);       break;
      default: cout << "Not Valid\n\n";break;
    }
  }
  return EXIT_SUCCESS;
}


void SLinkList::Insert(string code = "LGA", int dist = 0) { // Initialize LGA w/ 0
  Node* newNode = new Node();
  newNode->SetNodeData(code, dist);       // Set the default codes as the nodes codes
  newNode->SetNextNode(NULL);             // Set the nodes next code as 'NULL', the end of the list
  
  Node* cNode = head;                     // Create a cNode pointer, Set the 'cNode' pointer variable of type Node equal to the head of the list
  if ( cNode != NULL ) {                  // If the head is pointing to the end (If there are any nodes in the list)
    while ( cNode->getNext() != NULL ) {  // While the 'next' pointer variable isnt pointing to NULL / end of the list
      cNode = cNode->getNext();           // Get the next node and set it as the current node
    }
    cNode->SetNextNode(newNode);          // As soon as the while loop ends b/c the current 'next' pointer is pointing to NULL/the end of list... ->
  }                                       // Set the current nodes 'next' pointer to the recently made node
  else {
    head = newNode;
  }
}


void SLinkList::Insert() {                // Append a node to the linked list
  int dist;
  string code;
  
  cout << "Enter the 3 character airport code to be added: "; cin >> code;
  while (3 < code.length()){
    cout << "Wrong code number. Please only 3 characters for the airport code.\n";
    cout << "Enter the 3 character airport code to be added: ";
    cin >> code;
    if (3 >= code.length()){
      break;
    }
  }
  
  int tMiles = 0;
  Node* temp = head, *pNode = NULL;
  while ( temp != NULL ) { // While the 'next' pointer variable isnt pointing to NULL / end of the list
    tMiles = tMiles + temp->getMiles();
    pNode = temp;
    temp = temp->getNext(); //  Get the next node and set it as the current node
  }

  cout << "Enter the distance, in miles, from ";
  if (pNode->getCode() != "LGA"){
    cout << "the last airport: " << pNode->getCode() << " (" << tMiles << " Miles Away From La Guardia)\n-> ";
  } else {
    cout << "La Guardia Airport.\n-> ";
  }
  
  cin >> dist;
  
  Node* newNode = new Node(); // Create a new node
  newNode->SetNodeData(code, dist); // Set the default codes as the nodes codes
  newNode->SetNextNode(NULL); // Set the nodes next code as 'NULL', the end of the list
  
  Node* cNode = head;
  if ( cNode != NULL ) { // If the head is pointing to the end (If there are any nodes in the list)
    while ( cNode->getNext() != NULL ) { // While the 'next' pointer variable isnt pointing to NULL / end of the list
      cNode = cNode->getNext(); //  Get the next node and set it as the current node
    }
    cNode->SetNextNode(newNode); // As soon as the while loop ends b/c the current 'next' pointer is pointing to NULL/the end of list... ->
  } else {                      // Set the current nodes 'next' pointer to the recently made node
    head = newNode;
  } cout << "\n\n"; //  Adds Spacing to the prompt
}


void SLinkList::standardSearch(){ // Search for a node in the linked list
  string cVal;
  int tMiles = 0;
  bool found = false; // to be used later as a way to tell if the code has been found(true) or not(false)
  Node* cNode = head; // Create a cNode pointer, Set the 'cNode' pointer variable of type Node equal to the head of the list... ->
  
  if(cNode == NULL){ // If the head alias variable, 'cNode', is equal to NULL, then there are no nodes in the linked list
    cout << "\nNo Airports in the list.\n"; return; // "return;" ends the function/method since there are no nodes in the list
  }
  
  cout << "Enter the 3 character code to be searched: ";
  cin >> cVal;
  
  while (found == false && cNode != NULL){ // As long as the node hasnt been found
    if (cVal == cNode->getCode()){ // if the code is == getCode()
      found = true; // Then the 'found' variable is set to true
      tMiles += cNode->getMiles();
    } else if (cNode == NULL) {  // Else if the nodes 'next' pointer == NULL or the end of the list, print the message and break out of the loop
      cout << "\nThe airport code '" << cVal << "' was not found...\n\n";
      break;
    } else {
      tMiles += cNode->getMiles();
      cNode = cNode->getNext();  // Get the next node and set it as the current node
    }
  }
  
  if (found) { // as long as found == true
    cout << "Code " << cNode->getCode() << ": " << tMiles << " miles away from La Guardia Airport\n\n\n"; // print this with the airport code and the miles
  } else {
    cout << "There arent any airports with the code " << cVal << "\n\n\n";
  }
}


int SLinkList::recursiveSearch(Node* cNode,string code){ // Search for a node in the linked list
  int mTotal = 0;
  if (cNode->getCode() != code && cNode->getNext() != NULL){
    return mTotal = mTotal + (cNode->getMiles() + recursiveSearch(cNode->getNext(), code));
  } else if (cNode->getCode() == code){
    cout <<  "Code " << code << ": ";
    return mTotal += cNode->getMiles();
  } else {
    cout << "There arent any Airports with the code " << code << "\n"; return mTotal;
  }
}


void SLinkList::Display() { // Print the contents of the list
  Node* cNode = head;
  if ( cNode == NULL ) {  // If the list is empty then end the function/method
    cout << "No Airports Found. \n";
    return;
  }
  if ( cNode->getNext() == NULL ) {  // If theres only one node in the list print this out
    cout << "Code LGA: 0 Miles\n\n";
  } else {
    while ( cNode != NULL ) {  // If there are multiple nodes in the list, then we print out its information
      cout << "\nCode " << cNode->getCode() << ": " << cNode->getMiles() << " Miles --->"; // print current node
      cNode = cNode->getNext(); // get the next node
    }
    cout << "\nNULL\n\n";
  }
}

