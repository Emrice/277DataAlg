#include <iostream>
#include <string>
using namespace std;

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
void addInfo(Student[], int);
double getAverage(int[], int);

int main(){
  // set ARR_LENGTH constant here outside of the operations loop
  // call the setArrayLength method and set the return vsalue as the constants value
  const int ARR_LENGTH = setLength();
  
  // set the main array to hold values back up in the student struct
  // asks for the 5 peces of info for each student
  addInfo(mainArr, ARR_LENGTH);
  
  // switch statement to sort through any info the user wants
  bool cont = true;
  int answer = 0;
  string fin;
  
  while(cont){
    cout << "\n\n\n";
    cout << "1. Show Student Names\n2.Show Student Records\n3. Show StudentIDs\n";
    cout << "4. Show Student Current Exam Grades\n5. Show Student Past Exam Grades\n";
    cout << "6. Show Student GPAs\nChoose from options 1-6: ";
    cin >> answer;
    
    switch(answer){
      case 1: cout << "Student Names: ";
              for(int x = 0; x < ARR_LENGTH; x++){
                if(x >= ARR_LENGTH - 1){
                  cout << mainArr[x].name.first << " " << mainArr[x].name.last << "\n\n";
                } else {
                  cout << mainArr[x].name.first << " " << mainArr[x].name.last << ", ";
                }
              }
      break;
    case 2:
      
      break;
    case 3:
      
      break;
    case 4:
      
      break;
    case 5:
      
      break;
    case 6:
      
      break;
    case 7:
      
      break;
    default: cout << "\n\n\n";
             cout << "Sorry thats not an option.\n";
             cout << "1. Show Student Records\n2. Show Student Names\n3. Show StudentIDs\n";
             cout << "4. Show Student Current Exam Grades\n5. Show Student Past Exam Grades\n";
             cout << "6. Show Student GPAs\nChoose from options 1-6: ";
      break;
    }
    
    cout << "Anything else? ('yes' or 'no'):";
    cin >> fin;
    
    if(fin != "yes"){
      cont = false;
      break;
    }
  }
  
  //Prints out all the students
  for(int p = 0; p < ARR_LENGTH; p++){
    cout << "\n";
    cout << mainArr[p].name.last << ", " << mainArr[p].name.first << "\nStudent ID: " << mainArr[p].studentID;
    cout << "\nCurrent Exam Grade:" << mainArr[p].cExamGrade << "\nPast Exam Grade: " << mainArr[p].pExamGrade;
    cout << "\nGPA: " << mainArr[p].GPA << "\n\n";
  };
  
  return 0;
  
  // sort the mainArr to be
  //sort(mainArr, ARR_LENGTH);
  
  // print out the values in the array with a massage saying thats what it is here
  //  cout << "\nAll Grades in order:\n[ ";
  //  for(int x = 0; x < ARR_LENGTH;x++){
  //    if (x != ARR_LENGTH - 1){
  //      cout << mainArr[x] << ", ";
  //    } else {
  //      cout << mainArr[x] << " ";
  //    }
  //  }
  //  cout << "]\n\n";
  
  // set the value of average grade to the return value of the getAverageGrade method
  //  double avg = getAverage(mainArr, ARR_LENGTH);
  
  // print out the value of the average grade here
  //  cout << "The average grade is " << avg << "%\n\n";
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
    //    cout << "\n\n" << mainArr[p].name.last << ", " << mainArr[p].name.first << "\nStudent ID: ";
    //    cout << mainArr[p].studentID << "\nCurrent Exam Grade:" << mainArr[p].cExamGrade;
    //    cout << "\nPast Exam Grade: " << mainArr[p].pExamGrade << "\nGPA: " << mainArr[p].GPA << "\n\n";
  };
};

//void sort(int mainArr[], int ARR_LENGTH){
//  // set three variables needed
//  int x, j, value;
//  
//  // Star a for loop with a starting value of 1
//  for(j = 1; j < ARR_LENGTH; j++){
//    //set value to the current item in the mainArr
//    value = mainArr[j];
//    
//    // Make the smaller values move up in the array
//    for(x = j - 1; (x >= 0) && (mainArr[x] < value); x--){
//      mainArr[x+1] = mainArr[x];
//    };
//    
//    mainArr[x+1] = value;    //Put value into its proper location
//  };
//};
//
//double getAverage(int mainArr[], int ARR_LENGTH){
//  // declare a variable of type double that will represent the total combined grade
//  double total;
//  
//  // use a for loop to go through the length of the array
//  // add each int value to the double variable - (C++ will convert the int into doubles)
//  for(int x = 0; x < ARR_LENGTH; x++){
//    total += mainArr[x];
//  }
//  //end for loop
//  
//  // return the average which is the total divided by the # of items mainArr holds
//  return total/ARR_LENGTH;
//};