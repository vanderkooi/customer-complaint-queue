// File:        a1simpledriver.cpp
// Author:      (your name here) / Geoffrey Tien
// Date:        2016-05021
// Description: Basic test driver for CPSC 221 assignment #2
//              This file tests some functions of the CCQueue and LinkedList classes of assignment #2.
//              Note that only functions which are called will be compiled, therefore you must
//                ensure that every function in your classes is called at least once.
//              Not all special cases have been tested; you will be responsible for adding
//                your own test code and function calls to this file in order to thoroughly
//                test all general and boundary cases for your functions.
//              In general, please ensure that you test:
//               1. invalid parameter(s)
//               2. valid parameter(s), boundary case
//               3. valid parameter(s), general case

#include <cstdlib>
#include <iostream>
#include <string>

#include "ccqueue.h"
#include "linkedlist.h"
#include "ticket.h"

using namespace std;

// forward function declarations
void LLTest();
void CCQTest();

// program entry point
int main()
{
  cout << "Entering LinkedList test function... " << endl;
  LLTest();
  cout << "... LinkedList test function complete!\n" << endl;

  cout << "Entering CCQueue test function... " << endl;
  CCQTest();
  cout << "... CCQueue test function complete!\n" << endl;

#ifdef _WIN32
  system("pause");
#endif
  return 0;
}

void LLTest()
{
  // default constructor, InsertFront, InsertBack, ElementAt
  LinkedList<int> lla;
  lla.InsertFront(5);
  lla.InsertBack(10);
  try
  {
  cout << "lla contains " << lla.ElementAt(100) << " at index 0." << endl;
}
catch (std::out_of_range e)
  {
    cout << "Exception in RemoveAt(): " << e.what() << endl;
  }


  // copy constructor, InsertAt, RemoveAt (with exception)
  LinkedList<int> llb(lla);
  llb.InsertAt(7, 1);
  try
  {
    int temp = llb.RemoveAt(12345);
    cout << temp << endl;
  }
  catch (std::out_of_range e)
  {
    cout << "Exception in RemoveAt(): " << e.what() << endl;
  }

  // assignment operator, IsEmpty, Size, RemoveDuplicates, Contains
  LinkedList<int> llc;
  if (llc.IsEmpty())
    cout << "llc is empty." << endl;
  else
    cout << "llc is not empty." << endl;
  llc = lla;
  llc.InsertBack(13);
  llc.InsertBack(13);
  llc.InsertBack(13);
  cout << "llc contains " << llc.Size() << " items." << endl;
  llc.RemoveDuplicates();
  if (llc.Contains(10))
    cout << "10 found in llc." << endl;
  else
    cout << "10 not found in llc." << endl;
  if (llc.Contains(13))
    cout << "13 found in llc." << endl;
  else
    cout << "13 not found in llc." << endl;
  llb.Append(lla);
  cout << "lla contains " << lla.Size() << " items, "
       << "llb contains " << llb.Size() << " items." << endl;

  LinkedList<int> lld;
  lld.InsertFront(4);
  lld.InsertBack(2);
  lld.InsertBack(1);
  lld.InsertBack(4);
  cout << lld.ElementAt(0) << endl << lld.ElementAt(1) << endl << lld.ElementAt(2) << endl << lld.ElementAt(3) << endl;
  lld.RemoveDuplicates();
  cout << lld.ElementAt(0) << endl << lld.ElementAt(1) << endl << lld.ElementAt(2) << endl;
  cout << lld.Size() << endl;
}

void CCQTest()
{
  CCQueue ccq;
  try {
    ccq.Service();
  }
  catch (std::logic_error e) {
    cout << "Exception in Service(): " << e.what() << endl;
  }
  ccq.Add("Alrikr", "Video card smoked");
  ccq.Add("Bjornstjerne", "Cable is wrong colour, computer not colour coordinated. Worst day ever");
  ccq.Add("Cyprianus", "Still lost game after consuming energy drink");
  ccq.Add("Dietrich", "Order not received");
  ccq.Add("Elisaeus", "Box says 1TB, only 931GB formatted");
  ccq.Add("", "ba ba");
  cout << "Size of ticket queue: " << ccq.Size() << endl;
  ccq.Service();
  ccq.MoveUp(1);
  ccq.MoveUp(0);
  ccq.MoveDown(2);
  cout << ccq.PrintStatus() << endl;
}
