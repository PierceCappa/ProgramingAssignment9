
#include "GameLoop.h"



void runGame()
{
	srand(time(0));
	LoadState loadState;
	GameState* currentState = &loadState;
	GameMenu labels;
	Board gameBoard;
	gameBoard.placeShips();
	BoardAI gameBoardAI;
	int x, y;
	const int squareSize = 78.0f;
	int phase = 0;
	sf::RenderWindow window(sf::VideoMode(1600, 1000), "BattleShip");

	while (window.isOpen())
	{
		sf::Event event;
		std::vector<Event> events;
		std::vector<SwitchFlags> switchFlags;
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
			else
			{
				events.push_back(event);
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