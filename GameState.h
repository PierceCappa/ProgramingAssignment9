#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <string>

#include "GameManager.h"

using namespace std;

enum class States
{
	NO_CHANGE, 
	MAIN_MENU,
	QUIT
};

class GameState
{
private:
	
public:
	// Call this when switching to this state from another state.
	virtual void onSwitch() = 0;

	// Call this when drawing the contents of the state
	virtual void draw(sf::RenderWindow& window) = 0;

	// Call this when updating game logic in the state
	// and return which state to switch to
	virtual States update(vector<sf::Event>& events) = 0;
};