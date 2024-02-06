#include "StringLibrary.h"

namespace StringLibrary
{
    string MyString::Concat(string a, string b)
    {
        return a + b;
    }

    int MyString::Compare(string a, string b)
    {
        return a.compare(b);
    }

string MyString::ToUpper(string a)
    {
        for_each(a.begin(), a.end(), [](char& c) {
            c = ::toupper(c);
        });
        return a;
    }

string MyString::ToLower(string a)
    {
        for_each(a.begin(), a.end(), [](char& c) {
            c = ::tolower(c);
        });

        return a;
    }
}

