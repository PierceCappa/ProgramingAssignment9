#include "PlayState.h"

PlayState::PlayState()
{

}

void PlayState::onSwitch()
{
}
States PlayState::update(vector<sf::Event>& events)
{
	std::cout << "dummy function" << endl;
	return States::MAIN_MENU;
}

void PlayState::draw(sf::RenderWindow& window)
{

}
