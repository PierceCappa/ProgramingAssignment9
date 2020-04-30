#pragma once
#pragma once
#include "GameState.h"
#include "iostream"
#include "MainMenuState.h"

#define PLAY 0
#define RULES 1
#define EXIT 2

using namespace sf;

class GameMenu : public MainMenuState
{
public:
	void placingShips(RenderWindow& window, string ship, int size);
	void game(RenderWindow& window);
};
