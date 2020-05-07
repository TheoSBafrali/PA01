// This file should contain unit tests for all the
// public interfaces of the classes that you implement

#include "testcards.h"
#include "cards.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <cerr>
using namespace std;


void test_contains() {
  std::cout << "contains test" << std::endl;
  ifstream testcards("ycards.txt");
  Player* p = new Player(testcards, "p");
  Card tmp(nullptr, 's', '2');
  if(p) {
    if(p->contains(tmp)) {
      std::cout << "contains passed" << std::endl;
    } else {
        std::cout << "contains failed" << std::endl;
    }
  }
}
void test_remove() {
  std::cout << "remove test" << std::endl;
  ifstream testcards("ycards.txt");

  Player* p = new Player(testcards, "p");
  Card tmp(*(p->get_head()->next_));
  p->remove(*(p->get_head()));
  if(*(p->get_head()) == tmp) {
    std::cout << "remove pass" << std::endl;
  } else {
    std::cout << "remove fail" << std::endl;
  }

}

void test_card_equality_operator() {
  std::cout << "equality test" << std::endl;
  Card c1(nullptr, 'c', 'k');
  Card c2(&c1, 'c', 'k');
  Card c3(&c1, 'a', 'k');

  if(c1 == c2) {
    std::cout << "positive test case yay" << std::endl;
  } else {
    std::cout << "positive test case nay" << std::endl;
  }

  if(!(c2 == c3)) {
    std::cout << "negative test case yay" << std::endl;

  } else {
    std::cout << "negative test case nay" << std::endl;
  }
  return;
}

void test_constructor() {
  ifstream testcards("ycards.txt");
  // Player constructor called no?
  std::cout << "constructor test" << std::endl;
  Player *p = new Player(testcards, "p");
  Card c1(nullptr, 'h', '3');
  Card c2(&c1, 's', '2');
  if (p->get_head() && p->get_head()->next_) {
    if (c1 == *(p->get_head()) && c2 == *(p->get_head()->next_)) {
      std::cout << "constructor works!" << std::endl;
      return;
    }
  } else {
    std::cout << "HERE THERE BE NULLPTRS!" << std::endl;
    return;
  }
  std::cout << ":( she's dead Jim! \n"
            << c1 << " != " << *(p->get_head()) << std::endl;
  std::cout << c2 << " != " << *(p->get_head()->next_) << std::endl;
  return;
}


void test_play() {
  std::cout << "play test" << std::endl;
  ifstream testcards1("ycards.txt");
  ifstream testcards2("zcards.txt");

  Player* Alice = new Player(testcards1, "Alice");
  Player* Bob = new Player(testcards2, "Bob");
  std::cerr << "testplay?" << std::endl;

  Alice->play(Bob);
  Bob->play(Alice);

  Alice->print_cards();
  Bob->print_cards();
}

int main() {
  std::cout << "Running Tests..." << std::endl;
  test_contains();
  test_card_equality_operator();
  test_remove();
  test_constructor();
  test_play();
  return 0;
}
