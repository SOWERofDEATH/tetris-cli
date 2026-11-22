#ifndef BOARD_H
#define BOARD_H

#include <vector>

class Board
{
public:
  Board();
  void displayBoard() const;

private:
  static constexpr int width = 10;
  static constexpr int height = 20;

  std::vector<std::vector<bool>> grid;

  bool isInsideGrid(int row, int column) const;
  bool isOccupied(int row, int column) const;
};

#endif // BOARD_H
