/*
	ChessBoard.h
*/

#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include"Square.h"
#include"Piece.h"
#include"GameEngine.h"
#include<SDL.h>
#include <vector>

class ChessBoard
{
public :

	ChessBoard();
	~ChessBoard();

	void InitChessBoard();
	void InitPieces();
	Square* GetSquare( int file, int rank );
	void ClickSquare( int x, int y );

	void RefreshPieces(GameEngine* ge);
	void RefreshChessBoard(GameEngine* ge);

	Piece* GetPieceAtSpecificSquare( int file, int rank );
	void RemovePieceFromSpecificSquare( int file, int rank );
	void PutPieceAtSpecificSquare( Piece* selectedPiece, int fileDest, int rankDest );

private :
	std::vector< std::vector< Square* > > m_Squares;  //All the squares which compose the chessBoard in a 2-dimensionnal vector
	std::vector< Piece* > m_WhitePieces;
	std::vector< Piece* > m_BlackPieces;

};

#endif
