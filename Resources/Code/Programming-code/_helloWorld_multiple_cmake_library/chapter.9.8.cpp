
//
// This is example code from Chapter 9.8 "The Date class" of 
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <iostream>
#include <Chrono.h>

using namespace std;

int main()
try
{
    Chrono::Date holiday(1978, Chrono::Date::jul, 4); // initialization
    Chrono::Date d2(1821, Chrono::Date::mar, 25);

    cout << "holiday is: " << holiday << "\n d2 is: " << d2 << endl;
    if (holiday != d2)
    cout<<"and indeed the two dates are different!"<<endl;
}
catch (Chrono::Date::Invalid&) {
    cerr << "error: Invalid date\n"; 
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n"; 
    return 2;
}

//------------------------------------------------------------------------------
