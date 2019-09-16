// File Name: Driver.cpp
//
// Author: Mark Pulido
// Date: 4/20/2019
// Assignment Number: 6
// CS 2308.255 Spring 2019
// Instructor: Jill Seaman
//
// Program that uses Queue ADT to simulate the management 
// of the line of people waiting to ride a roller coaster
// in an amusement park.

#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include"Queue.h"
using namespace std;

const int PARTIES = 100; // Worst Case Scenario of # of parties

//***********************************************************
// gatherInfo: Scans the input txt file for inforamtion
// (RC limit, Names of parties, number of people in each group,
// and finally the number of individial parties) 
// names: The array of group names
// numbers: The array of number of people in said group
// 
// returns the number of individual parties
//***********************************************************
int gatherInfo(string names[], int numbers[], int &limit) {

  int count = 0,
    i = 0;
  
  ifstream fin;
  fin.open("riders.txt");

  fin >> limit;
  
  while (fin >> names[i] >> numbers[i]) {
    i++;
    count++;
  }

  fin.close();
  
  return count;
}

//***********************************************************
// rollerCoasterFill: Fills the RC.
//
// rc is the queue of waiting people
// amount is the amount of people in the party
// name is the name of the party
// p is a pointer to the amount of passangers left
// returns: Nothining is void
//***********************************************************
void rollerCoasterFill (Queue &rc, int amount, string name, int* p) {

  string appendWord;
  int size = rc.size();
  
  for (int i = 1; i <= amount; i++) {
    appendWord = name  + " " + to_string(i);
	
    rc.enqueue(appendWord);

    // once a rider is placed into the rc que he/she is removed
    // from pool of total riders.
    --(*p);
  }
}

//***********************************************************
// rollerCoasterLaunch: Launches the RC when either full or
// no more passangers waiting to ride.
// rc is the queue of waiting people
// amount is the amount of people in the party
// name is the name of the party
// t is the pointer to amount of trains launched
// returns: Nothing, is void
//***********************************************************
void rollerCoasterLaunch(Queue &rc, int amount, string name, int* t) {

  int size = rc.size();

  (*t)++;
  
  cout << "Train #" << *t <<  endl;
  cout << "-------------" << endl;
    
  for (int i = 1; i <= size; i++)  
    cout << rc.dequeue() << endl;
  
  cout << endl;
}

//***********************************************************
// rollerCoasterQueue: Main algorithim for managing queue, checks
// to see if the people in the que and the incoming party is greater
// than the limit, if it is it launches a coaster, then fills the next
// but not before checking to see if the party is too large for the
// coaster limit. If not it fills one.
// Finally, checks to see if there is are anymore passangers to launch
// the final coaster.
//
// rc is the queue of waiting peole
// limit is the amount of people a single coaster can fit
// n is the array of people per party
// a is the array of party names
// t is the pointer to amount of trains launched
// returns: description of what function returns (if not void)
//***********************************************************
void rollerCoasterQueue(Queue &rc, int limit, int n[], string a[], int count, int* t) {    

  int passangers = 0;
  int* p = &passangers;

  // Calculates total amount of riders to be tracked
  // after they are placed into the rc queue
  for (int i = 0; i < count; i++)
    *p += n[i];

  // Loops through entire array of parties
  for (int i = 0; i < count; i++) {
    // Checking to see if incoming party is too large for avaliable remaining
    // seats, then if party is too large for coaster limit in general
    if ((rc.size() + n[i]) > limit){
      rollerCoasterLaunch(rc, n[i], a[i], t);
      
      if (n[i]  > limit) { 
	cout << "Sorry, party of " << a[i] << " " << n[i] << ", your group is too big "
	     << "please exit the line! \n\n";

	passangers -= n[i];
      }
      else
        rollerCoasterFill(rc, n[i], a[i], p);
    }
    // If not too large for coaster limit and availability it fills
    else
      rollerCoasterFill(rc, n[i], a[i], p);
    // Check for the final coaster to be launched by checking to see
    // if there are no more passangers and if the coaster isnt empty
    if (passangers == 0 && rc.size() != 0)
      rollerCoasterLaunch(rc, n[i], a[i], t);
  }			  
}

int main() {
  Queue rc;

  int limit,
    count = 0,
    riders = 0,
    trains = 0;

  int* t = &trains;
  string partyNames[PARTIES] = {};
  int partyNum[PARTIES] = {};

  count = gatherInfo(partyNames, partyNum, limit);

  // seperate calculation for total amount of riders
  for (int i = 0; i < count; i++)
    riders += partyNum[i];
  
  rollerCoasterQueue(rc, limit, partyNum, partyNames, count, t);
   
  cout << "Total Passangers: " << riders << endl;
  cout << "Total Trains: " << *t << endl;
}

