#include <array>
#include <cstddef>
#include <print>

#include "Block.h"
#include "BlockType.h"
#include "Board.h"
#include "Cell.h"

namespace
{

void printCells(const char* label, const std::array<Cell, 4>& cells)
{
    std::print("{}: ", label);
    for (const Cell& cell : cells)
    {
        std::print("({}, {}) ", cell.row, cell.column);
    }
    std::print("\n");
}

void showBlockPreview(const Board& baseBoard, const Block& block)
{
    Board preview = baseBoard;
    for (const Cell& cell : block.getCells())
    {
        if (preview.isInsideGrid(cell.row, cell.column))
        {
            const auto r = static_cast<std::size_t>(cell.row);
            const auto c = static_cast<std::size_t>(cell.column);
            preview.grid[r][c] = true;
        }
    }
    preview.displayBoard();
}

} // namespace

int main()
{
    Board board;
    Block lBlock(5, 4, BlockType::L);

    for (int step = 0; step < 4; ++step)
    {
        std::print("=== L Rotation Step {} ===\n", step);
        printCells("Cells", lBlock.getCells());
        showBlockPreview(board, lBlock);
        lBlock.rotate();
    }

    return 0;
}
