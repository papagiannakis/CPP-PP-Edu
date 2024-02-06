#include "std_lib_facilities.h"

void ValidGrammar(string input, int mode);
int CheckSentence(string input);
int CheckMultiSentence(string input);


int main(void) {
	string input;
	int mode;

	//Get mode from user
	cout << "Will the string be a single sentence? 0 or 1" << endl;
	cin >> mode;
	if (cin.fail() || mode > 1 || mode < 0) {
		cout << "Please insert 0 for single sentence or 1 for multiple." << endl;
	}
	cin.clear();
	cin.ignore();

	//Get input string and check if the rules specified are valid.
	getline(cin,input);
	ValidGrammar(input, mode);
	
}

void ValidGrammar(string input, int mode) {
	bool is_valid = false;
	if (mode == 0) {

		//Check if single sentence is correct.
		int pos = CheckSentence(input);
		
		//Print result
		if (pos == -1) cout << "The input sentence was valid" << endl;
		else cout << "There is mistake at pos: " << pos + 1 << endl;
	}

	if (mode == 1) {
		//Check if multiple sentences are correct.
		int pos = CheckMultiSentence(input);

		if (pos == -1) cout << "The input sentence was valid" << endl;
		else cout << "There is mistake at pos: " << pos + 1 << endl;;
	}
}

int CheckSentence(string input) {
	bool found_first = false;
	bool found_last = false;
	char first = '?';
	char last = '?';

	//Search for first symbol
	if (input.at(0) == '!' || input.at(0) == '?') {
		found_first = true;
		first = input.at(0);
	}

	//Search for last symbol
	if (input.at(input.size() - 1) == '!' || input.at(input.size() - 1) == '?') {
		found_last = true;
		last = input.at(input.size() - 1);
	}

	//If there is a symbol inbetween return its position
	for (int i = 1; i < input.size()-1; i++) {
		if (input.at(i) == '!' || input.at(i) == '?') {
			return i;
		}
	}

	//Return -1 only if found first & last & they are the same, marking it as valid sentence. Otherwise return the wrong position.
	if (found_first && found_last && first == last) {
		return -1;
	}
	else if (found_first && !found_last) {
		return (int)(input.size() - 1);
	}
	else if (!found_first && found_last) {
		return 0;
	}
	else return 0;
}

int CheckMultiSentence(string input)
{
	char cachedSymbol = ' ';
	int pos = -1;
	bool ignore_next = false;
	bool nextMustBecapital = false;
	bool sentenceHasStarted = false;

	for (int i = 0; i < input.size(); i++) {
		//When founding the first special symbol we also check for capital right after. In that case no need to check the next char.
		if (ignore_next) {
			ignore_next = false;
			continue;
		}

		////When closing a match, we  know that the next character must be capital but we can allow white spaces.
		if (nextMustBecapital) {
			if (isalpha(input.at(i))) {
				if(!isupper(input.at(i))) return i;
				nextMustBecapital = false;
			}
		}

		//This is the first occurence, capital letter should follow also check if capital has already appeared!
		if ((input.at(i) == '!' || input.at(i) == '?') && cachedSymbol == ' ') {	
			cachedSymbol = input.at(i);
			pos = i;
			if (i + 1 < input.size() && !isupper(input.at(i + 1))) {
				nextMustBecapital = true;
			}
			else ignore_next = true;
		}
		//This is the second occurence, if chars do not match with the cached one return the wrong position!
		else if (input.at(i) == '!' || input.at(i) == '?') {
			if (cachedSymbol != input.at(i)) {
				return i + 1;
			}
			else {
				cachedSymbol = ' ';
				pos = -1;
			}
		}
		//If we find upper character before we find cached symbol there is a mistake.!
		else if (isupper(input.at(i)) && cachedSymbol != ' ') {
			return i;
		}
	}
	return -1;
}
