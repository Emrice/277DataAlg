//
//  homework #1
//
//  Created by Bernin A. Uben on 1/21/16.
//  Copyright © 2016 Bernin A. Uben. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

struct date {
  int  month;
  int  day;
  int  year;
};

struct person {
  string  firstName;
  string  lastName;
};

struct Passenger {
  int     flightNum, ticketNumber;
  double  tPrice;
  string  seatLoc, freqFlyer;
  person  name;
  date    day;
};


int main(){
  Passenger jetBlue;
  string answer;
  
  cout << "Please enter the following information:\n\n";
  
  cout << "First Name:\n";
  cin >> jetBlue.name.firstName;
  
  cout << "Last Name:\n";
  cin >> jetBlue.name.lastName;
  
  cout << "Ticket Number:\n";
  cin >> jetBlue.ticketNumber;
  
  cout << "Are you a frequent flyer?('Yes' or 'No'):\n";
  cin >> jetBlue.freqFlyer;
  
  cout << "Ticket Price:\n";
  cin >> jetBlue.tPrice;
  
  cout << "Flight Number:\n";
  cin >> jetBlue.flightNum;
  
  cout << "Seat Location:\n";
  cin.ignore();
  getline(cin, jetBlue.seatLoc);
  
  cout << "\nFlight Date (Format: MM/DD/YYYY)\n";
  cout << "Month:\n";
  cin >> jetBlue.day.month;
  
  cout << "Day:\n";
  cin >> jetBlue.day.day;
  
  cout << "Year:\n";
  cin >> jetBlue.day.year;
  
  cout << "\n\n\nInformation:\n";
  cout << "--------------------------\n";
  cout << "Name:\n" << jetBlue.name.lastName << ", " << jetBlue.name.firstName << "\n\n";
  cout << "Ticket Number:\n" << jetBlue.ticketNumber << "\n\n";
  cout << "Ticket Price:\n$" << jetBlue.tPrice << "\n\n";
  cout << "Flight Number:\n" << jetBlue.flightNum << "\n\n";
  cout << "Seat Location:\n" << jetBlue.seatLoc << "\n\n";
  cout << "Flight Date:\n" << jetBlue.day.month << "-" << jetBlue.day.day << "-" << jetBlue.day.year << "\n\n";
  cout << "Frequent Flyer?\n" << jetBlue.freqFlyer << "\n\n";
  
  return 0;
}