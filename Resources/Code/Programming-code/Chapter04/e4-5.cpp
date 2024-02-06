// Bjarne Stroustrup 3/26/2009
// Chapter 4 Exercise 5

#include "std_lib_facilities.h"	
// note that different compilers/SDEs keep header files in different places
// so that you may have to use "../std_lib_facilities.h" or "../../std_lib_facilities.h"
// the ../ notation means "look one directly/folder up from the current directory/folder"

// Correction/errata: % is not defined for floating-point numbers, so we don't implement %
// the alternative would be to use integers for the input values.

// How do you exit?

int main()
{
	cout<< "please enter two floating-point values separated by an operator\n The operator can be + - * or / : ";
	double val1 = 0;
	double val2 = 0;
	char op = 0;
	while (true) {	// read number operation number
		cin>>val1>>op>>val2;
        string oper;
		double result;
		switch (op) {
		case '+':
			oper = "sum of ";
			result = val1+val2; 
			break;
		case '-':
			oper = "difference between ";
			result = val1-val2; 
			break;
		case '*':
			oper = "product of ";
			result = val1*val2; 
			break;
		case '/':
			oper = "ratio of";
			if (val2==0) error("trying to divide by zero");
			result = val1/val2; 
                return 0;
			break;
		//case '%':
		//	oper = "remainder of ";
		//	result = val1%val2; 
		//	break;
		default:
				return 0;
                //error("bad operator");
		}
		cout << oper << val1 << " and " << val2 << " is " << result << '\n';
		cout << "Try again: ";
	}
}
