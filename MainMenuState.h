#pragma once
#include "GameState.h"
#include "iostream"

enum {
	PLAY,
	RULES,
	EXIT
};

//using namespace sf;

using sf::Font;
using sf::Text;
using sf::RectangleShape;
using sf::Event;
using sf::RenderWindow;
using sf::Color;
using sf::Vector2f;
using sf::Keyboard;


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

