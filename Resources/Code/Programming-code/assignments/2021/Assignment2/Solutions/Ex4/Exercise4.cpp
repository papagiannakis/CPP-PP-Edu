#include "../std_lib_facilities.h"
#include "MathLibrary.h"

int main()
{
    MathLibrary::Arithmetic mathLib;
    float a = 5.50f;
    float b = 87.22f;

    std::cout << "a + b = " <<
        mathLib.Add(a, b) << std::endl;
    std::cout << "a - b = " <<
        mathLib.Subtract(a, b) << std::endl;
    std::cout << "a * b = " <<
        mathLib.Multiply(a, b) << std::endl;
    std::cout << "a / b = " <<
        mathLib.Divide(a, b) << std::endl;

    return 0;
}