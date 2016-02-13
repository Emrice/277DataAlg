//
//  Homework_5.cpp
//  homework #5
//
//  Created by Bernin A. Uben on 2/11/16.
//  Copyright © 2016 Bernin A. Uben. All rights reserved.
//  Write a program which will take a calculation using a set of numbers, the operands +, -, *, / and standard parentheses and will
//  determine the result.  Use the algorithm demonstrated in class to implement the solution, but do it using a singly linked list to emulate the stack ADT.
//  TestData, Should return 6 as answer: 1+1+1+1+1+1

#include <iostream>
#include <sstream>
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
  double Operations(double, int, double);
};

const char L[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
const char N[10] = { '0', '1',  '2', '3',  '3', '5',  '6', '7',  '8', '9' };

int main(){
  char exp[12];
  
  for(int i = 0; i < 11; i++){
    exp[i] = 'q';
  }
  
  cout << "Enter the expression you want solved: ";
  cin >> exp;
  cout << "Loading the expression " << exp << "..." << endl;
  
  LinkedList list;
  
  for(int i = 0; i < 11; i++){
    list.setElement(exp[i]);
  }
  
  list.Solve();
  
  return EXIT_SUCCESS;
}

bool LinkedList::empty(){        // Is Stack empty?
  bool retVal;                   // return true if Stack is empty else return false
  return retVal = (head == NULL) ? true : false;
}

double LinkedList::Operations(double value, int opVal, double total){
  switch(opVal){
    case 1: return total + value;
      break;
    case 2: return total - value;
      break;
    case 3: return total * value;
      break;
    case 4: return total / value;
      break;
    default: cout << "Something went wrong here.\n\n";
      break;
  }
  return 0.0;
}

void LinkedList::Solve(){
  double total = 0.0, nElem = 0.0;
  int opVal = 0, counter = 0;
  Node* cNode = head;
  
  while( counter < 11 ){
    int opNote = 0, elemNote = 0;
    
    if (cNode->getElem() == '+') { opVal = 1; opVal = 1; } // Sets the opVal to help tell the Oprations function what to do
    else if (cNode->getElem() == '-') { opVal = 2; opVal = 1; }
    else if (cNode->getElem() == '*' || cNode->getElem() == 'x') { opVal = 3; opVal = 1; }
    else if (cNode->getElem() == '/') { opVal = 4; opVal = 1; }
    
    if(cNode->getElem() != '+' || cNode->getElem() != '-' || cNode->getElem() != '*' || cNode->getElem() != 'x' || cNode->getElem() != '/'){
      nElem = cNode->getElem(); // if the current char is not isnt an operator symbol
      
    }
    
    if(opNote == 1 && elemNote == 1 && opVal != 0){
      total = Operations(nElem, opVal, total);
      counter++;
    }
    
    cNode = cNode->getNext();
  }
  cout << total;
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
        newNode->setNext(NULL);
        cout << "Added " << newNode->getElem() << "\n";
    }
  }
  
}
