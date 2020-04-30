#pragma once
#ifndef BOARDAI_H
#define BOARDAI_H
#include "GameState.h"
#include "Board.h"
#include "iostream"


#define PLAY 0
#define RULES 1
#define EXIT 2

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
	void drawBoard(RenderWindow& window);
	void placeShips();
	void check(int size, string shipName, int ship);
	
};
void choiceAI(int& x, int& y);

#endif
