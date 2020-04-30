#include "PlayState.h"

PlayState::PlayState()
{
	sf::Texture* tex = GameManager::getTexture("textures/test.png");

	sprite = sf::Sprite(*tex);
	sprite.move(20, 0);
}

void PlayState::onSwitch()
{
}

int hori = 10;
int verti = 10;
States PlayState::update(vector<sf::Event>& events)
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
}

void PlayState::draw(sf::RenderWindow& window)
{
		
		window.clear();
		labels.game(window);
		gameBoardAI.drawBoard(window);
		gameBoard.drawBoard(window);
		window.display();
}
