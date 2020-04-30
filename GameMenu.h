#pragma once
#pragma once
#include "GameState.h"
#include "iostream"
#include "MainMenuState.h"

using namespace sf;

//this class inherits from MainMenuState and is used for the 
class GameMenu : public MainMenuState
{
public:
// this function displays the instructions for in the placing ships function for the user
	void placingShips(RenderWindow& window, string ship, int size);
// this function displays all of the text in the actual game
	void game(RenderWindow& window);
};
