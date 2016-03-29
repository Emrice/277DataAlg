//
//  Assignment_8.cpp
//  Assignment #8
//
//  Created by Bernin A. Uben on 3/21/16.
//  Copyright © 2016 Bernin A. Uben. All rights reserved.
// 
//  Finish the In-Class Assignment from the PPT slide
//  Should display 1)5  2)9  3)3  4)2  5)7  6)0  7)1  8)6  9)10
//

#include <iostream>
#include <string>
using namespace std;

class Node {    // Node class
  int   elem;
  Node* ParentNode;
  Node* SiblingNode;
  Node* LeafNode;

public:
  Node() { elem = NULL; ParentNode = NULL, SiblingNode = NULL, LeafNode = NULL; };
  int   getElem()       { return elem;        }
  Node* getParentNode() { return ParentNode;  }
  Node* getSiblingNode(){ return SiblingNode; }
  Node* getLeafNode()   { return LeafNode;    }
  
  void  setElem       (int data)    { elem = data;         }
  void  setParentNode (Node* PNode) { ParentNode = PNode;  }
  void  setSiblingNode(Node* SNode) { SiblingNode = SNode; }
  void  setLeafNode   (Node* LNode) { LeafNode = LNode;    }
};

class Tree {    // Tree class
  Node* root;
public:
  Tree() { root = NULL; }
  
  Node* getRoot(){ return root; }
  void  setRoot(Node* cNode){ root = cNode; }
  void  addRoot(int = 0, Node* Par = NULL, Node* Sib = NULL, Node* Leaf = NULL);
  Node* addNode(int = 0, Node* par = NULL, Node* sib = NULL, Node* leaf = NULL);
  void Preorder(Node* node);
};

int main() {
  Tree* tree = new Tree();                // Create a new tree
  Node* zero;  Node* one; Node* two;      // Declare the Node pointer vars
  Node* three; Node* six; Node* seven;    // Declare the Node pointer vars
  Node* nine;  Node* ten;                 // Declare the Node pointer vars
  
  tree->addRoot(5);                       //  Create the root Node with a value of 5
  Node* root = tree->getRoot();           // Declare the Node pointer vars
  
  nine  = tree->addNode(9, root);
  six   = tree->addNode(6, root);
  ten   = tree->addNode(10,root);
  three = tree->addNode(3, nine);
  two   = tree->addNode(2, nine);
  seven = tree->addNode(7, nine);
  zero  = tree->addNode(0, seven);
  one   = tree->addNode(1, seven);
  
  root->setLeafNode(nine);
  nine->setParentNode(root);
  six->setParentNode(root);
  ten->setParentNode(root);
  
  nine->setSiblingNode(six);
  six->setSiblingNode(ten);
  
  nine->setLeafNode(three);
  three->setParentNode(nine);
  three->setSiblingNode(two);
  two->setSiblingNode(seven);
  
  two->setParentNode(nine);
  seven->setParentNode(nine);
  
  seven->setLeafNode(zero);
  zero->setParentNode(seven);
  zero->setSiblingNode(one);
  one->setParentNode(seven);

  cout << "Pre-Order Traversal\n" << endl;
  tree->Preorder(tree->getRoot());
  
  delete tree;
  return 0;
}

void Tree::addRoot(int value, Node* Par, Node* Sib, Node* Leaf) { //  Sets Root Node
  Node* cNode = new Node;       //  Create a new Node called cNode
  cNode->setElem(value);        //  Sets the elem value in cNode to the value passed in to the function
  cNode->setParentNode(Par);
  cNode->setSiblingNode(Sib);
  cNode->setLeafNode(Leaf);
  setRoot(cNode);               //  Sets the root pointer in tree to cNode
}

Node* Tree::addNode(int value, Node* PNode, Node* SNode, Node* LNode){
  Node* cNode = new Node;       //  Create a new Node called cNode
  cNode->setElem(value);        //  Sets the elem value in cNode to the value passed in to the function
  cNode->setParentNode(PNode);
  cNode->setSiblingNode(SNode);
  cNode->setLeafNode(LNode);
  return cNode;
}

void Tree::Preorder(Node* root){
  Node* cNode = root;
  int count = 1;
  
  if (cNode == root){ cout << "Getting Root of tree:\n" << count << ". " << cNode->getElem() << "\n\n"; count += 1; }
  
  while(10 > count){
    if (cNode->getLeafNode() != NULL){
      while (cNode->getLeafNode() != NULL){
        cNode = cNode->getLeafNode();
        cout << "Getting Leaf Node(s):\n";
        cout << count << ". " << cNode->getElem() << "\n\n";
        count += 1;
      }
    } else if (cNode->getSiblingNode() != NULL) {
      while (cNode->getSiblingNode() != NULL) {
        cNode = cNode->getSiblingNode();
        cout << "Getting Sibling Node(s):\n";
        cout << count << ". " << cNode->getElem() << "\n\n";
        count += 1;
      }
    } else if (cNode->getSiblingNode() == NULL && cNode->getLeafNode() == NULL){
      cNode = root->getLeafNode();
      while (cNode->getSiblingNode() != NULL) {
        cNode = cNode->getSiblingNode();
        cout << "Getting Sibling Node(s):\n";
        cout << count << ". " << cNode->getElem() << "\n\n";
        count += 1;
      }
    }
  }
}
