/*
	Piece.h
*/

#ifndef PIECE_H
#define PIECE_H

#include "Square.h"

class Piece
{
public :
	enum PieceColor { BLACK=0, WHITE };
	enum PieceType { KING=0, QUEEN, ROOK, BISHOP, KNIGHT, PAWNS };

	Piece(int type, bool canJump, Square* square, int color);

	int GetType() {return m_PieceType; }
	void SetType(int type) { m_PieceType = type; }
	bool CanJump() {return m_CanJump; }
	void SetCanJump(bool value) { m_CanJump = value; }
	int GetPieceColor() {return m_PieceColor; }
	void SetPieceColor(int type) { m_PieceColor = type; }
	Square* GetSquare() {return m_Square; }
	void SetSquare(Square* square) { m_Square = square; }
		/*m_Square->SetSquareColor( square->GetSquareColor() );
		m_Square->SetFile( square->GetFile() );
		m_Square->SetRank( square->GetRank() ); }*/

	~Piece();

private :
	int m_PieceType;
	bool m_CanJump; //For knight
	int m_PieceColor;
	Square* m_Square;

};

#endif
