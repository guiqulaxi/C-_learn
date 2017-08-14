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
	enum moveDirection{ UP, LEFT, DOWN, RIGHT }; //��ֻ���ĸ��ƶ��������Կ��Զ�����һ�����˶������ö������  
	CSnake()        //�߳�ʼʱ��ֻ��������Ԫ�����,��ʼ�ƶ������趨Ϊ����  
	{
		snake.push_back(CPoint(18, 16));
		snake.push_back(CPoint(16, 16));
		direction = moveDirection::RIGHT;
	}
	//��������ǰ�ƶ�һ���������µ㼯snake  
	void move()
	{
		switch (direction)//���ݴ�ʱ�ķ������жϸ�����ƶ����ƶ�ʱΪ���Ч�ʽ�ֻ��Ҫ������β��Ԫ��  
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
		if ((direction + 2) % 4 == this->direction)  //������뷽�����ߵ�ǰ�ƶ������෴�����ı��ʱ�ߵ�ǰ������  
			return false;
		else
			this->direction = direction;
		return true;
	}
	//���������ػ�������Ϊ���Ч�ʣ��ú���Ӧ��ֻ����Ϸ��ʼ��ʱ����  
	void PaintSnake(HANDLE hOut)
	{
		for (CPoint& point : snake)
		{
			CPoint::SetOutputPosition(point.GetX(), point.GetY(), hOut);
			point.Plot(hOut);
		}
	}
	//�����ͷ�Ƿ���������غϣ������ж��Ƿ񷸹�  
	bool HitItself()
	{
		for (CPoint& point : snake)
		{
			if (point == *snake.begin())
			{
				if (&point == &(*snake.begin()))    //��������ͷ����ͷ�غϵ������  
					continue;
				else
					return true;
			}
		}
		return false;
	}
	//���ĳ���Ƿ�������غϣ��ж����������ʳ���Ƿ�ŵ��������ϡ�  
	bool Hit(CPoint& point)
	{
		for (CPoint& pointInSnake : snake)
		{
			if (point == pointInSnake)
				return true;
		}
		return false;
	}
	//�����ͷ�Ƿ�ײǽ�������ж��Ƿ񷸹�  
	bool HitEdge()
	{
		int x = snake.begin()->GetX();
		int y = snake.begin()->GetY();
		if ((x == 0) || (y == 2) || (x == 78) || (y == 24)) //��Ĭ��ǽ��λ�ý��бȽ�  
			return true;
		else
			return false;
	}
	//������Ҫ������ͷ����β�����Զ�����������������  
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
		//���ӵ��ж���䣬�����ж�ʳ���Ƿ�����ͷ�ƶ������ϵ�ǰ��  
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