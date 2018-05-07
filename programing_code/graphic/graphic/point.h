#pragma once
#include"stdafx.h"

class Point
{	
public:
	double x, y;
	Point(double x1 = 0.0, double y1 = 0.0)
	{
		x = x1;
		y = y1;
	}
	
	double get_x()const { return x; }
	double get_y()const { return y; }
	void operator=(Point)
	{

	}
};
