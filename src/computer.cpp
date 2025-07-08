#include "main.h"
#include "shared.h"
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

int getComputerCol(const Board &board);
int getPlayerCol(const Board &board);

GameState playComputer() {
  srand(time(0));
  Board board;

  while (true) {
    int chosenEnemyCol = getComputerCol(board);
    int isValidEnemyPlacement = board.placeCol(chosenEnemyCol, Player::ENEMY);
    if (!isValidEnemyPlacement) {
      cerr << "Computer tried placing at col: " << chosenEnemyCol << endl;
      exit(1);
    }

    board.print();
    GameState enemyState = board.getGameState(Player::ENEMY);
    if (enemyState != GameState::RUNNING) {
      return enemyState;
    }

    std::cout << "\n";
    int chosenPlayerCol = getPlayerCol(board);
    int isValidPlayerPlacement = board.placeCol(chosenPlayerCol, Player::OWN);
    if (!isValidPlayerPlacement) {
      cerr << "Player tried placing at col: " << chosenPlayerCol << endl;
      exit(1);
    }

    board.print();
    GameState playerState = board.getGameState(Player::OWN);
    if (playerState != GameState::RUNNING) {
      return playerState;
    }
  }
}

int getComputerCol(const Board &board) {
  vector<int> avaiableCols = {0, 1, 2, 3, 4, 5, 6, 7, 8};

  while (!avaiableCols.empty()) {
    int chosenIdx = rand() % avaiableCols.size();
    int chosenCol = avaiableCols[chosenIdx];

    Player player = board.getCell(0, chosenCol);
    if (player == Player::EMPTY) {
      return chosenCol;
    }

    avaiableCols.erase(avaiableCols.begin() + chosenIdx);
  }

  cerr << "Computer ran out of placement options" << endl;
  exit(1);
}

int getPlayerCol(const Board &board) {
  cout << "Where do you want to place your own piece ("
       << static_cast<char>(Player::OWN) << "). Choose cols (1-" << BOARD_LENGTH
       << "): ";

  string result;
  getline(cin, result);

  if (result.size() != 1) {
    cerr << "You must enter a column number between 1 and " << BOARD_LENGTH
         << endl;
    return getPlayerCol(board);
  }

  int chosenCol = result[0] - '1';
  if (chosenCol < 0 || chosenCol > 8) {
    cerr << "You must enter a column number between 1 and " << BOARD_LENGTH
         << endl;
    return getPlayerCol(board);
  }

  Player player = board.getCell(0, chosenCol);
  if (player != Player::EMPTY) {
    cerr << "This column is already filled up" << endl;
    return getPlayerCol(board);
  }

  return chosenCol;
}
