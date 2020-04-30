#include "BoardAI.h"



void BoardAI::drawBoard(RenderWindow& window)
{

	sf::Vector2f cellSize(squareSize, squareSize);
	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < boardSize; j++) {
			grid[i][j].setSize(cellSize);

			if (x == i && y == j)
			{
				grid[i][j].setOutlineColor(sf::Color::Magenta);
			}
			else
			{
				grid[i][j].setOutlineColor(sf::Color::Blue);
			}	
			grid[i][j].setOutlineThickness(5.0f);
		
			if (board[i][j] == 1)
			{
				grid[i][j].setFillColor(sf::Color::Cyan);
			}
			
			else if (board[i][j] == 3)
			{
				grid[i][j].setFillColor(sf::Color::Red);
			}
			else
			{
				grid[i][j].setFillColor(sf::Color::White);
			}
			grid[i][j].setPosition(i * cellSize.x + 817.0f, j * cellSize.y + 210.0f);
			window.draw(grid[i][j]);
		}
	}
}

void BoardAI::placeShips()
{
	check(5, "carrier", 1);
	check(4, "BattleShip", 2);
	check(3, "Cruiser", 3);
	check(3, "Submarine", 4);
	check(2, "Destroyer", 5);
}

void BoardAI::check(int size, string shipName, int ship)
{
	cout << ship << endl;
	bool place = true;
	bool up, right, down, left;
	int y;
	int x;
	int input;
	while (place == true)
	{
		choiceAI(x, y);
		if (x >= 0 && x <= 9 && y >= 0 && y <= 9)
		{
			if (checkIfSpaceForShip(size, up, right, down, left, x, y) == true)
			{

				input = rand() % 4 + 1;
				if (input == 1 && up == true)
				{
					placeShip(x, y, 0, -1, size, ship);
					place = false;
				}
				else if (input == 2 && down == true)
				{
					placeShip(x, y, 0, 1, size, ship);
					place = false;
				}
				else if (input == 3 && left == true)
				{
					placeShip(x, y, -1, 0, size, ship);
					place = false;
				}
				else if (input == 4 && right == true)
				{
					placeShip(x, y, 1, 0, size, ship);
					place = false;
				}
			}
	
		}
		
	}
}

void choiceAI(int& x, int& y)
{
	y = rand() % 10;
	x = rand() % 10;
}