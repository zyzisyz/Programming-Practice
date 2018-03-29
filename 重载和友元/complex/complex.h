// complex.h
#include <iostream>
using namespace std;

class Complex
{
  private:
	double rpart, ipart;	 // 实部和虚部
	double abs(void) const;  // 复数模
	double norm(void) const; // 复数模的平方

  public:
	Complex(void) { rpart = .0, ipart = .0; }

	Complex(const Complex &c) // 预定义拷贝构造函数（可忽略）
	{
		rpart = c.rpart, ipart = c.ipart;
	}

	Complex(const double &r, const double &i) { rpart = r, ipart = i; }

	Complex(const double &r) { rpart = r, ipart = .0; }

	Complex &operator=(const Complex &c) // 预定义赋值运算（可忽略）
	{
		rpart = c.rpart, ipart = c.ipart;
		return *this;
	}

	Complex operator-(void);
	friend Complex operator+(const Complex &, const Complex &);
	friend Complex operator-(const Complex &, const Complex &);
	friend Complex operator*(const Complex &, const Complex &);
	friend Complex operator/(const Complex &, const Complex &);
	Complex operator+=(const Complex &);
	Complex operator-=(const Complex &);
	friend int operator==(const Complex &, const Complex &);
	friend int operator<(const Complex &, const Complex &);
	friend int operator>(const Complex &, const Complex &);
	friend istream &operator>>(istream &, Complex &);
	friend ostream &operator<<(ostream &, Complex &);
};