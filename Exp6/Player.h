#pragma once

#include <iostream>
#include <string>

class Player
{
public:
	enum SolderType { ARCHER, CATAPULT, SWORDSMAN };
	Player(int archers, int catapults, int swordsmen);
	~Player();
	void SetName();
	void SetName(std::string name);
	std::string GetName();
	void ShowStatus();
	int GetRemainSolders(SolderType st);
	void SetSend(SolderType st);
	void SetSend(int archers_sent, int catapults_sent, int swordsmen_sent);
	void BattleWith(bool & end, bool & lost, Player & other_player);
private:
	std::string name;; //used to store the player¡¯s name

	int archers;
	int catapults;
	int swordsmen;

	//variables to store how many units the player sends
	int archers_sent;
	int catapults_sent;
	int swordsmen_sent;
};

