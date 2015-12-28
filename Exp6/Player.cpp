#include <iostream>
#include <string>
#include "Player.h"

Player::Player(int archers, int catapults, int swordsmen)
{
	this->archers = archers;
	this->catapults = catapults;
	this->swordsmen = swordsmen;
}

Player::~Player()
{

}

void Player::SetName()
{
	std::cin >> name;
}

void Player::SetName(std::string name)
{
	this->name = name;
}

std::string Player::GetName()
{
	return name;
}

void Player::ShowStatus()
{
	std::cout << "\n" << name << " has " << archers
		<< " archers, " << catapults
		<< " catapults, and "
		<< swordsmen << " swordsmen.\n";
}

int Player::GetRemainSolders(SolderType st)
{
	switch (st)
	{
	case Player::ARCHER:
		return archers - archers_sent;
		break;
	case Player::CATAPULT:
		return catapults - catapults_sent;
		break;
	case Player::SWORDSMAN:
		return swordsmen - swordsmen_sent;
		break;
	}
	return -1;
}

void Player::SetSend(SolderType st)
{
	switch (st)
	{
	case Player::ARCHER:
		do {
			std::cout << "How many archers"
				" would you like to send?\n";
			std::cin >> archers_sent;
		} while (!(archers_sent > -1
			&& archers_sent <= archers));
		break;
	case Player::CATAPULT:
		do {
			std::cout << "How many catapults"
				" would you like to send?\n";
			std::cin >> catapults_sent;
		} while (!(catapults_sent > -1 &&
			catapults_sent <= catapults));
		break;
	case Player::SWORDSMAN:
		do {
			std::cout << "How many swordsmen"
				" would you like to send?\n";
			std::cin >> swordsmen_sent;
		} while (!(swordsmen_sent > -1 &&
			swordsmen_sent <= swordsmen));
		break;
	}
}

void Player::SetSend(int archers_sent, int catapults_sent, int swordsmen_sent)
{
	this->archers_sent = archers_sent;
	this->catapults_sent = catapults_sent;
	this->swordsmen_sent = swordsmen_sent;
}

void Player::BattleWith(bool & end, bool & lost, Player & other_player)
{
	std::cout << "\nEntering Battle...\n";

	int archers_dead, catapults_dead, swordsmen_dead;
	int g_archers_dead, g_catapults_dead;
	int g_swordsmen_dead;

	//each catapult kills 2 archers
	archers_dead = 2 * other_player.catapults;
	//each swordsman kills 1 catapult
	catapults_dead = other_player.swordsmen;
	//each archer kills 3 swordsmen
	swordsmen_dead = 3 * other_player.archers;

	g_archers_dead = 2 * catapults_sent;
	g_catapults_dead = swordsmen_sent;
	g_swordsmen_dead = 3 * archers_sent;

	//makes sure that the number of 
	//units does not go below 0.
	archers = (archers_dead < archers) ?
		archers - archers_dead : 0;
	catapults = (catapults_dead < catapults) ?
		catapults - catapults_dead : 0;
	swordsmen = (swordsmen_dead < swordsmen) ?
		swordsmen - swordsmen_dead : 0;

	other_player.archers = (g_archers_dead < other_player.archers) ?
		other_player.archers - g_archers_dead : 0;
	other_player.catapults = (g_catapults_dead < other_player.catapults) ?
		other_player.catapults - g_catapults_dead : 0;
	other_player.swordsmen = (g_swordsmen_dead < other_player.swordsmen) ?
		other_player.swordsmen - g_swordsmen_dead : 0;

	std::cout << "It was a long battle. "
		<< archers_dead << " archers died.\n"
		<< catapults_dead << " catapults died.\n"
		<< swordsmen_dead << " swordsmen died.\n";
	//if player¡¯s army is dead than they have lost
	if ((archers + catapults + swordsmen) == 0)
	{
		end = lost = true;
		return;
	}
	//if germanium army is dead, player has won
	if ((other_player.archers + other_player.catapults
		+ other_player.swordsmen) == 0)
	{
		lost = false;
		end = true;

	}
	end = false;
}
	


