#include <iostream>

class Rational
{
public:
	Rational();	// конструктор по умолчанию 0/1	
	Rational(int n, int d); // конструктор n/d
	Rational(int n); // конструктор создания дроби 𝑁/1 из целого числа N

	int getNumerator();
	void setNumerator(int n);
	int getDenominator();
	void setDenominator(int d);
	void print();

private:
	int numerator;
	int denominator;

	int gcd(int x, int y);
	void normalize();
};
