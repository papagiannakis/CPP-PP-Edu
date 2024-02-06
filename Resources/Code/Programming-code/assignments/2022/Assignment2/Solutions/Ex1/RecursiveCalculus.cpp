//#include "std_lib_facilities.h"


//float ResursiveCalc(int idx , vector<float> numbers, int mode);

/*int main() {

	vector<float> numbers;
	int sizeOfArray=0, inputNumber = 0, calcMode = 0;
	
	//Get Size of array
	cout << "Please insert size of array: ";
	cin >> sizeOfArray;

	try {
		if (cin.fail() || sizeOfArray < 1) {
			throw runtime_error("Wrong size of array.");
		}

		////Get elements of array
		for (int i = 0; i < sizeOfArray; i++) {
			cout << "Please insert number [ " << i << "]: ";
			cin >> inputNumber;
			
			if (cin.fail()) {
				throw runtime_error("Wrong type of number input.");
			}
			numbers.push_back(inputNumber);
		}

		//Choose caluclation mode
		cout << "Please insert the calculation mode (0-2)" << endl
			<< "0 : Addition" << endl
			<< "1 : Multiplication" << endl
			<< "2 : Difference" << endl << "Mode:";

		cin >> calcMode;
		if ((calcMode != 0) && (calcMode != 1) && (calcMode != 2)) {
			throw runtime_error("This mode is not supported");
		}

		//Perform calculation recursively
		ResursiveCalc(0, numbers, calcMode);
	}
	catch (exception e) {
		cout << "Error: " << e.what() << endl;
	}
}

float ResursiveCalc(int idx, vector<float> numbers, int mode)
{
	//Finish when you reach end of vector
	if (idx == numbers.size()-1) return numbers[idx];
	
	//Check what calculation is needed
	switch (mode) {

		case 0:
		{
			//Perform calculation recursively on all elements of array
			float result = ResursiveCalc(idx + 1, numbers, mode);
			numbers[idx] = numbers[idx] + result;
			cout << "numbers[" << idx << "] + " << "numbers[" << idx + 1 << "] =" << numbers[idx] << endl;
			break;
		}
		case 1:
		{
			numbers[idx] = numbers[idx] * ResursiveCalc(idx + 1, numbers, mode);
			cout << "numbers[" << idx << "] * " << "numbers[" + idx + 1 << "] =" << numbers[idx] << endl;
			break;
		}
		case 2:
		{
			numbers[idx] = numbers[idx] - ResursiveCalc(idx + 1, numbers, mode);
			cout << "numbers[" << idx << "] - " << "numbers[" + idx + 1 << "] =" << numbers[idx] << endl;
			break;
		}
	}

	//Return result of this iteration
	return numbers[idx];
}*/
