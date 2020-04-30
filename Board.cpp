#include "Board.h"

Board::Board()
{
	x = 0; y = 0;
	boardCreatorLoop();
	

}

void Board::boardCreatorLoop()
{
	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 10; y++)
		{
			board[x][y] = 0;
		}
	}
}




Board::~Board()
{
	
}

void shipPlaceReset(int& x, int& y, int& size, string& shipName, int& ship, int count)
{
	if (count == 0)
	{
		size = 5;
		shipName = "Carrier";
		ship = 1;
		x = 0;
		y = 0;
	}
	else if (count == 1)
	{
		size = 4;
		shipName = "BattleShip";
		ship = 2;
		x = 0;
		y = 0;
	}
	else if (count == 2)
	{
		size = 3;
		shipName = "Cruiser";
		ship = 3;
		x = 0;
		y = 0;
	}
	else if (count == 3)
	{
		size = 3;
		shipName = "Submarine";
		ship = 4;
		x = 0;
		y = 0;
	}
	else if (count == 4)
	{
		size = 2;
		shipName = "Destroyer";
		ship = 5;
		x = 0;
		y = 0;
	}
}

void Board::placeShips()
{

	bool up, right, down, left;
	int count = 0;
	int size;
	int part;
	string shipName;
	int ship;
	GameMenu gameInstructions;
	sf::RenderWindow window(sf::VideoMode(800, 900), "BattleShip");
	part = 0;
	shipPlaceReset(x, y, size, shipName, ship, count);
	while (window.isOpen())
	{
		sf::Event event;
		std::vector<Event> events;
		std::vector<SwitchFlags> switchFlags;
		if (count == 5)
		{
			window.close();
		}
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			else if (event.type == Event::KeyPressed)
			{
				if (part == 0)
				{
					getUserInput(event);
					if (checkIfSpaceForShip(size, up, right, down, left, x, y) == true && Keyboard::isKeyPressed(Keyboard::Enter))
					{
						cout << up << "	" << down << "	" << right << "	" << left << endl;
						part++;
					}
				}
				else
				{

					if (Keyboard::isKeyPressed(Keyboard::Up) && up == true)
					{
						placeShip(x, y, 0, -1, size, ship);
						count++;
						shipPlaceReset(x, y, size, shipName, ship, count);
						part--;
					}
					else if (Keyboard::isKeyPressed(Keyboard::Down) && down == true)
					{
						placeShip(x, y, 0, 1, size, ship);
						count++;
						shipPlaceReset(x, y, size, shipName, ship, count);
						part--;
					}
					else if (Keyboard::isKeyPressed(Keyboard::Left) && left == true)
					{
						placeShip(x, y, -1, 0, size, ship);
						count++;
						shipPlaceReset(x, y, size, shipName, ship, count);
						part--;
					}
					else if (Keyboard::isKeyPressed(Keyboard::Right) && right == true)
					{
						placeShip(x, y, 1, 0, size, ship);
						count++;
						shipPlaceReset(x, y, size, shipName, ship, count);
						part--;
					}


				}
			}
			else
			{
				events.push_back(event);
			}
		}
		
		window.clear();
		drawBoard(window);
		gameInstructions.placingShips(window, shipName, size);
		window.display();
	}
	x = 100;
	y = 100;
}

void Board::getUserInput(Event &event)
{
	 
			
		 if (Keyboard::isKeyPressed(Keyboard::Up) && y > 0)
			 y--;
		 else if (Keyboard::isKeyPressed(Keyboard::Down) && y < 9)
			 y++;
		 if (Keyboard::isKeyPressed(Keyboard::Left) && x > 0)
			 x--;
		 else if (Keyboard::isKeyPressed(Keyboard::Right) && x < 9)
			 x++;

		 cout << x << "	" << y << endl;

}



void Board::placeShip(char x, int y, int changeX, int changeY, int size, int ship)
{
	cout << "placing ship" << endl;
	int cX, cY;
	char pX;
	int pY;
	for (int i = 0; i < size; i++)
	{
		pX = x;
		pY = y;
		cX = changeX;
		cY = changeY;
		cX *= i;
		cY *= i;
		if (ship == 1)
		{
			carrier[i] = &board[pX + cX][pY + cY];
			*carrier[i] = 2;
		}
		if (ship == 2)
		{
			battleShip[i] = &board[pX + cX][pY + cY];
			*battleShip[i] = 2;
		}
		if (ship == 3)
		{
			cruiser[i] = &board[pX + cX][pY + cY];
			*cruiser[i] = 2;
		}
		if (ship == 4)
		{
			submarine[i] = &board[pX + cX][pY + cY];
			*submarine[i] = 2;
		}
		if (ship == 5)
		{
			destroyer[i] = &board[pX + cX][pY + cY];
			*destroyer[i] = 2;
		}
	}

}


bool Board::checkIfSpaceForShip(int size, bool& up, bool& right, bool& down, bool& left, char x, int y)
{
	up = true;
	right = true;
	down = true;
	left = true;
	if (board[x][y] != 0)
	{
		return false;
	}
	if (x - size >= 0)
	{
		for (int i = 0; i < size; i++)
		{
			if (board[x-i][y] != 0)
			{
				left = false;
			}
		}
	}
	else
	{
		left = false;	
	}
	if (x + size <= 9)
	{
		for (int i = 0; i < size; i++)
		{
			if (board[x+i][y] != 0)
			{
				right = false;
			}
		}
	}
	else
	{
		right = false;
	}
	if (y - size >= 0)
	{
		for (int i = 0; i < size; i++)
		{
			if (board[x][y-i] != 0)
			{
				up = false;
			}
		}
	}
	else
	{
		up = false;
	}
	if (y + size <= 9)
	{
		for (int i = 0; i < size; i++)
		{
			if (board[x][y+i] != 0)
			{
				down = false;
			}
		}
	}
	else
	{
		down = false;
	}
	if (up == false && left == false && right == false && down == false)
	{
		return false;
	}
	else
		return true;
}

int Board::checkIfSpaceHasShip(char x, int y)
{
	if (cISHSLoop(x, y, carrier, 5) != 0)
	{
		return 1;
	}
	else if (cISHSLoop(x, y, battleShip, 4) != 0)
	{
		return 2;
	}
	else if (cISHSLoop(x, y, cruiser, 3) != 0)
	{
		return 3;
	}
	else if (cISHSLoop(x, y, submarine, 3) != 0)
	{
		return 4;
	}
	else if (cISHSLoop(x, y, battleShip, 2) != 0)
	{
		return 5;
	}
}

int Board::cISHSLoop(char x, int y, int** arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (*arr[i] == board[x][y])
		{
			return *arr[i];
		}
	}
	return 0;
}

int Board::checkHit(char x, int y)
{
	int ship = checkIfSpaceHasShip(x, y);
	if (ship != 0)
	{
		board[x][y] = 3;
	}
	else
	{
		board[x][y] = 1;
	}
	return ship;
}

bool Board::checkIfLost()
{
	
	for (int i = 0; i < 5; i++)
	{
		if (*carrier[i] == 2)
		{
			return false;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (*battleShip[i]== 2)
		{
			return false;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		if (*cruiser[i] == 2 || *submarine[i] == 2)
		{
			return false;
		}
	}
	for (int i = 0; i < 2; i++)
	{
		if (*destroyer[i] == 2)
		{
			return false;
		}
	}

	return true;
}

int convertCharCoordinate(char character)
{
	return character - 'a';
}

int getUserInputShipDirection()
{
	return 1;
}

void Board::drawBoard(RenderWindow& window)

{
	sf::RectangleShape grid[10][10];
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
			else if (board[i][j] == 2)
			{
				grid[i][j].setFillColor(sf::Color::Black);
			}
			else if (board[i][j] == 3)
			{
				grid[i][j].setFillColor(sf::Color::Red);
			}
			else
			{
				grid[i][j].setFillColor(sf::Color::White);
			}
			grid[i][j].setPosition(i * cellSize.x + 10.0f, j * cellSize.y + 210.0f);
			window.draw(grid[i][j]);
		}
	}
}


void Board::moveX(int X)
{
	x += X;
}

void Board::moveY(int Y)
{
	y += Y;
}

void Board::setXY()
{
	x = 0;
	y = 0;
}

int Board::getX()
{
	return x;
}

int Board::getY()
{
	return y;
}