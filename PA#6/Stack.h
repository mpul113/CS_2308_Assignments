// File Name: Stack.h
//
// Author: Mark Pulido
// Date: 4/20/2019
// Assignment Number: 6
// CS 2308.255 Spring 2019
// Instructor: Jill Seaman
//
// Class file which defines a linked list Stack.

#include<cassert>
#include <string>
using namespace std;

class Stack {
private:
  // define a Node to store strings and the head or top variable here
  struct Node
  {
    string data;
    Node* next;
  };

  Node* head;

public:
  Stack() { head = NULL; }
  void push(string x) ;
  string pop() ;
  bool isEmpty() { return (head == NULL); }
};

//***********************************************************
// Stack::push: Pushes a new node onto the stack.
//
// newNew: value being added into the node
//
//
// returns: Nothing, is void
//***********************************************************
void Stack::push(string newNew) {

  Node* temp = new Node;
  temp->data = newNew;
  temp->next = nullptr;

  temp->next = head;
  head = temp;
}

//***********************************************************
// Stack::pop: Pops the node from the stack
//
//
//
// 
// returns: The value in the node.
//***********************************************************
string Stack::pop() {

  assert(!isEmpty());
  
  string value = head->data;
  Node* p = head;
  head = head->next;
  delete p;

  return value;
}

