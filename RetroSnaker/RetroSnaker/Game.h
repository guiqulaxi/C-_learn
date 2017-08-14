#pragma once  
#include<iostream>  
#include "Snake.h"  
#include "Food.h"  
#include "Point.h"  
#include "conio.h"  
#include<windows.h>  
#include<time.h>  
using std::endl;
class CSnake;
class CGame
{
public:
	CGame()
	{
		length = 80;
		width = 24;
		score = 0;
		exit = false;
	}
	bool Exit(){ return exit; };
	void NewGame()
	{
		//SMALL_RECT rc = { 0, 0, 80 - 1, 25 - 1 }; // 重置窗口位置和大小  
		system("cls");
		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED);
		//system("color 81");  
		COORD position = { 17, 6 };
		SetConsoleCursorPosition(hOut, position);

		//设置输出“SNAKE”  
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);

		cout << " ■■■   ■     ■  ■■■  ■    ■ ■■■■";
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
		CPoint::SetOutputPosition(17, 7, hOut);
		cout << "■    ■  ■■   ■ ■    ■ ■   ■  ■";
		CPoint::SetOutputPosition(17, 8, hOut);
		SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "■        ■ ■  ■ ■    ■ ■  ■   ■";
		CPoint::SetOutputPosition(17, 9, hOut);
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << " ■■■   ■  ■ ■ ■■■■ ■■     ■■■";
		CPoint::SetOutputPosition(17, 10, hOut);
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "      ■  ■   ■■ ■    ■ ■  ■   ■";
		CPoint::SetOutputPosition(17, 11, hOut);
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "■    ■  ■     ■ ■    ■ ■   ■  ■";
		CPoint::SetOutputPosition(17, 12, hOut);
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		cout << " ■■■   ■     ■ ■    ■ ■    ■ ■■■■";

		while (true)
		{
			CPoint::SetOutputPosition(27, 20, hOut);
			cout << "Press any key to start...";

			Sleep(70);
			for (int i = 0; i < 25; i++)
				cout << "\b \b";
			Sleep(70);
			if (_kbhit())
				break;
		}
		cin.get();
	}
	void SetGame()
	{
		char chooseLevel;
		system("cls");
		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << " ■■■  ■■■■ ■■■ ■■■  ■■  ■     ■  ■■■   ■■■ " << endl;
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << "■    ■ ■         ■     ■     ■   ■■   ■ ■    ■ ■    ■" << endl;
		SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "■       ■         ■     ■     ■   ■ ■  ■ ■       ■     " << endl;
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << " ■■■  ■■■     ■     ■     ■   ■  ■ ■ ■  ■■  ■■■ " << endl;
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "      ■ ■         ■     ■     ■   ■   ■■ ■    ■       ■" << endl;
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "■    ■ ■         ■     ■     ■   ■     ■ ■    ■ ■    ■" << endl;
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		cout << " ■■■  ■■■■   ■     ■    ■■  ■     ■  ■■■   ■■■ " << endl;
		CPoint::SetOutputPosition(9, 15, hOut);
		cout << "Chose difficulity : " << endl;
		cout << "                                           1)Easy" << endl
			<< "                                           2)Normal" << endl
			<< "                                           3)Hard" << endl;
		while (true)
		{
			chooseLevel = _getch();
			if (chooseLevel == '1' || chooseLevel == '2' || chooseLevel == '3')
			{
				level = chooseLevel - '0';
				switch (level)
				{
				case 1:
					speed = 500;
					break;
				case 2:
					speed = 250;
					break;
				case 3:
					speed = 100;
					break;
				}
				break;
			}
		}
	}
	void PaintEdge()
	{
		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		for (int x = 0; x <= 78; x += 2)
		{
			for (int y = 0; y < 25; y++)
			{
				if ((x == 0) || (y == 0) || (x == 78) || (y == 24))
				{
					CPoint::SetOutputPosition(x, y, hOut);
					cout << "■";
				}
			}
		}

		for (int x = 2; x <= 78; x += 2)
		{
			CPoint::SetOutputPosition(x, 2, hOut);
			cout << "■";
		}
	}
	void ShowState()
	{
		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hOut, BACKGROUND_GREEN | FOREGROUND_RED | BACKGROUND_INTENSITY | FOREGROUND_INTENSITY);
		CPoint::SetOutputPosition(2, 1, hOut);
		cout << "Difficulity : ";
		switch (level)
		{
		case 1:
			cout << "Easy    "; break;
		case 2:
			cout << "Noraml"; break;
		case 3:
			cout << "Hard    "; break;
		}
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << "■";
		SetConsoleTextAttribute(hOut, BACKGROUND_GREEN | FOREGROUND_RED | BACKGROUND_INTENSITY | FOREGROUND_INTENSITY);
		cout << "Press WASD to move your snake.";
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << "■";
		SetConsoleTextAttribute(hOut, BACKGROUND_GREEN | FOREGROUND_RED | BACKGROUND_INTENSITY | FOREGROUND_INTENSITY);
		cout << "Score : " << score << "           ";

	}
	void UpdateScore(bool eaten)
	{
		if (eaten)
		{
			HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hOut, BACKGROUND_GREEN | FOREGROUND_RED | BACKGROUND_INTENSITY | FOREGROUND_INTENSITY);
			score += 10;
			CPoint::SetOutputPosition(58, 1, hOut);
			cout << "Score : " << score;
			int spaceUsed = 0;

			for (int s = score; s != 0; s /= 10)
				spaceUsed++;
			for (int i = 0; i < 10 - spaceUsed; i++)
				cout << ' ';
		}
	}
	bool DirectionChanged()
	{
		char ch;
		if (_kbhit())
		{
			ch = _getch();
			switch (ch)
			{
			case 'w':case 'W':
				return snake.ChangeDirection(snake.UP);
			case 'a':case 'A':
				return snake.ChangeDirection(snake.LEFT);
			case 's':case 'S':
				return snake.ChangeDirection(snake.DOWN);
			case 'd':case 'D':
				return snake.ChangeDirection(snake.RIGHT);
			}
		}
		return false;
	}
	void RandomFood(CFood& food)
	{
		srand(static_cast<unsigned>(time(NULL)));
		int x, y;
		while (true)
		{
			x = rand() % (length / 2) * 2;
			y = rand() % (width / 2) * 2;
			if ((x <= 2) || (y <= 6) || (x >= 70) || (y >= 20))
				continue;
			if (!snake.Hit(CPoint(x, y)))
				break;
			else
				continue;
		}
		food.PlaceFood(x, y);
	}
	void PlayGame()
	{
		//游戏界面初始化阶段  
		system("cls");
		PaintEdge();
		ShowState();
		food.PlaceFood(20, 20);  //设置食物初始位置  
		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		snake.PaintSnake(hOut);
		while (true)
		{
			snake.Tail().Clear(hOut);
			DirectionChanged();
			bool eaten = snake.Eat(food);
			if (!eaten)
				snake.move();
			else
				RandomFood(food);
			UpdateScore(eaten);
			//将当前字体设置为黑底白色  
			SetConsoleTextAttribute(hOut, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			snake.Head().Plot(hOut);
			if (snake.HitEdge() || snake.HitItself())
			{
				Sleep(1000);
				SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_RED);
				snake.Head().Plot(hOut);
				Sleep(3000);
				break;
			}
			Sleep(speed);
		}
	}
	void GameOver()
	{
		int x = 28;
		int y = 3;
		system("cls");
		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		CPoint::SetOutputPosition(x, y, hOut);
		cout << "       ■■■■■";
		CPoint::SetOutputPosition(x, y + 1, hOut);
		cout << "    ■■■■■■■■ ";
		CPoint::SetOutputPosition(x, y + 2, hOut);
		cout << "  ■■■ ■■■ ■■■ ";
		CPoint::SetOutputPosition(x, y + 3, hOut);
		cout << " ■■■    ■    ■■■ ";
		CPoint::SetOutputPosition(x, y + 4, hOut);
		cout << "  ■■■  ■■  ■■■";
		CPoint::SetOutputPosition(x, y + 5, hOut);
		cout << "   ■■■■■■■■■";
		CPoint::SetOutputPosition(x, y + 6, hOut);
		cout << "     ■■■■■■■";
		CPoint::SetOutputPosition(x, y + 7, hOut);
		cout << "     ■■ ■■ ■■";
		CPoint::SetOutputPosition(x, y + 8, hOut);
		cout << "                        ";
		CPoint::SetOutputPosition(x, y + 9, hOut);
		cout << "     ■■ ■■ ■■ ";
		CPoint::SetOutputPosition(x, y + 10, hOut);
		cout << "      ■■■■■■";
		CPoint::SetOutputPosition(x + 7, y + 13, hOut);
		cout << "GAME  OVER";
		CPoint::SetOutputPosition(x + 7, y + 15, hOut);
		cout << "Score : " << score;
		CPoint::SetOutputPosition(x + 4, y + 17, hOut);
		cout << "Play Again?(Y/N)";
		char ch;
		while (true)
		{
			ch = _getch();
			if (ch == 'n' || ch == 'N')
			{
				exit = true;
				break;
			}
			else if (ch == 'y' || ch == 'Y')
				break;
		}
		CPoint::SetOutputPosition(x - 1, y + 19, hOut);
	}
private:
	bool exit;
	int level;
	int speed;
	bool gameOver;
	CSnake snake;
	CFood food;
	int length; //游戏区域总长度  
	int width;  //游戏区域总宽度  
	int score;
};