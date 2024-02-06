#pragma once
#include <iostream>
#include <vector>


using namespace std;
/*Global vector that holds the players and their "aliveness"*/
vector<int> players;
vector<bool> alive;

//Init Function that assigns serialKiller and Doctor.
void Init(int& serialKillerIDX, int& DoctorIDX);

//Prints all AlivePlayers
void PrintAlivePlayers( int serialKillerIDX, int doctorIDX);

//Starts the NightEvent where SK and Doctor use their roles.
void NightEvent( int SerialKillerIDX, int DoctorIDX);

//Removes a player fromt the game.
void KillPlayer( int deadPlayerIDX);

//Starts the Day event where users vote for which player to leave.
void DayEvent(int SerialKillerIDX, int doctorIDX, int& LastDeadPleayer);

//Voting system, prompts the users to select another user.
void Election( vector<int>& votes);

//Returns the result of the current election.
int VotingResult(vector<int> votes, int StartingVoters);

//Returns the count of the current candidates.
int FindSizeofCandidates(vector<int> candidates);

//Prints the current candidates.
void PrintEligiblePlayers( vector<int> votes);

//Prints the message at the end of the game, informing user who won.
void PrintWinMessage( int serialKiller);

//Prepares election for the second phase.
void PrepareElectionSecondPhase(vector<int>& votes);

//Show menu for the users to select information.
void DisplayMenu( int serialKillerIDX, int doctorIDX, int LastDeadPleayer);

//Get Input from user, check for invalid input.
int GetValidInput(vector<int> availableInt);

//Returns a vector with Only the alive players.
vector<int> GetAlivePlayers();