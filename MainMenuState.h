#pragma once
#include "GameState.h"
#include "iostream"

#define PLAY 0
#define RULES 1
#define EXIT 2

using namespace sf;

class MainMenuState :
	public GameState
{
private:
	Font font;
	Text title;
	Text menu;
public:
	// formats the main menu
	MainMenuState();
	void onSwitch(std::vector<SwitchFlags>& flags);
	
	// draws the main menu
	void draw(RenderWindow& window);

	// draws the entire rules tab
	void rules(RenderWindow& window);
	States update(std::vector<Event>& events, std::vector<SwitchFlags>& o_flags);
	RectangleShape selector;
	int selectorpos;
	~MainMenuState();
};

