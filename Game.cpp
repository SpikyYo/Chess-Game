/*
	Programmer : Jean-Sébastien Chiasson
	Date : 04/03/12
	Project : Chess Game
*/

#include"Game.h"
#include"GameEngine.h"
#include"ChessBoard.h"
#include"Square.h"

int main(int argc, char* args[] )
{
	GameEngine *mainEngine = new GameEngine();
	ChessBoard *chessBoard = new ChessBoard();

	bool quit = false;

	if( !mainEngine->init() || !mainEngine->LoadFiles() )
		return 1;

	mainEngine->DrawChessBoard();

	chessBoard->InitChessBoard();
	chessBoard->InitPieces();
	chessBoard->RefreshChessBoard(mainEngine);
	chessBoard->RefreshPieces(mainEngine);

	//if( SDL_Flip( mainEngine->GetScreen() ) == -1 )
	//	return 1;

	//SDL_Delay( 10000 ); //For testing purpose only...

	SDL_Event myEvent;
	std::pair< int, int > pos;
	Piece* selectedPiece;
	bool isPieceSelected = false;

	while( quit == false )
	{
		while( SDL_PollEvent( &myEvent ) )
		{
			if( myEvent.type == SDL_MOUSEBUTTONDOWN )
			{
				if( myEvent.button.button == SDL_BUTTON_LEFT )
				{
					//Getting the position
					pos = std::make_pair( myEvent.button.x, myEvent.button.y );
					pos = Square::GetPositionFromFileRank( Square::GetFileFromPosition(pos), Square::GetRankFromPosition(pos) );

					if( isPieceSelected )
					{
						if( chessBoard->GetPieceAtSpecificSquare( Square::GetFileFromPosition(pos), Square::GetRankFromPosition(pos) ) == NULL )
						{
							chessBoard->PutPieceAtSpecificSquare( selectedPiece, Square::GetFileFromPosition(pos), Square::GetRankFromPosition(pos) );
							isPieceSelected = false;
						}
					}
					else
					{
						selectedPiece = chessBoard->GetPieceAtSpecificSquare( Square::GetFileFromPosition(pos), Square::GetRankFromPosition(pos) );

						if( selectedPiece != NULL )
						{
							isPieceSelected = true;
						}
					}

					chessBoard->RefreshChessBoard(mainEngine);
					mainEngine->DrawHilite(pos.first, pos.second);
					chessBoard->RefreshPieces(mainEngine);
				}
			}

			if( myEvent.type == SDL_QUIT ) 
			{
				quit = true;
			}
		}
	}

	mainEngine->CleanUp();

	delete mainEngine;
	delete chessBoard;

	return 0;
}