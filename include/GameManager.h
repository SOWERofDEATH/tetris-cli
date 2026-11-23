#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

class GameManager
{
public:
	GameManager();

	void run();
	void stop();

private:
	bool isRunning;

};

#endif // GAME_MANAGER_H
