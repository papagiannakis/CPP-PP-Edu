// MathLibrary.h
#pragma once
#include <string>
#include <algorithm>

using namespace std;

namespace StringLibrary
{
    class MyString
    {
    public:
        // Returns a + b
        string Concat(string a, string b);

        // Returns a - b
        int Compare(string a, string b);

        // Returns a * b
        string ToUpper(string a);

        // Returns a / b
        string ToLower(string a);
    };
}