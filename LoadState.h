#pragma once

#include "GameState.h"
#include <iostream>

class LoadState : public GameState
{
public:
	void onSwitch(std::vector<SwitchFlags>& flags);
	void draw(sf::RenderWindow& window);
	States update(std::vector<sf::Event>& events, std::vector<SwitchFlags>& o_flags);
	~LoadState();
};