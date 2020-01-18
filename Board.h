#ifndef BOARD_H
#define BOARD_H

class Board// class board created.
{
public:
	Board();
	void displayBoard();//board displays on screen
	bool putShip(int playerid,int shipid,int rowStart,int colStart,int rowEnd,int colEnd);//puts ship in given coordinates if correct
	bool makeAHit(int row,int column);//hits if there is a ship
	bool checkIfPlayerWon(int playerid);//checks if player won.
private:
	int theBoard[6][6];//6x6 matrix created.
};





#endif
