#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <string>

using namespace std;

enum class States
{
	NO_CHANGE, 
	LOAD,
	MAIN_MENU,
	EXIT
};

enum class SwitchFlags
{

};

class GameState
{
public:
	// Call this when switching to this state from another state.
	virtual void onSwitch(vector<SwitchFlags>& flags) = 0;

	// Call this when drawing the contents of the state
	virtual void draw(sf::RenderWindow& window) = 0;

	// Call this when updating game logic in the state
	// and return which state to switch to
	// o_flags is an outut parameter
	virtual States update(vector<sf::Event>& events, vector<SwitchFlags>& o_flags) = 0;
};