/*
	GameLogic.h
*/

#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include"Piece.h"
#include"Square.h"
#include"ChessBoard.h"
#include"PiecesRules.h"

class GameLogic
{
public :
	GameLogic();
	~GameLogic();
	bool ClickSquare( ChessBoard *cb, PiecesRules *pr, std::pair< int, int > pos );

	Piece* GetSelectedPiece() {
		return m_SelectedPiece; }
	bool IsPieceSelected() {
		return m_IsPieceSelected; }
	bool CancelMove() {
		return m_CancelMove; }

private :
	Piece* m_SelectedPiece;
	bool m_IsPieceSelected;
	bool m_CancelMove;
	int m_PlayerTurn;
};

#endif