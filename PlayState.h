#pragma once

#include "GameState.h"
#include "GameManager.h"
#include <iostream>

class PlayState : public GameState
{
private:
public:
	PlayState();
	void onSwitch();
	States update(vector<sf::Event>& events);
	void draw(sf::RenderWindow& window);
	
};