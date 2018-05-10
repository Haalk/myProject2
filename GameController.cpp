#include ""
#include "GameController.h"
#include "Helper.h"
#include <iostream>
#include <conio.h>

GameController::GameController()
{
	m_field = new Field;
	m_field->load_field();
	m_enemies.resize(SIZE_ENEMIES);
	int time = 0;
	for (int i = 0; i < SIZE_ENEMIES; i++)
	{
		m_enemies[i].setRandom(m_field);
		switch (i)
		{
		case 0:std::cout << "\n\n\t\tHello this is PacMan"; break;
		case 1:std::cout << "\n\n\n\t\t\tby Denis"; break;
		case 2:std::cout << "\n\n\n\n\t\tYou must to pick up"; break;
		case 3:std::cout << "\n\n\n\n\n\t\t5500 scores to WIN!!!"; break;
		case 4:std::cout << "\n\n\n\n\n\n\t\tOn the field there are " 
						<< SIZE_ENEMIES << " enemies"; break;
		case 5:std::cout << "\n\n\n\n\n\n\n\t\tBe CAREFUL"; break;
		default:for (int i = 0; i < time; i++) {}; break;
		}
		time += 10000;
		_getch();
	}
	std::cout << "\n\n\n\n\n\n\n\n\t\tLet'go?";
	_getch();
	m_field->show_field();
}

void GameController::Game()
{
	while (true)
	{
		m_player.move(m_field);
		m_player.move(m_field);
		m_field->show_field();
		m_player.ShowScore();
		for (int i = 0; i<SIZE_ENEMIES; i++)
			m_enemies[i].move(m_field);
	}
}

GameController::~GameController()
{
	delete m_field;
}