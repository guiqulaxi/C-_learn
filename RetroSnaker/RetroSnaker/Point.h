#pragma once  
#include<iostream>  
#include<windows.h>  
using std::cout;
using std::cin;

class CPoint
{
public:
	CPoint(){}
	CPoint(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	void Plot(HANDLE hOut)
	{
		SetOutputPosition(x, y, hOut);
		cout << "■";
	}
	void Clear(HANDLE hOut)
	{
		SetOutputPosition(x, y, hOut);
		cout << "  ";
	}
	void Clear()
	{
		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		cout << " ";
	}
	//静态方法，用于设定输出点在控制台的位置  
	static void SetOutputPosition(int x, int y, HANDLE hOut)
	{
		COORD position;
		position.X = x;
		position.Y = y;
		SetConsoleCursorPosition(hOut, position);
	}
	bool operator == (CPoint& point)
	{
		return (point.x == this->x) && (point.y == this->y);
	}
	//改变CPoint对象的位置  
	void SetPosition(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	int GetX(){ return x; };
	int GetY(){ return y; };
private:
	int x, y;
};