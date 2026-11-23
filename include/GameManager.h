#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "Block.h"
#include "Board.h"

#include <chrono>

class GameManager
{
public:
	GameManager();

	void run();
	void stop();

private:
	using Clock = std::chrono::steady_clock;

	bool isRunning;
	Board board {};
	Block activeBlock {getRandomActiveBlock()};
	std::chrono::milliseconds dropInterval {500};

	static Block getRandomActiveBlock();
	void gravityStep();
	void spawnBlock();
	void drawFrame() const;
	void clearScreen() const;
};

#endif // GAME_MANAGER_H
