#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Simple_window.h"    // get access to our window library
#include "Graph.h"            // get access to our graphics library facilities

using namespace Graph_lib;   // our graphics facilities are in Graph_lib
using namespace std;

/*Class that represents players.*/
class Player {
private:
	string name; //Username of player.
	bool alive; //Variable that determines if they are still in the game.
	string role; //Role, can be civilian,gangster or doctor.
	int currentVotes; //Counts how many votes this player has in the current selection.
public:
	/*Constructors*/
	Player();
	Player(string, bool, string);

	/*This player votes another player.*/
	void vote();

	/*Getters&Settters for votes variable*/
	string GetName();
	void SetName(string s);

	/*Getters&Settters for alive variable*/
	bool isAlive();
	void MarkAsDead();

	/*Getters&Settters for role variable*/
	string GetRole();
	void SetRole(string s);

	/*Getters&Settters for votes variable*/
	void IncreaseVotes();
	void SetVotes(int i);
	int  GetCurrentVotes();
};
void Init(string);

void SubmitCallback(Address, Address pw);

void ShowPlayers();

void startVoting();

void ChangeBackground();

int FindPlayerWithMaxVotes();