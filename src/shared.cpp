#include "shared.h"
#include <cassert>
#include <iostream>

Board::Board() {
  for (int row = 0; row < BOARD_HEIGHT; row++) {
    for (int col = 0; col < BOARD_LENGTH; col++) {
      m_Board[row][col] = Player::EMPTY;
    }
  }
}

void Board::print() {
  using namespace std;

  cout << "\n"
          " 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 "
          "\n"
          "---+---+---+---+---+---+---+---+---"
       << endl;

  for (int row = 0; row < BOARD_HEIGHT; row++) {
    for (int col = 0; col < BOARD_LENGTH; col++) {
      Player player = m_Board[row][col];
      char playerChar = static_cast<char>(player);

      cout << " " << playerChar << " ";

      if (col != BOARD_LENGTH - 1) {
        cout << "|";
      }
    }

    if (row != BOARD_HEIGHT - 1) {
      cout << "\n" << "---+---+---+---+---+---+---+---+---";
    }

    cout << endl;
  }
}

bool isGameTied(const Player board[BOARD_HEIGHT][BOARD_LENGTH]) {
  for (int row = 0; row < BOARD_HEIGHT; row++) {
    for (int col = 0; col < BOARD_LENGTH; col++) {
      if (board[row][col] == Player::EMPTY) {
        return false;
      }
    }
  }

  return true;
}

GameState Board::getGameState(const Player &player) {
  if (isGameTied(m_Board)) {
    return GameState::TIE;
  }

  // Horizontal
  for (int row = 0; row < BOARD_HEIGHT; row++) {
    for (int col = 0; col < BOARD_LENGTH - 3; col++) {
      Player first = getCell(row, col);
      Player second = getCell(row, col + 1);
      Player third = getCell(row, col + 2);
      Player fourth = getCell(row, col + 3);

      if (first != player || second != player || third != player ||
          fourth != player) {
        continue;
      }

      return player == Player::OWN ? GameState::OWN_WIN : GameState::ENEMY_WIN;
    }
  }

  // Vertical
  for (int row = 0; row < BOARD_HEIGHT - 3; row++) {
    for (int col = 0; col < BOARD_LENGTH; col++) {
      Player first = getCell(row, col);
      Player second = getCell(row + 1, col);
      Player third = getCell(row + 2, col);
      Player fourth = getCell(row + 3, col);

      if (first != player || second != player || third != player ||
          fourth != player) {
        continue;
      }

      return player == Player::OWN ? GameState::OWN_WIN : GameState::ENEMY_WIN;
    }
  }

  // Diagnols topleft -> bottomright
  for (int row = 0; row < BOARD_HEIGHT - 3; row++) {
    for (int col = 0; col < BOARD_LENGTH - 3; col++) {
      Player first = getCell(row, col);
      Player second = getCell(row + 1, col + 1);
      Player third = getCell(row + 2, col + 2);
      Player fourth = getCell(row + 3, col + 3);

      if (first != player || second != player || third != player ||
          fourth != player) {
        continue;
      }

      return player == Player::OWN ? GameState::OWN_WIN : GameState::ENEMY_WIN;
    }
  }

  // Diagnols bottomleft -> topright
  for (int row = 3; row < BOARD_HEIGHT; row++) {
    for (int col = 0; col < BOARD_LENGTH - 3; col++) {
      Player first = getCell(row, col);
      Player second = getCell(row - 1, col + 1);
      Player third = getCell(row - 2, col + 2);
      Player fourth = getCell(row - 3, col + 3);

      if (first != player || second != player || third != player ||
          fourth != player) {
        continue;
      }

      return player == Player::OWN ? GameState::OWN_WIN : GameState::ENEMY_WIN;
    }
  }

  return GameState::RUNNING;
}

bool Board::placeCol(int col, const Player &player) {
  for (int row = BOARD_HEIGHT - 1; row >= 0; row--) {
    if (m_Board[row][col] != Player::EMPTY) {
      continue;
    }

    m_Board[row][col] = player;
    return true;
  }

  return false;
}

Player Board::getCell(int row, int col) const { return m_Board[row][col]; }
