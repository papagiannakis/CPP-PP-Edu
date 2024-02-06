#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

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

/*Class that represents Rounds.*/
class Round {
private:
	int roundNO = 0; //ID of this round.
	Player LastKilled; //The player that was killed this round.
	Player LastVoted; //The player that was removed this round.

public:
	/*Constructors*/
	Round();
	Round(int, Player, Player);

	/*Getters&Settters for roundNO variable*/
	int getRoundNO();
	void setRoundNO(int);

	/*Getters&Settters for LastKilled variable*/
	Player	GetLastKilled();
	void	SetLastKilled(Player);

	/*Getters&Settters for LastVoted variable*/
	Player	GetLastVoted();
	void	SetLastVoted(Player);

	/*Helper function for printing this round to the console.*/
	void Print();

	/*Export this round to the output file*/
	void RoundExport(ofstream&);
};

/*Enum used to define how input/output will be handled.*/
enum PlayersType
{
	AlivePlayers,
	AllPlayers,
	EligiblePlayers,
	Players_NoRoles,
	DeadPlayers
};

/*Init function that loads players from file*/
void Init(string);

/*Print all players that meet the criteria of enum PlayersType*/
void PrintPlayers(PlayersType type);

/*Save Current round.*/
void SaveRound(Player voted, Player killed);

/*The NightEvent function. Returns the killed player, default if no player was killed.*/
void NightEvent(Player& KilledPlayer);

/*The DayEvent function. Returns the removed player, default if no player was elected.*/
void DayEvent(Player& VotedPlayer);

/*Helper function that removes the deadPlayerIDX player.*/
void KillPlayer(int deadPlayerIDX);

/*Run election.*/
void Election();

/*Based on the results of the election determines if a player will be removed*/
int VotingResult();

/*Helper function. Returns the number of eligible candidates*/
int FindSizeofCandidates();

/*Helper function. Prints the number of eligible candidates*/
void PrintEligiblePlayers();

/*Helper function. Prints the result of the match.*/
void PrintWinMessage();

/*Helper function. Prepares the candidates for the second phase by reinitializing their votes.*/
void PrepareElectionSecondPhase();

/*Displays the menu to the user where he can select different types of info.*/
void DisplayMenu(Player& LastPlayer);

/*Helper function. Validates the input of user based on the criteria of playerType.*/
int GetValidInput(PlayersType inputMode);

/*Helper functions. That return the gangster/doctor and the corresponding id.*/
Player* GetGangster(int& idx);
Player* GetDoctorIDX(int& idx);

/*Helper function. Find the count of alive players*/
int AlivePlayersCount();

/*Helper function. Get all players*/
vector<Player*> GetAllPlayers();

/*Export all rounds.*/
void ExportRounds();

/*Helper function. Reset all votes after each cycle.*/
void ResetVotes();