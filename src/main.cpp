#include "main.h"
#include "shared.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv) {
  if (argc != 2) {
    cerr << "Usage: ./connectio [computer]" << endl;
    return 1;
  }

  string opponentType = argv[1];
  if (opponentType == "computer") {
    GameState state = playComputer();
    switch (state) {
    case GameState::TIE:
      cout << "\n"
              "You tied"
           << endl;
      return 0;
    case GameState::OWN_WIN:
      cout << "\n"
              "You won"
           << endl;
      return 0;
    case GameState::ENEMY_WIN:
      cout << "\n"
              "You lost"
           << endl;
      return 0;
    default:
      cerr << "\n"
              "Game shouldn't end at a running state"
           << endl;
      return 1;
    }
  }

  cerr << "Invalid opponent type given" << endl;
  return 1;
}
