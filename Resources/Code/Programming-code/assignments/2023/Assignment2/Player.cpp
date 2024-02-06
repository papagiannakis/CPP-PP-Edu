#pragma once
#include "Ass2.h"
/*Default constructor*/
Player::Player()
{
	name = "";
	alive = true;
	role = "Civilian";
	currentVotes = 0;

}

/*Init constructor*/
Player::Player(string Name , bool isAlive, string Role)
{
	name = Name;
	alive = isAlive;
	role = Role;
	currentVotes = 0;
}

/*Gets input from terminal and adds the vote to the corresponing player.*/
void Player::vote()
{
	int currentVote = 0;
	vector<Player*> players = GetAllPlayers();
	if (alive) {
		cout << "Player:" << name << " votes player : ";
		currentVote = GetValidInput(EligiblePlayers);
		players[currentVote]->IncreaseVotes();

	}
}

string Player::GetName()
{
	return name;
}

void Player::SetName(string s)
{
	name = s;
}

bool Player::isAlive()
{
	return alive;
}

void Player::MarkAsDead()
{
	alive = false;
}

string Player::GetRole()
{
	return role;
}

void Player::SetRole(string s)
{
	role = s;
}

void Player::IncreaseVotes()
{
	currentVotes++;
}

void Player::SetVotes(int i)
{
	currentVotes = i;
}

int Player::GetCurrentVotes()
{
	return currentVotes;
}
