#include "../std_lib_facilities.h"
#include "StringLibrary.h"

int main()
{
    StringLibrary::MyString mySTR;
    string a = "First test";
    string b = " Second test";

    std::cout << "a + b = " <<
        mySTR.Concat(a, b) << std::endl;
    std::cout << "a == b = " <<
        mySTR.Compare(a, b) << std::endl;
    std::cout << "ToUpper " <<
        mySTR.ToUpper(a) << std::endl;
    std::cout << "ToLower " <<
        mySTR.ToLower(a) << std::endl;

    return 0;
}