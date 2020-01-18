#include "mnuhoglu_nuhoglu_murat_hw6_Board.h"
#include "mnuhoglu_nuhoglu_murat_hw6_Player.h"
#include <iostream>
using namespace std;

bool Player::guess(int r, int c)
{
	bool check = myboard.makeAHit(r,c);
	return check;
}
bool Player::wins()
{
	bool check = myboard.checkIfPlayerWon(playerid);
	return check;
}



