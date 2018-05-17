#pragma once
#include"Resource.h"
#include"stdafx.h"
using namespace std;
#define PI 3.1415926
#define POINT_NUM 1000
#define DOUBLE_PI 2*3.1415926

// shape 类
class Shape
{
public:
	virtual void move(double dx, double dy) = 0;
	virtual void SetColor(COLORREF mColor) = 0;
};

// 点类
class Point :public Shape
{
public:
	double x, y;
	COLORREF color;

	Point() { x = 0; y = 0; }
	void setPoint(double x1, double y1)
	{
		x = x1; 
		y = y1;
	}
	Point(double x1, double y1)
	{
		x = x1;
		y = y1;
	}
	double get_x()const { return x; }
	double get_y()const { return y; }
	COLORREF get_color() const { return color; }

	virtual void move(double dx, double dy)
	{
		x += dx;
		y += dy;
	}
	virtual void SetColor(COLORREF mColor)
	{
		color = mColor;
	}
};

// 线类
class Line :public Shape
{
public:
	Line() { }
	Line(Point p1, Point p2) { from = p1; to = p2; }
	Point get_start() const { return from; }
	Point get_end() const { return to; }
	COLORREF get_color() const { return color; }

	virtual void move(double dx, double dy)
	{
		from.move(dx, dy);
		to.move(dx, dy);
	}
	virtual void SetColor(COLORREF mColor) { color = mColor; }

private:
	Point from;
	Point to;
	COLORREF color;
};

// 圆类
class Circle :public Shape
{
public:
	Circle() { radius = 0.0; }
	Circle(Point p, double r) { center = p; radius = r; }
	void setCircle(Point p, double r){ center = p; radius = r; }
	Point get_center() const { return center; }
	double get_radius() const { return radius; }
	COLORREF get_color() const { return color; }

	virtual void move(double dx, double dy) { center.move(dx, dy); }
	virtual void SetColor(COLORREF mColor) { color = mColor; }
private:
	Point center;
	double radius;
	COLORREF color;
};

//文本信息类
class Message
{
public:
	Message() {}
	Message(Point s, double x);
	Message(Point s, const string& m) { start = s; text = m; };
	Point get_start()const { return start; }
	string get_text()const { return text; }
	void move(double dx, double dy) { start.move(dx, dy); }
private:
	Point start;
	string text;
};
Message::Message(Point s, double x)
{
	start = s;
	char buf[20];
	sprintf_s(buf, "%g", x);
	text = buf;
};

//绘图类
class GraphicWindow {
public:
	GraphicWindow()
		:_user_xmin(-10), _user_xmax(10), _user_ymin(6), _user_ymax(-6)
	{ }
	// 设置窗口坐标
	void coord(double xmin, double ymin, double xmax, double ymax)
	{
		_user_xmin = xmin, _user_xmax = xmax;
		_user_ymin = ymin, _user_ymax = ymax;
	}
	// 清除窗口
	void clear();
	GraphicWindow& operator<<(Point p);  // 显示一个点
	GraphicWindow& operator<<(Circle c);  // 显示一个圆
	GraphicWindow& operator<<(Line s);  // 显示一条线    
	GraphicWindow& operator<<(Message t);  // 显示一个文本串
	void open(HWND hwnd, HDC mainwin_hdc);  // 打开一个窗口
	HDC GetHDC() { return _hdc; }
private:
	int user_to_disp_x(double x) const;  // 逻辑到设备x坐标转换
	int user_to_disp_y(double y) const;  // 逻辑到设备y坐标转换
	double disp_to_user_x(int x) const;  // 设备到逻辑x坐标转换
	double disp_to_user_y(int y) const;  // 设备到逻辑y坐标转换
	void point(double x, double y, COLORREF mColor); // 画一个点
													 // 画一条线
	void line(double xfrom, double yfrom, double xto, double yto, COLORREF mColor);
	// 画一个椭圆
	void ellipse(double x, double y, double ra, double rb, COLORREF mColor);
	void text(string t, double x, double y); // 图形方式输出一个文本串
	
	
	// 逻辑坐标
	double _user_xmin, _user_xmax, _user_ymin, _user_ymax;
	// 设备坐标（像素为单位）
	int _disp_xmax, _disp_ymax;
	// 设备环境句柄
	HDC _hdc;
};
void GraphicWindow::open(HWND hwnd, HDC mainwin_hdc) {
	RECT rect;
	GetClientRect(hwnd, &rect);
	_disp_xmax = rect.right - 1;
	_disp_ymax = rect.bottom - 1;
	_hdc = mainwin_hdc;
	
	
	//创建蓝色笔刷
	HBRUSH hbrush = CreateSolidBrush(RGB(0, 120, 215)); 
	SelectObject(_hdc, hbrush);  // 指定画刷
	SelectObject(_hdc, GetStockObject(BLACK_PEN));
	SelectObject(_hdc, GetStockObject(SYSTEM_FONT));
	clear();
}

void GraphicWindow::clear() {
	COLORREF color = RGB(0, 120, 215);
	HBRUSH brush = CreateSolidBrush(color);
	HBRUSH saved_brush = (HBRUSH)SelectObject(_hdc, brush);
	PatBlt(_hdc, 0, 0, _disp_xmax, _disp_ymax, PATCOPY);
	SelectObject(_hdc, saved_brush);
	DeleteObject(brush);
}
//逻辑到设备坐标转换
int GraphicWindow::user_to_disp_x(double x) const 
{
	return (int)((x - _user_xmin)*_disp_xmax / (_user_xmax - _user_xmin));
}
int GraphicWindow::user_to_disp_y(double y) const
{
	return (int)((y - _user_ymin)*_disp_ymax / (_user_ymax - _user_ymin));
}

//设备到逻辑坐标转换
double GraphicWindow::disp_to_user_x(int x) const 
{
	return (double)x*(_user_xmax - _user_xmin) / _disp_xmax + _user_xmin;
}
double GraphicWindow::disp_to_user_y(int y) const 
{
	return (double)y*(_user_ymax - _user_ymin) / _disp_ymax + _user_ymin;
}

void GraphicWindow::point(double x, double y, COLORREF mColor) 
{
	const int POINT_RADIUS = 3;
	int disp_x = user_to_disp_x(x);
	int disp_y = user_to_disp_y(y);

	SelectObject(_hdc, CreatePen(PS_SOLID, 1, mColor));
	Ellipse(_hdc, disp_x - POINT_RADIUS, disp_y - POINT_RADIUS, disp_x + POINT_RADIUS, disp_y + POINT_RADIUS);
}

void GraphicWindow::line(double xfrom, double yfrom, double xto, double yto, COLORREF mColor) 
{
	SelectObject(_hdc, CreatePen(PS_SOLID, 1, mColor));
	MoveToEx(_hdc, user_to_disp_x(xfrom), user_to_disp_y(yfrom), 0);
	LineTo(_hdc, user_to_disp_x(xto), user_to_disp_y(yto));
}

void GraphicWindow::ellipse(double x, double y, double ra, double rb, COLORREF mColor) 
{
	SelectObject(_hdc, CreatePen(PS_SOLID, 1, mColor));
	Ellipse(_hdc, user_to_disp_x(x - ra), user_to_disp_y(y - rb), user_to_disp_x(x + ra), user_to_disp_y(y + rb));
}

void GraphicWindow::text(string s, double x, double y) 
{
	const char *t = s.c_str();
	SetBkMode(_hdc, TRANSPARENT);
	TextOut(_hdc, user_to_disp_x(x), user_to_disp_y(y), t, lstrlen(t));
}

GraphicWindow& GraphicWindow::operator<<(Point p)
{
	point(p.get_x(), p.get_y(), p.get_color());
	return *this;
}

GraphicWindow& GraphicWindow::operator<<(Circle c) 
{
	ellipse(c.get_center().get_x(), c.get_center().get_y(), c.get_radius(), c.get_radius(), c.get_color());
	return *this;
}

GraphicWindow& GraphicWindow::operator<<(Line s) 
{
	line(s.get_start().get_x(), s.get_start().get_y(), s.get_end().get_x(), s.get_end().get_y(), s.get_color());
	return *this;
}

GraphicWindow& GraphicWindow::operator<<(Message t) 
{
	text(t.get_text(), t.get_start().get_x(), t.get_start().get_y());
	return *this;
}

void mclock(GraphicWindow cwin)
{
	Shape *pShape;
	/* 画表盘*/
	int radius = 6;
	Point org(0, 0);
	pShape = &org;
	pShape->SetColor(RGB(0, 0, 0)); // 白色
	cwin << org;
	Circle clkPlate(org, radius);
	pShape = &clkPlate;
	pShape->SetColor(RGB(0, 120, 215));	// 蓝色
	cwin << clkPlate;
	double x, y, x_s, y_s, x_m, y_m, x_h, y_h;
	int i;
	for (i = 0; i<12; i++)
	{
		x = 0.9*radius*sin(PI*i / 6);
		y = 0.9*radius*cos(PI*i / 6);
		Point mPoint(x, y);
		pShape = &mPoint;
		pShape->SetColor((RGB(255, 255, 255)));
		cwin << mPoint;
	}
	tm local;
	time_t t;

	t = time(NULL);  // 获取系统日历时间	
	localtime_s(&local, &t); // 将日历时间转化为本地时间

	x_s = 0.89*radius*sin(PI*(local.tm_sec) / 30);
	y_s = 0.89*radius*cos(PI*(local.tm_sec) / 30);
	x_m = 0.7*radius*sin(PI*(local.tm_min) / 30);
	y_m = 0.7*radius*cos(PI*(local.tm_min) / 30);
	x_h = 0.5*radius*sin(PI*(local.tm_hour) / 6);
	y_h = 0.5*radius*cos(PI*(local.tm_hour) / 6);

	/* 画表针*/
	Point hEnd(x_h, y_h), mEnd(x_m, y_m), sEnd(x_s, y_s);
	Line hLine(org, hEnd), mLine(org, mEnd), sLine(org, sEnd);

	hLine.SetColor((RGB(50, 50, 50)));		//时针	   
	mLine.SetColor((RGB(55, 20, 220)));	//分针
	sLine.SetColor((RGB(215, 90, 90)));		//秒针
	cwin << hLine << mLine << sLine << org;
}

int n = 5;						//球的个数
int r[5], g[5], b[5];			//颜色
double x[5], y[5];				//位置
double w[5];					//倾斜角

int Ccount;						//计数器
Point p[5];
Circle c[5];
bool GoLeft[5];
bool GoUp[5];


void init()
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; ++i)
	{
		r[i] = rand() % 256;
		g[i] = rand() % 256;
		b[i] = rand() % 256;
		x[i] = (rand() / 100) % 10;
		y[i] = (rand() / 100) % 6;
		p[i].setPoint(x[i], y[i]);
		c[i].setCircle(p[i], 0.7);
		w[i] = PI / 2 * (rand() % 200) / 200;
		if ((PI / 4) > w[i] || w[i] > 0)
		{
			GoUp[i] = true;
			GoLeft[i] = true;
		}
		else if (2 * (PI / 4) > w[i] || (PI / 4) < w[i])
		{
			GoUp[i] = true;
			GoLeft[i] = false;
		}
		else if (1.5*(PI / 4) > w[i] || 2 * (PI / 4) < w[i])
		{
			GoUp[i] = false;
			GoLeft[i] = false;
		}
		else if (2 * (PI / 4) > w[i] || 1.5 * (PI / 4) < w[i])
		{
			GoUp[i] = false;
			GoLeft[i] = true;
		}
		else if (PI / 4 == w[i])
		{
			GoLeft[i] = true;
		}
		else if (PI / 2 == w[i])
		{
			GoUp[i] = true;
		}
		else if (3 * PI / 4 == w[i])
		{
			GoLeft[i] = false;
		}
		else if (2 * PI == w[i])
		{
			GoUp[i] = false;
		}
	}
}

void DrawBall(GraphicWindow cwin)
{
	//位置变化
	for (int i = 0; i < n; ++i)
	{
		//判断有没有有到边界
		if (x[i] + 0.5 >= 10) { GoLeft[i] = false; }
		if (x[i] - 0.5 <= -10) { GoLeft[i] = true; }
		if (y[i] + 0.5 >= 6) { GoUp[i] = false; }
		if (y[i] - 0.5 <= -6) { GoUp[i] = true; }
		if (GoLeft[i])
		{
			x[i] += 0.3*cos(w[i]);
		}
		else
		{
			x[i] -= 0.3*cos(w[i]);
		}

		if (GoUp[i])
		{
			y[i] += 0.3*sin(w[i]);
		}
		else
		{
			y[i] -= 0.3*sin(w[i]);
		}
		
	}

	//颜色变化
	Ccount++;
	srand((unsigned)time(NULL));
	if (Ccount == 20)
	{
		Ccount = 0;
		for (int i = 0; i < 5; ++i)
		{
			r[i] = rand() % 256;
			g[i] = rand() % 256;
			b[i] = rand() % 256;
		}
		HBRUSH hbrush = CreateSolidBrush(RGB(r, g, b));
		SelectObject(cwin.GetHDC(), hbrush);  // 指定画刷
	}
	
	//画画
	for (int i = 0; i < n; ++i)
	{		
		HBRUSH hbrush = CreateSolidBrush(RGB(r[i], g[i], b[i]));
		SelectObject(cwin.GetHDC(), hbrush);  // 指定画刷
		p[i].setPoint(x[i], y[i]);
		c[i].setCircle(p[i], 0.7);
		cwin << c[i];
	}
}