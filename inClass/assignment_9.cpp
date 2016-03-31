//
//  Assignment_9.cpp
//  Assignment #9
//
//  Created by Bernin A. Uben on 3/31/16.
//  Copyright © 2016 Bernin A. Uben. All rights reserved.
//
//  Build a binary search tree.  Do not use an STL.
//  Allow the user to enter any numerical key and store it properly in the tree, along with the key there are 2 fields called name and balance due.
//  1.  Let the user enter the 3 pieces of information for as many keys as desired.
//  2.  Let the user see the results of having built the tree by providing an in-order search.
//  3.  Let the user retrieve one node based on entry of a key.  Return the key and the additional 2 fields.
//      Make sure you can deal with the situation where the key is not found.
//

#include <iostream>
#include <cstdlib>
using namespace std;

class Node {
  int    pos;
  Node*  left;
  Node*  right;
  string balance;
  string name;
  friend class BTree;
};

class BTree {
  Node* root;
  
public:
  BTree() { root = NULL; }
  void search(int);
  void inorder(Node*);
  void insert(int, string, string);
  void displayInOrder() { inorder(root); }
  bool isEmpty()  { return root == NULL; }
};


int main() {
  BTree bank;
  int answer;
  
  while(1) {
    cout << "\n\n";
    cout << " BTree Options:\n";
    cout << " ----------------------\n";
    cout << " 1. Insertion w/ Position\n";
    cout << " 2. In-Order Traversal\n";
    cout << " 3. Search w/ Position\n";
    cout << " 4. Exit\n";
    cout << " Enter Choice: ";
    cin >> answer;
    
    int num; string balance, name;
    switch(answer){
      case 1: cout << "\n Enter Numerical Position: "; cin >> num;
        cout << " Enter Name: ";               cin.ignore();  getline(cin, name);
        cout << " Enter Balance Due: $";       cin >> balance;
        bank.insert(num, balance, name);       break;
        
      case 2: cout << "\n In-Order Traversal  \n";
        cout << " ------------------- \n";
        bank.displayInOrder();     break;
        
      case 3: cout<<"\n Enter Position: "; cin >> num;
        bank.search(num);          break;
      case 4: return 0;
    }
  }
}

void BTree::inorder(Node* cNode) {
  if (cNode != NULL){
    if (cNode->left) { inorder(cNode->left); }
    cout << "\n " << cNode->pos << ". " << cNode->name << "\n";
    cout << " Balance Due: " << cNode->balance << "\n\n";
    if (cNode->right) { inorder(cNode->right); }
  } else {
    return;
  }
}

void BTree::insert(int d, string b, string n){ // Smaller Positions are placed to the left, Larger  Positions are placed to the right
  Node* newNode = new Node;
  Node* parent = NULL;
  
  newNode->pos = d;
  newNode->name = n;
  newNode->balance = b;
  newNode->left = NULL;
  newNode->right = NULL;
  
  if(isEmpty()){     // Checks if the tree is empty because there isn't a way to remove any nodes so an empty tree == new tree
    root = newNode;
  } else {
    Node* cNode = root;
    
    while (cNode) {  // It finds the parent for the current node to be added
      parent = cNode;
      cNode = (newNode->pos > cNode->pos) ? cNode->right : cNode->left;
    }
    
    if (newNode->pos < parent->pos) {
      parent->left = newNode;
    } else {
      parent->right = newNode;
    }
  }
}

void BTree::search(int searchPos) {
  if(isEmpty()) { cout << "\nList is empty!\n\n"; return; }
  Node* cNode = root;
  Node* parent = NULL;
  bool found = false;
  
  while(cNode != NULL && found == false) {
    if(cNode->pos == searchPos) {
      found = true;
      cout << "\n " << cNode->pos << ") " << cNode->name << "\n";
      cout << " Balance Due: " << cNode->balance << "\n\n";
      break;
    } else {
      parent = cNode;
      cNode = (searchPos > cNode->pos) ? cNode->right : cNode->left;
    }
  }
  
  if (!found) { cout << "\n Nothing in position " << searchPos << "!\n"; return; }
}
