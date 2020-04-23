// comment or uncomment the following line to enable test mode
// #define TESTING

#if defined(TESTING)
#include "Test.h"

int main()
{

	return 0;
}

#else

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "MainMenuState.h"
#include "LoadState.h"

using namespace std;

int main()
{
	LoadState loadState;
	MainMenuState menuState;
	GameState* currentState = &loadState;

	sf::RenderWindow window(sf::VideoMode(800, 600), "My Window");
	window.setVerticalSyncEnabled(true);

	sf::CircleShape shape(50.f);
	shape.setFillColor(sf::Color(100, 250, 50));

	while (window.isOpen())
	{
		sf::Event event;
		std::vector<sf::Event> events;
		std::vector<SwitchFlags> switchFlags;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			else
			{
				events.push_back(event);
			}
		}

		// update game logic
		auto nextStateEnum = currentState->update(events, switchFlags);

		// clear before draw
		window.clear(sf::Color::Black);

		// draw calls
		currentState->draw(window);
		
		// finally, show the frame
		window.display();

		// After doing all that, change state if necessary

		bool switching = true;
		switch (nextStateEnum)
		{
		case (States::LOAD):
			currentState = &loadState;
			break;
		case (States::MAIN_MENU):
			currentState = &menuState;
			break;
		default:
			cout << "Unimplemented state enum!" << endl;
		case (States::NO_CHANGE):
			switching = false;
			break;
		}
		if (switching)
		{
			currentState->onSwitch(switchFlags);
		}
	}
	return 0;
}

#endif