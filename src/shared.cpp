#include "shared.h"
#include <cassert>
#include <iostream>

Board::Board() {
  for (int row = 0; row < BOARD_HEIGHT; row++) {
    for (int col = 0; col < BOARD_LENGTH; col++) {
      m_Board[row][col] = EMPTY;
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
      ushort value = m_Board[row][col];

      cout << " ";

      switch (value) {
      case EMPTY:
        cout << EMPTY_CHAR;
        break;
      case OWN:
        cout << OWN_CHAR;
        break;
      case ENEMY:
        cout << ENEMY_CHAR;
        break;
      default:
        assert(value >= EMPTY && value <= ENEMY &&
               "Invalid value found when printing");
      }

      cout << " ";

      if (col != BOARD_LENGTH - 1) {
        cout << "|";
      }
    }

    if (row != BOARD_HEIGHT - 1) {
      cout << "\n"
              "---+---+---+---+---+---+---+---+---";
    }

    cout << endl;
  }
}
