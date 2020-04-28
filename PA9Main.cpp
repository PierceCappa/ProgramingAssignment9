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
#include <conio.h>
#include "MainMenuState.h"
#include "LoadState.h"
#include "GameState.h"
#include "Board.h"


using namespace sf;

int main()
{
	LoadState loadState;
	MainMenuState menuState;
	GameState* currentState = &loadState;
	MainMenuState rules;

	RenderWindow window(VideoMode(800, 800), "My Window");
	window.setVerticalSyncEnabled(true);     

	int k;

	while (window.isOpen())
	{
		Event event;
		std::vector<Event> events;
		std::vector<SwitchFlags> switchFlags;

		while (window.pollEvent(event))
		{
			// if user closes the window, close the window
			if (event.type == Event::Closed)
			{
				window.close();
			}
			// if user presses a key in the main menu
			else if (event.type == Event::KeyPressed)
			{
				// if user presses the down or up arrow,  change the value of the selector's position (grey box)
				//	0 for play, 1 for rules and 2 for exit
				if (Keyboard::isKeyPressed(Keyboard::Down) && menuState.selectorpos < 2)
					++menuState.selectorpos; 
				if (Keyboard::isKeyPressed(Keyboard::Up) && menuState.selectorpos >= 0)
					--menuState.selectorpos;
			}
			// not entirely sure what this does
			else 
			{
				events.push_back(event);
			}      
		}
		//  changes where the selector is drawn in the window as well as the size to fit around the words
		switch (menuState.selectorpos)
		{
		case PLAY:
			menuState.selector.setPosition(Vector2f(10, 165));
			menuState.selector.setSize(Vector2f(105, 55));
			break;
		case RULES:
			menuState.selector.setPosition(Vector2f(10, 222));
			menuState.selector.setSize(Vector2f(130, 55));
			break;
		case EXIT:
			menuState.selector.setPosition(Vector2f(10, 279));
			menuState.selector.setSize(Vector2f(105, 55));
			break;
		}

		// update game logic
		auto nextStateEnum = currentState->update(events, switchFlags);

		// if enter is pressed it will go through the switch to find what the user selected using the selectorpos
		if (Keyboard::isKeyPressed(Keyboard::Enter))
		{
			switch (menuState.selectorpos)
			{
				//if play, the game will begin
			case PLAY:
				break;
				//if rules, the rules will be displayed
			case RULES:
				// clear before draw
				window.clear(Color(0, 20, 40, 255));
				
				//draw rules
				menuState.rules(window);

				//display
				window.display();

				while (!Keyboard::isKeyPressed(Keyboard::Escape))
				{
					if (event.type == Event::Closed)
					{
						window.close();
					}
				}

				break;
				//if exit, the program will end and the window will close
			case EXIT:
				exit(0);
			}
		}
		else
		{
			//////////////
			//// DRAW ////
			//////////////

			// clear before draw
			window.clear(Color(0, 20, 40, 255));

			// draw calls
			currentState->draw(window);

			// finally, show the frame
			window.display();
		}
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
			std::cout << "Unimplemented state enum!" << std::endl;
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