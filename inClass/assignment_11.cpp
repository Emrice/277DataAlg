//
//  assignment_11.cpp
//  assignment #11
//
//  Created by Bernin A. Uben on 5/3/16.
//  Copyright © 2016 Bernin A. Uben. All rights reserved.
//
//  Create a trie data structure which can handle the following text:  "I like food". The user will enter the text.
//  After you build the trie, allow the user to enter a single word and determine whether or not it was in the original text.
//  You should provide 2 functions:
//    1) receive the text and build the trie;
//    2) receive a word and determine whether it exists within the text.
//

#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

class Node {
private:
  char nVal;
  bool nMarker;
  vector<Node*> cChildren;
  
public:
  Node() { nVal = ' '; nMarker = false; }
  Node* getChild(char cChar);
  
  char val() { return nVal; }
  void setVal(char cChar) { nVal = cChar; }
  
  bool wMark() { return nMarker; }
  void setwMark() { nMarker = true; }
  void appendChild(Node* child) { cChildren.push_back(child); }
  vector<Node*> children() { return cChildren; }
};

class Trie {
private:
  Node* root;
  
public:
  Trie() { root = new Node(); }
  void insert(string sStr);
  bool search(string sStr);
};

// Test program
int main() {
  int answer = 0;
  string again = "y", phrase;
  Trie* trie = new Trie();
  
  cout << "Trie Program\n";
  while (again == "y"){
    printf ("%s", "Options\n");
    printf ("%5s", "1) Insert\n");
    printf ("%5s", "2) Search\n");
    printf ("%5s", "3) Exit\n");
    cout << "Please enter the number correlating to an option:"; cin >> answer;
    
    switch(answer){
      case 1:
        cout << "Enter something to add to the Trie:"; cin.ignore(); getline(cin, phrase);
        trie->insert(phrase); cout << "Added '" + phrase + "' into the Trie! :D\n\n";
        break;
      case 2:
        cout << "Enter something to search the Trie:"; cin.ignore(); getline(cin, phrase);
        if (trie->search(phrase)){
          cout << "'" + phrase + "' has been found in the Trie! :D\n\n";
        } else {
          cout << "Sorry, '" + phrase + "' wasn't found in the Trie! D:\n\n";
        }
        break;
      case 3:
        cout << "\n\n\n\n\n\n\nTerminating...\n"; return 0;
      default: cout << "Sorry thats not an option. Try again.\n"; break;
    }
  }
}

Node* Node::getChild(char cChar) {
  for (int x = 0; x < cChildren.size(); x++){
    Node* cNode = cChildren[x];
    if (cNode->val() == cChar) { return cNode; }
  }
  return NULL;
}

void Trie::insert(string sStr){
  Node* current = root;
  
  if (sStr.length() == 0){ current->setwMark(); return; }
  
  for (int x = 0; x < sStr.length(); x++){
    Node* child = current->getChild(sStr[x]);
    if (child != NULL){
      current = child;
    } else {
      Node* cNode = new Node();
      cNode->setVal(sStr[x]);
      current->appendChild(cNode);
      current = cNode;
    }
    if (x == sStr.length() - 1){ current->setwMark(); }
  }
}

bool Trie::search(string sStr){
  Node* current = root;
  while (current != NULL){ //STOP
    for (int x = 0; x < sStr.length(); x++){
      Node* cNode = current->getChild(sStr[x]);
      if (cNode == NULL) { return false; }
      current = cNode;
    }
    bool retVal = (current->wMark()) ? true : false;
    return retVal;
  }
  return false;
}