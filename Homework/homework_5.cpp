//
//  main.cpp
//  hw6
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