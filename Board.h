
class Board
{
	protected:
	BoardNode* topRightCornor;
	//true means part of ship has not been sunk, false means it has been sunk
	bool ship1[2];
	bool ship2[3];
	public:
	//this function creates the board, and makes sure each ship is placed by user, and it connected. it also calls. then creates a 10 by 10 board of boardNodes
	BoardNode();
	~BoardNode();
	//this function goes through each of the arrays of boats and makes sure all of them are not false, if they are all false it returns true
	bool checkIfLost();
	// goes to that spot x and y and checks to see it a hit was made then calls set state for that boardNode.
	//if a hit was made it passes in 4, else it passes in 2
	bool checkHit(char x, int y);
	
}