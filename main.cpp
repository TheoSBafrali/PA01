#include "cards.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(int argv, char **argc) {
  if (argv != 3) {
    cout << "Please provide 2 file names" << endl;
    return 1;
  }
  ifstream cardFile1(argc[1]);
  ifstream cardFile2(argc[2]);
  if (cardFile1.fail()) {
    cout << "Could not open file " << argc[1];
    return 1;
  }
  if (cardFile2.fail()) {
    cout << "Could not open file " << argc[2];
    return 1;
  }

  Player *Alice = new Player(cardFile1, "Alice");
  Player *Bob = new Player(cardFile2, "Bob");

  bool is_running = true;
  bool alice_turn = true;

  while (is_running) {
    if (alice_turn) {
      is_running = Alice->play(Bob);
    } else {
      is_running = Bob->play(Alice);
    }
    alice_turn = !(alice_turn);
  }

  Alice->print_cards();
  Bob->print_cards();

  // Create two objects of the class you defined
  // to contain two sets of cards in two input files

  // Read each file and store cards
  /*
  while (getline (cardFile1, line) && (line.length() > 0)){
  }
  cardFile1.close();

  while (getline (cardFile2, line) && (line.length() > 0)){
  }
  cardFile2.close();
  */

  // Start the game

  return 0;
}
