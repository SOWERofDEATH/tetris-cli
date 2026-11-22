#include "Board.h"
#include <print>

Board::Board() : grid(height, std::vector<bool>(width, false)) {}

void Board::displayBoard() const
{
  // Print top of the Boarder
  std::print("┌");
  for (int i = 0; i < width; i++)
  {
    std::print("─");
  }
  std::print("┐\n");

  // Print grid with border edges
  for (const auto &row : grid)
  {
    std::print("│");

    for (const auto &col : row) {
      std::print("{}", col ? "#" : " ");
    }

    std::print("│\n");
  }

  // Print bottom of the border
  std::print("└");
  for (int i = 0; i < width; i++)
  {
    std::print("─");
  }
  std::print("┘\n");
}

bool Board::isInsideGrid(int row, int column) const
{
  // Check if row is withing the grid
  if (row < 0 || row >= height)
    return false;

  // Check if column is withing the grid
  if (column < 0 || column >= width)
    return false;

  return true;
}

bool Board::isOccupied(int row, int column) const
{
  if (!isInsideGrid(row, column))
    return false;

  return grid[row][column];
}
