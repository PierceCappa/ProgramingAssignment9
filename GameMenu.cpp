#include "GameMenu.h"

void GameMenu::game(RenderWindow& window)
{
	Text titles, instructions, state, divide;
	titles.setString("Player 1 Board        Computer Board");
	titles.setFont(font);
	titles.setCharacterSize(90);
	titles.setFillColor(Color(169, 169, 169, 255));
	titles.setStyle(Text::Bold);
	titles.setPosition(0.f, -20.f);
	window.draw(titles);

	divide.setString("						   |\n			 			  |");
	divide.setFont(font);
	divide.setCharacterSize(100);
	divide.setFillColor(Color(169, 169, 169, 255));
	divide.setStyle(Text::Bold);
	divide.setPosition(10.f, -20.f);
	window.draw(divide);

	instructions.setString("If a square is white, it is either empty or unkown,\nA cyan square means a square was bombed and it was empty \nA black sqaure represents one of your ship pieces\nA red square means it was bombed and a ship piece was there");
	instructions.setFont(font);
	instructions.setCharacterSize(20);
	instructions.setFillColor(Color(169, 169, 169, 255));
	instructions.setStyle(Text::Bold);
	instructions.setPosition(0.f, 90.f);
	window.draw(instructions);

	state.setString("To play simply select the space on your opponents board that you which to bomb\nThe computer will then do the same to you\nThis will continue until one of you has won");
	state.setFont(font);
	state.setCharacterSize(20);
	state.setFillColor(Color(169, 169, 169, 255));
	state.setStyle(Text::Bold);
	state.setPosition(820.f, 90.f);
	window.draw(state);
}

void GameMenu::placingShips(RenderWindow& window, string ship, int size)
{
	Text shipInfo, instructions;
	ship += ", size:";
	ship += to_string(size);
	string info = "Now placing your ";
	info += ship;
	shipInfo.setString(info);
	shipInfo.setFont(font);
	shipInfo.setCharacterSize(40);
	shipInfo.setFillColor(Color::Blue);
	shipInfo.setStyle(Text::Bold);
	shipInfo.setPosition(0.f, -5.f);
	window.draw(shipInfo);

	instructions.setString("To place your ship, Scroll throug the board using the arrow keys \nOnce you have found a location to put your ship, press enter\nThen press the arrow key once more in the direction you which to angle the ship");
	instructions.setFont(font);
	instructions.setCharacterSize(20);
	instructions.setFillColor(Color::Cyan);
	instructions.setStyle(Text::Bold);
	instructions.setPosition(0.f, 35.f);
	window.draw(instructions);
}