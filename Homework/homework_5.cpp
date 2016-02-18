//
//  Homework_5.cpp
//  homework #5
//
//  Created by Bernin A. Uben on 2/11/16.
//  Copyright © 2016 Bernin A. Uben. All rights reserved.
//  Write a program which will take a calculation using a set of numbers, the operands +, -, *, / and standard parentheses and will
//  determine the result.  Use the algorithm demonstrated in class to implement the solution, but do it using a singly linked list to emulate the stack ADT.
//  TestData, Should return 6 as answer: 1+2+3+4+5+6 returns 21,  1+2/3+1*2-3 returns 1

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

const int LIMIT = 50;

class Node {
  char elem;
  Node* next;
  
public:
  Node(){};
  Node* getNext(){ return next; };
  void setNext(Node* aNode) { next = aNode; };
  
  char getElem(){ return elem; };
  void setElem(char element ){ elem = element; };
};

class Stack {
  Node *head;
  
public:
  Stack(){ head = NULL; };
  bool empty();
  void setElement(char);
  double Solve();
  double Operations(double, double, int);
};

int main(){
  char exp[LIMIT+1];
  
  for(int i = 0; i < LIMIT; i++){
    exp[i] = 'n';
  }
  
  cout << "Enter the expression you want solved: ";
  cin >> exp;
  cout << "Loading the expression " << exp << "..." << endl;
  
  Stack stack;
  
  for(int i = LIMIT; i >= 0; i--){ // adding sequence in reverse order (int i = LIMIT; i >= 0; i--)
    stack.setElement(exp[i]);
  }
  
  cout << "\nExpression total: " << stack.Solve() << endl;
  
  return EXIT_SUCCESS;
}

void Stack::setElement(char exp){
  
  if( (exp == '0' || exp == '1' || exp == '2' || exp == '3' || exp == '4' || exp == '5' || exp == '6' || exp == '7' || exp == '8' || exp == '9' ) ||
      (exp == '+' || exp == '-' || exp == '*' || exp == 'x' || exp == '/') ){
    if ( empty() ) {
      Node *newNode = new Node;
      head = newNode;
      newNode->setElem(exp);
      newNode->setNext(NULL);
      cout << "Added " << newNode->getElem() << " as Head\n";
    } else {
      Node *newNode = new Node;
      newNode->setElem(exp);
      newNode->setNext(head);
      head = newNode;
      cout << "Added " << newNode->getElem() << "\n";
    }
  }
  
}

bool Stack::empty(){        // Is Stack empty?
  bool retVal;                   // return true if Stack is empty else return false
  return retVal = (head == NULL) ? true : false;
}

double Stack::Solve(){
  double total = 0, elemVal = 0;
  int opVal = 0;
  bool initChecker = false, opChecker = false, elemChecker = false;
  
  Node* cNode = head;
  
  for(int count = 0; count < LIMIT; count++){
    if( initChecker == false && total == 0 ){           // If initChecker == false && total == 0
      if (cNode->getElem() == '0') { total = 0.0; }
      else if (cNode->getElem() == '1') { total = 1; }
      else if (cNode->getElem() == '2') { total = 2; }
      else if (cNode->getElem() == '3') { total = 3; }
      else if (cNode->getElem() == '4') { total = 4; }
      else if (cNode->getElem() == '5') { total = 5; }
      else if (cNode->getElem() == '6') { total = 6; }
      else if (cNode->getElem() == '7') { total = 7; }
      else if (cNode->getElem() == '8') { total = 8; }
      else if (cNode->getElem() == '9') { total = 9; } //      cout << "\nThe current element: " << cNode->getElem() << endl << "Total is now: " << total << "\n\n";
      cout << "\nStarting with " << total << ",\n";
      initChecker = true;                               // Set initChecker to true to tell program that the first number has been loaded
      
      // Else if - the current element in the stack is a number && elemChecker == false
    } else if ( (cNode->getElem() == '0' || cNode->getElem() == '1' || cNode->getElem() == '2' || cNode->getElem() == '3' || cNode->getElem() == '4' ||
                 cNode->getElem() == '5' || cNode->getElem() == '6' || cNode->getElem() == '7' || cNode->getElem() == '8' || cNode->getElem() == '9' ) && elemChecker == false ){
      if (cNode->getElem() == '0') { elemVal = 0.0; }
      else if (cNode->getElem() == '1') { elemVal = 1; }
      else if (cNode->getElem() == '2') { elemVal = 2; }
      else if (cNode->getElem() == '3') { elemVal = 3; }
      else if (cNode->getElem() == '4') { elemVal = 4; }
      else if (cNode->getElem() == '5') { elemVal = 5; }
      else if (cNode->getElem() == '6') { elemVal = 6; }
      else if (cNode->getElem() == '7') { elemVal = 7; }
      else if (cNode->getElem() == '8') { elemVal = 8; }
      else if (cNode->getElem() == '9') { elemVal = 9; }//      cout << "The current element: " << cNode->getElem() << endl << "elemVal is now: " << elemVal << "\n\n";
      cout << elemVal;
      elemChecker = true;                               // Set elemChecker to true
      
      // Else if the current element in the stack is an operation value && opChecker == false
    } else if((cNode->getElem() == '+' || cNode->getElem() == '-' || cNode->getElem() == '*' || cNode->getElem() == 'x' || cNode->getElem() == '/') && opChecker == false){
      cout << total;
      if      (cNode->getElem() == '+') { opVal = 1; cout << " + "; } // Sets the opVal to help tell the Oprations function what to do
      else if (cNode->getElem() == '-') { opVal = 2; cout << " - "; } // Set the opVal value to the corresponding value depending on the type of element
      else if (cNode->getElem() == '*') { opVal = 3; cout << " * "; } // Sets the opVal to help tell the Oprations function what to do
      else if (cNode->getElem() == 'x') { opVal = 3; cout << " * "; } // Set the opVal value to the corresponding value depending on the type of element
      else if (cNode->getElem() == '/') { opVal = 4; cout << " / "; } // Sets the opVal to help tell the Oprations function what to do
      opChecker = true;                         // Set opChecker to true //      cout << "The current element: " << cNode->getElem() << endl << "opVal is now: " << opVal << "\n\n";
    }

    if (opChecker == true && elemChecker == true) {       // if(elemChecker == true && opChecker == true) // Else if elemChecker && opChecker variables are 'true' then
      cout << " = " << Operations(total, elemVal, opVal) << "\n";
      total = Operations(total, elemVal, opVal);// Call the Operations function and set the return as the new 'total' value
      opChecker = false; elemChecker = false;   // Set the opChecker and elemChecker values to false
      opVal = 0; elemVal = 0;                   // Set opVal & elemVal to nothing
    }
    
    cNode = cNode->getNext();                           // Set the next element as the new head
    if (cNode == NULL) {
      break;
    }
  }
  return total;
}

double Stack::Operations(double total, double value, int opVal){
  double final;
  if (opVal == 1) {
    final = total + value;
    return final;
  } else if (opVal == 2) {
    final = total - value;
    return final;
  } else if (opVal == 3) {
    final = total * value;
    return final;
  } else if (opVal == 4) {
    final = total / value;
    return final;
  } else {
    cout << "Something went wrong here.\n\n";
    return final;
  }
}
