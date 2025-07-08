#pragma once

#include <sys/types.h>

constexpr int BOARD_HEIGHT = 6;
constexpr int BOARD_LENGTH = 9;

enum class Player : char { EMPTY = ' ', OWN = 'X', ENEMY = 'O' };
enum class GameState { RUNNING, TIE, ENEMY_WIN, OWN_WIN };

class Board {
public:
  Board();
  Player getCell(int row, int col) const;
  GameState getGameState(const Player &player);
  bool placeCol( int col, const Player &player);
  void print();

private:
  Player m_Board[BOARD_HEIGHT][BOARD_LENGTH];
};
