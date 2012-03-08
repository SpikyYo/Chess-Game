/*
	ChessBoard.cpp
*/

#include"ChessBoard.h"

ChessBoard::ChessBoard()
{
}

ChessBoard::~ChessBoard()
{
}

void ChessBoard::InitChessBoard()
{
	int xPos = 0; 
	int yPos = 0; 
	bool isDarkSquare = false;
	std::vector< Square* > tempSquare;

	for(int i=0; i<8; i++)  //8 should not be hardcoded...  NUM_RANKS
	{
		for(int j=0; j<8; j++)  //8 should not be hardcoded... NUM_FILES
		{
			if (isDarkSquare )
				tempSquare.push_back( new Square(Square::SquareColor::DARK, 8-j, i) );
			else
				tempSquare.push_back( new Square(Square::SquareColor::LIGHT, 8-j, i) );

			isDarkSquare = !isDarkSquare;

			xPos += 50;
		}

		m_Squares.push_back(tempSquare);

		isDarkSquare = !isDarkSquare;

		xPos = 0;
		yPos += 50;
	}
}

void ChessBoard::InitPieces()
{
	//int xPos[] = {0, 94, 190, 285, 380, 480};
	//SDL_Rect tempRect;

	//for( int i = 0; i < 6; i++)
	//{
	//	tempRect.x = xPos[i];
	//	tempRect.y = 0;
	//	tempRect.w = 50;
	//	tempRect.h = 50;

	//	m_BlackPieces.push_back(tempRect);

	//	tempRect.x = xPos[i];
	//	tempRect.y = 80;
	//	tempRect.w = 50;
	//	tempRect.h = 50;

	//	m_WhitePieces.push_back(tempRect);

	//	//if( i == 0 || i == 1 )
	//	//	xPos += 90;
	//	//else
	//	//	xPos += 100;
	//}
}

void ChessBoard::ClickSquare(int x, int y)
{
	Square* tempRect;

	for(int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 8; j++)
		{
			tempRect = m_Squares[i][j];
			
		}
	}
}
