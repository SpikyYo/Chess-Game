/*
	Programmer : Jean-Sébastien Chiasson
	Date : 04/03/12
	Project : Chess Game
*/

#include"Game.h"
#include"GameEngine.h"
#include"ChessBoard.h"

int main(int argc, char* args[] )
{
	GameEngine *mainEngine = new GameEngine();
	ChessBoard *chessBoard = new ChessBoard();

	bool quit = false;

	if( !mainEngine->init() || !mainEngine->LoadFiles() )
		return 1;

	mainEngine->DrawChessBoard();
	mainEngine->DrawPieces();

	chessBoard->InitChessBoard();

	//if( SDL_Flip( mainEngine->GetScreen() ) == -1 )
	//	return 1;

	//SDL_Delay( 10000 ); //For testing purpose only...

	SDL_Event myEvent;
	int x = 0; 
	int y = 0;

	while( quit == false )
	{
		while( SDL_PollEvent( &myEvent ) )
		{
			if( myEvent.type == SDL_MOUSEBUTTONDOWN )
			{
				if( myEvent.button.button == SDL_BUTTON_LEFT )
				{
					x = myEvent.button.x;
					y = myEvent.button.y;


				}
			}

			if( myEvent.type == SDL_QUIT ) 
			{
				quit = true;
			}
		}
	}

	mainEngine->CleanUp();

	return 0;
}