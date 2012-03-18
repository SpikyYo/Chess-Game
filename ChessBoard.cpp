/*
	ChessBoard.cpp
*/

#include"ChessBoard.h"

ChessBoard::ChessBoard()
{
	m_WhitePieces.reserve(16);
	m_BlackPieces.reserve(16);
	m_Squares.reserve(64);
}

ChessBoard::~ChessBoard()
{
	for(std::vector< Piece* >::iterator it = m_WhitePieces.begin(); it != m_WhitePieces.end(); it++)
	{
		delete (*it);
		(*it) = NULL;
	}
	m_WhitePieces.clear();

	for(std::vector< Piece* >::iterator it = m_BlackPieces.begin(); it != m_BlackPieces.end(); it++)
	{
		delete (*it);
		(*it) = NULL;
	}
	m_BlackPieces.clear();

	std::vector< Square* > temp;

	for(std::vector< std::vector< Square* > >::iterator it = m_Squares.begin(); it != m_Squares.end(); it++)
	{
		temp = (*it);
		
		for(std::vector< Square* >::iterator itr = temp.begin(); itr != temp.end(); itr++)
		{
			delete (*itr);
			(*itr) = NULL;
		}
	}
	m_Squares.clear();
}

void ChessBoard::InitChessBoard()
{
	//Each square is going to be stored for access purpose later on

	int xPos = 0; 
	int yPos = 0; 
	bool isDarkSquare = false;
	std::vector< Square* > tempSquare;

	for(int i=0; i<Square::NUM_RANK; i++)  
	{
		tempSquare.clear();

		for(int j=0; j<Square::NUM_FILE; j++)  
		{
			if (isDarkSquare )
			{
				tempSquare.push_back( new Square(Square::SquareColor::DARK, Square::NUM_RANK-i-1, j) ); //reverse rank and file?... suppose to be j, Square::NUM_RANK-i-1
			}
			else
			{
				tempSquare.push_back( new Square(Square::SquareColor::LIGHT, Square::NUM_RANK-i-1, j) );
			}

			isDarkSquare = !isDarkSquare;
		}

		m_Squares.push_back(tempSquare);

		isDarkSquare = !isDarkSquare;
	}
}

void ChessBoard::InitPieces()
{
	//Each pieces is going to be stored for access purpose later on

	//White back row
	m_WhitePieces.push_back( new Piece( Piece::KING, false, GetSquare( Square::E_FILE, Square::RANK_1 ), Piece::WHITE ) );
	m_WhitePieces.push_back( new Piece( Piece::QUEEN, false, GetSquare( Square::D_FILE, Square::RANK_1 ), Piece::WHITE ) );
	m_WhitePieces.push_back( new Piece( Piece::BISHOP, false, GetSquare( Square::C_FILE, Square::RANK_1 ), Piece::WHITE ) );
	m_WhitePieces.push_back( new Piece( Piece::BISHOP, false, GetSquare( Square::F_FILE, Square::RANK_1 ), Piece::WHITE ) );
	m_WhitePieces.push_back( new Piece( Piece::KNIGHT, true, GetSquare( Square::B_FILE, Square::RANK_1 ), Piece::WHITE ) );
	m_WhitePieces.push_back( new Piece( Piece::KNIGHT, true, GetSquare( Square::G_FILE, Square::RANK_1 ), Piece::WHITE ) );
	m_WhitePieces.push_back( new Piece( Piece::ROOK, false, GetSquare( Square::A_FILE, Square::RANK_1 ), Piece::WHITE ) );
	m_WhitePieces.push_back( new Piece( Piece::ROOK, false, GetSquare( Square::H_FILE, Square::RANK_1 ), Piece::WHITE ) );

	//White pawns
	m_WhitePieces.push_back( new Piece( Piece::PAWNS, false, GetSquare( Square::A_FILE, Square::RANK_2 ), Piece::WHITE ) );
	m_WhitePieces.push_back( new Piece( Piece::PAWNS, false, GetSquare( Square::B_FILE, Square::RANK_2 ), Piece::WHITE ) );
	m_WhitePieces.push_back( new Piece( Piece::PAWNS, false, GetSquare( Square::C_FILE, Square::RANK_2 ), Piece::WHITE ) );
	m_WhitePieces.push_back( new Piece( Piece::PAWNS, false, GetSquare( Square::D_FILE, Square::RANK_2 ), Piece::WHITE ) );
	m_WhitePieces.push_back( new Piece( Piece::PAWNS, false, GetSquare( Square::E_FILE, Square::RANK_2 ), Piece::WHITE ) );
	m_WhitePieces.push_back( new Piece( Piece::PAWNS, false, GetSquare( Square::F_FILE, Square::RANK_2 ), Piece::WHITE ) );
	m_WhitePieces.push_back( new Piece( Piece::PAWNS, false, GetSquare( Square::G_FILE, Square::RANK_2 ), Piece::WHITE ) );
	m_WhitePieces.push_back( new Piece( Piece::PAWNS, false, GetSquare( Square::H_FILE, Square::RANK_2 ), Piece::WHITE ) );

	//Specified that each squares, with a piece on it, is occupied
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 8; j++)
		{
			GetSquare( j, i )->SetIsOccupied(true);
		}
	}

	//Black back row
	m_BlackPieces.push_back( new Piece( Piece::KING, false, GetSquare( Square::E_FILE, Square::RANK_8 ), Piece::BLACK ) );
	m_BlackPieces.push_back( new Piece( Piece::QUEEN, false, GetSquare( Square::D_FILE, Square::RANK_8 ), Piece::BLACK ) );
	m_BlackPieces.push_back( new Piece( Piece::BISHOP, false, GetSquare( Square::C_FILE, Square::RANK_8 ), Piece::BLACK ) );
	m_BlackPieces.push_back( new Piece( Piece::BISHOP, false, GetSquare( Square::F_FILE, Square::RANK_8 ), Piece::BLACK ) );
	m_BlackPieces.push_back( new Piece( Piece::KNIGHT, true, GetSquare( Square::B_FILE, Square::RANK_8 ), Piece::BLACK ) );
	m_BlackPieces.push_back( new Piece( Piece::KNIGHT, true, GetSquare( Square::G_FILE, Square::RANK_8 ), Piece::BLACK ) );
	m_BlackPieces.push_back( new Piece( Piece::ROOK, false, GetSquare( Square::A_FILE, Square::RANK_8 ), Piece::BLACK ) );
	m_BlackPieces.push_back( new Piece( Piece::ROOK, false, GetSquare( Square::H_FILE, Square::RANK_8 ), Piece::BLACK ) );

	//Black pawns
	m_BlackPieces.push_back( new Piece( Piece::PAWNS, false, GetSquare( Square::A_FILE, Square::RANK_7 ), Piece::BLACK ) );
	m_BlackPieces.push_back( new Piece( Piece::PAWNS, false, GetSquare( Square::B_FILE, Square::RANK_7 ), Piece::BLACK ) );
	m_BlackPieces.push_back( new Piece( Piece::PAWNS, false, GetSquare( Square::C_FILE, Square::RANK_7 ), Piece::BLACK ) );
	m_BlackPieces.push_back( new Piece( Piece::PAWNS, false, GetSquare( Square::D_FILE, Square::RANK_7 ), Piece::BLACK ) );
	m_BlackPieces.push_back( new Piece( Piece::PAWNS, false, GetSquare( Square::E_FILE, Square::RANK_7 ), Piece::BLACK ) );
	m_BlackPieces.push_back( new Piece( Piece::PAWNS, false, GetSquare( Square::F_FILE, Square::RANK_7 ), Piece::BLACK ) );
	m_BlackPieces.push_back( new Piece( Piece::PAWNS, false, GetSquare( Square::G_FILE, Square::RANK_7 ), Piece::BLACK ) );
	m_BlackPieces.push_back( new Piece( Piece::PAWNS, false, GetSquare( Square::H_FILE, Square::RANK_7 ), Piece::BLACK ) );

	//Specified that each squares, with a piece on it, is occupied
	for(int i = 6; i < 8; i++)
	{
		for(int j = 0; j < 8; j++)
		{
			GetSquare( j, i )->SetIsOccupied(true);
		}
	}
}

Square* ChessBoard::GetSquare( int file, int rank )
{
	return m_Squares[file][rank];
}

void ChessBoard::ClickSquare(int x, int y)
{
	
}

void ChessBoard::RefreshPieces(GameEngine* ge)
{
	//Draw each pieces on the board with the info stored
	for(int i = 0; i < 16; i++)
	{
		ge->DrawSpecificPiece( m_WhitePieces[i]->GetType(), 
			Square::GetXFromPosition( Square::GetPositionFromFileRank( m_WhitePieces[i]->GetSquare()->GetFile(), m_WhitePieces[i]->GetSquare()->GetRank() ) ), 
			Square::GetYFromPosition( Square::GetPositionFromFileRank( m_WhitePieces[i]->GetSquare()->GetFile(), m_WhitePieces[i]->GetSquare()->GetRank() ) ),
			m_WhitePieces[i]->GetPieceColor() );

		ge->DrawSpecificPiece( m_BlackPieces[i]->GetType(), 
			Square::GetXFromPosition( Square::GetPositionFromFileRank( m_BlackPieces[i]->GetSquare()->GetFile(), m_BlackPieces[i]->GetSquare()->GetRank() ) ), 
			Square::GetYFromPosition( Square::GetPositionFromFileRank( m_BlackPieces[i]->GetSquare()->GetFile(), m_BlackPieces[i]->GetSquare()->GetRank() ) ),
			m_BlackPieces[i]->GetPieceColor() );
	}
}

void ChessBoard::RefreshChessBoard(GameEngine* ge)
{
	ge->DrawChessBoard();
}

Piece* ChessBoard::GetPieceAtSpecificSquare( int file, int rank )
{
	//Since each piece is on a specific square, but a square don't know if there's a specific piece on it.. 
	//	.. we need to check each pieces if it is occupying the specific square (file & rank)
	// might need to be improve.

	Piece* temp = NULL;
	bool isFound = false;

	for(int i = 0; i < 16; i++)
	{
		temp = m_WhitePieces[i];
		if( temp != NULL )
		{
			if( temp->GetSquare()->GetFile() == file && temp->GetSquare()->GetRank() == rank )
			{
				isFound = true;
				break;
			}
		}

		temp = m_BlackPieces[i];
		if( temp != NULL )
		{
			if( temp->GetSquare()->GetFile() == file && temp->GetSquare()->GetRank() == rank )
			{
				isFound = true;
				break;
			}
		}
	}

	if( !isFound )
		temp = NULL;

	return temp;
}

void ChessBoard::RemovePieceFromSpecificSquare( int file, int rank )
{
}

void ChessBoard::PutPieceAtSpecificSquare( Piece* selectedPiece, int fileDest, int rankDest )
{
	selectedPiece->SetSquare( GetSquare( fileDest, rankDest ) );
}

