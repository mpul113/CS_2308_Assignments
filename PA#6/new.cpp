#include<iostream>
using namespace std;


int main() {

  int a = 4;
  int* test = &a;

  cout << a << endl;
  cout << *test << endl;

  *test = 5;

  cout << a << endl;



}
