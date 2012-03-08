/*
	Player.h
*/

#ifndef PLAYER_H
#define PLAYER_H

class Player
{
public :
	enum ColorPlayer { BLACK=0, WHITE };

	Player(int Color);
	~Player();

private :
	int m_ColorPlayer;

};

#endif
