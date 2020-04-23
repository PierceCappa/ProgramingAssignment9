
class BoardNode
{
	protected:
	//if state = 0, space is empty, state = 1, space is empty and other player has shot a round there, state = 2 player has a ship piece there, state  = 3 player has a ship there that has been hit
	int state
	BoardNode* spaceBelow
	BoardNode* spaceRight
	public:
	BoardNode();
	~BoardNode();
	void setState(int state);
	int getState();
	BoardNode* getSpaceBelow();
	BoardNode* getSpaceRight();
	void setSpaceBelow(BoardNode* node);
	void setSpaceRight(BoardNode* node);
}