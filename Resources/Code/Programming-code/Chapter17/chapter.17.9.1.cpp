
//
// This is example code from Chapter 17.9.1 "Pointer and reference parameters" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int  incr_v(int x) { return x+1; } // compute a new value and return it
void incr_p(int* p) { cout<<"incr_p p:="<<p<<" and *p:="<<*p<<endl; ++*p; }      // pass a pointer
                                   // (dereference it and increment the result)
void incr_r(int& r) { ++r; }       // pass a reference

void incr_p(char* p)
{
    if (p==0) error("null pointer argument to incr_p()");
    ++*p; // dereference the pointer and increment to object pointed to
}

//------------------------------------------------------------------------------

int main()
try
{
    // returning the value often leads to the most obvious
    {
        int x = 2;
        incr_v(x);
        cout<<"Copy x:= "<<x<<endl;
        x = incr_v(x); // copy x to incr_v(); then copy the result out and assign it
        cout<<"Copy assignment x:= "<<x<<endl;
    }

    // Using a pointer argument alerts the programmer that something might be changed
    {
        int x = 7;
        incr_p(&x);    // the & is needed
        cout<<"Pointer x:= "<<x<<endl;
        incr_r(x);
        cout<<"Reference x:= "<<x<<endl;
    }

    // someone might call it with a null pointer
    {
        //incr_p(0);     // crash: incr_p() will try to dereference 0
        char* p = 0;
        incr_p(p);     // crash: incr_p() will try to dereference 0
    }
}
catch (exception& e) {
    cerr << "error: " << e.what() << '\n'; 
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n"; 
    return 2;
}

//------------------------------------------------------------------------------
