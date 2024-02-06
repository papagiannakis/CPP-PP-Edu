
//
// This is example code from Chapter 8.6 "Order of evaluation" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"


// Calculate Fibonacci numbers (0, 1, 1, 2, 3, 5, 8, 13....) 
// using recursive function.
// A very inefficient way, but illustrates recursion well
int fib(int number)
{
	if (number == 0) return 0;
	if (number == 1) return 1;
	return (fib(number-1) + fib(number-2));
}

int main(){	// driver function
	int inp_number=4;
	//cout << "Please enter an integer: ";
	//cin >> inp_number;
	cout << "The Fibonacci number for "<< inp_number 
		 << " is "<< fib(inp_number)<<endl;
  return 0;
}