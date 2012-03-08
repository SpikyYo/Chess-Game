/*
	ChessBoard.h
*/

#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include"Square.h"
#include"Piece.h"
#include<SDL.h>
#include <vector>

class ChessBoard
{
public :

	ChessBoard();
	~ChessBoard();

	void InitChessBoard();
	void InitPieces();
	void ClickSquare( int x, int y );

private :
	std::vector< std::vector< Square* > > m_Squares;

};

#endif
