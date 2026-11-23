#include "GameManager.h"
#include "Board.h"

GameManager::GameManager() : isRunning(false) {}

void GameManager::run()
{
	this->isRunning = true;

	Board board;

	// Game Loop
	while(isRunning)
	{

		board.displayBoard();
	}
}

void GameManager::stop()
{
	this->isRunning = false;
}
