#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

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
	Block activeBlock {getNextActiveBlock()};
	std::chrono::milliseconds dropInterval {500};

	static Block getNextActiveBlock();

	void gravityStep();
	void spawnBlock();
	void drawFrame() const;
	void clearScreen() const;
};

#endif // GAME_MANAGER_H
