#include "stdafx.h"
#include "Field.h"
#include "Helper.h"
#include <iostream>
#include <fstream>
#include <conio.h>
Field::Field()
{
	m_field.resize(SIZE);
	for (int i = 0; i < SIZE; ++i)
		m_field[i].resize(SIZE);
}

void Field::load_field()
{
	std::ifstream fin("field.txt");
	int x = 0;
	int y = 0;
	char ch;
	while (!fin.eof())
	{
		ch = fin.get();

		if (ch == '\n')
		{
			++y;
			x = 0;
			ch = fin.get();
		}
		m_field[y][x] = ch;
		if (ch == ' ')
			m_field[y][x] = '.';
		x++;
	}
	m_field[1][1] = 'P';
}

void Field::show_field() const
{
	system("cls");
	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
			std::cout << m_field[i][j];
		std::cout << std::endl;
	}
}
void Field::set_point(int x, int y, char ch)
{
	m_field[x][y] = ch;
}

bool Field::isWall(int x, int y)
{
	if (m_field[x][y] == '#' || m_field[x][y]=='@')
		return true;
	else return false;
}

bool Field::isCoin(int x, int y)
{
	if (m_field[x][y] == '.')
		return true;
	else
		return false;
}

bool Field::isPlayer(int x,int y)
{
	if (m_field[x][y] == m_field[player_x][player_y])
		return true;
	else 
		return false;
}

void Field::PlayerCoord(int x, int y)
{
	player_x = x;
	player_y = y;
}
char Field::getChar(int x, int y)
{
	return m_field[x][y];
}

void Field::ShowEnd() const
{
	std::cout << "\nGame Over\nLOOK YOUR SCORE! Bye!" << std::endl;
	_getch();
	_getch();
	_getch();
	exit(0);
}