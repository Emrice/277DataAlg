//
//  hw2.cpp
//
//  Created by Bernin A. Uben on 1/24/16.
//  Copyright © 2016 Bernin A. Uben. All rights reserved.
//  Using the program you developed for Homework 1, define a structure which supports the following types of information:
//  - student name
//  - student ID number
//  - current exam grade
//  - prior exam grade
//  - overall GPA
//  The user will once again identify the number of students being represented and will then provide the 5 pieces of
//  information for each student.  The user can sort based on any one of the 5 criteria, by specifying a value of 1-5.
//  After sorting, print the result.
//

#include <iostream>
#include <string>
using namespace std;
// Test data for 3 people: Han Solo 1443039 92.40 85.90 3.6 Naruto Uzumaki 3374569 79.30 50.20 2.90 John S117 0000117 98.90 99.70 4.0

struct Name {
  string first;
  string last;
};

struct Student {
  Name name;
  int studentID;
  double cExamGrade;
  double pExamGrade;
  double GPA;
} mainArr[30];

int setLength();
void sort(int[], int);
void dSort(double[], int);  // Not overloading for clarity
void addInfo(Student[], int);

int main(){
  // set ARR_LENGTH constant here outside of the operations loop
  // call the setArrayLength method and set the return vsalue as the constants value
  const int ARR_LENGTH = setLength();
  
  // temp array for temp doing operations
  int tempArr[ARR_LENGTH + 1];
  double dTempArr[ARR_LENGTH + 1];
  
  // set the main array to hold values back up in the student struct
  // asks for the 5 peces of info for each student
  addInfo(mainArr, ARR_LENGTH);
  
  // switch statement to sort through any info the user wants
  bool cont = true;
  int answer = 0;
  string fin;
  
  while(cont){
    cout << "\n\n\n";
      cout << "1. Show Student Records\n2. Show Student Names\n3. Show Student IDs\n";
      cout << "4. Show Student Current Exam Grades\n5. Show Student Past Exam Grades\n";
      cout << "6. Show Student GPAs\nChoose from options 1-6: ";
      cin >> answer;
      
      switch(answer){
        case 1: for(int p = 0; p < ARR_LENGTH; p++){ //Prints out all the students
                  cout << "\n";
                  cout << mainArr[p].name.last << ", " << mainArr[p].name.first << "\nStudent ID: " << mainArr[p].studentID;
                  cout << "\nCurrent Exam Grade:" << mainArr[p].cExamGrade << "\nPast Exam Grade: " << mainArr[p].pExamGrade;
                  cout << "\nGPA: " << mainArr[p].GPA << "\n\n";
                };
          break;
        //
        case 2: cout << "\nStudent Names: ";
                for(int x = 0; x < ARR_LENGTH; x++){
                  if(x >= ARR_LENGTH - 1){
                    cout << mainArr[x].name.first << " " << mainArr[x].name.last << "\n\n";
                  } else {
                    cout << mainArr[x].name.first << " " << mainArr[x].name.last << ", ";
                  }
                }
                cout << endl;
          break;
        //
        case 3: for(int x = 0; x < ARR_LENGTH; x++){
                  tempArr[x] = mainArr[x].studentID;
                }
                
                sort(tempArr, ARR_LENGTH); // sorts the numbers
                
                cout << "\nStudent IDs: ";
                for(int r = 0; r < ARR_LENGTH; r++){
                    cout << tempArr[r] << " ";
                }
                cout << "\n\n";
            break;
            //
        case 4: for(int x = 0; x < ARR_LENGTH; x++){
                  dTempArr[x] = mainArr[x].cExamGrade;
                }
                        
                dSort(dTempArr, ARR_LENGTH); // sorts the numbers
                
                cout << "\nCurrent Student Exam Grades: ";
                for(int r = 0; r < ARR_LENGTH; r++){
                    cout << dTempArr[r] << " ";
                }
                cout << "\n\n";
            break;
            
        case 5: for(int x = 0; x < ARR_LENGTH; x++){
                    dTempArr[x] = mainArr[x].pExamGrade;
                }
            
                dSort(dTempArr, ARR_LENGTH); // sorts the numbers
                
                cout << "\nCurrent Student Exam Grades: ";
                for(int r = 0; r < ARR_LENGTH; r++){
                    cout << dTempArr[r] << " ";
                }
                cout << "\n\n";
            break;
            
        case 6: for(int x = 0; x < ARR_LENGTH; x++){
                  dTempArr[x] = mainArr[x].GPA;
                }
                
                dSort(dTempArr, ARR_LENGTH); // sorts the numbers
                
                cout << "\nCurrent Student Exam Grades: ";
                for(int r = 0; r < ARR_LENGTH; r++){
                    cout << dTempArr[r] << " ";
                }
                cout << "\n\n";
            break;
            //
        default: cout << "\n\n\n";
            cout << "Sorry thats not an option.\n";
            cout << "1. Show Student Records\n2. Show Student Names\n3. Show StudentIDs\n";
            cout << "4. Show Student Current Exam Grades\n5. Show Student Past Exam Grades\n";
            cout << "6. Show Student GPAs\nChoose from options 1-6: ";
            break;
      }

      cout << "Anything else? ('yes' or 'no'): ";
      cin >> fin;
        
      if(fin != "yes"){
          cont = false;
          break;
      }
    }

    cout << "\n\n\n\n\n\nTerminated.\n";
    return 0;
}

int setLength(){
  int length;
  // ask for an integer to set the length of the array
  // maximum of 30 grades allowable (Max length of 30)
  cout << "How many grades are there going to be in the list?(Max: 30): \n";
  
  // set the user input as the tempLength value
  cin >> length;
  
  // if the length is greater than 30 or less than 0, ask again
  // if the length is not not an integer, then ask again
  if(length <= 0 || length > 30)
    while(length <= 0 || length > 30){
      cout << "INCORRECT INPUT! NUMBER OF STUDENTS CANNOT BE OVER 30 OR LESS THAN 0.\nPLEASE RE-ENTER AMMOUNT OF STUDENTS.\n";
      cout << "How many grades are there going to be in the list?(Max: 30): \n";
      cin >> length;
      if(length > 0 && length <= 30){
        break;
      };
    };
    
    // AFTER all the validation, return the length value
    return length;
};

// takes in al the info needed for the structs
void addInfo(Student mainArr[], int ARR_LENGTH){
  for(int p = 0; p < ARR_LENGTH; p++){
    cout << "\nStudent " << p+1 << endl;
    cout << "First Name: ";
    cin >> mainArr[p].name.first;
    
    cout << "Last Name: ";
    cin >> mainArr[p].name.last;
    
    cout << "Student ID: ";
    cin >> mainArr[p].studentID;
    
    cout << "Current Exam Grade: ";
    cin >> mainArr[p].cExamGrade;
    
    cout << "Past Exam Grade: ";
    cin >> mainArr[p].pExamGrade;
    
    cout << "Grade Point Average(GPA): ";
    cin >> mainArr[p].GPA;
  };
};

// test data: Han Solo 1443039 92.40 85.90 3.6 Naruto Uzumaki 3374569 79.30 50.20 2.90 John S117 3049573 98.50 99.70 4.0
// sorting for int arrays
void sort(int tempArr[], int length){
  int holder = -1;
  
  for(int x = length - 1; x > 0; x--){
    for(int i = 0; i < length; i++){
      if (tempArr[i] > tempArr[i + 1]){
        holder = tempArr[i + 1];
        tempArr[i + 1] = tempArr[i];
        tempArr[i] = holder;
      }
      length--;
      //  uncomment next 4 lines to see how the array is sorted
      //  for(int l = 0; l < 3; l++){
      //    cout << tempArr[l] << " ";
      //  }
      //  cout << "\n";
    }
  }
}

// sorting for double type arrays
void dSort(double dTempArr[], int length){
  int holder = -1;
  
  for(int x = length - 1; x > 0; x--){
    for(int i = 0; i < length; i++){
      if (dTempArr[i] > dTempArr[i + 1]){
        holder = dTempArr[i + 1];
        dTempArr[i + 1] = dTempArr[i];
        dTempArr[i] = holder;
      }
      length--;
      //  uncomment next 4 lines to see how the array is sorted
      //  for(int l = 0; l < 3; l++){
      //    cout << dTempArr[l] << " ";
      //  }
      //  cout << "\n";
    }
  }
}


