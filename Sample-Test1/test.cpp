#include "pch.h"
#include "C:\Users\Yakov\source\repos\лаба4\лаба4\rational.h"

#define RAND ((int)pow(-1, rand() % 2) * rand() % INT_MAX)

TEST(Rational, ConstructorDefault) {
	Rational r;

	for (int i = 0; i < 100; ++i) {
		EXPECT_EQ(r.getNumerator(), 0);
		EXPECT_EQ(r.getDenominator(), 1);
	}
}

TEST(Rational, ConstructorRational) {
	{
		for (int i = -10; i < 10; ++i) {
			for (int j = -10; j < 10; ++j) {
				if (i != 0 && j != 0) {
					int q = std::gcd(i, j);
					Rational r(i, j);
					EXPECT_EQ(r.getNumerator(), i / q);
					EXPECT_EQ(r.getDenominator(), j / q);
				}
			}
		}
	}

	{
		for (int i = 0; i < 10; ++i) {
			int a = RAND;
			int b = RAND;

			if (b != 0) {
				Rational r(a, b);
				int q = std::gcd(a, b);

				EXPECT_EQ(r.getNumerator(), a / q);
				EXPECT_EQ(r.getDenominator(), b / q);
			}
		}
	}

	{
		for (int i = 0; i < 10; ++i) {
			bool error = false;
			try {
				Rational r(RAND, 0);
			}
			catch (std::exception&) {
				error = true;
			}
			EXPECT_TRUE(error);
		}
	}
}

TEST(Rational, ConstructorNumber) {
	for (int i = 0; i < 10; ++i) {
		Rational r(i);

		EXPECT_EQ(r.getNumerator(), i);
		EXPECT_EQ(r.getDenominator(), 1);
	}

	for (int i = 0; i < 10; ++i) {
		int a = RAND;
		Rational r(a);

		EXPECT_EQ(r.getNumerator(), a);
		EXPECT_EQ(r.getDenominator(), 1);
	}
}

TEST(Rational, setGet) {
	{
		Rational r;
		for (int i = -10; i < 10; ++i) {
			r.setNumerator(i);
			EXPECT_EQ(r.getNumerator(), i);
		}
	}

	{
		Rational r;
		for (int i = -10; i < 10; ++i) {
			if (i != 0) {
				r.setDenominator(i);
				EXPECT_EQ(r.getDenominator(), i);
			}
		}
	}

	{
		Rational r;
		bool error = false;
		try {
			r.setDenominator(0);
		}
		catch (std::exception&) {
			error = true;
		}
		EXPECT_TRUE(error);
	}
}

TEST(Rational, print) {
	{
		std::stringstream ss;
		Rational r;
		ss << r.getNumerator();
		EXPECT_EQ(ss.str(), "0");

		for (int i = 1; i < 10; ++i) {
			r.setDenominator(i);
			ss.str("");
			r.print(ss);
			EXPECT_EQ(ss.str(), "0");
		}
	}

	{
		std::stringstream ss;
		Rational r(15);
		ss << r.getNumerator();
		EXPECT_EQ(ss.str(), "15");

		for (int i = 1; i < 10; ++i) {
			int a = RAND;
			r.setNumerator(a);
			ss.str("");
			r.print(ss);
			EXPECT_EQ(ss.str(), std::to_string(a));
		}
	}

	{
		std::stringstream ss;
		for (int i = 1; i < 10; ++i) {
			for (int j = 10; j > i; --j) {
				Rational r(i, j);
				int gcd = std::gcd(i, j);
				ss.str("");
				r.print(ss);
				EXPECT_EQ(ss.str(), std::to_string(i / gcd) + "/" + std::to_string(j / gcd));
			}
		}
	}

	{
		std::stringstream ss;
		for (int i = 100; i > 0; --i) {
			for (int j = 1; j < i; ++j) {
				Rational r(i, j);
				int gcd = std::gcd(i, j);
				ss.str("");
				r.print(ss);

				if (i % j != 0) {
					EXPECT_EQ(ss.str(), std::to_string(i / j) + " " + std::to_string((i % j) / gcd) + "/" + std::to_string(j / gcd));
				}
				else {
					EXPECT_EQ(ss.str(), std::to_string(i / j));
				}
			}
		}
	}
}

class TestObject : public Rational {
public:
	void SetUpTestCase() {
		EXPECT_EQ(gcd(1071, 462), std::gcd(1071, 462));
		EXPECT_EQ(gcd(5, 2), std::gcd(5, 2));
		EXPECT_EQ(gcd(15, 3), std::gcd(15, 3));
		EXPECT_EQ(gcd(225, 5), std::gcd(225, 5));

		for (int i = 0; i < 10; ++i) {
			int a = RAND;
			int b = RAND;
			EXPECT_EQ(gcd(a, b), std::gcd(a, b));
		}

		for (int i = 1; i < 100; ++i) {
			setNumerator(1);
			setDenominator(1);

			int a = RAND;
			int b = i;
			setNumerator(a);
			setDenominator(b);
			normalize();

			int del = std::gcd(a, b);

			EXPECT_EQ(getNumerator(), a / del);
			EXPECT_EQ(getDenominator(), b / del);
		}
	}
};

TEST(Rational, TestNormalizeAndGCD) {
	TestObject t1;
	t1.SetUpTestCase();
}