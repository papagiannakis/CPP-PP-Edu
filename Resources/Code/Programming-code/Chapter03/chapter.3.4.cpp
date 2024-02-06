
//
// This is example code from Chapter 3.4 "Operations and operators" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
{
    int count;
    cin >> count;                // >> reads an integer into count
    string name;
    cin >> name;                 // >> reads a string into name

    int c2 = count+2;            // + adds integers
    string s2 = name + " Jr. ";  // + appends characters

    int c3 = count-2;            // - subtracts integers
    //string s3 = name - "Jr. "; // error: - isn't defined for strings
    
    cout<<"count: "<<count<<" and name: "<<name<<endl;
    cout<<"c2: "<<c2<<" and s2: "<<s2<<endl;
    cout<<"c3: "<<c3<<endl;

    int age = -100;
}

//------------------------------------------------------------------------------
