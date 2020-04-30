
#include "GameLoop.h"



void runGame(sf::RenderWindow& window)
{
	GameMenu labels;
	Board gameBoard;
	gameBoard.placeShips(window);
	BoardAI gameBoardAI;
	int x, y;
	const int squareSize = 78.0f;
	int phase = 0;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || gameBoard.checkIfLost() == true || gameBoardAI.checkIfLost() == true)
			{
				window.close();
			}
			else if (event.type == Event::KeyPressed)
			{
				if (Keyboard::isKeyPressed(Keyboard::Up) && gameBoardAI.getY() > 0)
				{
					gameBoardAI.moveY(-1);
				}
				else if (Keyboard::isKeyPressed(Keyboard::Down) && gameBoardAI.getY() < 9)
				{
					gameBoardAI.moveY(1);
				}
				else if (Keyboard::isKeyPressed(Keyboard::Left) && gameBoardAI.getX() > 0)
				{
					gameBoardAI.moveX(-1);
				}
				else if (Keyboard::isKeyPressed(Keyboard::Right) && gameBoardAI.getX() < 9)
				{
					gameBoardAI.moveX(1);
				}
				else if (Keyboard::isKeyPressed(Keyboard::Enter))
				{
					gameBoardAI.checkHit(gameBoardAI.getX(), gameBoardAI.getY());
					choiceAI(x, y);
					gameBoard.checkHit(x, y);
				}
			}
		}
		const int squareSize = 78.0f;
		window.clear();
		labels.game(window);
		gameBoardAI.drawBoard(window);
		gameBoard.drawBoard(window);
		window.display();
	}

}