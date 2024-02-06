#pragma once
#include "std_lib_facilities.h"

int FastCalculate(int a, int b, int mode);

int main() {
	int a, b;
	int mode;
	try {
		cout << "Please insert your 2 integers: " << endl;
		cin >> a >> b;

		//checking if user gave correct input and handling it with the appropriate exeption message.
		if (cin.fail()) {
			throw runtime_error("Wrong input. Please insert two integers.");
		}

		//checking if user gave correct input and handling it with the appropriate exeption message.
		cout << "Select mode (from 1 to 5): ";
		cin >> mode;
		if (cin.fail() || mode < 1 || mode > 5) {
			throw runtime_error("Wrong Input. Mode must be and integer and exist in [1 5]. ");
		}

		//finally print the result.
		cout << "Result is: " << FastCalculate(a, b, mode) << endl;
	}
	catch (exception& e) {
		cout << "Caught exception: " << e.what() << endl;
	}
}

int FastCalculate(int a, int b, int mode)
{
	//switch to handle all the modes that are needed
	switch (mode) {

	case 0:
		return -1;
	case 1:
	{
		return a * b;
	}
	case 2:
	{
		if (b == 0) throw runtime_error("Your denominator was 0. Cannod devide by 0.");
		return a / b;
	}
	case 3:
	{
		//casting here to avoid warnings, no need for students to cast.
		double a2 = a * a;
		double b2 = b * b;
		if (a2 == 0 && b2 == 0) throw runtime_error("Both a and b are 0 cannot calculate sqrt of 0.");;
		return (int) sqrt(a2 + b2);
	}
	case 4:
		//same here, casting is not necessary
		return (int)pow(a, b);
	case 5:
		return a % b;
	default:
		return -1;
	}
}
	
