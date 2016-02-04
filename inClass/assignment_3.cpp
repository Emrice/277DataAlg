//
//  Assignment_3.cpp
//  Assignment #3
//
//  Created by Bernin A. Uben on 2/3/16.
//  Copyright © 2016 Bernin A. Uben. All rights reserved.
//
//  Create a singly linked list which contains 3 nodes.
//  The user is requested to provide a single value which will become the "elem" value for the node.
//  Then repeat the process 2 more times.
//  If you want to do something extra, read thru the list and print each node.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

class Node {     // Node class
    string text; // node content
    Node*  next; // Pointer to the next node
    
public:
    Node(){};  // Constructor
    string getText()  { return text; }; // accesses the Text variable to return the Text value
    Node*  getNext()  { return next; }; // accesses the next variable to return the next value
    void   SetNextNode(Node* aNext)  { next = aNext; }; // Sets the next node private pointer
    void   SetNodeText(string aText) { text = aText; }; // sets the Text private variable
};

class SLinkList { // SLinkList class
    Node *head;  // sets the start of the node linked list
public:
    SLinkList() { head = NULL; }; // sets the head to point to NULL or the end of the list
    void Insert();  // lests the user to input the nodes
    void Display(); // Shows all the nodes in the linked list with its code and mile values
};

int main() {
    SLinkList List; // Initialize a list called 'List'
    cout << "Please enter three lines of text\n";
    for (int x = 0; x < 3; x++) {
        cout << x+1 << ". ";
        List.Insert();
    }
    
    List.Display();
    
    cout << "Terminating...\n";
    return EXIT_SUCCESS;
}

void SLinkList::Insert() {  // Append a node to the linked list
    Node* newNode = new Node(); // Create a new node
    string value;
    cout << "Enter text: "; getline(cin, value);
    
    // use the derefrencer, '->', instead of the dot operator to use class methods/functions
    newNode->SetNodeText(value); // Set the default values as the nodes values
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

void SLinkList::Display() { // Print the contents of the list
    Node *temp = head; // Create a temp pointer, Set the 'temp' pointer variable of type Node equal to the head of the list... ->
    // so that 'temp' is used as an alias for 'head' in the SLinkedList class
    
    cout << "\n\nList Contents: \n";
    if ( temp->getNext() == NULL ) {  // If theres only one node in the list print this out
        cout << temp->getText() << "  --->  NULL\n";
    } else {
        while ( temp != NULL ) {  // If there are multiple nodes in the list, then we print out its information
            cout << temp->getText() << "  --->  "; // print current node
            temp = temp->getNext(); // get the next node
        }
        cout << "NULL\n\n" << endl;
    }
}
