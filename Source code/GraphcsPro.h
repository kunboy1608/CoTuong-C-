#pragma once
#include <iostream>
#include <math.h>
#include <Windows.h>
using namespace std;
// Hàm vẽ đường thẳng từ (x1,y1) đến (x2,y2) với màu mặc định là màu trắng
static void Line(int x1, int y1, int x2, int y2)
{
	HWND myconsole = GetConsoleWindow();
	//Get a handle to device context
	HDC mydc = GetDC(myconsole);
	//Choose any color
	COLORREF COLOR = RGB(255, 255, 255);
	double x = x1;
	double y = y1;
	double iTemp;
	SetPixel(mydc, x1, y1, COLOR);
	SetPixel(mydc, x2, y2, COLOR);
	while (x != x2 || y != y2)
	{
		if (x != x2)
		{
			x1 > x2 ? --x : ++x;
			iTemp = (1 - abs((x2 - x * 1.0) / (x1 - x2 * 1.0))) * abs(y1 - y2);
			y = y1;
			y1 > y2 ? y -= iTemp : y += iTemp;
		}
		else
		{
			y1 > y2 ? --y : ++y;
		}
		SetPixel(mydc, (int)x, (int)y, COLOR);
		//Sleep(1);
	}
}
// Hàm vẽ đường thẳng từ (x1,y1) đến (x2,y2) với màu được chọn trước
static void Line(int x1, int y1, int x2, int y2, COLORREF COLOR)
{
	HWND myconsole = GetConsoleWindow();
	//Get a handle to device context
	HDC mydc = GetDC(myconsole);
	//Choose any color
	//COLORREF COLOR = RGB(255, 255, 255);
	double x = x1;
	double y = y1;
	double iTemp;
	SetPixel(mydc, x1, y1, COLOR);
	SetPixel(mydc, x2, y2, COLOR);
	while (x != x2 || y != y2)
	{
		if (x != x2)
		{
			x1 > x2 ? --x : ++x;
			iTemp = (1 - abs((x2 - x * 1.0) / (x1 - x2 * 1.0))) * abs(y1 - y2);
			y = y1;
			y1 > y2 ? y -= iTemp : y += iTemp;
		}
		else
		{
			y1 > y2 ? --y : ++y;
		}
		SetPixel(mydc, (int)x, (int)y, COLOR);
		//Sleep(1);
	}
}
// Hàm vẽ hình tròn với bán kính r với tọa độ tâm (PosionX, PosionY) với màu mặc định là trắng
static void Circle2(int r, int PosionX, int PosionY)
{
	HWND myconsole = GetConsoleWindow();
	//Get a handle to device context
	HDC mydc = GetDC(myconsole);
	//Choose any color
	COLORREF COLOR = RGB(255, 255, 255);
	float y = PosionY;
	for (float x = PosionX - r; x <= PosionX; x += 1)
	{
		y = sqrt(r * r - (x - PosionX * 1.0) * (x - PosionX * 1.0));
		Line((int)x, (int)y + PosionY, (int)x, -(int)y + PosionY);
		Line(2 * PosionX - (int)x, (int)y + PosionY, 2 * PosionX - (int)x, -(int)y + PosionY);
		
	}
}
// Hàm vẽ hình tròn với bán kính r với tọa độ tâm (PosionX, PosionY) với màu chọn trước
static void Circle2(int r, int PosionX, int PosionY,COLORREF COLOR)
{
	HWND myconsole = GetConsoleWindow();
	//Get a handle to device context
	HDC mydc = GetDC(myconsole);
	float y = PosionY;
	for (float x = PosionX - r; x <= PosionX; x += 1)
	{
		y = sqrt(r * r - (x - PosionX * 1.0) * (x - PosionX * 1.0));
		Line((int)x, (int)y + PosionY, (int)x, -(int)y + PosionY, COLOR);
		Line(2 * PosionX - (int)x, (int)y + PosionY, 2 * PosionX - (int)x, -(int)y + PosionY, COLOR);
	}
}
// Hàm vẽ nửa đường tròn với bán kính r với tọa độ tâm (PosionX, PosionY)
static void HalfCircle(int r, int PosionX, int PosionY, COLORREF COLOR, bool z)
{
	HWND myconsole = GetConsoleWindow();
	//Get a handle to device context
	HDC mydc = GetDC(myconsole);
	float y = PosionY;
	if (!z)
	{
		for (float x = PosionX - r; x <= PosionX; x += 0.1)
		{
			y = sqrt(r * r - (x - PosionX * 1.0) * (x - PosionX * 1.0));
			SetPixel(mydc, (int)x, (int)y + PosionY, COLOR);
			SetPixel(mydc, (int)x, -(int)y + PosionY, COLOR);
		}
	}
	else
	{
		for (float x = PosionX; x <= PosionX + r; x += 0.1)
		{
			y = sqrt(r * r - (x - PosionX * 1.0) * (x - PosionX * 1.0));
			SetPixel(mydc, (int)x, (int)y + PosionY, COLOR);
			SetPixel(mydc, (int)x, -(int)y + PosionY, COLOR);
		}
	}
}
// Hàm đưa con trỏ văn bản đến tọa độ (x, y)
static void gotoxy(int x, int y)
{
	static HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}

///////////////// Create by Hoang Tran Gia Hieu \\\\\\\\\\\\\\\\\\\\\\\\\\
////////////////////////// Open Sourse \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\