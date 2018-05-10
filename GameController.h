#pragma once
#include "Enemy.h"
#include "Player.h"
class GameController
{
public:
	GameController();
	void Game();
	~GameController();
private:
	Field * m_field;
	Player m_player;
	std::vector<Enemy> m_enemies;
};