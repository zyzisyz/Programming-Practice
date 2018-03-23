#include<iostream>
#include<cmath>
using namespace std;

class CPoint
{
private:
	double X;
	double Y;
public:
	CPoint(double xx = 0, double yy = 0)
	{
		X = xx;
		Y = yy;
	}
	~CPoint(){}
	double GetX() { return X; }
	double GetY() { return Y; }

	double GetDistance(CPoint n)
	{
		double m = pow(X - n.GetX(), 2) + pow(Y - n.GetY(), 2);
		return pow(m, 0.5);
	}
	void SetPoint(double xx, double yy)
	{
		X = xx;
		Y = yy;
	}
	void SetPoint()
	{
		double xx, yy;
		cout << "ÇëÊäÈëx£º";
		cin >> xx;
		cout << "ÇëÊäÈëy£º";
		cin >> yy;
		X = xx;
		Y = yy;
	}
};

class Rectangle :public CPoint
{
private:
	double Width;
	double Length;
	CPoint x1;
	CPoint x2;
	CPoint x3;
	CPoint x4;

public:
	Rectangle(double xx, double yy, double w, double l) :CPoint(xx, yy)
	{
		Width = w;
		Length = l;
		x1.SetPoint(xx, yy);
		x2.SetPoint(xx + w, yy);
		x3.SetPoint(xx, yy + l);
		x4.SetPoint(xx + w, yy + l);
	}
	double GetSquare() { return Width*Length; }
	double GetWidth() { return Length; }
	double GetLength() { return Width; }
	CPoint GetX1() { return x1; }
	CPoint GetX2() { return x2; }
	CPoint GetX3() { return x3; }
	CPoint GetX4() { return x4; }

};

int main(void)
{
	CPoint a(1, 1);
	CPoint b(1, 2);
	a.GetDistance(b);

	double x = 1, y = 2, w = 3, l = 4;
	Rectangle test(x, y, w, l);
	cout << test.GetX() << endl;
	cout << test.GetSquare() << endl;
	cout << test.GetX4().GetX() << endl;
	cout << test.GetDistance(test.GetX4()) << endl;
	system("pause");
}