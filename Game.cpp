/*
	Programmer : Jean-Sébastien Chiasson
	Date : 04/03/12
	Project : Chess Game
*/

#include"Game.h"
#include"GameEngine.h"
#include"ChessBoard.h"
#include"Square.h"
#include"GameLogic.h"
#include"PiecesRules.h"

int main(int argc, char* args[] )
{
	GameEngine *mainEngine = new GameEngine();
	ChessBoard *chessBoard = new ChessBoard();
	GameLogic *gameLogic = new GameLogic();
	PiecesRules *piecesRules = new PiecesRules();

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
	PiecesRules::VectorMoves availableMove;
	bool refresh = false;

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

					refresh = gameLogic->ClickSquare( chessBoard, piecesRules, pos );

					if(refresh)
					{
						chessBoard->RefreshChessBoard(mainEngine);

						if( gameLogic->IsPieceSelected() )
						{
							//Find the available move for the piece selected and draw and hilite on it
							//...king and pawns have differents rules than other pieces...
							if( gameLogic->GetSelectedPiece()->GetType() == Piece::KING )
							{
								availableMove = piecesRules->SetKingPossibleMove( pos );
							}
							else if( gameLogic->GetSelectedPiece()->GetType() == Piece::PAWNS )
							{
								availableMove = piecesRules->SetPawnsPossibleMove(pos, gameLogic->GetSelectedPiece()->GetPieceColor() );
							}
							else
							{
								availableMove = piecesRules->FindPossibleMove( gameLogic->GetSelectedPiece()->GetType(), pos );
							}

							for( PiecesRules::VectorMoves::iterator it = availableMove.begin(); it != availableMove.end(); it++ )
							{
								pos = Square::GetPositionFromFileRank( (*it).first, (*it).second );
								mainEngine->DrawHilite( pos.first, pos.second ); //Must have coordonates instead of file/rank..
							}
						}
						else
						{
							if( !gameLogic->CancelMove() )
								mainEngine->DrawHilite( pos.first, pos.second );
						}

						chessBoard->RefreshPieces(mainEngine);
					}
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
	delete gameLogic;
	delete piecesRules;

	return 0;
}