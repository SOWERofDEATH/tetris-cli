#include "GameManager.h"

#include <thread>

GameManager::GameManager() : isRunning(false) {}

void GameManager::run()
{
	isRunning = true;
	spawnBlock();
	board.displayBoard();

	Clock::time_point lastDrop = Clock::now();

	// Game Loop
	while(isRunning)
	{
		const Clock::time_point now = Clock::now();

		if (now - lastDrop >= dropInterval)
		{
			lastDrop = now;

			gravityStep();

			clearScreen();
      drawFrame();
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(20));
	}

}

void GameManager::stop()
{
	isRunning = false;
}

Block GameManager::getNextActiveBlock()
{
 return Block {1, Board::width / 2, Block::getRandomBlockType()};
}

void GameManager::gravityStep()
{
	Block testMove = activeBlock;
	testMove.moveDown();

	if (board.canPlace(testMove))
	{
		activeBlock = testMove;
	}
	else
	{
		board.lockBlock(activeBlock);
		spawnBlock();
	}
}

void GameManager::spawnBlock()
{
	activeBlock = getNextActiveBlock();

	if (!board.canPlace(activeBlock))
	{
		stop();
	}
}

void GameManager::drawFrame() const
{
    Board frame = board;

    for (const Cell& cell : activeBlock.getCells())
    {
        if (frame.isInsideGrid(cell.row, cell.column))
        {
            const std::size_t row = static_cast<std::size_t>(cell.row);
            const std::size_t col = static_cast<std::size_t>(cell.column);
            frame.grid[row][col] = true;
        }
    }

    frame.displayBoard();
}

void GameManager::clearScreen() const
{
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}
