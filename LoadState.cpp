#include "LoadState.h"

void LoadState::onSwitch(std::vector<SwitchFlags>& flags)
{

}
void LoadState::draw(sf::RenderWindow& window)
{

}
States LoadState::update(std::vector<sf::Event>& events, std::vector<SwitchFlags>& o_flags)
{
	std::cout << "Load function called!" << std::endl;
	return States::MAIN_MENU;
}
LoadState::~LoadState()
{

}