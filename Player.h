#ifndef PLAYER_H
#define PLAYER_H
#include "mnuhoglu_nuhoglu_murat_hw6_Board.h"
class Player//class player created.
{
public:
	Player();
	Player::Player(Board&myboard,int id)//shares the board object.
		:myboard(myboard),playerid(id)
	{}
	bool guess(int r, int c);//takes the guesses of player.
	bool wins();

private:
	Board &myboard;//objectshared.
	int playerid;//private data 
};

#endif 
