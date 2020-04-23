#include "MainMenuState.h"

MainMenuState::MainMenuState()
{
	shape = sf::CircleShape(50.0f);
	shape.setFillColor(sf::Color(100, 250, 50));
}

void MainMenuState::onSwitch(std::vector<SwitchFlags>& flags)
{

}

void MainMenuState::draw(sf::RenderWindow& window)
{
	window.draw(shape);
}

States MainMenuState::update(std::vector<sf::Event>& events, std::vector<SwitchFlags>& o_flags)
{
	// currently unimplemented!
	return States::NO_CHANGE;
}

MainMenuState::~MainMenuState()
{
}
