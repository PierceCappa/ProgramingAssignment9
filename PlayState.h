#pragma once

#include "GameState.h"
#include "GameManager.h"

class PlayState : public GameState
{
private:
	sf::Sprite sprite;
public:
	PlayState();
	void onSwitch();
	States update(vector<sf::Event>& events);
	void draw(sf::RenderWindow& window);
	
};