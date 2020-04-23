#pragma once
#include "GameState.h"
class MainMenuState :
	public GameState
{
private:
	sf::CircleShape shape;
	
public:
	MainMenuState();
	void onSwitch(std::vector<SwitchFlags>& flags);
	void draw(sf::RenderWindow& window);
	States update(std::vector<sf::Event>& events, std::vector<SwitchFlags>& o_flags);
	~MainMenuState();
};

