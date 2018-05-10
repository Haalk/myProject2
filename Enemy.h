#pragma once
#include "Field.h"

class Enemy
{
public:
	void move(Field *f);
	Enemy(int,int);
	Enemy();
	void setCoord(int,int);
	void setRandom(Field *f);
private:
	int px, py;
	char ch;
	int time_rand;
};