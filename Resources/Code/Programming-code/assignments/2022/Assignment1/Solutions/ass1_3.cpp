#pragma once
#include "std_lib_facilities.h"

string EncryptDecryptString(string s, int magicnumber, int encrypt);

int main() {
	int magicNumber,mode;
	string InputString;

	try {
		//Get magicNumber input from user.
		cout << "Please give me the magic number:" << endl;
		cin >> magicNumber;
		if (cin.fail() || magicNumber < 0) {
			throw runtime_error("Magic number must be positive.");
		}

		//Get input string from user.
		cout << "What is the string that you want to encrypt/decrypt" << endl;
		cin >> InputString;

		//Get what kind of mode to run (encrypt/decrypt).
		cout << "Do you want to encrypt or decrypt the above sting? (0 or 1)" << endl;
		cin >> mode;
		if (cin.fail() || (mode != 0 && mode != 1)) {
			throw runtime_error("Mode must be either 0 or 1.");
		}
		cout << "The result is: " << EncryptDecryptString(InputString, magicNumber, mode);

	}
	catch (exception e) {
		cout << "Caught exception \"" << e.what() << "\"" << endl;
	}

	
}

string EncryptDecryptString(string s, int magicnumber, int encrypt)
{
	
	string result = "";
	for (int i = 0; i < s.size(); i++) {
		if (encrypt==1) {
			//In case of encryption add magicnumber to character and push it to the new string. Else substract the magic number.
			result.push_back(s.at(i) + magicnumber);
		}
		else
			result.push_back(s.at(i) - magicnumber);;
	}
	//Don't forget the end of string.
	result.push_back('\0');
	return result;
}