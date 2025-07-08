#pragma once

#include <sys/types.h>

constexpr int BOARD_HEIGHT = 6;
constexpr int BOARD_LENGTH = 9;

constexpr ushort EMPTY = 0;
constexpr ushort OWN = 1;
constexpr ushort ENEMY = 2;

constexpr char EMPTY_CHAR = ' ';
constexpr char OWN_CHAR = 'X';
constexpr char ENEMY_CHAR = 'O';

class Board {
public:
  Board();
  void print();

private:
  ushort m_Board[BOARD_HEIGHT][BOARD_LENGTH];
};
