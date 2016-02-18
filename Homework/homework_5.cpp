//
//  Homework_5.cpp
//  homework #5
//
//  Created by Bernin A. Uben on 2/11/16.
//  Copyright © 2016 Bernin A. Uben. All rights reserved.
//  Write a program which will take a calculation using a set of numbers, the operands +, -, *, / and standard parentheses and will
//  determine the result.  Use the algorithm demonstrated in class to implement the solution, but do it using a singly linked list to emulate the stack ADT.
//  TestData, Should return 6 as answer: 1+2+3+4+5+6

#include <iostream>
#include <cstdlib>
#include <stdlib.h>     /* atof */
#include <string>
using namespace std;

const int LIMIT = 11;

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

class LinkedList {
  Node *head;
  
public:
  LinkedList(){ head = NULL; };
  bool empty();
  void setElement(char);
  int Solve();
  int Operations(int, int, int);
};

//const char L[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
//const char N[10] = { '0', '1',  '2', '3',  '3', '5',  '6', '7',  '8', '9' };

int main(){
  char exp[LIMIT+1];
  
  for(int i = 0; i < LIMIT; i++){
    exp[i] = 'q';
  }
  
  cout << "Enter the expression you want solved: ";
  cin >> exp;
  cout << "Loading the expression " << exp << "..." << endl;
  
  LinkedList list;
  
  for(int i = 0; i < LIMIT; i++){ // adding sequence in reverse order (int i = LIMIT; i >= 0; i--)
    list.setElement(exp[i]);
  }
  
  cout << list.Solve();
  
  return EXIT_SUCCESS;
}

void LinkedList::setElement(char exp){
  
  if( exp != '\0' && exp != 'a' && exp != 'b' && exp != 'c'  && exp != 'd' && exp != 'e' && exp != 'f'  && exp != 'g' && exp != 'h' && exp != 'i' && exp != 'j' && exp != 'k' && exp != 'l' && exp != 'm' && exp != 'n' && exp != 'o' && exp != 'p' && exp != 'q' && exp != 'r' && exp != 's' && exp != 't' && exp != 'u' && exp != 'v' && exp != 'w' && exp != 'x' && exp != 'y' && exp != 'z' ){
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

bool LinkedList::empty(){        // Is Stack empty?
  bool retVal;                   // return true if Stack is empty else return false
  return retVal = (head == NULL) ? true : false;
}

int LinkedList::Solve(){
  int total = 0, elemVal = 0, opVal = 0;
  bool initChecker = false, opChecker = false, elemChecker = false;
  
  Node* cNode = head;
  
  for(int count = 0; count < LIMIT; count++){
    
    cNode = cNode->getNext();                 // Set the next element as the new head
    
    if (cNode == NULL) {
      break;
    }
    
    if( initChecker == false && total == 0 ){   // If initChecker == false && total == 0
      total = cNode->getElem() - 48;            // Set the total as the first number in the expression
      initChecker = true;                       // Set initChecker to true to tell program that the first number has been loaded
                                                // Increment the current head of the stack and pop it off
    } else if (cNode->getElem() != '+' && cNode->getElem() != '-' && cNode->getElem() != '*' && cNode->getElem() != 'x' && cNode->getElem() != '/' && elemChecker == false){ // Else if - the current element in the stack is a number && elemChecker == false
      elemVal = cNode->getElem() - 48;          // Add the element from char to int into the elemVal variable
      elemChecker = true;                       // Set elemChecker to true
                                                // Increment the current head of the stack and pop it off
    } else if(cNode->getElem() == '+' && cNode->getElem() == '-' && cNode->getElem() == '*' && cNode->getElem() == 'x' && cNode->getElem() == '/' && opChecker == false){ // Else if the current element in the stack is an operation value && opChecker == flase
      cout << "Operation:";
      if      (cNode->getElem() == '+') { opVal = 1; cout << " + \n"; } // Sets the opVal to help tell the Oprations function what to do
      else if (cNode->getElem() == '-') { opVal = 2; cout << " - \n"; } // Set the opVal value to the corresponding value depending on the type of element
      else if (cNode->getElem() == '*') { opVal = 3; cout << " * \n"; } // Sets the opVal to help tell the Oprations function what to do
      else if (cNode->getElem() == 'x') { opVal = 3; cout << " * \n"; } // Set the opVal value to the corresponding value depending on the type of element
      else if (cNode->getElem() == '/') { opVal = 4; cout << " / \n"; } // Sets the opVal to help tell the Oprations function what to do
      opChecker = true;                         // Set opChecker to true
                                                // Increment the head of stack
    } else if(elemChecker && opChecker) {       // Else if elemChecker && opChecker variables are 'true' then
      total = Operations(total, elemVal, opVal);// Call the Operations function and set the return as the new 'total' value
      opChecker = false; elemChecker = false;   // Set the opChecker and elemChecker values to false
      opVal = 0; elemVal = 0;                   // Set opVal & elemVal to nothing
                                                // increment the head to the next one
    }
  }
  return total;
}

int LinkedList::Operations(int total, int value, int opVal){
  int final;
  switch(opVal){
    case 1: final = total + value;
      return final;
      break;
    case 2: final = total - value;
      return final;
      break;
    case 3: final = total * value;
      return final;
      break;
    case 4: final = total / value;
      return final;
      break;
    default: cout << "Something went wrong here.\n\n";
      return final;
      break;
  }
}


//        if (cNode->getElem() == '0') { elemVal = 0.0; }
//        else if (cNode->getElem() == '1') { third = 1.0; }
//        else if (cNode->getElem() == '2') { third = 2.0; }
//        else if (cNode->getElem() == '3') { third = 3.0; }
//        else if (cNode->getElem() == '4') { third = 4.0; }
//        else if (cNode->getElem() == '5') { third = 5.0; }
//        else if (cNode->getElem() == '6') { third = 6.0; }
//        else if (cNode->getElem() == '7') { third = 7.0; }
//        else if (cNode->getElem() == '8') { third = 8.0; }
//        else if (cNode->getElem() == '9') { third = 9.0; }

//        if (cNode->getElem() == '0') { elemVal = 0.0; }
//        else if (cNode->getElem() == '1') { elemVal = 1.0; elemChecker = true; }
//        else if (cNode->getElem() == '2') { elemVal = 2.0; elemChecker = true; }
//        else if (cNode->getElem() == '3') { elemVal = 3.0; elemChecker = true; }
//        else if (cNode->getElem() == '4') { elemVal = 4.0; elemChecker = true; }
//        else if (cNode->getElem() == '5') { elemVal = 5.0; elemChecker = true; }
//        else if (cNode->getElem() == '6') { elemVal = 6.0; elemChecker = true; }
//        else if (cNode->getElem() == '7') { elemVal = 7.0; elemChecker = true; }
//        else if (cNode->getElem() == '8') { elemVal = 8.0; elemChecker = true; }
//        else if (cNode->getElem() == '9') { elemVal = 9.0; elemChecker = true; }

// OLD SOLVE FUNCTION: TOTAL WAS OUT OF SCOPE IN THE WHILE LOOP
//
//  while( counter < 11 ){
//    if (cNode != NULL) {
//      bool opChecker = false, elemChecker = false, thirdChecker = false;
//      
//      if (opChecker == true && elemChecker == true && thirdChecker == true ){
//        if (opVal == 1) { cout << total << " + " << elemVal << "? "; }
//          else if (opVal == 2) { cout << total << " - " << elemVal << "? "; }
//          else if (opVal == 3) { cout << total << " * " << elemVal << "? "; }
//          else if (opVal == 4) { cout << total << " / " << elemVal << "? "; }
//          cout << Operations(total, elemVal, opVal) << " is now the total.\n\n";
//          total = Operations(total, elemVal, opVal);
//          opChecker = false; elemChecker = false; opVal = 0; elemVal = 0.0;
//          counter += 1;
//          
//          } else if (opChecker == true && elemChecker == true && thirdCounter > 1 && thirdChecker == false) {
//            char dNum = cNode->getElem();
//            third = (int)dNum;
//            cout << "Current value to modify the total: " << third << "\n";
//            total = Operations(elemVal, third, opVal); // sets the elem + the third num to be added and returned as the total only if its the first time round else its going to do operations on the total variable
//            thirdChecker = true; opChecker = false; elemChecker = false; opVal = 0; elemVal = 0.0; counter++;
//            
//          } else if (cNode->getElem() != '+' && cNode->getElem() != '-' && cNode->getElem() != '*' && cNode->getElem() != 'x' && cNode->getElem() != '/' && elemChecker == true){
//            char dNum = cNode->getElem();
//            elemVal = (int)dNum;
//            elemChecker = true;
//            cout << "Current value to modify the total: " << elemVal << "\n";
//            if (thirdCounter < 2){ thirdCounter += 1; }
//            
//          } else if (cNode->getElem() == '+' && cNode->getElem() == '-' && cNode->getElem() == '*' && cNode->getElem() == 'x' && cNode->getElem() == '/' && opChecker != true) {
//            cout << "Operation:";
//            if      (cNode->getElem() == '+') { opVal = 1; cout << " + \n"; } // Sets the opVal to help tell the Oprations function what to do
//            else if (cNode->getElem() == '-') { opVal = 2; cout << " - \n"; }
//            else if (cNode->getElem() == '*') { opVal = 3; cout << " * \n"; }
//            else if (cNode->getElem() == 'x') { opVal = 3; cout << " * \n"; }
//            else if (cNode->getElem() == '/') { opVal = 4; cout << " / \n"; }
//            opChecker = true;
//            if (thirdCounter < 2){ thirdCounter += 1; }
//            
//          } else {
//            if (cNode->getNext() == NULL) {
//              cout << "Nothing left\n";
//              break;
//            } else {
//              cNode = cNode->getNext();
//            }
//          }
//          
//          } else {
//            cout << "No expression registered\n\n";
//            break;
//          }
//          }
//          cout << total << endl;
//          return total;
//
