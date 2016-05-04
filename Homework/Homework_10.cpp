//
//  Homework_10.cpp
//  Homework #10
//
//  Created by Bernin A. Uben on 3/30/16.
//  Copyright © 2016 Bernin A. Uben. All rights reserved.
//
//  An airline has an algorithm to determine the priority of passengers who are wait-listed for a flight.
//  It calculates a priority key based upon (1) frequent flyer status, (2) price paid for the ticket and (3) arrival time at the gate.
//  The lower the key value, the higher placed the passenger is in the queue.  The calculation is as follows:
//  - If frequent flyer status is ‘NONE’, add 40 to priority key.  If frequent flyer status is ‘SLVR’, add 30 to priority key.
//    If frequent flyer status is ‘GOLD’, add 20 to priority key.  If frequent flyer status is ‘PLAT’, do not add anything to priority key.
//  - If price paid for the ticket is $500 or more, do not add anything to the priority key. Otherwise, points are accumulated for every drop in price.
//    Each price range is $49.  For every drop between $1 and $49 dollars, add 5 to the priority key.
//    For example, if the ticket price was $310, add 20 points to the priority key.
//  - The gate is considered to be open 1 hour prior to the flight. If the passenger is 60 minutes early, no points are added.
//    For each minute closer to the flight time, add 1 point to the priority key.
//  Create a priority queue using a do-it-yourself doubly linked list (do not use the queue STL).
//  You may treat it as either sorted or unsorted as you choose.  However, document your choice at the beginning of the program.
//  Provide for user input of passenger last name, frequent flyer status, price paid and number of minutes prior to departure time arrival.
//  Test Data: 1 Jones GOLD 415 40 4 1 Martinez SLVR 500 60 4 1 Smith PLAT 500 55 4 1 Uben NONE 0 0 4
//

#include <iostream>
#include <string>
using namespace std;

class Node {
  int    priority;
  int    arrivalTime;
  int    ticketPrice;
  string lName;
  string flyStatus;
  Node*  next;
  
public:
  int    getTime()    { return arrivalTime; }
  int    getPrice()   { return ticketPrice; }
  int    getPriority(){ return priority; }
  Node*  getNext()    { return next; }
  string getLName()   { return lName; }
  string getStatus()  { return flyStatus; }
  
  void setTime(int mTime)         { arrivalTime = mTime; }
  void setPriority(int mPriority) { priority = mPriority; }
  void setPrice(int mPrice)       { ticketPrice = mPrice; }
  void setNext(Node* mNext)       { next = mNext; }
  void setLName(string mLName)    { lName = mLName; }
  void setStatus(string mStatus)  { flyStatus = mStatus; }
};

class pQueue {
  Node* head;
public:
  pQueue()    { head = NULL; }
  void min();
  void insert();
  void removeMin();
  void displayPQ();
  void dequeueInOrder();
  bool empty() { bool rVal = head == NULL ? true : false; return rVal; }
};

int calculatePriority(int, string, int);

int main() {
  pQueue flightList;
  cout << "PRIORITY QUEUE TYPE: SORTED\n";

  while(true){
    int answer;
    cout << "OPTIONS:\n";
    cout << "1) Add New Passenger ('Insert()')\n";
    cout << "2) Show All Passengers\n";
    cout << "3) Show Passenger With Top Priority ('min()')\n";
    cout << "4) Show All Passengers without DELETE\n";
    cout << "5) Exit\nChoice:";
    cin >> answer;
    
    switch (answer) {
      case 1: flightList.insert();
        break;
      case 2: flightList.dequeueInOrder();
        break;
      case 3: flightList.min();
        break;
      case 4: flightList.displayPQ();
        break;
      case 5: exit(EXIT_SUCCESS);
        break;
      default: cout << "Not an option, sorry. Try again:\n\n";
        break;
    }
  }
}

void pQueue::min(){
  Node* cNode = head;
  cout << "Passenger Name: " << cNode->getLName() << "\n";
  cout << "Passenger Priority: " << cNode->getPriority() << "     STATUS: " << cNode->getStatus() << "\n";
  cout << "Ticket Price: $" << cNode->getPrice() << "\n";
  cout << "Minutes Prior to Departure: " << cNode->getTime() << " minutes\n\n";
}

void pQueue::removeMin(){
  if (empty()){
    cout << "Priority Queue empty, nothing to remove...\n\n"; return;
  } else {
    cout << "Removing: " << head->getLName() << " with priority of " << head->getPriority() << "...\n\n";
    Node* qNode = head;
    head = head->getNext();
    delete qNode;
    return;
  }
}

void pQueue::displayPQ(){
  Node* cNode = head;
  
  while(cNode != NULL){
    cout << "\nBOARDING:\n";
    cout << "Passenger Name: " << cNode->getLName() << "\n";
    cout << "Passenger Priority: " << cNode->getPriority() << "     STATUS: " << cNode->getStatus() << "\n";
    cout << "Ticket Price: $" << cNode->getPrice() << "\n";
    cout << "Minutes Prior to Departure: " << cNode->getTime() << " minutes\n\n";
    cNode = cNode->getNext();
    //Node* cNode = head; || removeMin(); // this is for when were certain that the program runs and we want to board("dequeue") all the passengers in the queue
  }
}

void pQueue::dequeueInOrder(){
  Node* cNode = head;
  if( head == NULL){ cout << "\nIts queue is empty.\n\n"; return; }
  
  while(cNode != NULL){
    cout << "\nBOARDING:\n";
    cout << "Passenger Name: " << cNode->getLName() << "\n";
    cout << "Passenger Priority: " << cNode->getPriority() << "     STATUS: " << cNode->getStatus() << "\n";
    cout << "Ticket Price: $" << cNode->getPrice() << "\n";
    cout << "Minutes Prior to Departure: " << cNode->getTime() << " minutes\n\n";
    cNode = cNode->getNext();
    removeMin();
  }
}

int calculatePriority(int price, string status, int time){
  int priorityTotal = 0;
  
  if (status == "NONE")    { priorityTotal += 40; cout << "Passenger frequent flyer status is 'NONE'.\nAdding 40 points to priority.\nPriority: " << priorityTotal << "\n\n"; }
  else if(status == "SLVR"){ priorityTotal += 30; cout << "Passenger frequent flyer status is 'SLVR'.\nAdding 30 points to priority.\nPriority: " << priorityTotal << "\n\n"; }
  else if(status == "GOLD"){ priorityTotal += 20; cout << "Passenger frequent flyer status is 'GOLD'.\nAdding 20 points to priority.\nPriority: " << priorityTotal << "\n\n"; }
  else if(status == "PLAT"){ cout << "Passenger frequent flyer status is 'PLAT'.\nNot adding any 'priority' points.\nPriority: " << priorityTotal << "\n\n"; }
  
  if (price < 499){
    double ePrice = 500 - price;
    while (ePrice >= 0){
      cout << ePrice << " - 49 = ";
      priorityTotal += 5;
      ePrice -= 49;
      cout << ePrice << "\n";
      cout << "New total of " << priorityTotal << "\n";
    }
    cout << "\n";
  } else { cout << "No priority penalty for ticket price.\n\n"; }
  
  if (60 > time){
    cout << "Adding " << (60 - time) << " a priority point for each minute after gate opens. Total: " << priorityTotal << ".\n";
    priorityTotal += (60 - time);
  } else {
    cout << "No penalty for being at least an hour early.\nPriority Total: " << priorityTotal << "\n";
  }
  return priorityTotal;
}

void pQueue::insert(){
  int    minutes, price, nPriority;
  Node*  cNode = new Node;
  string fName, lName, status;
  
  cout << "Enter Passenger's Last Name: ";                               cin >> lName;
  cout << "Enter Passenger's Frequent Flyer Status: ";                   cin >> status;
  cout << "Enter Passenger's Ticket Price(Enter number without '$'): ";  cin >> price;
  cout << "Enter how minutes early the passenger is for their flight: "; cin >> minutes;
  
  cNode->setLName(lName);
  cNode->setStatus(status);
  cNode->setPrice(price);
  cNode->setTime(minutes);
  
  cout << "\n\nCalculating " << fName << " " << lName << "'s flight priority...\n";
  nPriority = calculatePriority(price, status, minutes);
  cout << "Total of " << nPriority << " points.\n\n";
  cNode->setPriority(nPriority);
  
  Node* qNode = head;
  Node* prevNode = NULL;
  
  if( head == NULL ){
    head = cNode;
    cout << "List is empty.\nAdding " << fName << " " << lName << " to the top of the list.\n\n";
  } else {
    if( nPriority < head->getPriority()){
      cNode->setNext(head);
      head = cNode;
    } else {
      while( nPriority >= qNode->getPriority() ){
        if ( qNode->getNext() != NULL ){
          cout << "Passenger " << qNode->getLName() << ", with priority "<< qNode->getPriority() << ", is higher than " << nPriority << ".\n\n";
          prevNode = qNode;
          qNode = qNode->getNext();
        } else {
          break;
        }
      }
      if ( qNode->getNext() == NULL ){
        if (nPriority > qNode->getPriority()){
          qNode->setNext(cNode);
        } else {
          prevNode->setNext(cNode);
          cNode->setNext(qNode);
        }
      } else if ( qNode->getNext() != NULL ){
        if (nPriority > qNode->getPriority()){
          qNode->setNext(cNode);
        } else {
          prevNode->setNext(cNode);
          cNode->setNext(qNode);
        }
      }
    }
  }
}