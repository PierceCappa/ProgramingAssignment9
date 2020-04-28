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
}

// draws the entire rules tab
void MainMenuState::rules(RenderWindow& window)
{
	Text rulestext,
		rulestitle,
		rulesSubtitle;

	rulestitle.setString("Rules");
	rulestitle.setFont(font);
	rulestitle.setCharacterSize(100);
	rulestitle.setFillColor(Color(169, 169, 169, 255));
	rulestitle.setStyle(Text::Bold);
	rulestitle.setPosition(280.f, 0.f);
	window.draw(rulestitle);

	rulesSubtitle.setString("Objective:");
	rulesSubtitle.setFont(font);
	rulesSubtitle.setCharacterSize(40);
	rulesSubtitle.setFillColor(Color(169, 169, 169, 255));
	rulesSubtitle.setStyle(Text::Bold);
	rulesSubtitle.setPosition(10.f, 100.f);
	window.draw(rulesSubtitle);

	rulestext.setString("\nThe object of Battleship is to try and sink all of the \nother player's before they sink all of your ships.\n"
		"All of the other player's ships are somewhere on \ntheir board. You try and hit them by clicking one of the \nsquares on the board.");
	rulestext.setFont(font);
	rulestext.setCharacterSize(20);
	rulestext.setFillColor(Color(169, 169, 169, 255));
	rulestext.setPosition(10.f, 125.f);
	window.draw(rulestext);

	rulesSubtitle.setString("Starting the Game:");
	rulesSubtitle.setFont(font);
	rulesSubtitle.setCharacterSize(40);
	rulesSubtitle.setFillColor(Color(169, 169, 169, 255));
	rulesSubtitle.setStyle(Text::Bold);
	rulesSubtitle.setPosition(10.f, 350.f);
	window.draw(rulesSubtitle);
	
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
	window.draw(rulestext);
}

void MainMenuState::onSwitch(std::vector<SwitchFlags>& flags)
{

}

void MainMenuState::draw(sf::RenderWindow& window)
{
	window.draw(title);
	window.draw(menu);
	window.draw(selector);
}

States MainMenuState::update(std::vector<sf::Event>& events, std::vector<SwitchFlags>& o_flags)
{
	// currently unimplemented!
	return States::NO_CHANGE;
}

MainMenuState::~MainMenuState()
{

}