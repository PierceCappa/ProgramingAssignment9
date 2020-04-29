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
	bool draw_rules;

	Text rulestext,
		rulestitle,
		rulesSubtitle;
public:
	// formats the main menu
	MainMenuState();
	void onSwitch();
	
	// draws the main menu
	void draw(RenderWindow& window);

	// draws the entire rules tab
	void init_rules();
	States update(std::vector<Event>& events);
	RectangleShape selector;
	int selectorpos;
	~MainMenuState();
};

