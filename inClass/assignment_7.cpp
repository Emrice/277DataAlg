//
//  Assignment_7.cpp
//  Assignment #7
//
//  Created by Bernin A. Uben on 3/20/16.
//  Copyright © 2016 Bernin A. Uben. All rights reserved.
//
//  Write a C++ program that will take any input infix computation consisting of (, ), +, -, *, / and
//  positive numeric operands and convert it to postfix.  Use a stack, as was demonstrated in class.
//
//  Secondly, use the postfix form of the computation to actually calculate the result of applying the operators to the operands.
//  In other words, use the output of the first part (a postfix string) to calculate the result.
//  The precedence order is as follows:
//  • * / = operators which have same precedence
//  • + - = operators which have same precedence
//  • ) = lower precedence than the operators
//  • ( = lowest precedence
//
//  The computation should be input as a single string.
//  Assume it is always correct with regard to format and
//  parenthesis balancing, so you don't need to address errors.
//

#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <cctype>
#include <stdexcept>
using namespace std;

int    postEval         (const string);                                                                                       // Returns solution to Postfix expression passed
int    pOperation       (const char, const int, const int);                                                                   // Returns solution based on respective numbers and op val
bool   checkPrecedence  (const char, const char);                                                                             // Checks for precidence
bool   IsNumericDigit   (char i){ if (i >= '0' && i <= '9'){ return true; } else { return false; } }                          // Checks if the char C passed is a NUMBER
bool   isOperator       (char i){ if (i == '+' || i == '-' || i == '*' || i == '/'){ return true; } else { return false; } }  // Checks if the char c passed is a SYMBOL
string cToP             (const string&);                                                                                      // Returns string conversion of Infix notation to postfix notation

int main() {
  cout << "Welcome to the Infix to Postfix Calculator!\n\nDirections:\n";
  cout << "1. Sample Expressions:(Spaces Don't Matter)\n      ex: '2 + 3 * 4' = '14'\n      ex: '2 * 3 + 4' = '10'\n      ex: '( 2 + 3 ) * 10' = '50'\n      ex: '((5*4)-(6+4))*(2+8)' = '100'\n";
  cout << "2. Expected & Allowed Values Include:\n      Numbers: 0, 1, 2, 3, 4, 5, 6, 7, 8, & 9\n      Operators: +, -, *, & / \n      Parenthesis: ( & )\n";
  while (true){
    cout << "\n\nEnter the Arithmetic Expression: ";
    string iExp;
    getline(cin, iExp);
    
    if (iExp.empty() == false){
      cout << "Infix Notation:   '" << iExp << "'\n";
      cout << "Postfix Notation: '" << cToP(iExp) << "'\n";
      cout << "Postfix Solution: '" << postEval(cToP(iExp)) << "'\n";
    } else {
      break;
    }
  }
}

int pOperation(const char op, const int num1, const int num2) {
  if     (op == '+'){ return num1 + num2; }
  else if(op == '-'){ return num1 - num2; }
  else if(op == '*'){ return num1 * num2; }
  else if(op == '/'){ return num1 / num2; }
  else { cout << "Something went wrong in Preform Operation method D:\n\n"; }
  return -1;
}

bool checkPrecedence(const char leftOp, const char rightOp){
  if ( rightOp == '*' || rightOp == '/')  {
    return false;
  } else if ( leftOp == '*' || leftOp == '/') {
    return true;
  }
  return true;
}

string cToP(const string& infix){
  stringstream postfix;                                     // Return String Value
  stack<char> cStack;                                       // Stack of type char named 'cStack'
  cStack.push('(');                                         // Push a left parenthesis ‘(‘ onto the cStack.
  
  for(int i = 0; i < infix.size(); ++i) {                   // Begin to look through the infix expression
    const char current = infix[i];                          // Check the current char in position i in the infix string
    if (isspace(current)) {                                 // isspace() in C++ checks if the current i position in the infix string is a whitespace
                                                            // Ignore it if it is a whitespace
    } else if(isalnum(current) || '.' == current) {         // If it's a digit or '.' or a letter ("variables"), add it to the output -- isalnum() basically ches for all alphnumeric characters
      postfix << current;                                   // Add it into postfix sstream
    } else if(current == '(') {                             // If the current item in the i position in string infix is an open/left parenthesis then
      cStack.push(current);                                 // Push the open/left parenthesis into cStack
    } else if(isOperator(current)) {                        // Else if the current item in the i position in string infix is an operator ex: (+ - * /)
      char rightOperator = current;                         // Set the right operator to current(i position in infix string)
      while(!cStack.empty() && isOperator(cStack.top()) && checkPrecedence(cStack.top(), rightOperator)) { // While the stack isn't empty && the top of the cStack is an operator &&
        postfix << ' ' << cStack.top();                     // The precedence has been checked, add it into the postfix sstream
        cStack.pop();                                       // Pop off the top of the cStack
      }
      postfix << ' ';                                       // Add in another whitespace
      cStack.push(rightOperator);                           // Push in the operator
    } else if(')' == current) {                             // Found right parenthesis
      while(!cStack.empty() && '(' != cStack.top()) {       // While top of cStack is not a left parenthesis
        postfix << ' ' << cStack.top();                     // Push a space and top of the cStack into postfix stringstream
        cStack.pop();                                       // Pop off the cStack
      }
      cStack.pop(); postfix << ' ';                         // Else there is a left parethesis, throw it away
    }
  }                                                         // End For Loop
  
  while(!cStack.empty() && cStack.top() != '(') {
    postfix << ' ' << cStack.top();
    cStack.pop();
  }
  cStack.pop();                                             // Throw away the left parenthesis
  return postfix.str();
}


int postEval(string sExp){
  stack<int> iStack;                                        // Declaring a Stack of type int called iStack
  for(int i = 0; i < sExp.length(); i++) {
    if(sExp[i] == ' ' || sExp[i] == ','){                   // Scanning each character from left and skip if its is a space or comma
      // Do nothing
    } else if(isOperator(sExp[i])){                         // If character is operator, pop two elements from stack, perform operation and push the result back.
      int num2 = iStack.top(); iStack.pop();                // Pop two operands.
      int num1 = iStack.top(); iStack.pop();
      iStack.push(pOperation(sExp[i], num1, num2));   //Push back result of operation on stack.
    } else if(IsNumericDigit(sExp[i])){
      int operand = 0;
      while(i<sExp.length() && IsNumericDigit(sExp[i])) {   // Get a number from the string and itterate over i as long as its not a operator
        operand = (operand*10) + (sExp[i] - '0');           // For a number with more than 9, as it scans from left to right, everytime it gets ->
        i++;                                                // a digit, we can multiply current total by 10 and add the new number
      }
      i--;
      iStack.push(operand);                                 // Push operand on stack.
    }
  }
  return iStack.top();                                      // If the user inputted the string in correct format, the Stack will eventually have one element which is what will be the answer
}

