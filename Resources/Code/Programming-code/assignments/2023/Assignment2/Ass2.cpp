#pragma once
#include "Ass2.h"

vector<Player*> players;
vector<Round*> roundInfo;
Round currentRound;

int main()
{
	int serialKillerIDX = 0;
	Player votedPlayer;
	Player killedPlayer;

	/*Load players from file and print them*/
	Init("Players.txt");
	PrintPlayers(AlivePlayers);

	/*Game loop. Runs until gangster leaves or one civilian remains with gangster*/
	while (GetGangster(serialKillerIDX)->isAlive() == true && AlivePlayersCount() > 2) {
		/*Init round and start night event*/
		currentRound.setRoundNO(currentRound.getRoundNO() + 1);
		NightEvent(killedPlayer);

		/*Once night event ends start day event. And finally save this round.*/
		DayEvent(votedPlayer);
		SaveRound(votedPlayer,killedPlayer);
		
		/*Display Menu for user to get any type of info he needs.*/
		if (votedPlayer.GetName() != "")
			DisplayMenu(votedPlayer);
		else if (killedPlayer.GetName() != "")
			DisplayMenu(killedPlayer);
		else DisplayMenu(votedPlayer);

		ResetVotes();
	}


	/*Print winner and export output file*/
	ExportRounds();
	PrintWinMessage();
}


void Init(string FileName) {
	ifstream playersFile(FileName);
	string username, role;
	
	/*Read file till you reach the end.*/
	while (!playersFile.eof()) {
		
		/*Get username and role*/
		playersFile >> username;
		playersFile >> role;

		/*Create a new player and add it to global vector*/
		Player* p = new Player(username, true, role);
		players.push_back(p);
	}

}
int AlivePlayersCount() {
	int count = 0;

	/*Count how many players are still in the game.*/
	for (int i = 0; i < players.size(); i++) {
		if (players[i]->isAlive()) count++;
	}

	return count;
}
vector<Player*> GetAllPlayers()
{
	return players;
}
void ExportRounds()
{
	//Create file for output with name TownOfSalem_Output.txt
	ofstream output("TownOfSalem_Output.txt");
	
	for (int i = 0; i < roundInfo.size(); i++) {
		roundInfo[i]->RoundExport(output); //Export each round.
	}

	//Close stream after export has finished.
	output.close();
}
void ResetVotes()
{
	for (int i = 0; i < players.size(); i++) {
		players[i]->SetVotes(0);
	}
}
void PrintPlayers(PlayersType type) {
	switch (type) {
		case AlivePlayers:
			cout << "---Alive players---" << endl;

			for (int i = 0; i < players.size(); i++) {
				if (players[i]->isAlive()) {
					cout << "Player[" << i << "]: ";
					cout << players[i]->GetName();
					cout << " -- " << players[i]->GetRole();
					cout << endl;
				}
			}
			cout << "-----------" << endl << endl;
			break;
		case Players_NoRoles:
			cout << "---Alive players---" << endl;

			for (int i = 0; i < players.size(); i++) {
				if (players[i]->isAlive()) {
					cout << "Player[" << i << "]: ";
					cout << players[i]->GetName();
					cout << endl;
				}
			}
			cout << "-----------" << endl << endl;
			break;
		case DeadPlayers:
			cout << "---Dead players---" << endl;

			for (int i = 0; i < players.size(); i++) {
				if (!players[i]->isAlive()) {
					cout << "Player[" << i << "]: ";
					cout << players[i]->GetName();
					cout << endl;
				}
			}
			cout << "-----------" << endl << endl;

			break;
	}


}
void SaveRound(Player voted, Player killed) {

	/*Create a new round to save with the information of the current round*/
	Round *newRound = new Round(currentRound.getRoundNO(), killed, voted);
	//Set the needed information of this round.
	currentRound.SetLastKilled(killed);
	currentRound.SetLastVoted(voted);

	//Print and save the current round.
	currentRound.Print();
	roundInfo.push_back(newRound);
}
void NightEvent(Player& KilledPlayer) {
	int deadPlayerIDX = 0, doctorPlayerIDX = -1, gangsterIDX = -1, doctorChosenIDX=-1;
	Player* Doctor = GetDoctorIDX(doctorPlayerIDX);
	Player* Gangster = GetGangster(gangsterIDX);

	//Announce that night event start and prompt the gangster to select a player.
	cout << "Night comes and the Gangster [" << GetGangster(gangsterIDX)->GetName() << "] roams..." << endl;
	cout << "The Gangster kills player: ";
	deadPlayerIDX = GetValidInput(AlivePlayers);
	
	//Check if doctor is still in the game. If yes then prompt him to select a player.
	if (Doctor->isAlive()) {
		cout << "The doctor visits house of player: ";
		doctorChosenIDX = GetValidInput(AlivePlayers);
	}
	//Check if doctor has saved a player
	if (deadPlayerIDX == doctorChosenIDX && deadPlayerIDX != doctorPlayerIDX) {
		cout << "The doctor saved player[" << deadPlayerIDX << "]: "<< players[doctorChosenIDX]->GetName() << endl<<endl;
	}
	else {
		//Remove the player that the doctor failed to save.
		KillPlayer(deadPlayerIDX);
		KilledPlayer = *players[deadPlayerIDX];
	}

}
void KillPlayer(int deadPlayerIDX) {
	//If the player is still in the game remove him.
	if (players[deadPlayerIDX]->isAlive()) {
		players[deadPlayerIDX]->MarkAsDead();
		cout << "The gangster killed player[" << deadPlayerIDX << "]:" << players[deadPlayerIDX]->GetName() << endl << endl;
	}
	else 
		cout << "the player is already dead" << endl << endl;
}
void DayEvent(Player& VotedPlayer) {

	//Announce that day event is starting.
	cout << "Day comes and the people start suspecting each other." << endl;
	cout << "Each player is voting for who is the killer: " << endl;

	//Show the eleigible players for voting.
	PrintEligiblePlayers();
	//Prompt each user to vote.
	Election();

	//Prepare for second phase if needed by recalculating the eligible players.
	PrepareElectionSecondPhase();
	
	/*
	Compute the result.
	If - 2 then there is no winner.
	If - 1 then redo the trial.
	If >0 then a player has been chosen.
	*/
	int votingResult = VotingResult();

	if (votingResult == -2) {
		cout << "Voting ended without a winner." << endl;
		
		return;
	}
	else if (votingResult == -1) {
		cout << endl << "Draw Detected. Restarting voting..." << endl;
		//Redo the election and reprint the eligible players for the user to choose.
		PrintEligiblePlayers();
		Election();
		votingResult = VotingResult();
	}

	//If we have a "winner" set it to votedplayer and remove him.
	if (votingResult >= 0) {
		VotedPlayer = *players[votingResult];
		KillPlayer(votingResult);
		cout << "Player[" << votingResult << "]:"<< VotedPlayer.GetName() <<" was removed" << endl;
	}
	else {
		cout << "Finished voting without a winner" << endl;
	}
}
int VotingResult() {
	int voteMAX = -1;
	int playerIDX = 0;
	int drawCount = 0;

	/*Find which is the maximum amounts of votes a candidate has and the candidate*/
	for (int i = 0; i < players.size(); i++) {
		if (players[i]->GetCurrentVotes() > voteMAX) {
			voteMAX = players[i]->GetCurrentVotes();
			playerIDX = i;
		}
	}
	/*Find the number of users that have the maximum amount of votes*/
	for (int i = 0; i < players.size(); i++) {
		if (players[i]->GetCurrentVotes() == voteMAX) {
			drawCount++;
		}
	}

	/*If all the players have the same amount of votes return a value that describes "no_reelection"*/
	if (drawCount == AlivePlayersCount()) {
		return -2;
	}
	else if (drawCount > 1) {
		return -1; //If we have draws then we need reelection.
	}
	return playerIDX; // Else return the player that gets voted out.
}
void PrintWinMessage() {
	int i = 0;

	/*If gangster is removed then civilians have won.*/
	if (!GetGangster(i)->isAlive()) {
		cout << endl << "------------Civilians win!!!!---------" << endl;
		return;
	}

	/*If gangster is alive and two civilians remain have won.*/
	if (AlivePlayersCount() <= 2) {
		cout << endl << "------------Gangster wins!!!!---------" << endl;
	}

}
void PrintEligiblePlayers() {

	/*Prints all players that have current votes >=0.*/
	cout << "---Available candidates----" << endl;
	for (int i = 0; i < players.size(); i++) {
		if (players[i]->isAlive() && players[i]->GetCurrentVotes() >= 0) {
			cout << "Player [" << i << "]: " << players[i]->GetName() << endl;
		}
	}
	cout << endl << endl;
}
void Election() {
	/*Calls the vote function of each player.*/
	for (int i = 0; i < players.size(); i++) {
		players[i]->vote();
	}
}
void PrepareElectionSecondPhase() {
	int votesMAX = -1;
	int returnValue = 0;
	vector<int> tobeErasedIDX;
	
	//Find the maximum amount of votes
	for (int i = 0; i < players.size(); i++) {
		if (players[i]->GetCurrentVotes() > votesMAX) votesMAX = players[i]->GetCurrentVotes();
	}

	/*
	* If a player has lest than the maximum amount set his current votes to - 1 
	* invalidating from the next candidates
	*/	
	for (int i = 0; i < players.size(); i++) {
		if (players[i]->GetCurrentVotes() < votesMAX) players[i]->SetVotes(-1);
		else players[i]->SetVotes(0);
	}


}
int FindSizeofCandidates() {
	//Return the number of players that have >=0 number of votes.
	int candidatesSize = 0;
	for (int i = 0; i < players.size(); i++) {
		if (players[i]->GetCurrentVotes() < 0) continue;
		candidatesSize++;
	}

	return candidatesSize;
}
void DisplayMenu(Player& LastPlayer){
	int option = -1;
	bool correct = false;
	while (option != 0) {
		//Print options to user
		cout << "Choose one of the following options:" << endl;
		cout << "1. Show players information" << endl;
		cout << "2. Show players infromaiton and their roles" << endl;
		cout << "3. Show players that left game" << endl;
		cout << "4. Show last player that left the game" << endl;
		cout << "Type 0 to continue the game." << endl;

		//Check for input correctness
		while (!correct) {
			try {
				cin >> option;
				if (cin.fail()) {
					//If wrong input throw exception and clear cin for next input.
					std::cin.clear();
					std::cin.ignore(256, '\n');
					throw "Wrong input. Please enter one integer from 0-4: ";
				}
				correct = true;
			}catch (const char* msg) {
				cerr << msg;
			}
		}

		/*Print results based on the option*/
		switch (option)
		{
		case 1:
			PrintPlayers(AlivePlayers);
			break;

		case 2:
			PrintPlayers(Players_NoRoles);
			break;

		case 3:
			PrintPlayers(DeadPlayers);
			break;

		case 4:
			if (LastPlayer.GetName()!= "") {
				cout << "The last player who left was: Player[" << LastPlayer.GetName() << "]" << endl;
			}
			else {
				cout << "No player left last round." << endl;
			}
			break;

		case 0:
			break;

		default:
			cout << "Please select one of the available options or 0 to continue" << endl;
		}
		correct = false;
	}
}
int GetValidInput(PlayersType inputMode) {
	bool correct = false;
	int input = -1;

	switch (inputMode) {
		
		case AlivePlayers:
			while (!correct) {
				try {
					cin >> input;
					if (cin.fail()) {
						//If wrong input throw exception and clear cin for next input.
						std::cin.clear();
						std::cin.ignore(256, '\n');
						throw "Wrong input. Please enter one integer\n";
					}

					for (int i = 0; i < players.size(); i++) {
						if (input == i && players[i]->isAlive()) {
							correct = true;
						}
					}
					/*If input refers to a dead player or that ID does not exist ask again for input.*/
					if (correct == false) {
						throw "Wrong input. Please enter one alive player\n";
					}
				}
				catch (const char* msg) {
					cerr << msg;
				}
			}
			break;
		
	case EligiblePlayers:
		while (!correct) {
			try {
				cin >> input;
				if (cin.fail()) {
					std::cin.clear();
					std::cin.ignore(256, '\n');
					throw "Wrong input. Please enter one integer\n";
				}

				for (int i = 0; i < players.size(); i++) {
					if (input == i && players[i]->isAlive() && players[i]->GetCurrentVotes() >= 0) {
						correct = true;
					}
				}
				/*If that player is not eligible for voting re-ask for input..*/
				if (correct == false) {
					throw  "Wrong input. Please enter one eligible player\n";
				}
			}
			catch (const char* msg) {
				cerr << msg;
			}
		}
		break;

	}

	return input;
}
Player* GetGangster(int& idx) {
	//Find the player with the Role "Gangster"
	for (int i = 0; i < players.size(); i++) {
		if (players[i]->GetRole() == "Gangster")
			return players[i];
	}

	return nullptr;
}
Player* GetDoctorIDX(int& idx) {
	//Find the player with the Role "Doctor"
	for (int i = 0; i < players.size(); i++) {
		if (players[i]->GetRole() == "Doctor") {
			idx = i;
			return players[i];
		}
	}

	return nullptr;
}
bool IsDoctorAlive() {
	//Check if doctor is still alive
	for (int i = 0; i < players.size(); i++) {
		if (players[i]->GetRole() == "Doctor")
			return players[i]->isAlive();
	}
	return false;
}