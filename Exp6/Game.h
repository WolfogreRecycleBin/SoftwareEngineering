#pragma once

#include "Player.h"

class Game
{
public:
	Game();
	~Game();
	void Start();
protected:
	void Welcome();
	bool Menu();
	void GameOver();
private:
	Player *player;
	Player *germania;
	bool lost;//used to test if the user lost the game
	bool end = false; //used to test if the user chose to quit
};