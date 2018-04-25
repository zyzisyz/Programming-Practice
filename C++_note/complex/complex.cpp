// complex.cpp
#include "complex.h"
#include <math.h>
#include <stdlib.h>

double Complex::abs() const
{
	double result = sqrt(rpart * rpart + ipart * ipart);
	return result;
}

double Complex::norm() const
{
	double result = rpart * rpart + ipart * ipart;
	return result;
}

Complex Complex::operator-()
{
	Complex temp;
	temp.rpart = --rpart;
	temp.ipart = -ipart;
	return temp;
}

Complex operator+(const Complex &c1, const Complex &c2)
{
	Complex temp;
	temp.rpart = c1.rpart + c2.rpart;
	temp.ipart = c1.ipart + c2.ipart;
	return temp;
}

Complex operator-(const Complex &c1, const Complex &c2)
{
	Complex temp;
	temp.rpart = c1.rpart - c2.rpart;
	temp.ipart = c1.ipart - c2.ipart;
	return temp;
}

Complex operator*(const Complex &c1, const Complex &c2)
{
	Complex temp;
	temp.rpart = (c1.rpart * c2.rpart) - (c1.ipart * c2.ipart);
	temp.ipart = (c1.rpart * c2.ipart) + (c1.ipart * c2.rpart);
	return temp;
}

Complex operator/(const Complex &c1, const Complex &c2)
{
	Complex temp;
	double den = c2.norm();
	if (den != .0)
	{
		temp.rpart = ((c1.rpart * c2.rpart) + (c1.ipart * c2.ipart)) / den;
		temp.ipart = ((c1.ipart * c2.rpart) - (c1.rpart * c2.ipart)) / den;
	}
	else
	{
		cout << "divided be zero!" << endl;
		exit(0);
	}
	return temp;
}

Complex Complex::operator+=(const Complex &c)
{
	rpart += c.rpart, ipart += c.ipart;
	return *this;
}

Complex Complex::operator-=(const Complex &c)
{
	rpart -= c.rpart, ipart -= c.ipart;
	return *this;
}

int operator>(const Complex &c1, const Complex &c2)
{
	return c1.abs() > c2.abs();
}

int operator==(const Complex &c1, const Complex &c2)
{
	return c1.abs() == c2.abs();
}

int operator<(const Complex &c1, const Complex &c2)
{
	return c1.abs() < c2.abs();
}

istream &operator>>(istream &s, Complex &c)
{
	s >> c.rpart >> c.ipart;
	return s;
}

ostream &operator<<(ostream &s, Complex &c)
{
	s << '(' << c.rpart << ',' << c.ipart << ')';
	return s;
}