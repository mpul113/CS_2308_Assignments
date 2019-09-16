// File Name: Queue.h
//
// Author: Mark Pulido
// Date: 4/20/2019
// Assignment Number: 6
// CS 2308.255 Spring 2019
// Instructor: Jill Seaman
//
// Class file for a Queue ADT

#include<cassert>
#include <string>
using namespace std;

class Queue {
private:
  // define a Node to store strings and any other memeber variables here
  struct Node {
    string data;
    Node* next;
  };

  Node* front;
  Node* rear;

public:
  Queue() { front = nullptr; rear = nullptr; }
  void enqueue(string);
  string dequeue();
  bool isEmpty() { return (front == nullptr); }
  int size();  //returns the number of elements in the queue
};

//***********************************************************
// Queue::enqueue: Adds a node to the LL queue
//
// newNew: Value, string, that placed into the node
// 
// 
// returns: Nothing, is void
//***********************************************************
void Queue::enqueue(string newNew) {

  Node* temp = new Node;
  temp->data = newNew;
  temp->next = NULL;

  if (front == nullptr) {
    front = temp;
    rear = temp;
  }
  else {
    rear->next = temp;
    rear = temp;
  }
}

//***********************************************************
// Queue::dequeue: returns the value of the node and removes
// it from the queue (LIFO order)
// 
// 
// 
// returns: value of the node
//***********************************************************
string Queue::dequeue() {

  assert(!isEmpty());

  string value = front->data;

  Node* p = front;
  front = front->next;
  delete p;

  return value;
}

//***********************************************************
// Queue::size: Counts the total amount of nodes in the Queue
// LL.
// 
// 
// 
// returns: Total amount of nodes in the Queue
//***********************************************************
int Queue::size() {

  int total = 0;

  Node* p = front;
  
  while(p) {
    total++;
    p = p->next;
  }
  
  return total;
}
