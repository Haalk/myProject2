#include ""
#include "Helper.h"
#include "Player.h"
#include "Field.h"
#include <conio.h>
#include <iostream>

Player::Player()
{
	px = py = 1;
	scores = 0;
}

void Player::move(Field *field)
{
	field->set_point(px, py, ' ');
	int key = _getch();
	if (key == LEFT && py > 1 && !(field->isWall(px, py - 1)))
	{
		--py;
	}
	else if (key == RIGHT && py < SIZE - 2 && !(field->isWall(px, py + 1)))
	{
		++py;
	}
	else if (key == DOWN && px < SIZE - 2 && !(field->isWall(px + 1, py)))
	{
		++px;
	}
	else if (key == UP && px > 1 && !(field->isWall(px - 1, py)))
	{
		--px;
	}
	else if (key == EXIT)
		exit(0);
	if (field->isCoin(px, py))
		scores += 10;
	field->set_point(px, py, 'P');
	field->PlayerCoord(px, py);
	if (scores >= 5500)
		WIN();
}

void Player::ShowScore() const
{
	std::cout << "Score : " << scores;
}

void Player::WIN()
{
	system("cls");
	std::cout << "\n\n\n\t\t\tCONGRATULATION!!!";
	_getch();
	_getch();
	_getch();
	exit(0);
}