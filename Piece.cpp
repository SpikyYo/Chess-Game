/*
	Piece.cpp
*/

#include"Piece.h"

Piece::Piece(int type, bool canJump, Square* square) :
	m_PieceType(type), 
	m_CanJump(canJump)
{
	SetSquare(square);
}

Piece::~Piece()
{
}
