// comment or uncomment the following line to enable test mode
//#define TESTING

#if defined(TESTING)
#include "test.h"

int main()
{
	return testing::run();
}

#else

// Please do not edit the main file unless you are changing 
// code that will be executed every frame!
//
// Most game logic should be written in GameState 
// update() code or draw() code.
// Please consult Cody if you don't understand this.

// TODO:
// implement framerate control.

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <conio.h>
#include "MainMenuState.h"
#include "PlayState.h"
#include "GameState.h"
#include "Board.h"

using sf::RenderWindow;
using sf::Event;
using sf::VideoMode;

int main()
{
	// Initialize the states.
	MainMenuState menuState;
	PlayState playState;
	GameState* currentState = &menuState;

	// create the window.
	RenderWindow window(VideoMode(800, 800), "My Window");
	window.setVerticalSyncEnabled(true);     

	while (window.isOpen())
	{
		Event event;
		std::vector<Event> events;

		/// EXPLANATION
		/*
		The window here is taking all events and inserting them into a vector.
		It will later pass that vector of events to the gamestate being called.
		Code to handle events should thus be written in the gamestate update code.
		Any event handling done in this loop is captured by the window before
		the state is called, overriding it. (e.g, clicking the x and triggering
		Event::Closed will always close the window regardless of what the 
		current gamestate wants.)
		*/
		while (window.pollEvent(event))
		{
			// if user closes the window, close the window
			if (event.type == Event::Closed)
			{
				window.close();
			}
			// this inserts the event into the event vector, to be sent to the state.
			else 
			{
				events.push_back(event);
			}      
		}
		
		/// EXPLANATION
		/*
		What the program is doing at any given time (showing the main menu, showing the actual game, etc.)
		will be represented by states that inherit the GameState class.

		This allows the program to compartmentalize various game states and not have to write
		a labyrinth of switch statements.

		Please add all actual game logic to an appropriate state. that code will be called here.

		nextStateEnum is an integer flag that just tells us what state to load next.

		Also, *do not write any code that assumes access to the window in game logic*. 
		*/
		auto nextStateEnum = currentState->update(events);
		
		//////////////
		//// DRAW ////
		//////////////

		// clear before draw
		window.clear(Color(0, 20, 40, 255));

		// EXPLANATION
		/*
		This is the same as the update block above, but with draw.
		any code that actually interact with the game window and renders to it should be called
		in the draw(window) function of the appropriate gamestate.
		*/
		currentState->draw(window);

		// swaps the display buffer, putting everything that was drawn on the screen.
		window.display();
		// After doing all that, change state if necessary


		// EXPLANATION
		/*
		The gamestate is changed here based on what is returned by the
		update function of the current gamestate.

		You may edit this section to add new gamestates if deemed necessary,
		making sure to also add an appropriate enum for the state in GameState.h

		States::NO_CHANGE and States::QUIT are special values that do not correspond
		to a particular state, but instead tell the program to keep the current state,
		or exit entirely, respectively.
		*/
		bool switching = true;
		switch (nextStateEnum)
		{
		case (States::MAIN_MENU):
			currentState = &menuState;
			break;
		case (States::PLAY):
			currentState = &playState;
			break;

		default:
			std::cout << "Unimplemented state enum!" << std::endl;
		case (States::NO_CHANGE):
			switching = false;
			break;
		case (States::QUIT):
			switching = false;
			window.close();
			break;
		}
		// If the gamestate is changed, onSwitch() is called 
		if (switching)
		{
			currentState->onSwitch();
		}
	}
	return 0;
}

#endif