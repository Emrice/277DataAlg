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
  void Solve();
  void setElement(char);
  double Operations(double, double, int);
};

//const char L[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
//const char N[10] = { '0', '1',  '2', '3',  '3', '5',  '6', '7',  '8', '9' };

int main(){
  char exp[12];
  
  for(int i = 0; i < 11; i++){
    exp[i] = 'q';
  }
  
  cout << "Enter the expression you want solved: ";
  cin >> exp;
  cout << "Loading the expression " << exp << "..." << endl;
  
  LinkedList list;
  
  for(int i = 11; i >= 0; i--){ // adding sequence in reverse order
    list.setElement(exp[i]);
  }
  
  list.Solve();
  
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

void LinkedList::Solve(){
  double total = 0.0, elemVal = 0.0, third = 0.0;
  int opVal = 0, counter = 0, thirdCounter = 0;
  
  Node* cNode = head;
  
  while( counter < 11 ){
    if (cNode != NULL) {
      bool opChecker = false, elemChecker = false, thirdChecker = false;
      
      if (opChecker == true && elemChecker == true && thirdChecker == true ){
        if (opVal == 1) { cout << total << " + " << elemVal << "? "; }
        else if (opVal == 2) { cout << total << " - " << elemVal << "? "; }
        else if (opVal == 3) { cout << total << " * " << elemVal << "? "; }
        else if (opVal == 4) { cout << total << " / " << elemVal << "? "; }
        cout << Operations(total, elemVal, opVal) << " is now the total.\n\n";
        total = Operations(total, elemVal, opVal);
        opChecker = false; elemChecker = false; opVal = 0; elemVal = 0.0;
        counter += 1;
        
      } else if (opChecker == true && elemChecker == true && thirdCounter > 1 && thirdChecker != true) {
        char dNum = cNode->getElem();
        third = atof(&dNum);
        cout << "Current value to modify the total: " << third << "\n";
        total = Operations(elemVal, third, opVal); // sets the elem + the third num to be added and returned as the total only if its the first time round else its going to do operations on the total variable
        thirdChecker = true; opChecker = false; elemChecker = false; opVal = 0; elemVal = 0.0; counter++;
        
      } else if (cNode->getElem() != '+' && cNode->getElem() != '-' && cNode->getElem() != '*' && cNode->getElem() != 'x' && cNode->getElem() != '/' && elemChecker == true){
        char dNum = cNode->getElem();
        elemVal = atof(&dNum);
        elemChecker = true;
        cout << "Current value to modify the total: " << elemVal << "\n";
        if (thirdCounter < 2){ thirdCounter++; }
        
      } else if (cNode->getElem() == '+' && cNode->getElem() == '-' && cNode->getElem() == '*' && cNode->getElem() == 'x' && cNode->getElem() == '/' && opChecker != true) {
        cout << "Operation:";
        if      (cNode->getElem() == '+') { opVal = 1; opChecker = true; cout << " + \n"; } // Sets the opVal to help tell the Oprations function what to do
        else if (cNode->getElem() == '-') { opVal = 2; opChecker = true; cout << " - \n"; }
        else if (cNode->getElem() == '*') { opVal = 3; opChecker = true; cout << " * \n"; }
        else if (cNode->getElem() == 'x') { opVal = 3; opChecker = true; cout << " * \n"; }
        else if (cNode->getElem() == '/') { opVal = 4; opChecker = true; cout << " / \n"; }
        if (thirdCounter < 2){ thirdCounter++; }

      } else {
        if (cNode->getNext() == NULL) {
          cout << "Nothing left\n";
          break;
        } else {
          cNode = cNode->getNext();
        }
      }
      
    } else {
      cout << "No expression registered\n\n";
      break;
    }
  }
  cout << total << endl;
}

double LinkedList::Operations(double total, double value, int opVal){
  switch(opVal){
    case 1: total = total + value;
      return total;
      break;
    case 2: total = total - value;
      return total;
      break;
    case 3: total = total * value;
      return total;
      break;
    case 4: total = total / value;
      return total;
      break;
    default: cout << "Something went wrong here.\n\n";
      return total;
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
