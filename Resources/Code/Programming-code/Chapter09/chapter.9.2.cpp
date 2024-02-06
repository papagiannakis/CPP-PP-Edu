
//
// This is example code from Chapter 9.2 "Classes and members" of 
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//------------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
using namespace std;

class X {
public:
    int m;              // data member
    int mf(int v) { int old = m; m=v; return old; } // function member
};

//------------------------------------------------------------------------------

int main()
{
    X var;              // var is a variable of type X
    var.m = 7;          // assign to var's data member m
    int x = var.mf(9);  // call var's member function mf()
    int y(10);
    
    cout<<"var.m :"<<setw(2);
    cout << var.m << endl;
    cout<<"x: "<<setw(6);
    cout << x << endl;

    cout<<"y(10): "<<setw(3);
    cout << y << endl;
    
    return x;
}

//------------------------------------------------------------------------------


/*
 // setw example
 #include <iostream>
 #include <iomanip>
 using namespace std;
 
 int main () {
 cout << setw (10);
 cout << 77 << endl;
 return 0;
 }
 */