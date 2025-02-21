	#include <iostream>
	#include <cmath>

	#define db double
	#define PI 3.14159265


	using namespace std;

	class ComplexNumber
	{
	public:
		double real;
		double imag;
		ComplexNumber(double, double);
		friend ComplexNumber operator+(const ComplexNumber &, const ComplexNumber &);
		friend ComplexNumber operator-(const ComplexNumber &, const ComplexNumber &);
		friend ComplexNumber operator*(const ComplexNumber &, const ComplexNumber &);
		friend ComplexNumber operator/(const ComplexNumber &, const ComplexNumber &);
		friend bool operator==(const ComplexNumber &, const ComplexNumber &);

		friend ostream &operator<<(ostream &os, const ComplexNumber &dt);

		db abs();
		db angle();
	};

	ComplexNumber::ComplexNumber(double x = 0, double y = 0)
	{
		real = x;
		imag = y;
	}

	ComplexNumber operator+(const ComplexNumber &lhs, const ComplexNumber &rhs)
	{
		return ComplexNumber(lhs.real + rhs.real, lhs.imag + rhs.imag);
	}

	ComplexNumber operator-(const ComplexNumber &lhs, const ComplexNumber &rhs)
	{
		return ComplexNumber(lhs.real - rhs.real, lhs.imag - rhs.imag);
	}

	// Write your code here
	ComplexNumber operator*(const ComplexNumber &lhs, const ComplexNumber &rhs)
	{
		db a, b, c, d;

		a = lhs.real;
		b = lhs.imag;
		c = rhs.real;
		d = rhs.imag;

		return ComplexNumber(a * c - b * d, (a * d) + (b * c));
	}

	ComplexNumber operator/(const ComplexNumber &lhs, const ComplexNumber &rhs)
	{
		db a, b, c, d, R, I;

		a = lhs.real;
		b = lhs.imag;
		c = rhs.real;
		d = rhs.imag;

		R = ((a * c) + (b * d)) / ((c * c) + (d * d));
		I = ((b * c) - (a * d)) / ((c * c) + (d * d));

		return ComplexNumber(R, I);
	}

	bool operator==(const ComplexNumber &lhs, const ComplexNumber &rhs)
	{
		return lhs.real == rhs.real && lhs.imag == rhs.imag;
	}

	db ComplexNumber::abs()
	{
		return sqrt(real * real + imag * imag);
	}

	db ComplexNumber::angle()
	{
		return atan2(imag, real) * 180 / PI;
	}

	ostream &operator<<(ostream &os, const ComplexNumber &i)
	{
		if (i.real == 0)
		{
			if (i.imag == 0)
				os << '0';
		}
		else
		{
			os << i.real;
			if (i.imag > 0)
				os << '+';
		}

		if (i.imag != 0)
		{
			os << i.imag << 'i';
		}

		return os;
	}

	int main()
	{
		ComplexNumber a(1.5, 2), b(3.2, -2.5), c(-1, 1.2);
		cout << a << "\n";
		cout << b << "\n";
		cout << c << "\n";
		cout << a + 2.5 << "\n";
		cout << 2.5 + a << "\n";
		cout << a - 1.5 << "\n";
		cout << 1.5 - a << "\n";
		cout << b + ComplexNumber(0, 2.5) << "\n";
		cout << c - c << "\n";
		cout << "-----------------------------------\n";

		ComplexNumber d = (a + b) / c;
		ComplexNumber e = b / (a - c);
		cout << d << "\n";
		cout << e << "\n";
		cout << c * 2 << "\n";
		cout << 0.5 * c << "\n";
		cout << 1 / c << "\n";
		cout << "-----------------------------------\n";

		cout << ComplexNumber(1, 1).abs() << "\n";
		cout << ComplexNumber(-1, 1).abs() << "\n";
		cout << ComplexNumber(1.5, 2.4).abs() << "\n";
		cout << ComplexNumber(3, 4).abs() << "\n";
		cout << ComplexNumber(69, -9).abs() << "\n";
		cout << "-----------------------------------\n";

		cout << ComplexNumber(1, 1).angle() << "\n";
		cout << ComplexNumber(-1, 1).angle() << "\n";
		cout << ComplexNumber(-1, -1).angle() << "\n";
		cout << ComplexNumber(1, -1).angle() << "\n";
		cout << ComplexNumber(5, 2).angle() << "\n";
		cout << "-----------------------------------\n";

		cout << (ComplexNumber(1, 1) == ComplexNumber(1, 2)) << "\n";
		cout << (ComplexNumber(1, 1) == 1) << "\n";
		cout << (0 == ComplexNumber()) << "\n";
	}
