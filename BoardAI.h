#pragma once
#ifndef BOARDAI_H
#define BOARDAI_H
#include "GameState.h"
#include "Board.h"
#include "iostream"

class BoardAI : public Board
{
public:
	BoardAI()
	{
		boardCreatorLoop();
		placeShips();
	}
	~BoardAI()
	{

	}
	//this funciton draws the board that for that AI that the player sees
	void drawBoard(RenderWindow& window);
	//this funciotn places all of the ships for the AI randomly
	void placeShips();
	//this function is called by the place ships function and checks to see if the AI can place a ship in a spot and in what direction
	void check(int size, string shipName, int ship);
	
};
//this function randomly generates and X and Y coordinate  between 0 and 9
void choiceAI(int& x, int& y);

#endif
