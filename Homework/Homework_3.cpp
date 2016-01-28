//
//  main.cpp
//  homework #3
//
//  Created by Bernin A. Uben on 1/27/16.
//  Copyright © 2016 Bernin A. Uben. All rights reserved.
//
//  Textbook:  Read pages 26 – 38, 66 - 76, 78 - 80
//  Consider the Passenger data structure we discussed during the last class.
//  Instead of using “struct”, we will use object-oriented “class”.
//  Create a hierarchy of 3 classes to support “Party”, “Person” and “Passenger”, where each inherits from its parent.
//  The attributes that define a Party are:
//             -  Party Type Code (‘P’ = person, ‘O’ = organization)
//             -  Address (one large string)
//             -  Phone Number (one string)
//  The attributes that define a Person are:
//             -  Date of Birth
//             -  First Name
//             -  Last Name
//  The attributes that define a Passenger are:
//             -  Ticket Number
//             -  Frequent Flyer Number (valid alphanumeric or N/A)
//             -  Ticket Price
//             -  Flight Number
//             -  Seat Location
//             -  Flight Date
//             -  Status (‘T’ = ticketed, ‘H’ = on hold, ‘C’ = cancel
//  The following functions are to be implemented:
//  (1)   Purchase a ticket.  This will create a passenger as an inheritance of both person and party.
//  (2)   Change a passenger’s seat location.  Assume that all seats are available.
//  (3)   Cancel the ticket.
//  Provide a user interface via Cout and Cin to obtain the information.
//  Print a confirmation when the transaction is complete.
//
//  Initialize Test Data: P 201-948-4834 43
//                        KappaPride Street
//                        Rockland
//                        NY 10049 John S117 03 07 2511 604.50 00000117 343117 A1 117 10 27 2558 T
//


#include <iostream>
#include <string>
using namespace std;
using std::string;


struct Name {
  string first;
  string last;
};

struct Date {
  int month;
  int day;
  int year;
};

struct Address {
  int streetNumber;
  string streetName;
  string city;
  string state;
  string zipCode;
};

class Party {
protected:
  char partyType;
  Address address;
  string pNumber;
};

class Person: public Party {
protected:
  Name name;
  Date dob;
};

class Passenger: public Person {
public:
  void initialize();
  void getInfo();
  void cancelTicket();
  void changeSeat();
  string getName();
  bool isCanceled();
  
private:
  int ticketNum;
  int flightNumber;
  float ticketPrice;
  Date flyDate;
  string status;
  string seatLocation;
  string freqFlyerNumber;
} people[30];


int main() {
  string answer = "y";
  int option = 0, counter = 0, pNum = 0;
  
  while(answer == "y"){
    int value;
    
    if(counter == 0){
      cout << "Welcome to the program.\nTo begin, we will need some information.\n\n\n";
      people[counter].initialize();
      counter += 1;
    }
    
    if (counter > 0 ){
      cout << "\n::::: Options :::::\n1) Create a New Passenger\n2) Work with a passengers information\n";
      cin >> value;
    }
    
    if(value == 1 && counter > 0) {
      
      people[counter].initialize();
      counter += 1;
      
    } else if(value == 2 && counter > 0 ){
      
      cout << "\n::::: All Passengers :::::\n";
      for(int x = 0; x < counter;x++){
        if(people[x].isCanceled() == false){
          cout << x << ") "<< people[x].getName() << "\n";
        }
      }
      cout << "::::::::::::::::::::::::::\n";
      
      if( counter > 1 ){
        cout << "\nPick a passengers information to work with: ";
        cin >> pNum;
      }
      
      if (people[pNum].isCanceled()){
        cout << "That Persons ticket is canceled.\n\n";
      } else {
        cout << "\n\n::::: Options :::::\n1) Get all the passengers information\n2) Change the passengers ";
        cout << "seat location\n3) Cancel the passengers ticket\n";
        cout << "Option: ";
        cin >> option;
        
        switch (option){
          case 1:
            people[pNum].getInfo();
            break;
          case 2:
            people[pNum].changeSeat();
            break;
          case 3:
            people[pNum].cancelTicket();
            break;
          default: cout << "That isnt an option.\n";
            break;
        }
      }
    }
    
    if (counter <= 1){
      cout << "Do you want to do anything else? ('y' for Yes): ";
      cin >> answer;
    }
    
    if (answer != "y"){
      break;
    }
  }
  
  cout << "\n\n::::: Receipt :::::\n";
  for ( int e = 0; e < counter; e++){
    people[e].getInfo();
    cout << endl;
  }
  cout << "Terminating\n";
  
  return 0;
}



void Passenger::initialize(){
  cout << ":::::::::::::::::::: PARTY INFORMATION ::::::::::::::::::::\n\n";
  cout << "Party Type(‘P’ = person, ‘O’ = organization): ";
  cin >> partyType;
  
  cout << "Phone Number (Format: 'xxx-xxx-xxxx'): ";
  cin >> pNumber;
  
  cout << "::::: Party Address :::::\n";
  cout << "Street Number: ";
  cin >> address.streetNumber;
  
  cout << "Street Name: ";
  cin.ignore();
  getline(cin, address.streetName);
  
  cout << "City: ";
  getline(cin, address.city);
  
  cout << "State (Format: XX | Ex: NY, NY, PA): ";
  cin >> address.state;
  
  cout << "Zip Code: ";
  cin >> address.zipCode;
  
  cout << "\n\n\n\n:::::::::::::::::::: PASSENGER PERSONAL INFORMATION ::::::::::::::::::::\n\n";
  
  cout << "First Name: ";
  cin >> name.first;
  
  cout << "Last Name: ";
  cin >> name.last;
  
  cout << "\n:::::Date of Birth:::::\n";
  cout << "Month: ";
  cin >> dob.month;
  cout << "Day: ";
  cin >> dob.day;
  cout << "Year: ";
  cin >> dob.year;
  
  cout << "\n\n\n\n:::::::::::::::::::: PASSENGER FLIGHT INFORMATION ::::::::::::::::::::\n\n";
  
  cout << "Ticket Price: ";
  cin >> ticketPrice;
  
  cout << "Ticket Number: ";
  cin >> ticketNum;
  
  cout << "Flight Number: ";
  cin >> flightNumber;
  
  cout << "Seat Location: ";
  cin >> seatLocation;
  
  cout << "Frequent Flyer Number: ";
  cin >> freqFlyerNumber;
  
  cout << "\n::::: Flight Date :::::\n";
  cout << "Flight Month: ";
  cin >> flyDate.month;
  cout << "Flight Day: ";
  cin >> flyDate.day;
  cout << "Flight Year: ";
  cin >> flyDate.year;
  status = "T";
}

void Passenger::getInfo(){
  cout << "\n\n:::::::::::::::::::: PASSENGER INFORMATION ::::::::::::::::::::\n\n";
  cout << "Name: " << name.last << ", " << name.first << "          Date of Birth: ";
  cout << dob.month << "-" << dob.day << "-" << dob.year << endl;
  cout << "Party Type: " << partyType << "               Phone Number: " << pNumber << endl;
  cout << "Address: " << address.streetNumber << " " << address.streetName << " ";
  cout << address.city << ", " << address.state << " " << address.zipCode << "\n\n";
  
  cout << "Ticket Number: " << ticketNum << "               Flight Number: " << flightNumber << endl;
  cout << "Ticket Price: $" << ticketPrice << "               Seat Location: " << seatLocation << "\n";
  cout << "Frequent Flyer Number: " << freqFlyerNumber <<  "          Status: " << status << "\n";
  cout << "Day of Departure: " << flyDate.month << "/" << flyDate.day << "/" << flyDate.year << "\n";
  cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n";
}

string Passenger::getName() {
  return name.last + ", " + name.first;
}

void Passenger::changeSeat(){
  cout << "What seat do you want to exchange seat " << seatLocation << " for?: ";
  cin >> seatLocation;
}

void Passenger::cancelTicket(){
  string ans;
  
  cout << "Are you sure you want to cancel this ticket?('y' for yes):";
  cin >> ans;
  if ( ans == "y"){
    ticketPrice = 0;
    ticketNum = 0;
    flightNumber = 0;
    seatLocation = "N/A";
    flyDate.month = 0;
    flyDate.day = 0;
    flyDate.year = 0;
    status = "C"; // gives error if I do this while status is of type 'char'
  }
}

bool Passenger::isCanceled(){
  if(status == "C"){
    return true;
  } else {
    return false;
  }
}
