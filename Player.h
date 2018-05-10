#pragma once
#include"Field.h"


class Player 
{
public:
	void move(Field *f);
	Player();
	void ShowScore() const;
	void WIN();
private:
	int px, py;
	enum dir { UP = 72, DOWN = 80, RIGHT = 77, LEFT = 75, EXIT = 27 };
	int scores;
};