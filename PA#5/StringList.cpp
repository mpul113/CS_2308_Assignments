// File Name: StringList.cpp
//
// Author: Mark Pulido
// Date: 4/10/2019
// Assignment Number: 5
// CS 2308.255 Spring 2019
// Instructor: Jill Seaman
//
// Class Member Functions for StringList.h

#include <iostream>
#include <iomanip>
#include <string>
#include "StringList.h"
using namespace std;

//***********************************************************
// StringList Constructor: Sets newly declared Linked List header.
// to null
// param-1: None
// param-2: None
// 
// returns: Nothing.
//***********************************************************
StringList::StringList() {

  head = nullptr;
}

//***********************************************************
// StringList Destructor: Destroys all nodes in Linked List.
// to null
// param-1: None
// param-2: None
// 
// returns: Nothing.
//***********************************************************
StringList::~StringList() {

  StringNode* p;
  StringNode* n;

  p = head;

  while (p) {
    n = p->next;
    delete p;
    p = n;
  }
}

//***********************************************************
// StringList::count: Counts number of nodes in list.
//
// param-1: None.
// param-2: None.
// 
// returns: (int) Sum of all nodes in list. 
//***********************************************************
int StringList::count() {

  StringNode* p = head;
  int sum = 0;
  
  while (p) {
    sum += 1;

    p = p->next;
  }

  return sum;
}

//***********************************************************
// StringList::push_front: Adds a new node to the front of the list.
//
// (string) newString: Input stored in the nodes data section (movie name).
// 
// 
// returns: Nothing
//***********************************************************
void StringList::push_front(string newString) {

  StringNode* newNode = new StringNode;
  newNode->data = newString;
  newNode->next = nullptr;

  newNode->next = head;
  head = newNode;
}

//***********************************************************
// StringList::push_back: Adds a new node to the back of the list.
//
// (string) newString: Input stored i nthe noeds data section (movie name).
// 
// 
// returns: Nothing
//***********************************************************
void StringList::push_back(string newString) {

  StringNode* newNode = new StringNode;
  newNode->data = newString;
  newNode->next = nullptr;

  if (head == nullptr) 
    head = newNode;
  else {    
    StringNode* p = head;

    while(p->next)
      p = p->next;

    p->next = newNode;
  }
}

//***********************************************************
// StringList::pop_front: Removes the first node in the list.
//
// param-1: None.
// param-2: None.
// 
// returns: Nothing
//***********************************************************
void StringList::pop_front() {

  StringNode* p = head;
  
  if(head) {
    head = head->next;
    delete p;
  }
  else
    cout << "The list is empty!" << endl;
}

//***********************************************************
// StringList::display: Traverses and displays nodes in list.
//
// param-1: None.
// param-2: None.
// 
// returns: Nothing
//***********************************************************
void StringList::display() {

  StringNode* p = head;
  while (p) {
    cout << p->data << endl;
    p = p->next;
  }
}

//***********************************************************
// StringList::remove: Removes designated (m) node by address.
//
// (StringNode*) m: Address of node wanted to be removed.
// 
// 
// returns: Nothing 
//***********************************************************
void StringList::remove(StringNode* m) {

  StringNode* p = head;
  StringNode* n = nullptr;
  
  while (p && p != m ) {
    n = p;
    p = p->next;
  }

  if (p) {
    if (p == head) {
      head = p->next;
      delete p;
    }
    else {
      n->next = p->next;
      delete p;
    }
  }
}

//***********************************************************
// StringList::maximum: Finds the maximum (Last in alphebetical order).
// node in list
// param-1: None.
// param-2: None.
// 
// returns: (StringList::StringNode*) Address of "max" node (refer above). 
//***********************************************************
StringList::StringNode* StringList::maximum() {
  
  StringNode* p = head;
  StringNode* n = head; // made n also head incase first node is already the largest value
  string max = p->data;
  
  while (p) {
    if (max < p->data){
      max = p->data;
      n = p;
    }
    
    p = p->next;
  }
  return n;
}

//***********************************************************
// StringList::sort: Sorts list by creating new list filled with maximums
// of old list. Then sets original head to newly created list.
// param-1: None.
// param-2: None.
// 
// returns: Nothing
//***********************************************************
void StringList::sort() {

  StringNode* sortHead  = nullptr;
  StringNode* max = nullptr;
  
  while (head) {
    max = maximum();
    
    StringNode* sortNode = new StringNode;
    sortNode->next = nullptr;
    sortNode->data = max->data;
  
    remove(max);

    sortNode->next = sortHead;
    sortHead = sortNode;
  }

  head = sortHead;
}
