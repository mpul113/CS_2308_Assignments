#include<iostream>
#include<iomanip>
using namespace std;

#include"Queue.h"



void Blep() {

  Queue Blerp;

  cout << Blerp.size() << endl;

  Blerp.enqueue("Blerp???");

  cout << Blerp.dequeue() << endl;

  cout << Blerp.size() << endl;



}


int main() {

  Blep();

}
