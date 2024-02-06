#include "Assignment1.h"

#define PLAYERS_NUMBER 5

int main()
{
	srand(time(NULL));

	int aliveCount = PLAYERS_NUMBER;
	int serialKillerIDX=0;
	int doctorIDX = 0;
	int LastDeadPleayer = -1;

	/*Init players and print them*/
	Init(serialKillerIDX,doctorIDX);
	PrintAlivePlayers(serialKillerIDX,doctorIDX);

	/*Game loop. Runs until gangster leaves or one civilian remains with gangster*/
	while (alive[serialKillerIDX] == true && GetAlivePlayers().size()>1) {
		try {
			/*Display Menu for user to get any type of info he needs.*/
			DisplayMenu( serialKillerIDX, doctorIDX, LastDeadPleayer);
		}
		catch (string s) {
			cout << "Bad Input was given" << endl;
		}


		NightEvent(serialKillerIDX, doctorIDX);
		DayEvent(serialKillerIDX, doctorIDX, LastDeadPleayer);
	}

	PrintWinMessage(serialKillerIDX);
}


void Init( int& serialKillerIDX, int& doctorIDX) {
	for (int i = 0; i < PLAYERS_NUMBER; i++) {
		players.push_back(i);
		alive.push_back(true);
	}

	while (serialKillerIDX == doctorIDX) {
		serialKillerIDX = rand() % PLAYERS_NUMBER;
		doctorIDX = rand() % PLAYERS_NUMBER;
	}
}
void PrintAlivePlayers(int serialKillerIDX, int doctorIDX) {
	cout << "---Alive players---" << endl;
	
	for (int i = 0; i < PLAYERS_NUMBER; i++) {
		if (alive[i]) {
			cout << "Player ["<<i<<"]";
			if (i == serialKillerIDX) cout << " -- Gangster";
			if (i == doctorIDX) cout << " -- Doctor";
			cout << endl;
		}
	}
	cout << "-----------" << endl<<endl;

}
void PrintAlivePlayersNoRoles() {
	cout << "---Alive players---" << endl;

	for (int i = 0; i < PLAYERS_NUMBER; i++) {
		if (alive[i]) {
			cout << "Player [" << i << "]";
			cout << endl;
		}
	}
	cout << "-----------" << endl << endl;

}
void NightEvent(int SerialKillerIDX, int doctorIDX) {
	int deadPlayerIDX = 0, doctorPlayerIDX=-1;
	
	//Announce that night event start and prompt the gangster to select a player.
	cout << "Night comes and the Gangster [Player" << SerialKillerIDX<< "] roams..." << endl;
	cout << "The Gangster kills player: ";
	deadPlayerIDX = GetValidInput(GetAlivePlayers());


	//Check if doctor is still in the game. If yes then prompt him to select a player.
	if (alive[doctorIDX]){
		cout << "The doctor visits house of player: ";
		doctorPlayerIDX= GetValidInput(GetAlivePlayers());
	}
	//Check if doctor has saved a player
	if (deadPlayerIDX == doctorPlayerIDX && deadPlayerIDX!=doctorIDX) {
		cout << "The doctor saved player[" << deadPlayerIDX << "]" << endl;
	}
	else {
		//Remove the player that the doctor failed to save.
		KillPlayer(deadPlayerIDX);
	}

	PrintAlivePlayers(SerialKillerIDX,doctorIDX);

}
void KillPlayer( int deadPlayerIDX) {
	//If the player is still in the game remove him.
	if (alive[deadPlayerIDX]) alive[deadPlayerIDX] = false;
	else cout << "the player is already dead";
}
void DayEvent( int SerialKillerIDX, int doctorIDX, int& LastDeadPleayer) {
	//Announce that day event is starting.
	cout << "Day comes and the people start suspecting each other." << endl;
	cout << "Each player is voting for who is the killer: " << endl;
	
	vector<int> votes(PLAYERS_NUMBER,0);
	//Show the eleigible players for voting.
	PrintEligiblePlayers(votes);
	//Prompt each user to vote.
	Election(votes);
	
	//Prepare for second phase if needed by recalculating the eligible players.
	int startingNumberofPlayers = votes.size();
	PrepareElectionSecondPhase(votes);

	/*
	Compute the result.
	If - 2 then there is no winner.
	If - 1 then redo the trial.
	If >0 then a player has been chosen.
	*/
	int votingResult = VotingResult(votes, startingNumberofPlayers);
	if (votingResult == -2) {
		cout << "Voting ended without a winner." << endl;
	}
	else if (votingResult == -1) {
		cout << "Restarting voting..." << endl;
		//Redo the election and reprint the eligible players for the user to choose.
		PrintEligiblePlayers(votes);
		
		for (int i = 0; i < PLAYERS_NUMBER; i++) {
			int currentvote = 0;
			if (alive[i]) {
				cout << "Player[" << i << "] votes player: ";
				cin >> currentvote;
				if (alive[currentvote] && votes[currentvote] >= 0) {
					votes[currentvote]++;
				}
				else {
					cout << "Chosen player is not in the voting system" << endl;
					i--;
				};
			}
		}
		votingResult = VotingResult(votes, startingNumberofPlayers);
	}

	//If we have a "winner" set it to votedplayer and remove him.
	if (votingResult >= 0) {
		LastDeadPleayer = votingResult;
		KillPlayer(votingResult);
		cout << "Player[" <<votingResult << "] was removed" << endl;
	}
	else {
		LastDeadPleayer = -1;
		cout << "Finished voting without a winner" << endl;
	}

	PrintAlivePlayers(SerialKillerIDX, doctorIDX);
}
int VotingResult(vector<int> votes, int StartingVoters) {
	int voteMAX = -1;
	int playerIDX = 0;

	/*If the eligible candidates are the same as the starting voters there is no reelection.*/
	if (FindSizeofCandidates(votes) == StartingVoters) {
		return -2;
	}

	/*Find the number of users that have the maximum amount of votes*/
	for (int i = 0; i < PLAYERS_NUMBER; i++) {
		if (votes[i] > voteMAX) {
			voteMAX = votes[i];
			playerIDX = i;
		}
	}

	/*If not all the players have the maximum but there is more than on return a value that describes "reelection"*/
	for (int i = 0; i < PLAYERS_NUMBER; i++) {
		if (voteMAX == votes[i] && playerIDX != i) {
			return -1;
		}
	}
	return playerIDX;
}
void PrintWinMessage(int serialKiller) {
	vector<int> alivePlayers;
	alivePlayers = GetAlivePlayers();
	if (alivePlayers.size() == 1) {
		/*If gangster is removed then civilians have won.*/
		if (alivePlayers[0] == serialKiller) cout << endl << "------------Gangster wins!!!!---------" << endl;
	}
	else {
		/*Else civilians win.*/
		cout << endl << "------------Civilians win!!!!---------" << endl;
	}
}
void PrintEligiblePlayers(vector<int> votes) {

	/*Prints all players that have current votes >=0.*/
	cout << "---Available candidates----" << endl;
	for (int i = 0; i < votes.size(); i++) {
		if(alive[i] && votes[i]>=0) cout << "Player [" << i << "]"<<endl;
	}
	cout << endl << endl;
}
void Election(vector<int>& votes) {
	/*Calls the vote function of each player.*/
	for (int i = 0; i < PLAYERS_NUMBER; i++) {
		int currentvote = 0;
		if (alive[i]) {
			cout << "Player[" << i << "] votes player: ";
			currentvote= GetValidInput(players);
			if (alive[currentvote]) votes[currentvote]++;
		}
	}
}
void PrepareElectionSecondPhase(vector<int>& votes) {
	int votesMAX = -1;
	int returnValue = 0;
	vector<int> tobeErasedIDX;
	
	//Find the maximum amount of votes
	for (int i = 0; i < PLAYERS_NUMBER; i++) {
		if (votes[i] > votesMAX) votesMAX = votes[i];
	}


	/*
	* If a player has lest than the maximum amount set his current votes to - 1
	* invalidating from the next candidates
	*/
	for (int i = 0; i < PLAYERS_NUMBER; i++) {
		if (votes[i] < votesMAX) votes[i] = -1;
		else votes[i] = 0;
	}

	
}
int FindSizeofCandidates(vector<int> candidates) {

	//Return the number of players that have >=0 number of votes.
	int candidatesSize=0;
	for (int i = 0; i < candidates.size(); i++) {
		if (candidates[i] < 0) continue;
		candidatesSize++;
	}

	return candidatesSize;
}
void DisplayMenu(int serialKillerIDX, int doctorIDX, int LastPlayer){
	int option = -1;

	while (option != 0) {
		//Print options to user
		cout << "Choose one of the following options:" << endl;
		cout << "1. Show players information" << endl;
		cout << "2. Show players infromaiton and their roles" << endl;
		cout << "3. Show players that left game" << endl;
		cout << "4. Show last player that left the game" << endl;
		cout << "Type 0 to continue the game." << endl;

		//Check for input correctness
		cin >> option;
		if (cin.fail())
		{
			//If wrong input throw exception and clear cin for next input.
			std::cin.clear();
			std::cin.ignore(256, '\n');
			throw "Wrong input. Please enter one integer from 0-4: ";
		}

		/*Print results based on the option*/
		switch (option)
		{
		case 1:
			PrintAlivePlayers(serialKillerIDX, doctorIDX);
			break;

		case 2:
			PrintAlivePlayersNoRoles();
			break;

		case 3:
			cout << "---Dead players---" << endl;

			for (int i = 0; i < PLAYERS_NUMBER; i++) {
				if (!alive[i]) {
					cout << "Player [" << i << "]";
					cout << endl;
				}
			}
			cout << "-----------" << endl << endl;
			break;

		case 4:
			if (LastPlayer >= 0) {
				cout << "The last player who left was: Player[" << LastPlayer << "]" << endl;
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
	}
}
int GetValidInput(vector<int> availableInt) {
	bool correct = false;
	int input=-1;
	while (!correct) {
		try {
			cin >> input;
			if (cin.fail()) {
				//If wrong input throw exception and clear cin for next input.
				std::cin.clear();
				std::cin.ignore(256, '\n');
				throw "Wrong input. Please enter one integer\n";
			}

			for (int i = 0; i < availableInt.size(); i++) {
				if (input == availableInt[i]) {
					correct = true;
				}
			}
			/*If input refers to a dead player or that ID does not exist ask again for input.*/
			if (correct == false) {
				throw "Wrong input. Please enter one integer\n";
			}
		}
		catch (const char* msg) {
			cerr << msg;
		}
	}

	return input;
}
vector<int> GetAlivePlayers() {
	//Create new vector that will have ONLY the players that are alive.
	vector<int> alivePlayers;

	for (int i = 0; i < alive.size(); i++) {
		if (alive[i]) alivePlayers.push_back(i);
	}

	return alivePlayers;
}