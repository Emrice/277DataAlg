//
//  Assignment_6.cpp
//  Assignment #6
//
//  Created by Bernin A. Uben on 2/20/16.
//  Copyright © 2016 Bernin A. Uben. All rights reserved.
//
//  Using the set of operations in my slide on Vectors (L9),
//  Write a C++ program based on the STL vector, to process each operation in the sequence shown.
//  After each operation, print the operation and the result, in a manner similar to my slide.
//  I have provided you with the results you should be getting.
//

#include <iostream>
#include <vector>     // Needed for Vector to work
using std::vector;    // Needed for Vector to work
using namespace std;  

void display(const vector<int>& data){
  cout << "Vector Contents: (";
  for (unsigned int i = 0; i < data.size(); i++) { // Unsigned int is so that no negative numbers are possible
    if(i == data.size()-1){                        // If the current item in the vector is the biggest position in the vector
      cout << data[i];
    } else {
      cout << data[i] << ",";
    }
  }
  cout << ")\n";
}

void val_in_pos(int pos, const vector<int>& data){
  try{                                                    // Start of exception handling
    
    if(data.size() < pos+1){                              // If the size of the vector is less than the position the user wants
      throw "position specified is too big!   |   ";      // Throw the exception
    } else {
      cout << "\nValue in Position " << pos << ": " << data.at(pos) << "   |   "; // Could also do 'data[pos]'
    }
    
  } catch(const char *err){ cout << "\nERROR: " << err; } // Part of the exception
  
  display(data);                                          // Show the Vector after showing the POS
}

int main() {
  vector<int> data;                                       // Initialize an integer vector called data
  
  cout << "Inserting 7 in position 1:\n";
  data.insert(data.begin() + 0, 7);                       // Insert the number 7 in the 1st position in the vector
  display(data);                                          // Shows the contents of the vector its called on
  
  cout << "\nInserting 4 in position 0:\n";
  data.insert(data.begin() + 0, 4);                       // Insert the number 4, 0 positions away from the index of the vector
  display(data);                                          // Shows the contents of the vector its called on
  
  val_in_pos(1, data);                                    // Displays the value in position 1 and then displays the contents of the vector
  
  cout << "\nInserting 2 in position 2:\n";
  data.insert(data.begin() + 2, 2);                       // Insert the number 2, 2 positions away from the index of the vector
  display(data);                                          // Shows the contents of the vector its called on
  
  val_in_pos(3, data);                                    // Supposed to put out 'error' through exception handling
  
  cout << "\nErasing value in position 1:\n";
  data.erase(data.begin() + 1);                           // Erase the number in the position 1
  display(data);                                          // Shows the contents of the vector its called on
  
  cout << "\nInserting 5 in position 1:\n";
  data.insert(data.begin() + 1, 5);                       // Insert the number 5, 1 positions away from the index of the vector
  display(data);                                          // Shows the contents of the vector its called on
  
  cout << "\nInserting 3 in position 1:\n";
  data.insert(data.begin() + 1, 3);                       // Insert the number 3, 1 positions away from the index of the vector
  display(data);                                          // Shows the contents of the vector its called on
  
  cout << "\nInserting 9 in position 4:\n";
  data.insert(data.begin() + 4, 9);                       // Insert the number 9, 4 positions away from the index of the vector
  display(data);                                          // Shows the contents of the vector its called on
  
  val_in_pos(2, data);                                    // Displays the value in position 2 and then displays the contents of the vector
  
  cout << "\nSetting value in position 3 to 8:\n";
  data.at(3) = 8;                                         // Set the number in position 3 to 8 (2 -> 8)
  display(data);                                          // Shows the contents of the vector its called on
  
  cout << "\n";
  return EXIT_SUCCESS;
}