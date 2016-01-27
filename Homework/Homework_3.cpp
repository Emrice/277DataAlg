//
//  main.cpp
//  HW3
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
    void getTicket();
    void cancelTicket();
    void changeSeat();
    
private:
    char status;
    int ticketNum;
    int flightNumber;
    float ticketPrice;
    Date flyDate;
    string seatLocation;
    string freqFlyerNumber;
};


int main() {
    
    Passenger bob;
    bob.initialize();
    bob.getInfo();
    
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
    
    cout << "Status(‘T’ = ticketed, ‘H’ = on hold, ‘C’ = cancel): ";
    cin >> status;
}

void Passenger::getInfo(){
    cout << "\n\n\n\n\n:::::::::::::::::::: PASSENGER INFORMATION ::::::::::::::::::::\n\n";
    cout << "Name: " << name.last << ", " << name.first << "          Date of Birth: ";
    cout << dob.month << "-" << dob.day << "-" << dob.year << endl;
    cout << "Party Type: " << partyType << "               Phone Number: " << pNumber << endl;
    cout << "Address: " << address.streetNumber << " " << address.streetName << " ";
    cout << address.city << ", " << address.state << " " << address.zipCode << "\n\n";
    
    cout << "Ticket Number: " << ticketNum << "               Flight Number: " << flightNumber << endl;
    cout << "Ticket Price: $" << ticketPrice << "               Seat Location: " << seatLocation << "\n";
    cout << "Frequent Flyer Number: " << freqFlyerNumber <<  "          Status: " << status << "\n";
    cout << "Day of Departure: " << flyDate.month << "/" << flyDate.day << "/" << flyDate.year << "\n\n";
}






// cout << "" << ;