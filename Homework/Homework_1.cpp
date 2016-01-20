//
//  main.cpp
//  hw1
//
//  Created by Bernin A. Uben on 1/20/16.
//  Copyright © 2016 Bernin A. Uben. All rights reserved.
//  Write a working C++ program to ask the user for a set of grades which are to be stored in an array in increasing sequence.  The user must first provide the number which represents the count of all grades to be provided.  For example, if there will be 10 grades, the user is first prompted to provide the number 10.  Subsequently, each grade is provided, one at a time.  Allow for a maximum of 30 grades in defining the array.  When all the grades have been sorted properly, print them all, along with the average.
//  If you are comfortable, process the array using a function which is invoked from the main body of the program.  The main body asks for the count of grades and then invokes the grade sequencing function.
//  You must write in proper C++ syntax and actually execute the program to ensure it works properly.

#include <iostream>
using namespace std;

void setArrayLength(int);
void placeInOrder();
double getAverageGrade(double);


int main(){
  // set arrLength variable here outside of the loop
  // call the setArrayLength method and pass in arrLength into it
  
  // begin the main loop

    // ask user for the grade they want to input to program

    // call placeInOrder and pass the pointer refrence to the array and the current grade they just input

    // output the array(list of grades), when the placeInOrder method is done, to the screen

  // end the main loop
  
  // set the value of average grade to the return value of the getAverageGrade method
  
  // print out the values in the array with a massage saying thats what it is here
  // print out the value of the average grade here
}

void setArrayLength(int){
  // declare tempLength variable
  // ask for an integer to set the length of the array with a maximum of 30 grades allowable (Max length of 30)
  // set the user input as the tempLength value
  
  // if the length is greater than 30 or less than 0, ask again
  // if the length is not not an integer, then ask again
  
  // AFTER all the validation, set tempLength to the value being pointed to by the arrLength pointer
}

void placeInOrder(){
  // NOTE: array goes from highest -> lowest
  // take the grade and cycle through each item in the array until the current item is equal to or smaller than the current grade
  
  // if the current grade is greater than the current grade being cycled, then push that grade into the array
  // else if the grade in the grade variable is less than or equal to the current grade in the array then push the grade variable into the array
  // Have the loop above continue until the array that was passed in is fully looped through
  
  // set the value of pointer to the old array as the new array
}

double getAverageGrade(double){
  // declare a variable of type double that represents the total combined grade
  
  // use a for loop to go through the length of the array
    // add each int value to the double variable because c++ will convert the int into doubles
  // end the for loop
  
  // divide the variable of type double at the beginning of the method by the length of the array and set it as itself
  
  // return the value of the double variable
}