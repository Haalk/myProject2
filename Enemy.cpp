#include "stdafx.h"
#include "Enemy.h"
#include <ctime>
#include <cstdlib>
#include "Helper.h"
#include <conio.h>
#include <iostream>
Enemy::Enemy()
{
	ch = '.';
	time_rand = 0;
}
void Enemy::setCoord(int x,int y)
{
	px = x;
	py = y;
}
Enemy::Enemy(int x,int y)
{
	px = x;
	py = y;
}

void Enemy::move(Field *field)
{
	int direction;
	direction = rand() % 4;
	if (direction == 0)
	{
		if (py > 1 && !(field->isWall(px, py - 1)))
		{
			ch = field->getChar(px, py - 1);
			field->set_point(px, py, ch);
			--py;
			field->set_point(px, py, '@');
		}

		else
		{
			direction = rand() % 3;
			if (direction == 0)
			{
				if (py < SIZE - 2 && !(field->isWall(px, py + 1)))
				{
					ch = field->getChar(px, py + 1);
					field->set_point(px, py, ch);
					++py;
					field->set_point(px, py, '@');
				}
				else
				{
					direction = rand() % 2;
					if (direction == 0)
					{
						if (px <SIZE - 2 && !(field->isWall(px + 1, py)))
						{
							ch = field->getChar(px + 1, py);
							field->set_point(px, py, ch);
							++px;
							field->set_point(px, py, '@');
						}
						else if (px>1 && !(field->isWall(px - 1, py)))
						{
							ch = field->getChar(px - 1, py);
							field->set_point(px, py, ch);				
							--px;
							field->set_point(px, py, '@');	
						}
					}
					else if (direction == 1)
					{
						if ((px > 1 && !(field->isWall(px - 1, py))))
						{
							ch = field->getChar(px - 1, py);
							field->set_point(px, py, ch);
							--px;
							field->set_point(px, py, '@');
						}
						else if (px <SIZE - 2 && !(field->isWall(px + 1, py)))
						{
							ch = field->getChar(px + 1, py);
							field->set_point(px, py, ch);
							++px;
							field->set_point(px, py, '@');
						}
					}
				}
			}
			else if (direction == 1)
			{
				if (px < SIZE - 2 && !(field->isWall(px + 1, py)))
				{
					ch = field->getChar(px + 1, py);
					field->set_point(px, py, ch);		
					++px;
					field->set_point(px, py, '@');
				}
				else
				{
					direction = rand() % 2;
					if (direction == 0)
					{
						if (px > 1 && !(field->isWall(px - 1, py)))
						{
							ch = field->getChar(px - 1, py);
							field->set_point(px, py, ch);
							--px;
							field->set_point(px, py, '@');
						}
						else if (py < SIZE - 2 && !(field->isWall(px, py + 1)))
						{
							ch = field->getChar(px, py + 1);
							field->set_point(px, py, ch);
							++py;
							field->set_point(px, py, '@');
						}
					}
					else if (direction == 1)
					{
						if (py < SIZE - 2 && !(field->isWall(px, py + 1)))
						{
							ch = field->getChar(px, py + 1);
							field->set_point(px, py, ch);
							++py;
							field->set_point(px, py, '@');
						}
						else if (px > 1 && !(field->isWall(px - 1, py)))
						{
							ch = field->getChar(px - 1, py);
							field->set_point(px, py, ch);
							--px;
							field->set_point(px, py, '@');
						}
					}
				}
			}
			else if (direction == 2)
			{
				if (px > 1 && !(field->isWall(px - 1, px)))
				{
					ch = field->getChar(px - 1, py);
					field->set_point(px, py, ch);
					--px;
					field->set_point(px, py, '@');
				}
				else
				{
					direction = rand() % 2;
					if (direction == 0)
					{
						if (px < SIZE - 2 && !(field->isWall(px + 1, py)))
						{
							ch = field->getChar(px + 1, py);
							field->set_point(px, py, ch);			
							++px;
							field->set_point(px, py, '@');
						}
						else if (py <SIZE - 2 && !(field->isWall(px, py + 1)))
						{
							ch = field->getChar(px, py + 1);
							field->set_point(px, py, ch);
							++py;
							field->set_point(px, py, '@');				
						}
					}
					else if (direction==1)
					{
						if (py < SIZE - 2 && !(field->isWall(px, py + 1)))
						{
							ch = field->getChar(px, py + 1);
							field->set_point(px, py, ch);
							++py;
							field->set_point(px, py, '@');
						}
						else if (px < SIZE - 2 && !(field->isWall(px + 1, py)))
						{
							ch = field->getChar(px + 1, py);
							field->set_point(px, py, ch);
							++px;
							field->set_point(px, py, '@');
						}
					}
				}
			}
		}
	}
	else if (direction == 1)
	{
		if (py <SIZE - 2 && !(field->isWall(px, py + 1)))
		{
			ch = field->getChar(px, py + 1);
			field->set_point(px, py, ch);
			++py;
			field->set_point(px, py, '@');
		}
		else
		{
			direction = rand() % 3;
			if (direction == 0)
			{
				if (py >1 && !(field->isWall(px, py - 1)))
				{
					ch = field->getChar(px, py - 1);
					field->set_point(px, py, ch);
					--py;
					field->set_point(px, py, '@');				
				}
				else
				{
					direction = rand() % 2;
					if (direction == 0)
					{
						if (px <SIZE - 2 && !(field->isWall(px + 1, py)))
						{
							ch = field->getChar(px + 1, py);
							field->set_point(px, py, ch);
							++px;
							field->set_point(px, py, '@');
						}
						else if (px>1 && !(field->isWall(px - 1, py)))
						{
							ch = field->getChar(px - 1, py);
							field->set_point(px, py, ch);					
							--px;
							field->set_point(px, py, '@');
						}
					}
					else if (direction == 1)
					{
						if (px>1 && !(field->isWall(px - 1, py)))
						{
							ch = field->getChar(px - 1, py);
							field->set_point(px, py, ch);
							--px;
							field->set_point(px, py, '@');
							
						}
						else if (px <SIZE - 2 && !(field->isWall(px + 1, py)))
						{
							ch = field->getChar(px + 1, py);
							field->set_point(px, py, ch);
							++px;
							field->set_point(px, py, '@');
						}
					}
				}
			}
			else if (direction == 1)
			{
				if (px < SIZE - 2 && !(field->isWall(px + 1, py)))
				{					
					ch = field->getChar(px + 1, py);
					field->set_point(px, py, ch);
					++px;
					field->set_point(px, py, '@');
				}
				else
				{
					direction = rand() % 2;
					if (direction == 0)
					{
						if (py > 1 && !(field->isWall(px, py-1)))
						{				
							ch = field->getChar(px, py - 1);
							field->set_point(px, py, ch);
							--py;
							field->set_point(px, py, '@');
						}
						else if (px>1 && !(field->isWall(px - 1, py)))
						{					
							ch = field->getChar(px - 1, py);
							field->set_point(px, py, ch);
							--px;
							field->set_point(px, py, '@');
						}
					}
					else if (direction == 1)
					{
						if (px>1 && !(field->isWall(px - 1, py)))
						{
							ch = field->getChar(px - 1, py);
							field->set_point(px, py, ch);
							--px;
							field->set_point(px, py, '@');
						}
						else if (py > 1 && !(field->isWall(px, py - 1)))
						{
							ch = field->getChar(px, py - 1);
							field->set_point(px, py, ch);
							--py;
							field->set_point(px, py, '@');
						}
					}
				}
			}
			else if (direction == 2)
			{
				if (px > 1 && !(field->isWall(px - 1, px)))
				{
					ch = field->getChar(px - 1, py);
					field->set_point(px, py, ch);
					--px;
					field->set_point(px, py, '@');
				}
				else
				{
					direction = rand() % 2;
					if (direction == 0)
					{
						if (px < SIZE - 2 && !(field->isWall(px + 1, py)))
						{					
							ch = field->getChar(px + 1, py);
							field->set_point(px, py, ch);
							++px;
							field->set_point(px, py, '@');
						}
						else if (py >1 && !(field->isWall(px, py - 1)))
						{			
							ch = field->getChar(px, py - 1);
							field->set_point(px, py, ch);
							--py;
							field->set_point(px, py, '@');							
						}
					}
					else if (direction == 1)
					{
						if (py >1 && !(field->isWall(px, py - 1)))
						{
							ch = field->getChar(px, py - 1);
							field->set_point(px, py, ch);
							--py;
							field->set_point(px, py, '@');
						}
						else if (px < SIZE - 2 && !(field->isWall(px + 1, py)))
						{
							ch = field->getChar(px + 1, py);
							field->set_point(px, py, ch);
							++px;
							field->set_point(px, py, '@');
						}
					}
				}
			}
		}
	}
	else if (direction == 2)
	{
		if (px > 1 && !(field->isWall(px - 1, py)))
		{
			ch = field->getChar(px - 1, py);
			field->set_point(px, py, ch);
			--px;
			field->set_point(px, py, '@');			
		}
		else
		{
			direction = rand() % 3;
			if (direction == 0)
			{
				if (py >1 && !(field->isWall(px, py - 1)))
				{
					ch = field->getChar(px, py - 1);
					field->set_point(px, py, ch);
					--py;
					field->set_point(px, py, '@');					
				}
				else
				{
					direction = rand() % 2;
					if (direction == 0)
					{
						if (py <SIZE - 2 && !(field->isWall(px, py+1)))
						{
							ch = field->getChar(px, py + 1);
							field->set_point(px, py, ch);
							++py;
							field->set_point(px, py, '@');							
						}
						else if (px < SIZE - 2 && !(field->isWall(px + 1, py)))
						{
							ch = field->getChar(px + 1, py);
							field->set_point(px, py, ch);
							++px;
							field->set_point(px, py, '@');							
						}
					}
					else if (direction == 1)
					{
						if (px < SIZE - 2 && !(field->isWall(px + 1, py)))
						{
							ch = field->getChar(px + 1, py);
							field->set_point(px, py, ch);
							++px;
							field->set_point(px, py, '@');
						}
						else if (py <SIZE - 2 && !(field->isWall(px, py + 1)))
						{
							ch = field->getChar(px, py + 1);
							field->set_point(px, py, ch);
							++py;
							field->set_point(px, py, '@');
						}
					}
				}
			}
			else if (direction == 1)
			{
				if (py < SIZE - 2 && !(field->isWall(px, py + 1)))
				{
					ch = field->getChar(px, py + 1);
					field->set_point(px, py, ch);
					++py;
					field->set_point(px, py, '@');					
				}
				else
				{
					direction = rand() % 2;
					if (direction == 0)
					{
						if (px < SIZE - 2 && !(field->isWall(px + 1, py)))
						{
							ch = field->getChar(px + 1, py);
							field->set_point(px, py, ch);
							++px;
							field->set_point(px, py, '@');							
						}
						else if (py >1 && !(field->isWall(px, py - 1)))
						{
							ch = field->getChar(px, py - 1);
							field->set_point(px, py, ch);
							--py;
							field->set_point(px, py, '@');							
						}
					}
					else if (direction == 1)
					{
						if (py >1 && !(field->isWall(px, py - 1)))
						{
							ch = field->getChar(px, py - 1);
							field->set_point(px, py, ch);
							--py;
							field->set_point(px, py, '@');
						}
						else if (px < SIZE - 2 && !(field->isWall(px + 1, py)))
						{
							ch = field->getChar(px + 1, py);
							field->set_point(px, py, ch);
							++px;
							field->set_point(px, py, '@');
						}
					}
				}
			}
			else if (direction == 2)
			{
				if (px <SIZE - 2 && !(field->isWall(px + 1, py)))
				{
					ch = field->getChar(px + 1, py);
					field->set_point(px, py, ch);
					++px;
					field->set_point(px, py, '@');					
				}
				else
				{
					direction = rand() % 2;
					if (direction == 0)
					{
						if (py > 1 && !(field->isWall(px, py - 1)))
						{
							ch = field->getChar(px, py - 1);
							field->set_point(px, py, ch);
							--py;
							field->set_point(px, py, '@');							
						}
						else if (py <SIZE - 2 && !(field->isWall(px, py + 1)))
						{
							ch = field->getChar(px, py + 1);
							field->set_point(px, py, ch);
							++py;
							field->set_point(px, py, '@');							
						}
					}
					else if (direction == 1)
					{
						if (py <SIZE - 2 && !(field->isWall(px, py + 1)))
						{
							ch = field->getChar(px, py + 1);
							field->set_point(px, py, ch);
							++py;
							field->set_point(px, py, '@');
						}
						else if (py > 1 && !(field->isWall(px, py - 1)))
						{
							ch = field->getChar(px, py - 1);
							field->set_point(px, py, ch);
							--py;
							field->set_point(px, py, '@');
						}
					}
				}
			}
		}
	}
	else if (direction == 3)
	{
		if (px < SIZE - 2 && !(field->isWall(px + 1, py)))
		{
			ch = field->getChar(px + 1, py);
			field->set_point(px, py, ch);
			++px;
			field->set_point(px, py, '@');			
		}
		else
		{
			direction = rand() % 3;
			if (direction == 0)
			{
				if (px >1 && !(field->isWall(px - 1, py)))
				{
					ch = field->getChar(px - 1, py);
					field->set_point(px, py, ch);
					--px;
					field->set_point(px, py, '@');					
				}
				else
				{
					direction = rand() % 2;
					if (direction == 0)
					{
						if (py >1 && !(field->isWall(px, py-1)))
						{
							ch = field->getChar(px, py - 1);
							field->set_point(px, py, ch);
							--py;
							field->set_point(px, py, '@');							
						}
						else if (py <SIZE-2 && !(field->isWall(px,py+1)))
						{
							ch = field->getChar(px, py + 1);
							field->set_point(px, py, ch);
							++py;
							field->set_point(px, py, '@');							
						}
					}
					else if (direction == 1)
					{
						if (py <SIZE - 2 && !(field->isWall(px, py + 1)))
						{
							ch = field->getChar(px, py + 1);
							field->set_point(px, py, ch);
							++py;
							field->set_point(px, py, '@');
						}
						else if (py >1 && !(field->isWall(px, py - 1)))
						{
							ch = field->getChar(px, py - 1);
							field->set_point(px, py, ch);
							--py;
							field->set_point(px, py, '@');
						}
					}
				}
			}
			else if (direction == 1)
			{
				if (py < SIZE - 2 && !(field->isWall(px, py + 1)))
				{
					ch = field->getChar(px, py + 1);
					field->set_point(px, py, ch);
					++py;
					field->set_point(px, py, '@');					
				}
				else
				{
					direction = rand() % 2;
					if (direction == 0)
					{
						if (px >1 && !(field->isWall(px - 1, py)))
						{
							ch = field->getChar(px - 1, py);
							field->set_point(px, py, ch);
							--px;
							field->set_point(px, py, '@');							
						}
						else if(py>1 && !(field->isWall(px,py-1)))
						{
							ch = field->getChar(px, py - 1);
							field->set_point(px, py, ch);
							--py;
							field->set_point(px, py, '@');							
						}
					}
					else if (direction == 1)
					{
						if (py>1 && !(field->isWall(px, py - 1)))
						{
							ch = field->getChar(px, py - 1);
							field->set_point(px, py, ch);
							--py;
							field->set_point(px, py, '@');
						}
						else if (px >1 && !(field->isWall(px - 1, py)))
						{
							ch = field->getChar(px - 1, py);
							field->set_point(px, py, ch);
							--px;
							field->set_point(px, py, '@');
						}
					}
				}
			}
			else if (direction == 2)
			{
				if (py >1 && !(field->isWall(px, py - 1)))
				{
					ch = field->getChar(px, py - 1);
					field->set_point(px, py, ch);
					--py;
					field->set_point(px, py, '@');					
				}
				else
				{
					direction = rand() % 2;
					if (direction == 0)
					{
						if (py <SIZE - 2 && !(field->isWall(px, py + 1)))
						{
							ch = field->getChar(px, py + 1);
							field->set_point(px, py, ch);
							++py;
							field->set_point(px, py, '@');							
						}
						else if(px>1 && !(field->isWall(px - 1, py)))
						{
							ch = field->getChar(px - 1, py);
							field->set_point(px, py, ch);
							--px;
							field->set_point(px, py, '@');							
						}
					}
					else if (direction == 1)
					{
						if (px>1 && !(field->isWall(px - 1, py)))
						{
							ch = field->getChar(px - 1, py);
							field->set_point(px, py, ch);
							--px;
							field->set_point(px, py, '@');
						}
						else if (py <SIZE - 2 && !(field->isWall(px, py + 1)))
						{
							ch = field->getChar(px, py + 1);
							field->set_point(px, py, ch);
							++py;
							field->set_point(px, py, '@');
						}
					}
				}
			}
		}
	}

	if (field->isPlayer(px, py))
	{
		field->ShowEnd();
	}
	
}

void Enemy::setRandom(Field *field)
{
	std::srand(time(0));
	int x;
	int y;
	char N, S, W, E;
	while (true)
	{
		for (int i = 0; i < time_rand; i++) {}
		x = rand() % SIZE-2;
		y = rand() % SIZE-2;
		if (x == 0)
			x++;
		if (y == 0)
			y++;
		x = abs(x);
		y = abs(y);
		N = field->getChar(x, y - 1);
		S = field->getChar(x, y + 1);
		W = field->getChar(x - 1, y);
		E = field->getChar(x + 1, y);
		if (!(field->isWall(x, y)))
		{		
			px = x;
			py = y;
			return;
		}
		time_rand += 10000;
	}
}