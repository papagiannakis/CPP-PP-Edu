#pragma once
#include "Ass2.h"

/*Default Costructor*/
Round::Round()
{
	roundNO = 0;
	LastKilled = Player();
	LastVoted = Player();
}

/*Init Costructor*/
Round::Round(int RNO, Player LastK, Player LastV)
{
	roundNO = RNO;
	LastKilled = LastK;
	LastVoted = LastV;
}

int Round::getRoundNO()
{
	return roundNO;
}

void Round::setRoundNO(int RNO)
{
	roundNO = RNO;
}

Player Round::GetLastKilled()
{
	return LastKilled;
}

void Round::SetLastKilled(Player LastK)
{
	LastKilled = LastK;
}

Player Round::GetLastVoted()
{
	return LastVoted;
}

void Round::SetLastVoted(Player LastV)
{
	LastVoted = LastV;
}

/*Write this round to the console*/
void Round::Print()
{
	cout <<endl<< "--------------ROUND INFO-------------"<<endl;
	cout << "Round:" << roundNO << " finished."<<endl;
	if (LastKilled.GetName() != "")
		cout << "Player: " << LastKilled.GetName() << " was killed." << endl;
	else
		cout << "No player was killed."<< endl;
	if(LastVoted.GetName() != "")
		cout << "Player: " << LastVoted.GetName() << " was elected." << endl;
	else
		cout << "The election was inconclusive." << endl;
	cout << "---------------------------" << endl<< endl;

}

/*Write this round to the ofstream file*/
void Round::RoundExport(ofstream& file)
{
	file << "Round:" << roundNO <<endl << endl;
	if (LastKilled.GetName() != "")
		file << "Player: " << LastKilled.GetName() << " was killed." << endl;
	else
		file << "No player was killed." << endl;
	if (LastVoted.GetName() != "")
		file << "Player: " << LastVoted.GetName() << " was elected." << endl;
	else
		file << "The election was inconclusive." << endl;

	file << "---------------------------" << endl << endl;

}


