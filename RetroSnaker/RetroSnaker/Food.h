#pragma once  
#include<iostream>  
#include "Point.h"  
using std::cout;
class CFood
{
public:
	CFood()
	{
		position.SetPosition(20, 20);
	}

	CFood(int x, int y)
	{
		position.SetPosition(x, y);
	}

	void PlaceFood(int x, int y)
	{
		position.SetPosition(x, y);
		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		CPoint::SetOutputPosition(x, y, hOut);
		cout << "$$";
	}

	CPoint& GetPosition()
	{
		return position;
	}

	void Show()
	{
		cout << '(' << position.GetX() << ',' << position.GetY() << ')';
	}
private:
	CPoint position;
};