/*
	Piece.cpp
*/

#include"Piece.h"

Piece::Piece(int type, bool canJump, Square* square, int color) :
	m_PieceType(type), 
	m_CanJump(canJump),
	m_PieceColor(color)
{
	//m_Square = NULL;
	m_Square = square;
}

Piece::~Piece()
{
}
