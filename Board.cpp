//#include "Board.h"
//
//Board::Board()
//{
//	topRightCornor = new BoardNode;
//	boardCreatorLoop(topRightCornor, 0);
//	placeShips();
//}
//
//void Board::boardCreatorLoop(BoardNode* currentRow, int row)
//{
//	if (row < 10)
//	{
//
//		rowCreatorLoop(currentRow, 0);
//		int nextRow = row;
//		nextRow++;
//		BoardNode* previousRow = findRow(row);
//		BoardNode* newNode = new BoardNode;
//		previousRow->setSpaceBelow(newNode);
//		boardCreatorLoop(previousRow->getSpaceBelow(), nextRow);
//	}
//}
//
//void Board::rowCreatorLoop(BoardNode*& currentNode, int member)
//{
//	if (member < 10)
//	{
//		BoardNode* newNode = new BoardNode;
//		currentNode->setSpaceRight(newNode);
//		currentNode = currentNode->getSpaceRight();
//		rowCreatorLoop(currentNode, member += 1);
//	}
//}
//
//BoardNode* Board::findRow(int Y)
//{
//	BoardNode* currentNode = topRightCornor;
//	for (int i = 0; i < Y; i++)
//	{
//		currentNode = currentNode->getSpaceBelow();
//	}
//	return currentNode;
//}
//
//Board::~Board()
//{
//	for (int y = 9; y > -1; y--)
//	{
//		for (char x = 'j'; x >= 'a'; x--)
//		{
//			free(findSpace(x, y));
//		}
//	}
//}
//
//void Board::displayBoardTerminal()
//{
//	BoardNode* currentNode;
//	char x = 'a';
//	cout << "	";
//	for (x; x < 'k'; x++)
//	{
//		cout << x << "	";
//	}
//	cout << endl;
//	x = 'a';
//	for (int y = 0; y < 10; y++)
//	{
//		cout << y << "	";
//		for (x; x < 'k'; x++)
//		{
//			cout << findSpace(x, y)->getState() << "	";
//		}
//		x = 'a';
//		cout << endl;
//	}
//}
//
//BoardNode* Board::findSpace(char x, int y)
//{
//	BoardNode* currentNode = findRow(y);
//	int X = x - 'a';
//	for (int i = 0; i < X; i++)
//	{
//		currentNode = currentNode->getSpaceRight();
//	}
//	return currentNode;
//}
//
//void Board::placeShips()
//{
//
//	displayBoardTerminal();
//	check(5, "carrier", 1);
//	displayBoardTerminal();
//	check(4, "BattleShip", 2);
//	displayBoardTerminal();
//	check(3, "Cruiser", 3);
//	displayBoardTerminal();
//	check(3, "Submarine", 4);
//	displayBoardTerminal();
//	check(2, "Destroyer", 5);
//}
//
//void Board::check(int size, string shipName, int ship)
//{
//	bool place = true;
//	bool up, right, down, left;
//	while (place == true)
//	{
//		char x;
//		int y;
//		int input;
//		cout << "where would you like to place the front of your " << shipName << ": size " << size << "(enter a letter a for your x and a number for y)" << endl;
//		cin >> x;
//		cin >> y;
//		if (x >= 'a' && x <= 'j' && y >= 0 && y <= 9)
//		{
//			if (checkIfSpaceForShip(size, up, right, down, left, x, y) == true)
//			{
//				if (up == true)
//				{
//					cout << "enter 1 to angle the ship up" << endl;
//				}
//				if (down == true)
//				{
//					cout << "enter 2 to angle the ship down" << endl;
//				}
//				if (left == true)
//				{
//					cout << "enter 3 to angle the ship left" << endl;
//				}
//				if (right == true)
//				{
//					cout << "enter 4 to angle the ship right" << endl;
//				}
//
//				cin >> input;
//				if (input == 1 && up == true)
//				{
//					placeShip(x, y, 0, -1, size, ship);
//					place = false;
//				}
//				else if (input == 2 && down == true)
//				{
//					placeShip(x, y, 0, 1, size, ship);
//					place = false;
//				}
//				else if (input == 3 && left == true)
//				{
//					placeShip(x, y, -1, 0, size, ship);
//					place = false;
//				}
//				else if (input == 4 && right == true)
//				{
//					placeShip(x, y, 1, 0, size, ship);
//					place = false;
//				}
//			}
//			else
//				cout << "invalid location, there is no room for this ship there" << endl;
//		}
//		else
//			cout << "this location does not exist try again" << endl;
//	}
//}
//
//void Board::placeShip(char x, int y, int changeX, int changeY, int size, int ship)
//{
//	int cX, cY;
//	char pX;
//	int pY;
//	for (int i = 0; i < size; i++)
//	{
//		pX = x;
//		pY = y;
//		cX = changeX;
//		cY = changeY;
//		cX *= i;
//		cY *= i;
//		if (ship == 1)
//		{
//			carrier[i] = findSpace(pX + cX, pY + cY);
//			carrier[i]->setState(2);
//		}
//		if (ship == 2)
//		{
//			battleShip[i] = findSpace(pX + cX, pY + cY);
//			battleShip[i]->setState(2);
//		}
//		if (ship == 3)
//		{
//			cruiser[i] = findSpace(pX + cX, pY + cY);
//			cruiser[i]->setState(2);
//		}
//		if (ship == 4)
//		{
//			submarine[i] = findSpace(pX + cX, pY + cY);
//			submarine[i]->setState(2);
//		}
//		if (ship == 5)
//		{
//			destroyer[i] = findSpace(pX + cX, pY + cY);
//			destroyer[i]->setState(2);
//		}
//	}
//
//}
//
//
//bool Board::checkIfSpaceForShip(int size, bool& up, bool& right, bool& down, bool& left, char x, int y)
//{
//	up = true;
//	right = true;
//	down = true;
//	left = true;
//	if (findSpace(x, y)->getState() != 0)
//	{
//		return 0;
//	}
//	if (x - size >= 'a')
//	{
//		for (int i = 0; i < size; i++)
//		{
//			if (findSpace(x - i, y)->getState() != 0)
//			{
//				left = false;
//			}
//		}
//	}
//	else
//	{
//		left = false;
//	}
//	if (x + size <= 'j')
//	{
//		for (int i = 0; i < size; i++)
//		{
//			if (findSpace(x + i, y)->getState() != 0)
//			{
//				right = false;
//			}
//		}
//	}
//	else
//	{
//		right = false;
//	}
//	if (y - size >= 0)
//	{
//		for (int i = 0; i < size; i++)
//		{
//			if (findSpace(x, y - i)->getState() != 0)
//			{
//				up = false;
//			}
//		}
//	}
//	else
//	{
//		up = false;
//	}
//	if (y + size <= 9)
//	{
//		for (int i = 0; i < size; i++)
//		{
//			if (findSpace(x, y + i)->getState() != 0)
//			{
//				down = false;
//			}
//		}
//	}
//	else
//	{
//		down = false;
//	}
//	if (up == false && left == false && right == false && down == false)
//	{
//		return false;
//	}
//	else
//		return true;
//}
//
//int Board::checkIfSpaceHasShip(char x, int y)
//{
//	if (cISHSLoop(x, y, carrier, 5) != 0)
//	{
//		return 1;
//	}
//	else if (cISHSLoop(x, y, battleShip, 4) != 0)
//	{
//		return 2;
//	}
//	else if (cISHSLoop(x, y, cruiser, 3) != 0)
//	{
//		return 3;
//	}
//	else if (cISHSLoop(x, y, submarine, 3) != 0)
//	{
//		return 4;
//	}
//	else if (cISHSLoop(x, y, battleShip, 2) != 0)
//	{
//		return 5;
//	}
//}
//
//int Board::cISHSLoop(char x, int y, BoardNode** arr, int size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		if (arr[i] == findSpace(x, y))
//		{
//			return arr[i]->getState();
//		}
//	}
//	return 0;
//}
//
//int Board::checkHit(char x, int y)
//{
//	int ship = checkIfSpaceHasShip(x, y);
//	if (ship != 0)
//	{
//		findSpace(x, y)->setState(4);
//	}
//	else
//	{
//		findSpace(x, y)->setState(2);
//	}
//	return ship;
//}
//
//bool Board::checkIfLost()
//{
//
//	for (int i = 0; i < 5; i++)
//	{
//		if (carrier[i]->getState() == 2)
//		{
//			return false;
//		}
//	}
//	for (int i = 0; i < 4; i++)
//	{
//		if (battleShip[i]->getState() == 2)
//		{
//			return false;
//		}
//	}
//	for (int i = 0; i < 3; i++)
//	{
//		if (cruiser[i]->getState() == 2 || submarine[i]->getState() == 2)
//		{
//			return false;
//		}
//	}
//	for (int i = 0; i < 2; i++)
//	{
//		if (destroyer[i]->getState() == 2)
//		{
//			return false;
//		}
//	}
//
//	return true;
//}