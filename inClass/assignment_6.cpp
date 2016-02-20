//
//  Homework_6.cpp
//  homework #6
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
#include <vector>
using std::vector;
using namespace std;

void display(const vector<int>& data){
  cout << "Vector Contents: (";
  for (unsigned int i = 0; i < data.size(); i++) {
    if(i == data.size()-1){
      cout << data[i];
    } else {
      cout << data[i] << ",";
    }
  }
  cout << ")\n";
}

void val_in_pos(int pos, const vector<int>& data){
  try{
    
    if(data.size() < pos+1){
      throw "position specified is too big!   |   ";
    } else {
      cout << "\nValue in Position " << pos << ": " << data.at(pos) << "   |   "; // Could also do 'data[pos]'
    }
    
  } catch(const char *err){ cout << "\nERROR: " << err; }
  
  display(data);
}

int main() {
  vector<int> data;
  
  cout << "Inserting 7 in position 1:\n";
  data.insert(data.begin() + 0, 7);
  display(data);
  
  cout << "\nInserting 4 in position 0:\n";
  data.insert(data.begin() + 0, 4);
  display(data);
  
  val_in_pos(1, data);
  
  cout << "\nInserting 2 in position 2:\n";
  data.insert(data.begin() + 2, 2);
  display(data);
  
  val_in_pos(3, data);  // Supposed to put out 'error'
  
  cout << "\nErasing value in position 1:\n";
  data.erase(data.begin() + 1);
  display(data);
  
  cout << "\nInserting 5 in position 1:\n";
  data.insert(data.begin() + 1, 5);
  display(data);
  
  cout << "\nInserting 3 in position 1:\n";
  data.insert(data.begin() + 1, 3);
  display(data);
  
  cout << "\nInserting 9 in position 4:\n";
  data.insert(data.begin() + 4, 9);
  display(data);
  
  val_in_pos(2, data);
  
  cout << "\nSetting value in position 3 to 8:\n";
  data.at(3) = 8;
  display(data);
  
  cout << "\n";
  return EXIT_SUCCESS;
}