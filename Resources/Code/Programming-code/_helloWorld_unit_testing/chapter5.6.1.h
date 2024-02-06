//
// This is example code from Chapter 5.6.1 "Bad arguments" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//
#pragma once


//------------------------------------------------------------------------------

class Bad_area { };    // a type specifically for reporting errors from area()

//------------------------------------------------------------------------------


// calculate area of a rectangle;
// throw a Bad_area exception in case of a bad argument
int area(int length, int width)
{
    if (length<=0 || width <=0) throw Bad_area();
    return length*width;
}