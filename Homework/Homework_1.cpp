//
//  homework #1
//
//  Created by Bernin A. Uben on 1/20/16.
//  Copyright © 2016 Bernin A. Uben. All rights reserved.
//
//  Instructions:
//  Write a working C++ program to ask the user for a set of grades which are to be stored in an array in increasing sequence.
//  The user must first provide the number which represents the count of all grades to be provided.
//  For example, if there will be 10 grades, the user is first prompted to provide the number 10.
//  Subsequently, each grade is provided, one at a time.  Allow for a maximum of 30 grades in defining the array.
//  When all the grades have been sorted properly, print them all, along with the average.
//  If you are comfortable, process the array using a function which is invoked from the main body of the program.
//  The main body asks for the count of grades and then invokes the grade sequencing function.
//  You must write in proper C++ syntax and actually execute the program to ensure it works properly.
//

#include <iostream>
using namespace std;


int setLength();
void sort(int[], int);
void addGrade(int[], int);
double getAverage(int[], int);


int main(){
  // set ARR_LENGTH constant here outside of the operations loop
  // call the setArrayLength method and set the return vsalue as the constants value
  const int ARR_LENGTH = setLength();
  cout << "Made space for " << ARR_LENGTH << " grades. \n\n";
  
  // set the main array to hold values
  int mainArr[ARR_LENGTH];
  // sets all the values in mainArr to 0
  for(int e = 0; e < ARR_LENGTH; e++){
    mainArr[e] = 0;
  };
  
  // asks to add each grade to its respective spot
  addGrade(mainArr, ARR_LENGTH);
  
  // sort the mainArr to be
  sort(mainArr, ARR_LENGTH);
  
  // print out the values in the array with a massage saying thats what it is here
  cout << "\nAll Grades in order:\n[ ";
  for(int x = 0; x < ARR_LENGTH;x++){
    if (x != ARR_LENGTH - 1){
      cout << mainArr[x] << ", ";
    } else {
      cout << mainArr[x] << " ";
    }
  }
  cout << "]\n\n";
  
  // set the value of average grade to the return value of the getAverageGrade method
  double avg = getAverage(mainArr, ARR_LENGTH);
  
  // print out the value of the average grade here
  cout << "The average grade is " << avg << "%\n\n";
  
  return 0;
}

int setLength(){
  int length;
  // ask for an integer to set the length of the array
  // maximum of 30 grades allowable (Max length of 30)
  cout << "How many grades are there going to be in the list?(Max: 30) \n";
  
  // set the user input as the tempLength value
  cin >> length;
  
  // if the length is greater than 30 or less than 0, ask again
  // if the length is not not an integer, then ask again
  if(length <= 0 || length > 30)
    while(length <= 0 || length > 30){
      cout << "INCORRECT INPUT! PLEASE RE-ENTER GRADE.\n";
      cout << "How many grades are there going to be in the list?(Max: 30) \n";
      cin >> length;
      if(length > 0 && length <= 30){
        break;
      };
    };
  
  // AFTER all the validation, return the length value
  return length;
};

void addGrade(int mainArr[], int ARR_LENGTH){
  for(int x = 0; x < ARR_LENGTH; x++){
    // ask user for the grade they want to input to program
    cout << "Please insert grade " << x+1 << "/" << ARR_LENGTH << ": ";
    
    // set answer variable to hold the current item to be added into the array & add in
    cin >> mainArr[x];
  };
};

void sort(int mainArr[], int ARR_LENGTH){
  // set three variables needed
  int x, j, value;
  
  // Star a for loop with a starting value of 1
  for(j = 1; j < ARR_LENGTH; j++){
    //set value to the current item in the mainArr
    value = mainArr[j];
    
    // Make the smaller values move up in the array
    for(x = j - 1; (x >= 0) && (mainArr[x] < value); x--){
      mainArr[x+1] = mainArr[x];
    };
    
    mainArr[x+1] = value;    //Put value into its proper location
  };
};

double getAverage(int mainArr[], int ARR_LENGTH){
  // declare a variable of type double that will represent the total combined grade
  double total;
  
  // use a for loop to go through the length of the array
  // add each int value to the double variable - (C++ will convert the int into doubles)
  for(int x = 0; x < ARR_LENGTH; x++){
    total += mainArr[x];
  }
  //end for loop
  
  // return the average which is the total divided by the # of items mainArr holds
  return total/ARR_LENGTH;
};