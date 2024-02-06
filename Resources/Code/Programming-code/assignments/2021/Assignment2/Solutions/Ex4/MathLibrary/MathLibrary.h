// MathLibrary.h
#pragma once

namespace MathLibrary
{
    class Arithmetic
    {
    public:
        // Returns a + b
        float Add(float a, float b);

        // Returns a - b
        float Subtract(float a, float b);

        // Returns a * b
        float Multiply(float a, float b);

        // Returns a / b
        float Divide(float a, float b);
    };
}