// testcards.h
// Authors: Your Partner's Name and Your Name
// All test declarations go here

// This is not exhaustive list of tests. You can remove / edit tests if it
// doesn't suit your design but you should definitelty add more You should test
// all possible cornere cases of your public functions

#ifndef TESTCARDS_H
#define TESTCARDS_H

#include <iostream>

using namespace std;
void runAll();

void test_constructor();
void test_card_equality_operator();
void test_remove();
void test_contains();
void test_play();

void START_TEST(string testname) { cout << "Start " << testname << endl; }

void END_TEST(string testname) { cout << "End " << testname << endl << endl; }

void assertEquals(string expected, string actual, string testDescription) {
  if (expected == actual) {
    cout << "PASSED " << endl;
  } else {
    cout << "  FAILED: " << testDescription << endl
         << "   Expected: " << expected << " Actual: " << actual << endl;
  }
}

void assertEquals(int expected, int actual, string testDescription) {
  if (expected == actual) {
    cout << "PASSED " << endl;
  } else {
    cout << "  FAILED: " << testDescription << endl
         << "   Expected: " << expected << " Actual: " << actual << endl;
  }
}

// You should add more assertEquals function for your classes. For example,
// Node/Card class
/*
void assertEquals(Node *expected, Node *actual, string testDescription){
  if (expected == actual) {
    cout<<"PASSED " << endl;
  } else {
    cout<< "  FAILED: "<< testDescription << endl <<"   Expected: "<< expected
<< " Actual: " << actual << endl;
  }
}
*/

#endif
