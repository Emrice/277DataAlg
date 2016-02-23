//
//  Homework_8.cpp
//  Homework #8
//
//  Created by Bernin A. Uben on 3/16/16.
//  Copyright © 2016 Bernin A. Uben. All rights reserved.
//
//  Write a program which will implement a queue to handle two types of transactions: enqueue and dequeue.
//  The activity to be simulated is contained in the Event List below. You can implement the queue as either an
//  array or a circularly-linked list, as you prefer. Whenever you process a dequeue, identify the number that was
//  removed and show all of the numbers remaining in the queue.  Do not use the STL for this exercise.
//

#include <iostream>
using namespace std;

class Node {
public:
  int elem;
  Node* next;
};

class Queue {
  Node* head;
  Node* back;
  int count;
    
public:
  Queue(){
    head = NULL;
    back = NULL;
    count = 0;
  }
  
  void  enqueue(int);
  int   dequeue();
  int   front();
  int   size()  { return count; }
  bool  empty() { return count == 0 ? true : false; }
};

class EmptyQException {
public:
  EmptyQException() { cout << "Queue empty" << endl; } // constructor that throws the execption when the class is called
};

int main() {
  Queue queue;
  if (queue.empty()){ cout << "Queue is empty\n\n"; }

  queue.enqueue(6); cout << "Enqueue: 6\nSize of queue = " << queue.size() << "\n\n";
  queue.enqueue(4); cout << "Enqueue: 4\nSize of queue = " << queue.size() << "\n\n";
  queue.enqueue(7); cout << "Enqueue: 7\nSize of queue = " << queue.size() << "\n\n";
  
  cout << "Dequeue: " << queue.dequeue() <<"\nSize of queue = " << queue.size() << "\n\n";
  cout << "Dequeue: " << queue.dequeue() <<"\nSize of queue = " << queue.size() << "\n\n";
  
  queue.enqueue(7); cout << "Enqueue: 7\nsize of queue = " << queue.size() << "\n\n";

  cout << "Dequeue: " << queue.dequeue() << "\nSize of queue = " << queue.size() << "\n\n";
  cout << "Dequeue: " << queue.dequeue() << "\nSize of queue = " << queue.size() << "\n\n";
}

int Queue::front(){
  if (!empty()) {
    throw new EmptyQException();
  } else {
    return head->elem;
  }
}

void Queue::enqueue(int element) {
  Node* cNode = new Node();     // Create a new node
  cNode->elem = element;
  cNode->next = NULL;
  
  if (empty()) {
    head = back = cNode;
  } else {
    back->next = cNode;         // Append to the list
    back = cNode;
  }
  count++;
}

int Queue::dequeue() {
  if (empty()) { throw new EmptyQException; }
  Node* cNode = head;
  int rNum = head->elem;
  
  head = head->next;        // Move the head pointer to next node
  count--;
  delete cNode;
  return rNum;
}
