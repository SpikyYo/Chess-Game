/*
	PiecesRules.h
*/

#ifndef PIECES_RULES_H
#define PIECES_RULES_H

#include<vector>
#include"Piece.h"
#include"Square.h"

class PiecesRules
{
public :
	typedef std::vector< std::pair< int, int > > VectorMoves;
	PiecesRules();
	~PiecesRules();
	VectorMoves FindPossibleMove(int pieceType, std::pair< int, int > pos );
	VectorMoves SetKingPossibleMove( std::pair< int, int > pos );
	void SetQueenPossibleMove( std::pair< int, int > pos );
	void SetRookPossibleMove( std::pair< int, int > pos );
	void SetBishopPossibleMove( std::pair< int, int > pos );
	void SetKnightPossibleMove( std::pair< int, int > pos );
	VectorMoves SetPawnsPossibleMove( std::pair< int, int > pos, int colorPiece );

	bool IsMoveOutOfBound( int file, int rank );
	bool IsMoveAvailable( int file, int rank );
	//bool IsSquareOccupied( int file, int rank ) {}

	VectorMoves GetPossibleAvailableMove() {
		return m_PossibleMoveAvailable; }

private :
	/*
		A vector of File and Rank of the possible moves available
	*/
	VectorMoves m_PossibleMoveAvailable;

};

#endif