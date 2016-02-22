//
//  Homework_5.cpp
//  homework #5
//
//  Created by Bernin A. Uben on 2/11/16.
//  Copyright © 2016 Bernin A. Uben. All rights reserved.
//
//  Write a program which will take a calculation using a set of numbers and the operands +, -, *, /
//  It will determine the result.  Use the algorithm demonstrated in class to implement the solution
//  Do it using a singly linked list to emulate the stack ADT.  You can exclude parentheses.
//  TestData, Should return 6 as answer: 1+2+3+4+5+6 returns 21,  1+2/3+1*2-3 returns 10,  10+20/30+10*20-30 returns 190,  1+2+3+4+5+6+7+8+9+10-20 returns 35

#include <iostream>
#include <string>
using namespace std;

class Node {   // Node Class
  char  elem;  // Node element
  Node* next;  // Node element
  
public:
  Node(){};                                        // Constructor
  Node* getNext(){ return next; };                 // Returns the 'next' variable
  void  setNext(Node* aNode) { next = aNode; };    // Sets the 'next' variable
  char  getElem(){ return elem; };                 // Returns the 'elem' Variable
  void  setElem(char element ){ elem = element; }; // Sets the 'elem' variable
};

class Stack {   // Stack Class
  Node *head;   // Variable points to head node
  
public:
  Stack(){ head = NULL; };                                  // Initialize head as NULL
  bool   empty(){ return (head == NULL) ? true : false; }   // Return true if Stack is empty else return false
  void   push(char);                                        // Adds a valid value as the current nodes element
  void   pop();                                             // Deletes the current node and sets the next as the head
  double Solve();                                           // Bulk logic for picking correct numbers from the stack
  double ctod(char);                                        // Changes the char value into a double value
  double Operations(double, double, int);                   // Takes the correct numbers and adds/multiplies/subtracts/divides them
};

const int LIMIT = 100; // Set the limit of characters allowed in the array to be 99

int main(){
  bool again = true;
  while(again){
    char exp[LIMIT+1];
    for(int i = 0; i < LIMIT; i++){ exp[i] = 'n'; }        // Initialize each char in the array as 'n'
    cout << "Enter the operation you want solved: ";
    cin >> exp; cout << "Loading the operation " << exp << "..." << endl;
    
    Stack stack;
    for(int i = LIMIT; i >= 0; i--){ stack.push(exp[i]); } // Adding sequence in reverse order (int i = LIMIT; i >= 0; i--) for stack to take in correct order
    cout << " as the Head\n\n";
    
    cout << "Calculating...\n";
    double total = stack.Solve(); cout << "Total: " << total << "\n\nNO CAPITAL LETTERS IN ANSWER\n";
    
    string repeat = "n"; cout << "Do you want to do another?(yes or no):"; cin >> repeat;
    again = (repeat.at(0) != 'y') ? false : true;          // If the user answer doesnt start with a 'y' then the 'again' variable will be set to 'false' and the while loop would end
  }
  
  cout << "Exiting...\n";
  return EXIT_SUCCESS;
}

void Stack::pop(){
  Node *cNode = head;                 // Set the 'cNode' pointer variable of type Node equal to the head of the list
  //cout << "Removing " << cNode->getElem() << " from Stack.\n";
  head = cNode->getNext();            // Set the 'head' pointer variable to the address of the 2nd node in the stack by getNext() returning mem address value
  delete cNode;                       // Delete the old head out of memory since the head isnt pointing to it and theres no way of getting to it.
}

double Stack::ctod(char cNum){
  string sNum(1,cNum);                // Changes the char element in the current node to type string and stores in wNum
  return stod(sNum);                  // Changes wNum, which got its value from the prevous line, into type double and adds it to the total
}

void Stack::push(char exp){           // If the current character in the exp char type array isnt equal to an integer or an operational value then continue else dont put it into the stack
  if( (exp == '0' || exp == '1' || exp == '2' || exp == '3' || exp == '4' || exp == '5' || exp == '6' || exp == '7' || exp == '8' || exp == '9' ) ||
     (exp == '+' || exp == '-' || exp == '*' || exp == 'x' || exp == '/') ){
    if ( !empty() ) {                 // If the stack is empty, add the element as the head
      Node *newNode = new Node;       // Create a new node
      newNode->setElem(exp);          // Set the elem variable in the current node
      newNode->setNext(head);         // Set the current nodes next as the head / front of Stack
      head = newNode;                 // Set the current node as the head of Stack
      cout << "\nAdded " << newNode->getElem();
    } else {
      Node *newNode = new Node;       // Create a new node
      head = newNode;                 // Set the current node as the head
      newNode->setElem(exp);          // Set the elem variable in the current node
      newNode->setNext(NULL);         // Sets the next as 'Null' since its still the head
      cout << "Added " << newNode->getElem() << " as the end of the stack";
    }
  }
}

double Stack::Solve(){
  int opVal = 0;
  Node* cNode = head;
  double total = 0, elemVal = 0;
  bool initChecker = false, opChecker = false, elemChecker = false;
  
  for(int count = 0; count < LIMIT; count++){
    if( initChecker == false){                    // If initChecker == false && total == 0
      total += ctod(cNode->getElem());            // Calls ctod(), which changes a character to type double and returns the value, and adds it to total
      cNode = cNode->getNext(); pop();            // Get the next node and set it as the current node
      
      while (cNode->getElem() != '+' && cNode->getElem() != '-' && cNode->getElem() != '*' && cNode->getElem() != 'x' && cNode->getElem() != '/') {
        if (total != 0) { total *= 10; }          // If the total value is '0' then theres no point in multiplying it by 10 b/c it still yields 0
        total += ctod(cNode->getElem());          // Calls ctod(), which changes a character to type double and returns the value, and adds it to total
        cNode = cNode->getNext(); pop();          // Get the next node and set it as the current node
      }
      initChecker = true;                         // Set initChecker to true to tell program that the first number has been loaded in as the total
      
      // Else if the current element value in the stack is an operation value && opChecker == false
    } else if((cNode->getElem() == '+' || cNode->getElem() == '-' || cNode->getElem() == '*' || cNode->getElem() == 'x' || cNode->getElem() == '/') && opChecker == false){
      char nElem = cNode->getElem();
      if      (nElem == '+') { opVal = 1; }       // Sets the opVal value to the corresponding value depending on the type of element
      else if (nElem == '-') { opVal = 2; }       // Sets the opVal value to the corresponding value depending on the type of element
      else if (nElem == '*') { opVal = 3; }       // Sets the opVal value to the corresponding value depending on the type of element
      else if (nElem == 'x') { opVal = 3; }       // Sets the opVal value to the corresponding value depending on the type of element
      else if (nElem == '/') { opVal = 4; }       // Sets the opVal value to the corresponding value depending on the type of element
      cout << total << " " << nElem << " ";       // Part of the lines that lets user know generally whats happening with the program
      cNode = cNode->getNext(); pop();            // Get the next node and set it as the current node
      opChecker = true;                           // Set opChecker to true
      
      // Else if - the current element value in the stack is a number && elemChecker == false
    } else if ( (cNode->getElem() == '0' || cNode->getElem() == '1' || cNode->getElem() == '2' || cNode->getElem() == '3' || cNode->getElem() == '4' ||
                 cNode->getElem() == '5' || cNode->getElem() == '6' || cNode->getElem() == '7' || cNode->getElem() == '8' || cNode->getElem() == '9' ) && elemChecker == false ){
      elemVal += ctod(cNode->getElem());          // Calls ctod(), which changes a character to type double and returns the value, and adds it to elemVal
      cNode = cNode->getNext(); pop();            // Get the next node and set it as the current node
      
      while ( cNode != NULL && cNode->getElem() != '+' && cNode->getElem() != '-' && cNode->getElem() != '*' && cNode->getElem() != 'x' && cNode->getElem() != '/' ) {
        if (elemVal != 0){ elemVal *= 10; }       // If the elemValue value is '0' then theres no point in multiplying it by 10 b/c it still yields 0
        elemVal += ctod(cNode->getElem());        // Calls ctod(), which changes a character to type double and returns the value, and adds it to elemVal
        cNode = cNode->getNext(); pop();          // Get the next node and set it as the current node
      }
      cout << elemVal; elemChecker = true;        // Output the elemVal vlaues and set elemChecker value to 'true'
    }
    
    if (opChecker == true && elemChecker == true) {                               // If elemChecker && opChecker variables are 'true' then
      total = Operations(total, elemVal, opVal); cout << " = " << total << endl;  // Call the Operations function and set the return value as the new 'total' value
      opChecker = false; elemChecker = false; opVal = 0; elemVal = 0;             // Reset the values opChacker, elemChecker, opVal, & elemVal
    }
    if (cNode == NULL) { break; }                                                 // If there's nothing left in the stack, then end this function here
  }
  return total;
}

double Stack::Operations(double total, double value, int opVal){
  switch(opVal) {
    case 1: return total + value; break;          // Adds both values and returns the result
    case 2: return total - value; break;          // Subtracts both values and returns the result
    case 3: return total * value; break;          // Multiplys both values and returns the result
    case 4: return total / value; break;          // Divides both values and returns the result
    default: cout << "Something went wrong here.\n\n"; return total; break;       // If there was a problem, then it returns the original total value
  }
}
