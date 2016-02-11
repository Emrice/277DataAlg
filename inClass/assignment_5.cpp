//
//  Assignment_5.cpp
//  Assignment #5
//
//  Created by Bernin A. Uben on 2/10/16.
//  Copyright © 2016 Bernin A. Uben. All rights reserved.
//  Write a program which uses a stack to match left and right parentheses.
//  The user can only enter parentheses.
//  Whenever a left parenthesis is found, push it.
//  Whenever a right parenthesis is found, pop the stack and see if the input string value is paired with the popped value.
//  Parentheses may be of the form (), [], OR {}
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

class Node {                        // Node class
  char  elem;                       // Holds the parenthesis
  Node* next;                       // Pointer to the next node
  
public:
  Node(){};                         // Constructor
  Node* getNext() { return next; }; // Accesses the 'next' variable to return the 'next' value
  char  getElem() { return elem; }; // Accesses the 'firstName' variable to return the 'firstName' value
  void  SetNode(char element)   { elem = element; }; // Sets the nodes private variables
  void  SetNextNode(Node* adding){ next = adding; }; // Sets the next node private pointer
};

class Stack{                  // DLinkList class
  Node *head;                 // Sets the start of the node linked list
public:
  Stack() { head = NULL;};    // Sets the head to point to NULL or the end of the list
  bool compare(char[]);       // Tells whether the sequence of the provided parenthesis is valid or invalid
  bool matching(char, char);  // Tells whether parenthesises match
  bool empty();               // Checks of the Stack is empty. Returns 'true' if the 'head' pointer variable points to NULL else returns 'false'
  void push(char);            // Adds the user to input the nodes
  void pop();                 // Takes out the elem/node at the top/front of the stack
};

int main(){
  bool answer = true;           // Initialize 'answer' variable with 'true'
  while (answer){               // While the answer/user is/says true/yes
    Stack List;                 // Initialize a Stack called 'List'
    string again = "y", confirm;// Initialize variable 'again' with "y" to let the while loop run the first time and 'confirm'
    char arr[30];               // Set the max of 30 charachters
    cout << "Enter a parenthesis sequence. '(, ), [, ], {, }' only:";
    cin >> arr;                 // Gets the parenthesis sequence to be checked
    
    if ( List.compare(arr) ) {  // If the sequence returns true, then put out correct else its invalid
      cout << "Correct\n\n";
    } else {
      cout << "Invalid/Incorrect\n\n";
    }
    
    cout << "Another?('y' or 'n'): ";
    cin >> again;               // Gets if user wants to go again
    
    if (again != "y"){          // If the user put anything but yes
      cout << "Are you sure you want to exit?('y' or 'n'): ";
      cin >> confirm;           // We confirm if they want to exit or continue
      if (confirm != "y"){
        again = "y";
      }
    }                           // If the user wants to go through the loop again, set answer to true else false to end the while loop
    answer = (again == "y") ? answer = true : answer = false;
  }
  cout << "Terminating...\n";
  return EXIT_SUCCESS;
}

// Returns true if 'opened'(left) and 'closed'(right) parenthesis are matching, false otherwise
bool Stack::matching(char opened, char closed) {
  if (opened == '(' && closed == ')')
    return true;
  else if (opened == '{' && closed == '}')
    return true;
  else if (opened == '[' && closed == ']')
    return true;
  else
    return false;
}

bool Stack::compare(char arr[]){
  int i = 0;
  
  while (arr[i]) {                                           // While there are still characters
    if (arr[0] == '}' || arr[0] == ')' || arr[0] == ']') {   // If the first parenthesis is 'closed'
      return false;                                          // return false because it automatically has no match
    } else {
      if (arr[i] == '{' || arr[i] == '(' || arr[i] == '[') { // If the arr[i] is a starting parenthesis then
        push(arr[i]);                                        // Push it into the stack (put at the front of the stack)
        Node *cNode = head;
        while(cNode != NULL){                                // While the list hasnt ended
          cout << " " << cNode->getElem() << " <-";          // Print
          cNode = cNode->getNext();                          // Set the current node as the next node in the list
        }
        cout << endl;
      }

      if (arr[i] == '}' || arr[i] == ')' || arr[i] == ']') { // If arr[i] is an ending parenthesis then pop from stack and check if the popped parenthesis is a matching pair
        if ( empty() ) {                                     // If Stack is empty() and the first item is a closing parenthesis, then it's incorrect so return false
          cout << "Nothing is in the Stack. ";
          return false;                                      // Close the function out
        } else if ( matching(head->getElem(), arr[i]) ) {    // If the top/front of Stack is the same as the current closing parenthesis
          pop();                                             // We want to pop() the top/front of Stack so the Stacks top is the parenthesis that was added before it in order
          if(!empty()){                                      // If the stack isnt empty print out in order
            Node *cNode = head;
            while(cNode != NULL){                            // While the list hasnt ended
              cout << " " << cNode->getElem() << " <-";
              cNode = cNode->getNext();
            }
            cout << endl;
          }
        } else {                                             // Else end the function here and just return false because its not possible for it to be true anymore
          return false;
        }
      }
    }
    i++;
  }
  
  cout << "\n\nWhats in the stack? ";
  Node *cNode = head;
  if( empty() ){
    cout << "Nothing...\n";
  } else {
    while(cNode != NULL){
      cout << " " << cNode->getElem() << " <-";
      cNode = cNode->getNext();
    }
    cout << endl;
  }
  
  if ( empty() ) {
    return true;
  } else {
    return false;
  }
}

bool Stack::empty(){             // Is Stack empty?
  bool retVal;                   // return true if Stack is empty else return false
  return retVal = (head == NULL) ? true : false;
}

void Stack::push(char elem){     // Append a node to the Stack
  Node *newNode = new Node();    // Create a new node
                                 // use the derefrencer, '->', instead of the dot operator to use class methods/functions
  cout << "Adding " << elem << " to Stack.\n";
  newNode->SetNode(elem);        // Set the default values as the nodes values
  if ( !empty() ){               // If the head is pointing to the end (If there aren't any nodes in the list)
    newNode->SetNextNode(head);  // Set the newNode 'next' pointer variable to the head of Stack
    head = newNode;              // Set the new 'head' to point to the newNode which is now at the top of Stack
  } else {                       // 'if (cNode == NULL)' the head is pointing to the end of the list and there are no nodes in the list
    head = newNode;              // Set the node, that was just made, as the head of the list since the head is pointing to NULL (Empty List)
    newNode->SetNextNode(NULL);  // Set the nodes 'next' pointer value as 'NULL', the end of the list
  }
}

void Stack::pop(){
  Node *cNode = head;            // Set the 'cNode' pointer variable of type Node equal to the head of the list
  cout << "Removing " << cNode->getElem() << " from Stack.\n";
  head = cNode->getNext();       // Set the 'head' pointer variable to the address of the 2nd node in the stack by getNext() returning mem address value
  delete cNode;                  // Delete the old head out of memory since the head isnt pointing to it and theres no way of getting to it.
}
