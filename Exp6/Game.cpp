#include <iostream>
#include <ctime>
#include "Game.h"

Game::Game()
{
	srand((int)time(0)); //seed the random number generator
	player = new Player(50, 25, 100);
	germania = new Player(rand() % (51) + 20, rand() % (41) + 10, rand() % (101) + 50);
	germania->SetName("Germania");
}

Game::~Game()
{
	delete player;
	delete germania;
}

void Game::Start(){
	Welcome();
	while (!end) //main game loop
	{
		player->SetSend(0, 0, 0);
		player->ShowStatus();
		germania->ShowStatus();

		while (Menu())
			;

		player->BattleWith(end, lost, *germania);
	} //end of main game loop

	//display appropriate ending message
	GameOver();
}

void Game::Welcome()
{
	std::cout << "Welcome Adventurer, what is your name?\n";
	player->SetName();
	std::cout << "Well, " << player->GetName()
		<< " welcome to the Roman Commander Game.\n"
		<< "\nYou are the commander of the Roman Army"
		<< " attacking Germania.";
}

bool Game::Menu()
{
	int menu_choice; //stores the user¡¯s choice from the menu
	//stores which numbers correspond to which menu choices
	int archers_menu, catapults_menu, swordsmen_menu;
	int fight_menu;

	//keeps track of which menu numbers
	//are being used
	int i = 1;
	if (player->GetRemainSolders(Player::ARCHER) > 0)
	{
		archers_menu = i;
		std::cout << "[" << i << "] Send Archers\n";
		i++;
	}
	else archers_menu = 0;
	if (player->GetRemainSolders(Player::CATAPULT) > 0)
	{
		catapults_menu = i;
		std::cout << "[" << i << "] Send Catapults\n";
		i++;
	}
	else catapults_menu = 0;
	if (player->GetRemainSolders(Player::SWORDSMAN) > 0)
	{
		swordsmen_menu = i;
		std::cout << "[" << i << "] Send Swordsmen\n";
		i++;
	}
	else swordsmen_menu = 0;
	fight_menu = i;
	std::cout << "[" << i << "] Go Fight\n";

	std::cin >> menu_choice;
	if (menu_choice == archers_menu)
		player->SetSend(Player::ARCHER);
	else if (menu_choice == catapults_menu)
		player->SetSend(Player::CATAPULT);
	else if (menu_choice == swordsmen_menu)
		player->SetSend(Player::SWORDSMAN);
	else if (menu_choice == fight_menu)
		return false;
	return true;
}

void Game::GameOver()
{
	if (lost)
	{
		std::cout << "\nYou lost. Try again next time.\n";
		return;
	}
	std::cout << "\nCongratulations, you won!\n";
}