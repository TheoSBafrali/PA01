// cards.cpp
// Authors: Theo Bafrali
// Implementation of the classes defined in cards.h
#include "cards.h"
#include <string>

Card::Card(Card *next, char suit, char value)
    : next_(next), suit_(suit), value_(value) {}

CardList::CardList(std::ifstream &stream) {
  char tmp_suit, tmp_value;
 
  if(!(this->head_) && stream >> tmp_suit && stream >> tmp_value) {
    this->head_ = new Card(nullptr, tmp_suit, tmp_value);
  }
  Card* n = this->head_;
  while (stream >> tmp_suit && stream >> tmp_value) {
      n->next_ = new Card(nullptr, tmp_suit, tmp_value);
      n = n->next_;
  }
}

CardList::~CardList() { free(this->head_); }

Card *CardList::get_head() { return this->head_; }

void CardList::free(Card *n) {
  if (n) {
    free(n->next_);
    delete n;
  }
}

void CardList::insert(Card *n, Card &card) {
  if (n->next_) {
    insert(n->next_, card);
  } else {
    n->next_ = new Card(nullptr, card.suit_, card.value_);
  }
}

void CardList::insert(Card &card) {
  if (!(this->head_)) {
    this->head_ = new Card(nullptr, card.suit_, card.value_);
  } else {
    CardList::insert(this->head_, card);
  }
}

void CardList::remove(Card *n, Card &card) {
  if (!(n->next_)) {
    return;
  }
  if (*(n->next_) == card) {
    Card *tmp = n->next_->next_;
    delete n->next_;
    n->next_ = tmp;
  } else {
    remove(n->next_, card);
  }
}

void CardList::remove(Card &card) {
  if (*(this->head_) == card) {
    Card *tmp = this->head_->next_;
    delete this->head_;
    this->head_ = tmp;
  } else {
    remove(this->head_, card);
  }
}

bool CardList::contains(Card &card) const {
  return contains(this->head_, card);
}

bool CardList::contains(Card *n, Card &card) const {
  if (n) {
    if ((*n) == card) {
      return true;
    } else {
      return contains(n->next_, card);
    }
  } else {
    return false;
  }
}

Player::Player(std::ifstream &stream, std::string name) : CardList(stream) {
  this->name_ = name;
  this->iterator_ = this->get_head();
}

Card *Player::get_head() { return CardList::get_head(); }

void Player::remove(Card& card) {
    if(this->iterator_) {
        if(*(this->iterator_) == card) {
            iterator_ = iterator_->next_;
        }
    }
    CardList::remove(card);
    
}

bool Player::play(Player* opponent) {
  while (iterator_) {
    if (opponent->contains(*iterator_)) {
      std::cout << name_ << " picked matching card " << (*iterator_)
                << std::endl;
      opponent->remove(*iterator_);
      this->remove(*iterator_);
      return true;
    } else {
      if (iterator_->next_) {
        iterator_ = iterator_->next_;
      } else {
        return false;
      }
    }
  }
  // if no match among players card's, game is over so return false
  return false;
}

void Player::print_cards() {
  Card *n = this->get_head();
  std::cout << this->name_ << "'s cards:" << std::endl;
  while (n) {
    std::cout << (*n) << std::endl;
    n = n->next_;
  }
}