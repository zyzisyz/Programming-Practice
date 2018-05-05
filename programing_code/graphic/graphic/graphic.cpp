//graphic.cpp: 定义应用程序的入口点。
//

#include "stdafx.h"
#include "graphic.h"
#include"stdafx.h"
#include"point.h"
#include<cmath>


#define MAX_LOADSTRING 100
#define POINT_NUM 1000
#define DOUBLE_PI 2*3.1415926


//画点的函数
void DrawPixels(HWND hwnd, HDC hdc)
{
	// 获得客户区域
	RECT r;
	GetClientRect(hwnd, &r);

	// 设置映像模式
	SetMapMode(hdc, MM_ISOTROPIC);

	// 设置窗口坐标范围
	SetWindowExtEx(hdc, 100, 100, NULL);

	// 设置视口坐标范围
	SetViewportExtEx(hdc, r.right, r.bottom, NULL);


	TextOut(hdc, 50, 50, TEXT("TEST"), lstrlen(TEXT("TEST")));

	//点
	for (int i = 0; i<20; i++)
	{
		SetPixelV(hdc, 20 + i, 20 + i, RGB(0, 0, 0));
	}

	//线
	MoveToEx(hdc, 30, 40, NULL);
	LineTo(hdc, 100, 10);
}

//画三角形的函数
void DrawTriangle(HWND hwnd, HDC hdc)
{
	RECT r;
	GetClientRect(hwnd, &r);
	// 设置映像模式
	SetMapMode(hdc, MM_ISOTROPIC);

	// 设置窗口坐标范围
	SetWindowExtEx(hdc, 100, 100, NULL);

	// 设置视口坐标范围
	SetViewportExtEx(hdc, r.right, r.bottom, NULL);
	Point p[] = { Point(10,10),Point(10,19),Point(22,19) };
	MoveToEx(hdc, p[0].get_x(), p[0].get_y(), NULL);
	for (int i = 0; i < 3; i++)
	{
		if (i == 2)
		{
			LineTo(hdc, p[0].get_x(), p[0].get_y());
			continue;
		}
		LineTo(hdc, p[i + 1].get_x(), p[i + 1].get_y());
	}
}

//画正弦曲线
void DrawSin(HWND hwnd, HDC hdc)
{
	// 获得客户区域
	RECT r;
	GetClientRect(hwnd, &r);

	// 设置映像模式
	SetMapMode(hdc, MM_ANISOTROPIC);

	// 设置窗口坐标范围
	SetWindowExtEx(hdc, 1000, 1000, NULL);

	// 设置视口坐标范围
	SetViewportExtEx(hdc, r.right, r.bottom, NULL);

	MoveToEx(hdc, 0, 1000 / 2, NULL);
	
	SelectObject(hdc, CreatePen(PS_SOLID, 1, RGB(0, 0, 0)));
	LineTo(hdc, 1000, 1000 / 2);				//画坐标轴

	point pt[POINT_NUM];
	for (int i = 0; i < POINT_NUM; i++)
	{
		pt[i].x = i * 1000 / POINT_NUM;
		pt[i].y = (int)(1000 / 2 * (1 - sin(DOUBLE_PI*i / POINT_NUM)));
	}
	SelectObject(hdc, CreatePen(PS_SOLID, 1, RGB(255, 0, 0)));

	MoveToEx(hdc, pt[0].x, pt[0].y, NULL);
	for (int i = 1; i < POINT_NUM; i++)
	{
		LineTo(hdc, pt[i].x, pt[i].y);
	}
}

void DrawPA(HWND hwnd, HDC hdc)
{
	// 获得客户区域
	RECT r;
	GetClientRect(hwnd, &r);

	// 设置映像模式
	SetMapMode(hdc, MM_ANISOTROPIC);

	// 设置窗口坐标范围
	SetWindowExtEx(hdc, 1000, 1000, NULL);

	// 设置视口坐标范围
	SetViewportExtEx(hdc, r.right, r.bottom, NULL);

	MoveToEx(hdc, 0, 800, NULL);
	SelectObject(hdc, CreatePen(PS_SOLID, 1, RGB(0, 0, 0)));
	LineTo(hdc, 1000, 800);						//画坐标轴

	MoveToEx(hdc, 1000/2, 0, NULL);
	SelectObject(hdc, CreatePen(PS_SOLID, 1, RGB(0, 0, 0)));
	LineTo(hdc, 1000/2, 1000);						//画坐标轴

	point pt[POINT_NUM];
	for (int i = 0; i < POINT_NUM; i++)
	{
		pt[i].x = i;
		int temp = pow(abs(500 - i), 2)/50;
		pt[i].y = (800 - temp);
	}
	SelectObject(hdc, CreatePen(PS_SOLID, 1, RGB(255, 0, 0)));
	MoveToEx(hdc, pt[0].x, pt[0].y, NULL);
	for (int i = 1; i < POINT_NUM; i++)
	{
		LineTo(hdc, pt[i].x, pt[i].y);
	}
}

//画心
void DrawHeart(HWND hwnd, HDC hdc)
{
	// 获得客户区域
	RECT r;
	GetClientRect(hwnd, &r);

	// 设置映像模式
	SetMapMode(hdc, MM_ANISOTROPIC);

	// 设置窗口坐标范围
	SetWindowExtEx(hdc, 1000, 1000, NULL);

	// 设置视口坐标范围
	SetViewportExtEx(hdc, r.right, r.bottom, NULL);

	MoveToEx(hdc, 0, 500, NULL);
	SelectObject(hdc, CreatePen(PS_SOLID, 1, RGB(0, 0, 0)));
	LineTo(hdc, 1000, 500);						//画x坐标轴

	MoveToEx(hdc, 1000 / 2, 0, NULL);
	SelectObject(hdc, CreatePen(PS_SOLID, 1, RGB(0, 0, 0)));
	LineTo(hdc, 1000 / 2, 1000);				//画y坐标轴

	point pt[1000], pt_rl[1000];

	for (int i = 0; i < POINT_NUM; ++i)
	{
		
	}

}

void DrawClock(HWND hwnd, HDC hdc)
{

}

// 全局变量: 
HINSTANCE hInst;                                // 当前实例
WCHAR szTitle[MAX_LOADSTRING];                  // 标题栏文本
WCHAR szWindowClass[MAX_LOADSTRING];            // 主窗口类名

												// 此代码模块中包含的函数的前向声明: 
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: 在此放置代码。

	// 初始化全局字符串
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_GRAPHIC, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// 执行应用程序初始化: 
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_GRAPHIC));

	MSG msg;

	// 主消息循环: 
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
}



//
//  函数: MyRegisterClass()
//
//  目的: 注册窗口类。
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_GRAPHIC));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_GRAPHIC);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}

//
//   函数: InitInstance(HINSTANCE, int)
//
//   目的: 保存实例句柄并创建主窗口
//
//   注释: 
//
//        在此函数中，我们在全局变量中保存实例句柄并
//        创建和显示主程序窗口。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance; // 将实例句柄存储在全局变量中

	HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

//
//  函数: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目的:    处理主窗口的消息。
//
//  WM_COMMAND  - 处理应用程序菜单
//  WM_PAINT    - 绘制主窗口
//  WM_DESTROY  - 发送退出消息并返回
//
//
int menue = 0;
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	
	switch (message)
	{
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		// 分析菜单选择: 
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;

		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;

		case POINT:
			menue = POINT;
			InvalidateRect(hWnd, NULL, true);
			break;

		case TRIANGLE:
			menue = TRIANGLE;
			InvalidateRect(hWnd, NULL, true);
			break;

		case PA:
			menue = PA;
			InvalidateRect(hWnd, NULL, true);
			break;

		case SIN:
			menue = SIN;
			InvalidateRect(hWnd, NULL, true);
			break;

		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
	break;
	case WM_PAINT:
	{
		
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		TEXTMETRIC tm;								// 取得与文本相关的数据     
		GetTextMetrics(ps.hdc, &tm);
		RECT rect;
		rect.top = 0L;
		rect.left = ps.rcPaint.left;
		rect.right = ps.rcPaint.right;
		rect.bottom = rect.top + tm.tmHeight;
		DrawText(ps.hdc, L"Welcome to use zyz's Graphic program!", -1, &rect, DT_CENTER);
	

		switch (menue) 
		{

		case POINT:
			DrawPixels(hWnd, hdc);
			EndPaint(hWnd, &ps);
			break;
		
		case TRIANGLE:
			DrawTriangle(hWnd, hdc);
			EndPaint(hWnd, &ps);
			break;
		case PA:
			DrawPA(hWnd, hdc);
			EndPaint(hWnd, &ps);
			break;
		case SIN:
			DrawSin(hWnd, hdc);
			EndPaint(hWnd, &ps);
			break;
		}
		
		
	}
	break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// “关于”框的消息处理程序。
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

