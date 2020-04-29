#include "MainMenuState.h"

// draws the main menu tab
MainMenuState::MainMenuState()
{
	//writing menu
	if (!font.loadFromFile("arial.ttf"))
	{
		cout << "Error loading font";
	}
	title.setFont(font);
	title.setString("Battleship");
	title.setCharacterSize(100);
	title.setFillColor(Color(169,169,169,255));
	title.setStyle(Text::Bold);
	title.setPosition(200.f, 0.f);
	
	menu.setFont(font);
	menu.setString("\nPlay\nRules\nExit");
	menu.setCharacterSize(50);
	menu.setFillColor(Color(169, 169, 169,255));
	menu.setPosition(10.f, 100.f);

	selector.setOutlineThickness(2);
	selector.setOutlineColor(Color(169, 169, 169, 150));
	selector.setFillColor(Color(0, 0, 0, 0));
	selectorpos = 0;

	// setup rules text
	draw_rules = false;
	init_rules();
}

// draws the entire rules tab
void MainMenuState::init_rules()
{

	rulestitle.setString("Rules");
	rulestitle.setFont(font);
	rulestitle.setCharacterSize(100);
	rulestitle.setFillColor(Color(169, 169, 169, 255));
	rulestitle.setStyle(Text::Bold);
	rulestitle.setPosition(280.f, 0.f);

	rulesSubtitle.setString("Objective:");
	rulesSubtitle.setFont(font);
	rulesSubtitle.setCharacterSize(40);
	rulesSubtitle.setFillColor(Color(169, 169, 169, 255));
	rulesSubtitle.setStyle(Text::Bold);
	rulesSubtitle.setPosition(10.f, 100.f);

	rulestext.setString("\nThe object of Battleship is to try and sink all of the \nother player's before they sink all of your ships.\n"
		"All of the other player's ships are somewhere on \ntheir board. You try and hit them by clicking one of the \nsquares on the board.");
	rulestext.setFont(font);
	rulestext.setCharacterSize(20);
	rulestext.setFillColor(Color(169, 169, 169, 255));
	rulestext.setPosition(10.f, 125.f);

	rulesSubtitle.setString("Starting the Game:");
	rulesSubtitle.setFont(font);
	rulesSubtitle.setCharacterSize(40);
	rulesSubtitle.setFillColor(Color(169, 169, 169, 255));
	rulesSubtitle.setStyle(Text::Bold);
	rulesSubtitle.setPosition(10.f, 350.f);
	
	rulestext.setString("\nEach player places their 5 ships somewhere on their board.\n"
		"The ships can only be placed vertically or horizontally. Diagonal placement\n"
		"is not allowed. No part of a ship may hang off the edge of the board.\n"
		"Ships may not overlap each other. No ships may be placed on another ship.\n"
		"Once the guessing begins, the players may not move the ships.\n"
		"\nThe 5 ships are :\nCarrier(occupies 5 spaces), Battleship(4), Cruiser(3), Submarine(3), and Destroyer(2).\n");
	rulestext.setFont(font);
	rulestext.setCharacterSize(20);
	rulestext.setFillColor(Color(169, 169, 169, 255));
	rulestext.setPosition(10.f, 375.f);
}

void MainMenuState::onSwitch()
{

}

void MainMenuState::draw(sf::RenderWindow& window)
{
	if (draw_rules)
	{
		window.draw(rulestitle);
		window.draw(rulesSubtitle);
		window.draw(rulestext);
		window.draw(rulesSubtitle);
		window.draw(rulestext);
	}
	else
	{
		window.draw(title);
		window.draw(menu);
		window.draw(selector);
	}
}

States MainMenuState::update(std::vector<sf::Event>& events)
{
	for (size_t i = 0; i < events.size(); ++i)
	{
		if (events[i].type == Event::KeyPressed && !draw_rules)
		{
			// if user presses the down or up arrow,  change the value of the selector's position (grey box)
			//	0 for play, 1 for rules and 2 for exit
			if (Keyboard::isKeyPressed(Keyboard::Down) && selectorpos < 2)
				++selectorpos;
			if (Keyboard::isKeyPressed(Keyboard::Up) && selectorpos >= 0)
				--selectorpos;
		}
	}
	//  changes where the selector is drawn in the window as well as the size to fit around the words
	switch (selectorpos)
	{
	case PLAY:
		selector.setPosition(Vector2f(10, 165));
		selector.setSize(Vector2f(105, 55));
		break;
	case RULES:
		selector.setPosition(Vector2f(10, 222));
		selector.setSize(Vector2f(130, 55));
		break;
	case EXIT:
		selector.setPosition(Vector2f(10, 279));
		selector.setSize(Vector2f(105, 55));
		break;
	}

	// if enter is pressed it will go through the switch to find what the user selected using the selectorpos
	if (Keyboard::isKeyPressed(Keyboard::Enter))
	{
		draw_rules = false;
		switch (selectorpos)
		{
			//if play, the game will begin
		case PLAY:
			return States::PLAY;
			break;
			//if rules, the rules will be displayed
		case RULES:
			draw_rules = true;
			break;
			//if exit, the program will end and the window will close
		case EXIT:
			return States::QUIT;
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		switch (selectorpos)
		{
		case RULES:
			draw_rules = false;
			break;
		}
	}
	return States::NO_CHANGE;
}

MainMenuState::~MainMenuState()
{

}