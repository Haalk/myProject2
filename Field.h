#pragma once
#include <vector>


class Field
{
public:
	Field();
	void load_field();
	void show_field() const;
	void set_point(int, int, char);
	bool isWall(int, int);
	bool isCoin(int x, int y);
	char getChar(int, int);
	bool isPlayer(int, int);
	void PlayerCoord(int,int);
	void ShowEnd() const;
private:
	std::vector<std::vector<char>> m_field;
	int player_x;
	int player_y;
};