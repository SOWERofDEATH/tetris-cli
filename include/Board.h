#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "Block.h"

class Board
{
public:
  Board();

  bool isInsideGrid(int row, int column) const;
  bool isOccupied(int row, int column) const;
  bool canPlace(const Block& block) const;
  void displayBoard() const;
  void lockBlock(const Block& block);

  static constexpr int width = 10;
  static constexpr int height = 20;
  std::vector<std::vector<bool>> grid;

};

#endif // BOARD_H
