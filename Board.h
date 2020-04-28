
#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <string>
using namespace std;
//for all inputs, the x coordinate needs to be between a-f and the y needs to be 0-9

class Board
{
protected:
	// this array contains the board
	//if state = 0, space is empty, state = 1, space is empty and other player has shot a round there, state = 2 player has a ship piece there, state  = 3 player has a ship there that has been hit
	int board[10][10];
	//these arrays are arrays containing the spaces where the ship would normally be.
	int* carrier[5];//this is boat 1
	int* battleShip[4]; //this is boat 2
	int* cruiser[3];//this is boat 3
	int* submarine[3];//this is boat 4
	int* destroyer[2];//this is boat 5
	

public:
	//This function creates the board and places ships. it first creates the topRightCornor node, and then calls the boardCreator loop, plassing the topRIghtCOrnor node in and num 0;
	// after the board is created the function calls placeShips which places the shipwithin the board.
	Board();
	// this function goes through each row, starting with the bottom row and deletes each node in order working back towards the topright cornor
	~Board();
	//this function creates the board by passing the begening of the row to rowCreatorLoop, and then calling this function by passing the head of the next row down and row++;
	//the recursive function stops once row = 10
	void boardCreatorLoop();

	


	//this function finds a space specified by the x and y, y is passed into the find row function, then the fucntion finds that specific node and returns it
	int* findSpace(char x, int y);
	//this function finds a row of the board given the y and returns that node

	//this function goes through each of the arrays of boats and makes sure all of them are not at 3, if all are 3 than the function returns true, else if at least one boats space is 2 returns false
	bool checkIfLost();
	// goes to that spot x and y and checks to see it a hit was made then calls set state for that boardNode. if a hit was made the space is changed to 3, if a miss the spot is changed to 1
	// if a boat was hit than the number of that boat is returned
	int checkHit(char x, int y);
	//this function displays the board to the terminal
	void displayBoardTerminal();
	//this function goes through each of the ship pointer arrays, asking for user input to decide where to put them.
	//this function calls displayBoardTerminal and check 5 times for each ship. passes name of ship, and size of ship as well as ship number to check
	void placeShips();
	//this function asks for the starting place of a place you whould like to put the ship, than calls checkIfSpaceForShip
	//this function then gives the user the options for the direction of the ship, and then places the ship based on user input
	void check(int size, string shipName, int ship);
	//this function checks to see if it is possible for a ship to be placed in that location, and in what direction it could be placed
	//if a ship can be placed true is returned, else false if returned. 
	bool checkIfSpaceForShip(int size, bool& up, bool& right, bool& down, bool& left, char x, int y);
	//this function makes the pointer array point to the nodes it was assigned on the board
	void placeShip(char x, int y, int changeX, int changeY, int size, int ship);
	//this function checks if a node has a ship on it, if a ship is present it returns the number of the ship, else  is the space does not have a ship 0 is returned
	int checkIfSpaceHasShip(char x, int y);
	//this function is called by check if space Has ship and is a recursive funciton
	int cISHSLoop(char x, int y, int** arr, int size);

};

int convertCharCoordinate(char character);

#endif
