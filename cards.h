// cards.h
// Authors: Your Partner's Name and Your Name
// All class declarations go here

#ifndef CARDS_H
#define CARDS_H
#include <fstream>
#include <iostream>
#include <string>

class Card {
public:
  Card(Card *next, char suit, char value);
  Card *next_;
  char suit_, value_;
  // this is defined, so wtf?   
  bool operator==(const Card &c) {
    return (this->suit_ == c.suit_ && this->value_ == c.value_);
  }

  friend std::ostream &operator<<(std::ostream &os, const Card &card) {
    os << card.suit_ << " " << card.value_;
    return os;
  }
};

class CardList {
public:
  CardList(std::ifstream &stream);
  ~CardList();
  void remove(Card &card);
  void insert(Card &card);
  bool contains(Card &card) const;
  Card *get_head();

private:
  void remove(Card *n, Card &card);
  void insert(Card *n, Card &card);
  bool contains(Card *n, Card &card) const;
  void free(Card *n);
  Card *head_;
};

class Player : public CardList {
public:
  Player(std::ifstream &stream, std::string name);
  ~Player();
  bool play(Player* opponent);
  void print_cards();
  Card* get_head();
  void remove(Card& card);
  Card* iterator_;

private:
  std::string name_;
};

#endif

// Use this file to define all your classes and public functions
// You should design your program with OOP prinicples using classes
// An example of class design would be having Card, CardList and Player as
// Classes. Card represent Node in your LinkedList which has some data in it
// CardList can be your LinkedList Class which has operations such as append,
// remove etc Player class represents your game player Think about the public
// functions that should be part of each class. (All public function need to be
// tested in unit testing) One of the important functions is search / find which
// is essential for players to find cars in their opponent's "hand" Make sure
// you overload the desired operators This is not the fixed design. We are not
// expecting exactly 3 classes. You can do with less or more. Important thing to
// consider is abstraction.
