#include "mnuhoglu_nuhoglu_murat_hw6_Board.h"
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

Board::Board()
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			theBoard[i][j] = 0;
		}
	}
}

void Board::displayBoard()
{
	cout << setw(9) << "P1" << setw(7) << "|" << setw(9) << "P2" << endl << setw(4);
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cout << theBoard[i][j] << setw(4);
			if (j==2)
			{
				cout << "|" << setw(4);
			}
		}
		cout << endl << setw(4);
	}
}




/************************************************************/

bool Board::putShip(int playerid,int shipid,int rowStart,int colStart,int rowEnd,int colEnd)
{
	if(playerid == 1)
	{
		if(shipid == 1)
		{
			if( theBoard[rowEnd][colEnd] == 1 || theBoard[rowStart][colStart] == 1)
				return false;
			if((abs(colStart-colEnd) == 1))
			{
				if(abs(rowStart-rowEnd) != 0 )
					return false;
			}
			if((abs(colStart-colEnd) == 0))
			{
				if(abs(rowStart-rowEnd) != 1 )
					return false;
			}
			if(colStart > 2 || colEnd > 2)
				return false;

		}
		else if(shipid == 2)
		{
			if( theBoard[rowEnd][colEnd] == 1 || theBoard[rowStart][colStart] == 1)
				return false;
			if((abs(colStart-colEnd) == 2))
			{
				if(abs(rowStart-rowEnd) != 0 )
					return false;
				theBoard[(rowStart+rowEnd)/2][(colStart+colEnd)/2] = 1;
			}
			if((abs(colStart-colEnd) == 0))
			{
				if(abs(rowStart-rowEnd) != 2 )
					return false;
				else if(abs(rowStart-rowEnd) == 2 )
				theBoard[(rowStart+rowEnd)/2][(colStart+colEnd)/2] = 1;
			}			
			if(colStart > 2 || colEnd > 2)
				return false;
		}
		theBoard[rowStart][colStart] = 1;
		theBoard[rowEnd][colEnd] = 1;
		return true;
	}
	else if(playerid == 2)
	{
		if(shipid == 1)
		{
			if( theBoard[rowEnd][colEnd] == 1 || theBoard[rowStart][colStart] == 1)
				return false;
			if((abs(colStart-colEnd) == 1))
			{
				if(abs(rowStart-rowEnd) != 0 )
					return false;
			}
			if((abs(colStart-colEnd) == 0))
			{
				if(abs(rowStart-rowEnd) != 1 )
					return false;
			}
			if(colStart < 3 || colEnd < 3)
				return false;

		}
		else if(shipid == 2)
		{
			if( theBoard[rowEnd][colEnd] == 1 || theBoard[rowStart][colStart] == 1)
				return false;		
			if((abs(colStart-colEnd) == 2))
			{
				if(abs(rowStart-rowEnd) != 0 )
					return false;
				theBoard[(rowStart+rowEnd)/2][(colStart+colEnd)/2] = 1;
			}
			if((abs(colStart-colEnd) == 0))
			{
				if(abs(rowStart-rowEnd) != 2 )
					return false;
				else if(abs(rowStart-rowEnd) == 2 )
				theBoard[(rowStart+rowEnd)/2][(colStart+colEnd)/2] = 1;
			}
			if(colStart < 3 || colEnd < 3)
				return false;
		}
		theBoard[rowStart][colStart] = 1;
		theBoard[rowEnd][colEnd] = 1;
		return true;
	}
	}





/////////////////////////////////////////////////////////////
bool Board::makeAHit(int row,int column)
{
	bool check = false;
	if (theBoard[row][column] == 1)
	{
		check = true;
		theBoard[row][column] = -1;
	}
	return check;
}
bool Board::checkIfPlayerWon(int playerid)
{
	bool check = true;
	if (playerid == 1)
	{
		for (int i = 3; i < 6; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (theBoard[j][i] == 1)
				{
					check = false;
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (theBoard[j][i] == 1)
				{
					check = false;
				}
			}
		}
	}
	return check;
}







