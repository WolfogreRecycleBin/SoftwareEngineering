#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

#include "Player.h"

using namespace std;      //introduces namespace std
int main(void)
{
	srand(time(0)); //seed the random number generator

	//units that the player starts with
	//int archers = 50;
	//int catapults = 25;
	//int swordsmen = 100;
	Player player(50, 25, 100);
	//units that the Germanians start with (random)
	// random number between 70 and 20
	//between 50 and 10
	//between 150 and 50
	Player germania(rand() % (51) + 20, rand() % (41) + 10, rand() % (101) + 50);
	germania.SetName("Germania");
	bool end = false; //used to test if the user chose to quit
	bool lost; //used to test if the user lost the game

	int menu_choice; //stores the user¡¯s choice from the menu


	

	//stores which numbers correspond to which menu choices
	int archers_menu, catapults_menu, swordsmen_menu;
	int fight_menu;

	cout << "Welcome Adventurer, what is your name?\n";
	player.SetName();
	cout << "Well, " << player.GetName()
		<< " welcome to the Roman Commander Game.\n"
		<< "\nYou are the commander of the Roman Army"
		<< " attacking Germania.";
	while (!end) //main game loop
	{
		player.SetSend(0, 0, 0);
		player.ShowStatus();
		germania.ShowStatus();
		do //pre-battle loop
		{
			//keeps track of which menu numbers
			//are being used
			int i = 1;
			if (player.GetRemainSolders(Player::ARCHER) > 0)
			{
				archers_menu = i;
				cout << "[" << i << "] Send Archers\n";
				i++;
			}
			else archers_menu = 0;
			if (player.GetRemainSolders(Player::CATAPULT) > 0)
			{
				catapults_menu = i;
				cout << "[" << i << "] Send Catapults\n";
				i++;
			}
			else catapults_menu = 0;
			if (player.GetRemainSolders(Player::SWORDSMAN) > 0)
			{
				swordsmen_menu = i;
				cout << "[" << i << "] Send Swordsmen\n";
				i++;
			}
			else swordsmen_menu = 0;
			fight_menu = i;
			cout << "[" << i << "] Go Fight\n";

			cin >> menu_choice;
			if (menu_choice == archers_menu)
			{
				player.SetSend(Player::ARCHER);
			}
			else if (menu_choice == catapults_menu)
			{
				player.SetSend(Player::CATAPULT);
			}
			else if (menu_choice == swordsmen_menu)
			{
				player.SetSend(Player::SWORDSMAN);
			}
		}
		//end pre-battle loop
		while (menu_choice != fight_menu);

		player.BattleWith(end, lost, germania);
	} //end of main game loop

	//display appropriate ending message
	if (lost)
	{
		cout << "\nYou lost. Try again next time.\n";
		return 0;
	}
	cout << "\nCongratulations, you won!\n";
	return 0;
}
