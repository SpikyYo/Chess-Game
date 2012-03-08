/*
	Piece.h
*/

#ifndef PIECE_H
#define PIECE_H

#include "Square.h"

class Piece
{
public :
	enum PieceType { KING=0, QUEEN, ROOK, KNIGHT, BISHOP, PAWNS };

	Piece(int type, bool canJump, Square* square);

	int GetType() {return m_PieceType; }
	void SetType(int type) { m_PieceType = type; }
	bool CanJump() {return m_CanJump; }
	void SetCanJump(bool value) { m_CanJump = value; }
	Square* GetSquare() {return m_Square; }
	void SetSquare(Square* square) { 
		m_Square->SetSquareColor( square->GetSquareColor() );
		m_Square->SetFile( square->GetFile() );
		m_Square->SetRank( square->GetRank() ); }

	~Piece();

private :
	int m_PieceType;
	bool m_CanJump; //For knight
	Square* m_Square;

};

#endif
