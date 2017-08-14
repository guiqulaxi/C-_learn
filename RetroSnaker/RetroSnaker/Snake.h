#pragma once  
#include<iostream>  
#include "Point.h"  
#include<deque>  

#include "Food.h"  
using std::cout;
using std::cin;
using std::deque;

class CSnake
{
public:
	enum moveDirection{ UP, LEFT, DOWN, RIGHT }; //蛇只有四个移动方向，所以可以定义了一个蛇运动方向的枚举类型  
	CSnake()        //蛇初始时将只由两个点元素组成,初始移动方向设定为向右  
	{
		snake.push_back(CPoint(18, 16));
		snake.push_back(CPoint(16, 16));
		direction = moveDirection::RIGHT;
	}
	//蛇整体向前移动一步，即更新点集snake  
	void move()
	{
		switch (direction)//根据此时的方向来判断该如何移动。移动时为提高效率将只需要处理首尾点元素  
		{
		case moveDirection::DOWN:
			snake.push_front(CPoint(snake.begin()->GetX(), snake.begin()->GetY() + 1)); break;
		case moveDirection::LEFT:
			snake.push_front(CPoint(snake.begin()->GetX() - 2, snake.begin()->GetY())); break;
		case moveDirection::RIGHT:
			snake.push_front(CPoint(snake.begin()->GetX() + 2, snake.begin()->GetY())); break;
		case moveDirection::UP:
			snake.push_front(CPoint(snake.begin()->GetX(), snake.begin()->GetY() - 1)); break;
		}
		snake.pop_back();
	}
	bool ChangeDirection(moveDirection direction)
	{
		if ((direction + 2) % 4 == this->direction)  //玩家输入方向与蛇当前移动方向相反将不改变此时蛇的前进方向  
			return false;
		else
			this->direction = direction;
		return true;
	}
	//把蛇整个地画出来。为提高效率，该函数应该只在游戏初始化时调用  
	void PaintSnake(HANDLE hOut)
	{
		for (CPoint& point : snake)
		{
			CPoint::SetOutputPosition(point.GetX(), point.GetY(), hOut);
			point.Plot(hOut);
		}
	}
	//检查蛇头是否和蛇身部分重合，用于判断是否犯规  
	bool HitItself()
	{
		for (CPoint& point : snake)
		{
			if (point == *snake.begin())
			{
				if (&point == &(*snake.begin()))    //将忽略蛇头与蛇头重合的情况。  
					continue;
				else
					return true;
			}
		}
		return false;
	}
	//检查某点是否和蛇身重合，判断随机产生的食物是否放到了蛇身上。  
	bool Hit(CPoint& point)
	{
		for (CPoint& pointInSnake : snake)
		{
			if (point == pointInSnake)
				return true;
		}
		return false;
	}
	//检查蛇头是否撞墙，用于判断是否犯规  
	bool HitEdge()
	{
		int x = snake.begin()->GetX();
		int y = snake.begin()->GetY();
		if ((x == 0) || (y == 2) || (x == 78) || (y == 24)) //和默认墙的位置进行比较  
			return true;
		else
			return false;
	}
	//经常需要处理蛇头和蛇尾，所以定义了这两个函数。  
	CPoint& Head()
	{
		return *snake.begin();
	}
	CPoint& Tail()
	{
		return *(snake.end() - 1);
	}
	bool Eat(CFood& food)
	{
		//复杂的判断语句，用于判断食物是否在蛇头移动方向上的前方  
		int foodx = food.GetPosition().GetX();
		int foody = food.GetPosition().GetY();
		int headx = Head().GetX();
		int heady = Head().GetY();
		bool toEat = ((foodx == headx) && (foody == (heady + 1)) && (direction == moveDirection::DOWN))
			|| ((foodx == headx) && (foody == (heady - 1)) && (direction == moveDirection::UP))
			|| (((foodx + 2) == headx) && (foody == heady) && (direction == moveDirection::LEFT))
			|| (((foodx - 2) == headx) && (foody == heady) && (direction == moveDirection::RIGHT));
		if (toEat)
		{
			snake.push_front(food.GetPosition());
			return true;
		}
		else
			return false;
	}
private:
	deque<CPoint> snake;
	moveDirection direction;
};