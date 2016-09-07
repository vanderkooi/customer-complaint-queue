// File:        a2gradingdriver.cpp
// Author:      Geoffrey Tien
// Date:        June 02, 2016
// Description: Grading driver for CPSC 221 assignment #2
//              Calls to test functions are on lines 71 to 121.
//              If any function causes a runtime crash, comment out the
//              call to the offending test function and recompile.
//              Repeat as necessary until a final score can be returned.

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

#include "ccqueue.h"
#include "linkedlist.h"
#include "ticket.h"

using namespace std;

// maximum test score declarations
const static double lltest1max = 3;
const static double lltest2max = 2;
const static double lltest3max = 3;
const static double lltest4max = 2;
const static double lltest5max = 4;
const static double lltest6max = 2.5;
const static double lltest7max = 2.5;
const static double lltest8max = 1;
const static double lltest9max = 1;
const static double ccqtest1max = 2;
const static double ccqtest2max = 3;
const static double ccqtest3max = 2;
const static double ccqtest4max = 2;

// forward function declarations
double LLTest1();
double LLTest2();
double LLTest3();
double LLTest4();
double LLTest5();
double LLTest6();
double LLTest7();
double LLTest8();
double LLTest9();
double CCQTest1();
double CCQTest2();
double CCQTest3();
double CCQTest4();

// program entry point
int main()
{
  double lltest1score = 0;
  double lltest2score = 0;
  double lltest3score = 0;
  double lltest4score = 0;
  double lltest5score = 0;
  double lltest6score = 0;
  double lltest7score = 0;
  double lltest8score = 0;
  double lltest9score = 0;
  double ccqtest1score = 0;
  double ccqtest2score = 0;
  double ccqtest3score = 0;
  double ccqtest4score = 0;

  // Test function calls
  // If any test function produces a runtime crash, comment out the line with the test function call
  // Recompile and run again
  cout << "Running linked list test 1: default constructor, InsertFront, InsertBack, Size, Contains, ElementAt...";
  lltest1score = LLTest1();
  cout << " done.\n" << endl;

  cout << "Running linked list test 2: InsertAt/RemoveAt/ElementAt exception cases...";
  lltest2score = LLTest2();
  cout << " done.\n" << endl;

  cout << "Running linked list test 3: InsertAt + InsertFront/Back...";
  lltest3score = LLTest3();
  cout << " done.\n" << endl;

  cout << "Running linked list test 4: RemoveAt (exception cases)...";
  lltest4score = LLTest4();
  cout << " done.\n" << endl;

  cout << "Running linked list test 5: RemoveAt (general cases) + InsertAt/Front/Back...";
  lltest5score = LLTest5();
  cout << " done.\n" << endl;

  cout << "Running linked list test 6: RemoveDuplicates...";
  lltest6score = LLTest6();
  cout << " done.\n" << endl;

  cout << "Running linked list test 7: Append...";
  lltest7score = LLTest7();
  cout << " done.\n" << endl;

  cout << "Running linked list test 8: Copy constructor...";
  lltest8score = LLTest8();
  cout << " done.\n" << endl;

  cout << "Running linked list test 9: Assignment operator...";
  lltest9score = LLTest9();
  cout << " done.\n" << endl;

  cout << "Running queue test 1: default constructor, Add, Size...";
  ccqtest1score = CCQTest1();
  cout << " done.\n" << endl;

  cout << "Running queue test 2: Service (exception + general)...";
  ccqtest2score = CCQTest2();
  cout << " done.\n" << endl;

  cout << "Running queue test 3: MoveUp + Add + Service...";
  ccqtest3score = CCQTest3();
  cout << " done.\n" << endl;

  cout << "Running queue test 4: MoveDown + Add + Service...";
  ccqtest4score = CCQTest4();
  cout << " done.\n" << endl;

  // compute total and maximum scores
  double testscoresum = lltest1score + lltest2score + lltest3score + lltest4score + 
                        lltest5score + lltest6score + lltest7score + lltest8score + lltest9score +
                        ccqtest1score + ccqtest2score + ccqtest3score + ccqtest4score;
  double testmax = lltest1max + lltest2max + lltest3max + lltest4max + 
                   lltest5max + lltest6max + lltest7max + lltest8max + lltest9max +
                   ccqtest1max + ccqtest2max + ccqtest3max + ccqtest4max;
  // format a string for summary output
  cout << "Test summary\n-------------------------------------------------------------" << endl;
  string summary;
  ostringstream oss;
  oss << "LLTest1: " << lltest1score << "/" << lltest1max << "\tLLTest2: " << lltest2score << "/" << lltest2max
      << "\tLLTest3: " << lltest3score << "/" << lltest3max << "\tLLTest4: " << lltest4score << "/" << lltest4max << endl
      << "LLTest5: " << lltest5score << "/" << lltest5max << "\tLLTest6: " << lltest6score << "/" << lltest6max
      << "\tLLTest7: " << lltest7score << "/" << lltest7max << endl
      << "LLTest8: " << lltest8score << "/" << lltest8max <<  "\tLLTest9: " << lltest9score << "/" << lltest9max << endl
      << "CCQTest1: " << ccqtest1score << "/" << ccqtest1max << "\tCCQTest2: " << ccqtest2score << "/" << ccqtest2max
      << "\tCCQTest3: " << ccqtest3score << "/" << ccqtest3max << "\tCCQTest4: " << ccqtest4score << "/" << ccqtest4max << endl
      << "-------------------------------------------------------------" << endl
      << "Total: " << testscoresum << "/" << testmax << endl;
  cout << oss.str() << endl;

#ifdef _WIN32
  system("pause");
#endif
  return 0;
}

// default constructor, IsEmpty, InsertFront, InsertBack, Size, Contains, ElementAt
double LLTest1()
{
  double score = 0;

  LinkedList<int> lla;
  if (lla.IsEmpty() && lla.Size() == 0 && !lla.Contains(12))
    score += 0.5;

  // InsertFront, empty list
  lla.InsertFront(12);
  if (!lla.IsEmpty() && lla.Size() == 1 && lla.Contains(12) && lla.ElementAt(0) == 12)
    score += 0.5;

  // InsertFront, general case
  lla.InsertFront(9);
  lla.InsertFront(8);
  lla.InsertFront(7);
  lla.InsertFront(9); // duplicate item, should be allowed
  if (lla.Size() == 5 && !lla.Contains(3) && lla.ElementAt(0) == 9 && lla.ElementAt(1) == 7 &&
      lla.ElementAt(2) == 8 && lla.ElementAt(3) == 9 && lla.ElementAt(4) == 12)
    score += 0.5;

  LinkedList<int> llb;
  // InsertBack, empty list
  llb.InsertBack(12);
  if (!llb.IsEmpty() && llb.Size() == 1 && llb.Contains(12) && llb.ElementAt(0) == 12)
    score += 0.5;

  // InsertBack, general case
  llb.InsertBack(9);
  llb.InsertBack(8);
  llb.InsertBack(7);
  llb.InsertBack(9); // duplicate item, should be allowed
  if (llb.Size() == 5 && !llb.Contains(3) && llb.ElementAt(0) == 12 && llb.ElementAt(1) == 9 &&
      llb.ElementAt(2) == 8 && llb.ElementAt(3) == 7 && llb.ElementAt(4) == 9)
    score += 0.5;

  LinkedList<int> llc;
  // InsertBack with InsertFront
  llc.InsertFront(4);
  llc.InsertBack(5);
  llc.InsertFront(3);
  llc.InsertBack(6);
  llc.InsertFront(2);
  llc.InsertBack(7);
  if (llc.Size() == 6 && !llc.Contains(12) && llc.ElementAt(0) == 2 && llc.ElementAt(1) == 3 &&
      llc.ElementAt(2) == 4 && llc.ElementAt(3) == 5 && llc.ElementAt(4) == 6 && llc.ElementAt(5) == 7)
    score += 0.5;

  return score;
}

// InsertAt/RemoveAt/ElementAt exception cases
double LLTest2()
{
  double score = 0;

  LinkedList<int> lla;

  // RemoveAt, empty list
  try
  {
    lla.RemoveAt(0);
  }
  catch (exception e)
  {
    score += 0.5;
  }

  lla.InsertBack(0);
  lla.InsertBack(1);
  lla.InsertBack(2); // list contains 3 items in valid indices 0,1,2

  // InsertAt exception cases
  try
  {
    lla.InsertAt(-1, -1); // < 0
  }
  catch (exception e)
  {
    score += 0.25;
  }
  try
  {
    lla.InsertAt(10, 10); // > size
  }
  catch (exception e)
  {
    score += 0.25;
  }

  // RemoveAt exception cases
  int value;
  try
  {
    value = lla.RemoveAt(-1); // < 0
  }
  catch (exception e)
  {
    score += 0.25;
  }
  try
  {
    value = lla.RemoveAt(3); // >= size
  }
  catch (exception e)
  {
    score += 0.25;
  }

  // ElementAt exception cases
  try
  {
    value = lla.ElementAt(-1); // < 0
  }
  catch (exception e)
  {
    score += 0.25;
  }
  try
  {
    value = lla.ElementAt(3); // > size
  }
  catch (exception e)
  {
    score += 0.25;
  }

  return score;
}

// InsertAt, InsertFront/Back combination with InsertAt
double LLTest3()
{
  double score = 0;
  try
  {
    LinkedList<double> lla; // start with InsertFront
    lla.InsertFront(12);
    lla.InsertBack(17);
    lla.InsertAt(14, 1);
    lla.InsertAt(21, 3);
    lla.InsertBack(23);
    lla.InsertFront(9);
    if (lla.Size() == 6 && lla.Contains(9) && lla.Contains(12) && lla.Contains(14) &&
        lla.Contains(17) && lla.Contains(21) && lla.Contains(23))
      score += 0.5;
    if (lla.ElementAt(0) == 9 && lla.ElementAt(1) == 12 && lla.ElementAt(2) == 14 &&
        lla.ElementAt(3) == 17 && lla.ElementAt(4) == 21 && lla.ElementAt(5) == 23)
      score += 0.5;
  }
  catch (exception e)
  {
    cout << "Unexpected error in LLTest3-A. Resuming... ";
  }
  try
  {
    LinkedList<int> llb; // start with InsertBack
    llb.InsertBack(17);
    llb.InsertAt(21, 1);
    llb.InsertFront(14);
    llb.InsertAt(12, 0);
    llb.InsertFront(9);
    llb.InsertBack(23);
    if (llb.Size() == 6 && llb.Contains(9) && llb.Contains(12) && llb.Contains(14) &&
        llb.Contains(17) && llb.Contains(21) && llb.Contains(23))
      score += 0.5;
    if (llb.ElementAt(0) == 9 && llb.ElementAt(1) == 12 && llb.ElementAt(2) == 14 &&
        llb.ElementAt(3) == 17 && llb.ElementAt(4) == 21 && llb.ElementAt(5) == 23)
      score += 0.5;
  }
  catch (exception e)
  {
    cout << "Unexpected error in LLTest3-B. Resuming... ";
  }
  try
  {
    LinkedList<int> llc; // start with InsertAt
    llc.InsertAt(14, 0);
    llc.InsertFront(12);
    llc.InsertBack(21);
    llc.InsertAt(17, 2);
    llc.InsertFront(9);
    llc.InsertBack(23);
    if (llc.Size() == 6 && llc.Contains(9) && llc.Contains(12) && llc.Contains(14) &&
        llc.Contains(17) && llc.Contains(21) && llc.Contains(23))
      score += 0.5;
    if (llc.ElementAt(0) == 9 && llc.ElementAt(1) == 12 && llc.ElementAt(2) == 14 &&
        llc.ElementAt(3) == 17 && llc.ElementAt(4) == 21 && llc.ElementAt(5) == 23)
      score += 0.5;
  }
  catch (exception e)
  {
    cout << "Unexpected error in LLTest3-C. Resuming... ";
  }
  return score;
}

// RemoveAt (exception cases)
double LLTest4()
{
  double score = 0;
  LinkedList<int> lla;
  int value = 0;
  try
  {
    value = lla.RemoveAt(0);
  }
  catch (exception e)
  {
    score += 0.5;
    if (lla.Size() == 0)
      score += 0.5;
  }
  LinkedList<int> llb;
  llb.InsertBack(9);
  llb.InsertBack(12);
  llb.InsertBack(14);
  try
  {
    value = llb.RemoveAt(-5);
  }
  catch (exception e)
  {
    if (llb.Size() == 3 && llb.ElementAt(0) == 9 && llb.ElementAt(1) == 12 && llb.ElementAt(2) == 14)
      score += 0.5;
  }
  LinkedList<int> llc;
  llc.InsertBack(9);
  llc.InsertBack(12);
  llc.InsertBack(14);
  try
  {
    value = llc.RemoveAt(10);
  }
  catch (exception e)
  {
    if (llc.Size() == 3 && llc.ElementAt(0) == 9 && llc.ElementAt(1) == 12 && llc.ElementAt(2) == 14)
      score += 0.5;
  }
  return score;
}

// RemoveAt (general cases) + InsertAt/Front/Back
double LLTest5()
{
  double score = 0;
  LinkedList<int> lla;
  LinkedList<int> llb;
  LinkedList<int> llc;

  lla.InsertBack(5);
  // remove only item in list
  try
  {
    if (lla.Size() == 1 && lla.Contains(5) && lla.RemoveAt(0) == 5 && lla.Size() == 0 && !lla.Contains(5))
      score += 0.5;
  }
  catch (exception e)
  {
    cout << "Unexpected error in LLTest5-A. Resuming..." << endl;
  }

  llb.InsertBack(5);
  llb.InsertBack(7);
  llb.InsertBack(9);
  // remove from front
  try
  {
    if (llb.Size() == 3 && llb.RemoveAt(0) == 5 && llb.Size() == 2 && !llb.Contains(5) &&
        llb.ElementAt(0) == 7 && llb.ElementAt(1) == 9)
      score += 1;
  }
  catch (exception e)
  {
    cout << "Unexpected error in LLTest5-B. Resuming..." << endl;
  }

  llc.InsertBack(5);
  llc.InsertBack(7);
  llc.InsertBack(9);
  // remove from back
  try
  {
    if (llc.Size() == 3 && llc.RemoveAt(2) == 9 && llc.Size() == 2 && !llc.Contains(9) &&
        llc.ElementAt(0) == 5 && llc.ElementAt(1) == 7)
      score += 1;
  }
  catch (exception e)
  {
    cout << "Unexpected error in LLTest5-C. Resuming..." << endl;
  }

  LinkedList<int> lld;
  lld.InsertBack(5);
  lld.InsertBack(7);
  lld.InsertBack(9);
  // remove from middle
  try
  {
    if (lld.RemoveAt(0) == 5 && lld.Size() == 2 && !lld.Contains(5))
    {
      lld.InsertFront(3);
      if (lld.Size() == 3 && lld.ElementAt(0) == 3 && lld.ElementAt(1) == 7 && lld.ElementAt(2) == 9)
        score += 0.5;
    }
    if (lld.RemoveAt(2) == 9 && lld.Size() == 2 && !lld.Contains(9))
    {
      lld.InsertBack(11);
      if (lld.Size() == 3 && lld.ElementAt(0) == 3 && lld.ElementAt(1) == 7 && lld.ElementAt(2) == 11)
        score += 0.5;
    }
    if (lld.RemoveAt(1) == 7 && lld.Size() == 2 && !lld.Contains(7))
      lld.InsertAt(4, 1);
      if (lld.Size() == 3 && lld.ElementAt(0) == 3 && lld.ElementAt(1) == 4 && lld.ElementAt(2) == 11)
        score += 0.5;
  }
  catch (exception e)
  {
    cout << "Unexpected error in LLTest5-D. Resuming..." << endl;
  }

  return score;
}

// RemoveDuplicates
double LLTest6()
{
  double score = 0;

  LinkedList<int> lla;
  lla.InsertBack(3);
  lla.InsertBack(7);
  lla.InsertBack(8);
  lla.InsertBack(7);
  lla.InsertBack(3);
  lla.InsertBack(3);
  lla.InsertBack(9);
  lla.InsertBack(11);
  lla.InsertBack(8);
  lla.InsertBack(8);
  lla.InsertBack(7);
  lla.InsertBack(7);
  lla.InsertBack(9);
  lla.InsertBack(9);
  if (lla.Size() == 14)
  {
    lla.RemoveDuplicates();
    try
    {
      if (lla.Size() == 5 && lla.ElementAt(0) == 3 && lla.ElementAt(1) == 11 && lla.ElementAt(2) == 8 &&
          lla.ElementAt(3) == 7 && lla.ElementAt(4) == 9)
        score += 0.5;
    }
    catch (exception e)
    {
      cout << "Unexpected error in LLTest6-A. Resuming..." << endl;
    }
  }

  LinkedList<int> llb;
  llb.RemoveDuplicates();
  if (llb.IsEmpty())
    score += 0.5;

  LinkedList<int> llc;
  llc.InsertBack(3);
  llc.RemoveDuplicates();
  try
  {
    if (llc.Size() == 1 && llc.ElementAt(0) == 3)
      score += 0.5;
  }
  catch (exception e)
  {
    cout << "Unexpected error in LLTest6-C. Resuming..." << endl;
  }
  
  LinkedList<int> lld;
  lld.InsertBack(3);
  lld.InsertBack(5);
  lld.InsertBack(7);
  lld.RemoveDuplicates();
  try
  {
    if (lld.Size() == 3 && lld.ElementAt(0) == 3 && lld.ElementAt(1) == 5 && lld.ElementAt(2) == 7)
      score += 0.5;
  }
  catch (exception e)
  {
    cout << "Unexpected error in LLTest6-D. Resuming..." << endl;
  }

  LinkedList<int> lle;
  lle.InsertBack(3);
  lle.InsertBack(3);
  lle.InsertBack(3);
  lle.RemoveDuplicates();
  try
  {
    if (lle.Size() == 1 && lle.ElementAt(0) == 3)
      score += 0.5;
  }
  catch (exception e)
  {
    cout << "Unexpected error in LLTest6-D. Resuming..." << endl;
  }
  return score;
}

// Append
double LLTest7()
{
  double score = 0;

  // append two empty lists, 0.5
  LinkedList<int> lla;
  LinkedList<int> llb;
  lla.Append(llb);
  if (lla.Size() == 0)
  {
    llb.InsertBack(5);
    try
    {
      if (lla.ElementAt(0) == 5)
      {
        // do nothing, should throw exception
      }
    }
    catch (exception e)
    {
      score += 0.5;
    }
  }

  // append empty list to non-empty, 0.5
  LinkedList<int> llc;
  LinkedList<int> lld;
  llc.InsertBack(223);
  llc.InsertBack(357);
  llc.InsertBack(454);
  llc.Append(lld);
  if (llc.Size() == 3 && lld.Size() == 0)
  {
    lld.InsertBack(500);
    try
    {
      if (llc.ElementAt(0) == 223 && llc.ElementAt(1) == 357 && llc.ElementAt(2) == 454)
      {
        try
        {
          if (llc.ElementAt(3) != 500)
          {
            // should cause exception
          }
        }
        catch (exception e)
        {
          score += 0.5;
        }
      }
    }
    catch (exception e)
    {
      cout << "Unexpected error in LLTest7-B. Resuming..." << endl;
    }
  }

  // append non-empty list to empty, 0.5
  LinkedList<int> lle;
  LinkedList<int> llf;
  llf.InsertBack(3);
  llf.InsertBack(5);
  llf.InsertBack(7);
  lle.Append(llf);
  if (lle.Size() == 3)
  {
    try
    {
      // remove from the middle of llf and check that lle is not affected
      llf.RemoveAt(1);
      if (lle.ElementAt(0) == 3 && lle.ElementAt(1) == 5 && lle.ElementAt(2) == 7 &&
          llf.Size() == 2 && llf.ElementAt(0) == 3 && llf.ElementAt(1) == 7)
        score += 0.5;
    }
    catch (exception e)
    {
      cout << "Unexpected error in LLTest6-C. Resuming..." << endl;
    }
  }

  // append two non-empty lists, 1
  LinkedList<int> llg;
  LinkedList<int> llh;
  llg.InsertBack(3);
  llg.InsertBack(5);
  llg.InsertBack(7);
  llh.InsertBack(2);
  llh.InsertBack(4);
  llh.InsertBack(6);
  llg.Append(llh);
  if (llg.Size() == 6 && llh.Size() == 3)
  {
    // remove an element from middle of llh, add an element to back of llg
    try
    {
      llh.RemoveAt(1);
      llg.InsertBack(9);
      if (llh.Size() == 2 && llh.ElementAt(0) == 2 && llh.ElementAt(1) == 6 &&
          llg.Size() == 7 && llg.ElementAt(0) == 3 && llg.ElementAt(1) == 5 &&
          llg.ElementAt(2) == 7 && llg.ElementAt(3) == 2 && llg.ElementAt(4) == 4 &&
          llg.ElementAt(5) == 6 && llg.ElementAt(6) == 9)
        score += 1;
    }
    catch (exception e)
    {
      cout << "Unexpected error in LLTest6-D. Resuming..." << endl;
    }
  }

  return score;
}

// Copy constructor
double LLTest8()
{
  double score = 0;
  LinkedList<int> lla;
  lla.InsertBack(3);
  lla.InsertBack(5);
  lla.InsertBack(7);

  LinkedList<int> llb(lla);
  try
  {
    lla.InsertBack(9);
    
    if (lla.Size() == 4 && llb.Size() == 3 && llb.RemoveAt(1) == 5 && llb.Size() == 2 &&
        lla.Contains(5) && !llb.Contains(9))
      score += 1;
  }
  catch (exception e)
  {
    cout << "Unexpected error in LLTest7. Resuming... " << endl;
  }

  return score;
}

// Assignment operator
double LLTest9()
{
  double score = 0;
  LinkedList<int> lla;
  lla.InsertBack(3);
  lla.InsertBack(5);
  lla.InsertBack(7);

  LinkedList<int> llb;
  llb.InsertBack(2);
  llb.InsertBack(4);
  llb.InsertBack(6);
  llb.InsertBack(8);

  llb = lla;

  try
  {
    if (llb.Size() == 3 && llb.ElementAt(0) == 3 && llb.ElementAt(1) == 5 && llb.ElementAt(2) == 7 &&
        !llb.Contains(2) && !llb.Contains(4) && !llb.Contains(6) && !llb.Contains(8))
    {
      lla.InsertBack(9);
    
      if (lla.Size() == 4 && llb.Size() == 3 && llb.RemoveAt(1) == 5 && llb.Size() == 2 &&
          lla.Contains(5) && !llb.Contains(9))
        score += 1;
    }
  }
  catch (exception e)
  {
    cout << "Unexpected error in LLTest8. Resuming... " << endl;
  }

  return score;
}

// Default constructor, Add, Size
double CCQTest1()
{
  double score = 0;
  ostringstream outputstream;
  string expectedresult = "";

  CCQueue q1;
  if (q1.Size() == 0)
  {
    if (!q1.Add("", "") && q1.Size() == 0)
      score += 1;
  }

  CCQueue q2;
  if (q2.Size() == 0)
  {
    if (q2.Add("aaa", "aaa") && q2.Add("bbb", "bbb") && q2.Add("ccc", "ccc") && q2.Add("ddd", "ddd"))
    {
      outputstream.str("");
      outputstream.clear();
      outputstream << "Ticket queue contains 4 open tickets.\n";
      outputstream << "Position\tTicket ID\tCustomer\tShort description\n";
      outputstream << "-----------------------------------------------------------------------\n";
      outputstream << "1\t\t1\t\taaa\taaa...\n";
      outputstream << "2\t\t2\t\tbbb\tbbb...\n";
      outputstream << "3\t\t3\t\tccc\tccc...\n";
      outputstream << "4\t\t4\t\tddd\tddd...\n";
      expectedresult = outputstream.str();
      if (q2.PrintStatus() == expectedresult)
        score += 1;
    }
  }

  return score;
}

// Service (exception + general)
double CCQTest2()
{
  double score = 0;
  ostringstream outputstream;
  string expectedresult = "";
  Ticket t;

  CCQueue q1;
  try
  {
    if (q1.Add("aaa", "aaa") && q1.Add("bbb", "bbb") && q1.Add("ccc", "ccc") && q1.Add("ddd", "ddd") && q1.Size() == 4)
    {
      t = q1.Service();
      if (q1.Size() == 3 && t.GetID() == 1 && t.GetCustomer() == "aaa" && t.GetComplaint() == "aaa")
      {
        outputstream.str("");
        outputstream.clear();
        outputstream << "Ticket queue contains 3 open tickets.\n";
        outputstream << "Position\tTicket ID\tCustomer\tShort description\n";
        outputstream << "-----------------------------------------------------------------------\n";
        outputstream << "1\t\t2\t\tbbb\tbbb...\n";
        outputstream << "2\t\t3\t\tccc\tccc...\n";
        outputstream << "3\t\t4\t\tddd\tddd...\n";
        expectedresult = outputstream.str();
        if (q1.PrintStatus() == expectedresult)
          score += 1;
      }
    }
  }
  catch (exception e)
  {
    cout << "Unexpected error in CCQTest2-A. Resuming..." << endl;
  }

  CCQueue q2;
  try
  {
    if (q2.Size() == 0)
      t = q2.Service();
  }
  catch (exception e)
  {
    score += 1;
  }

  CCQueue q3;
  try
  {
    if (q3.Add("aaa", "aaa") && q3.Size() == 1)
    {
      t = q3.Service();
      if (q3.Size() == 0 && t.GetID() == 1 && t.GetCustomer() == "aaa" && t.GetComplaint() == "aaa")
      {
        outputstream.str("");
        outputstream.clear();
        outputstream << "Ticket queue contains 0 open tickets.\n";
        outputstream << "Position\tTicket ID\tCustomer\tShort description\n";
        outputstream << "-----------------------------------------------------------------------\n";
        expectedresult = outputstream.str();
        if (q3.PrintStatus() == expectedresult)
          score += 1;
      }
    }
  }
  catch (exception e)
  {
    cout << "Unexpected error in CCQTest2-C. Resuming..." << endl;
  }

  return score;
}

// MoveUp + Add + Service
double CCQTest3()
{
  double score = 0;
  ostringstream outputstream;
  string expectedresult = "";
  Ticket t;

  CCQueue q1;
  if (!q1.MoveUp(0))
    score += 0.5;

  CCQueue q2;
  try
  {
    if (q2.Add("aaa", "aaa") && q2.Add("bbb", "bbb") && q2.Add("ccc", "ccc") && q2.Size() == 3)
    {
      if (!q1.MoveUp(0))
        score += 0.5;
    }
  }
  catch (exception e)
  {
    cout << "Unexpected error in CCQTest3-B. Resuming..." << endl;
  }

  CCQueue q3;
  try
  {
    if (q3.Add("aaa", "aaa") && q3.Add("bbb", "bbb") && q3.Add("ccc", "ccc") && q3.Size() == 3)
    {
      if (q3.MoveUp(2) && q3.MoveUp(1))
      {
        outputstream.str("");
        outputstream.clear();
        outputstream << "Ticket queue contains 3 open tickets.\n";
        outputstream << "Position\tTicket ID\tCustomer\tShort description\n";
        outputstream << "-----------------------------------------------------------------------\n";
        outputstream << "1\t\t3\t\tccc\tccc...\n";
        outputstream << "2\t\t1\t\taaa\taaa...\n";
        outputstream << "3\t\t2\t\tbbb\tbbb...\n";
        expectedresult = outputstream.str();

        if (q3.PrintStatus() == expectedresult)
          score += 0.5;
      }
      t = q3.Service();
      if (q3.Size() == 2 && t.GetID() == 3 && t.GetCustomer() == "ccc" && t.GetComplaint() == "ccc")
      {
        if (q3.Add("ddd", "ddd") && q3.Size() == 3)
        {
          outputstream.str("");
          outputstream.clear();
          outputstream << "Ticket queue contains 3 open tickets.\n";
          outputstream << "Position\tTicket ID\tCustomer\tShort description\n";
          outputstream << "-----------------------------------------------------------------------\n";
          outputstream << "1\t\t1\t\taaa\taaa...\n";
          outputstream << "2\t\t2\t\tbbb\tbbb...\n";
          outputstream << "3\t\t4\t\tddd\tddd...\n";
          expectedresult = outputstream.str();

          if (q3.PrintStatus() == expectedresult)
            score += 0.5;
        }
      }
    }
  }
  catch (exception e)
  {
    cout << "Unexpected error in CCQTest3-B. Resuming..." << endl;
  }

  return score;
}

// MoveDown + Add + Service
double CCQTest4()
{
  double score = 0;
  ostringstream outputstream;
  string expectedresult = "";
  Ticket t;

  CCQueue q1;
  if (!q1.MoveDown(0))
    score += 0.5;

  CCQueue q2;
  try
  {
    if (q2.Add("aaa", "aaa") && q2.Add("bbb", "bbb") && q2.Add("ccc", "ccc") && q2.Size() == 3)
    {
      if (!q1.MoveDown(0))
        score += 0.5;
    }
  }
  catch (exception e)
  {
    cout << "Unexpected error in CCQTest4-B. Resuming..." << endl;
  }

  CCQueue q3;
  try
  {
    if (q3.Add("aaa", "aaa") && q3.Add("bbb", "bbb") && q3.Add("ccc", "ccc") && q3.Size() == 3)
    {
      if (q3.MoveDown(0) && q3.MoveDown(1))
      {
        outputstream.str("");
        outputstream.clear();
        outputstream << "Ticket queue contains 3 open tickets.\n";
        outputstream << "Position\tTicket ID\tCustomer\tShort description\n";
        outputstream << "-----------------------------------------------------------------------\n";
        outputstream << "1\t\t2\t\tbbb\tbbb...\n";
        outputstream << "2\t\t3\t\tccc\tccc...\n";
        outputstream << "3\t\t1\t\taaa\taaa...\n";
        expectedresult = outputstream.str();

        if (q3.PrintStatus() == expectedresult)
          score += 0.5;
      }
      t = q3.Service();
      if (q3.Size() == 2 && t.GetID() == 2 && t.GetCustomer() == "bbb" && t.GetComplaint() == "bbb")
      {
        if (q3.Add("ddd", "ddd") && q3.Size() == 3)
        {
          outputstream.str("");
          outputstream.clear();
          outputstream << "Ticket queue contains 3 open tickets.\n";
          outputstream << "Position\tTicket ID\tCustomer\tShort description\n";
          outputstream << "-----------------------------------------------------------------------\n";
          outputstream << "1\t\t3\t\tccc\tccc...\n";
          outputstream << "2\t\t1\t\taaa\taaa...\n";
          outputstream << "3\t\t4\t\tddd\tddd...\n";
          expectedresult = outputstream.str();

          if (q3.PrintStatus() == expectedresult)
            score += 0.5;
        }
      }
    }
  }
  catch (exception e)
  {
    cout << "Unexpected error in CCQTest4-B. Resuming..." << endl;
  }

  return score;
}