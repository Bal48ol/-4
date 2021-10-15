#include <iostream>
#include "C:\Users\Yakov\source\repos\лаба4\лаба4\rational.h"

Rational::Rational() 
{
    numerator = 0;
    denominator = 1;
}

Rational::Rational(int n, int d) 
{
    numerator = n;
    denominator = d;
}

Rational::Rational(int n) 
{
    numerator = n;
    denominator = 1;
}

int Rational::getNumerator() 
{
    return numerator;
}

void Rational::setNumerator(int n) 
{
    numerator = n;
}

int Rational::getDenominator() 
{
    return denominator;
}

void Rational::setDenominator(int d) 
{
    denominator = d;
}

void Rational::print() 
{
    std::cout << numerator << "/" << denominator << std::endl;
}

int Rational::gcd(int x, int y)
{
    while (y > 0) {
        int c = x % y;
        x = y;
        y = c;
    }
    return x;
}

void Rational::normalize() 
{
    int nod = gcd(numerator, denominator);
    numerator = numerator / nod;
    denominator = denominator / nod;
}

