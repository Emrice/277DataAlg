//
//  main.cpp
//  homework #4
//
//  Created by Bernin A. Uben on 1/29/16.
//  Copyright © 2016 Bernin A. Uben. All rights reserved.
//
//
//  This assignment is an enhancement of the example provided in the textbook for linking airports.  Assume the user provides you with the following 2 items of information for as many different airports as they desire:
//  1.  Standard 3 character airport code
//  2.  Distance from New York City's LaGuardia
//
//  Airport to the specified airport, in miles.
//  The head of the list should be represented with an element whose value is 'LGA' and whose distance is 0.
//  Airport codes will be provided in order of closest to furthest away.
//  Create a singly linked list to house each of the airports as a node in the same order in which it was provided (nearest to furthest).
//  Each node should contain both the airport code and the entered distance.
//  Once the list is built, develop an additional function which allows the user to search for a user-specified code and then output all other codes and distances which follow it in the list.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

class Node {  // Node class
  int miles;
  string code;
  Node* next;
  
public:
  Node(){};
  void SetData(string aCode, int aMiles) { code = aCode; miles = aMiles; };
  void SetNext(Node* aNext) { next = aNext; };
  Node* Next() { return next; };
  
  string getCode() { return code; };
  int getMiles() { return miles; };
};

class List { // List class
  Node *head;
public:
  List() { head = NULL; };
  void Insert();
  void Search();
  void Display();
};

int main() {
  int choice;
  List list;
  
  while (1) {
    cout << "\n---------------------------------\n";
    cout << "|           Options             |\n";
    cout << "---------------------------------\n";
    cout << "1.Insert Airport\n";
    cout << "2.Search for an Airport\n";
    cout << "3.Show all airports\n";
    cout << "4.Exit\n";
    cout << "Enter your choice : ";
    cin >> choice;
    
    switch(choice){
      case 1:
        cout << "Inserting Airport\n";
        list.Insert();
        cout << endl;
        break;
      case 2:
        cout << "Search for an Airport\n";
        list.Search();
        cout << endl;
        break;
      case 3:
        cout << "Show all airports\n";
        list.Display();
        cout << endl;
        break;
      case 4:
        cout << "Terminating\n";
        exit(1);
        break;
      default:
        cout << "Not Valid\n";
    }
  }
  return 0;
}

// Initialize LGA w/ 0


// Append a node to the linked list
void List::Insert() {

  Node* newNode = new Node(); // Create a new node
  
  int dist;
  string value;
  
  cout << "Enter the 3 character airport code to be added: ";
  cin >> value;
  cout << "Enter the distance, in miles, from La Guardia Airport: ";
  cin >> dist;
  newNode->SetData(value, dist);
  newNode->SetNext(NULL);
  
  Node *tmp = head; // Create a temp pointer
  
  if ( tmp != NULL ) {
    while ( tmp->Next() != NULL ) { // Nodes already present in the list //  Parse to end of list
      tmp = tmp->Next();
    }
    tmp->SetNext(newNode); // Point the last node to the new node
  }
  else {
    head = newNode; // First node in the list
  }
}

void List::Search(){
  string value;
  bool found = false;
  
  Node *tmp = head; // Temp pointer
  
  if ( tmp == NULL ) {  // If no nodes then empty
    cout << "EMPTY" << endl;
    return;
  }

  cout << "\nEnter the value to be searched: ";
  cin >> value;
  while (found == false){
    if (value == tmp->getCode()){
      found = true;
    } else {
      tmp = tmp->Next();
    } 
    if(tmp == NULL){
      cout << "No Airport Found...";
      break;
    }
  }

  if(found){
    while (tmp != NULL) {
      cout << "\nCode:" << tmp->getCode() << ": " << tmp->getMiles() << " Miles ---> ";
      tmp = tmp->Next();
    }
  }
}

void List::Display() { // Print the contents of the list

  Node *tmp = head; // Temp pointer

  if ( tmp == NULL ) {  // No nodes
    cout << "EMPTY" << endl;
    return;
  }

  if ( tmp->Next() == NULL ) {  // One node in the list
    cout << "Code: " << tmp->getCode() << " - " << tmp->getMiles() << " Miles ---> \n";
    cout << "NULL" << endl;
  }
  else {
    do {  // Parse and print the list
      cout << "\nCode: " << tmp->getCode() << " - " << tmp->getMiles() << " Miles ---> ";
      tmp = tmp->Next();
    }
    while ( tmp != NULL );
    
    cout << "NULL" << endl;
  }
}

// Some Test Data: 1 LGA 0 1 JFK 5 1 TBR 21 1 NWK 28