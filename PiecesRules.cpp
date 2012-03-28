/*
	PiecesRules.cpp
*/

#include"PiecesRules.h";

PiecesRules::PiecesRules()
{
}

PiecesRules::~PiecesRules()
{
}

PiecesRules::VectorMoves PiecesRules::FindPossibleMove(int pieceType, std::pair< int, int > pos )
{
	m_PossibleMoveAvailable.clear();

	switch(pieceType)
	{
	//case Piece::KING :
	//	SetKingPossibleMove(pos);
	//	break;
	case Piece::QUEEN :
		SetQueenPossibleMove(pos);
		break;
	case Piece::ROOK :
		SetRookPossibleMove(pos);
		break;
	case Piece::BISHOP :
		SetBishopPossibleMove(pos);
		break;
	case Piece::KNIGHT :
		SetKnightPossibleMove(pos);
		break;
	//case Piece::PAWNS :
	//	SetPawnsPossibleMove(pos);
	//	break;
	default :
		//Error...
		break;
	}

	return m_PossibleMoveAvailable;
}

PiecesRules::VectorMoves PiecesRules::SetKingPossibleMove( std::pair< int, int > pos )
{
	m_PossibleMoveAvailable.clear();
	
	std::pair< int, int > tempMove;

	int file = 0;
	int rank = 0; 

	file = Square::GetFileFromPosition( pos );
	rank = Square::GetRankFromPosition( pos );

	for( int i = -1; i < 2; i++ )
	{		
		for( int j = -1; j < 2; j++ )
		{
			if( !IsMoveOutOfBound( file+i, rank+j) && (i != 0 || j != 0) )
			{
				tempMove.first = file+i;
				tempMove.second = rank+j;
				m_PossibleMoveAvailable.push_back( tempMove );
			}
		}
	}

	return m_PossibleMoveAvailable;
}

void PiecesRules::SetQueenPossibleMove( std::pair< int, int > pos )
{
	std::pair< int, int > tempMove;

	int file = 0;
	int rank = 0; 

	file = Square::GetFileFromPosition( pos );
	rank = Square::GetRankFromPosition( pos );

	for( int i = -8; i < 8; i++ )
	{		
		if( !IsMoveOutOfBound( file+i, rank) && /*(*/ i != 0 /*|| rank != 0)*/ )
		{
			tempMove.first = file+i;
			tempMove.second = rank;
			m_PossibleMoveAvailable.push_back( tempMove );
		}

		if( !IsMoveOutOfBound( file, rank+i) && /*(*/ i != 0 /*|| rank != 0)*/ )
		{
			tempMove.first = file;
			tempMove.second = rank+i;
			m_PossibleMoveAvailable.push_back( tempMove );
		}

		if( !IsMoveOutOfBound( file+i, rank+i) && i != 0 )
		{
			tempMove.first = file+i;
			tempMove.second = rank+i;
			m_PossibleMoveAvailable.push_back( tempMove );
		}

		if( !IsMoveOutOfBound( file-i, rank+i) && i != 0 )
		{
			tempMove.first = file-i;
			tempMove.second = rank+i;
			m_PossibleMoveAvailable.push_back( tempMove );
		}

		if( !IsMoveOutOfBound( file+i, rank-i) && i != 0 )
		{
			tempMove.first = file+i;
			tempMove.second = rank-i;
			m_PossibleMoveAvailable.push_back( tempMove );
		}

		if( !IsMoveOutOfBound( file-i, rank-i) && i != 0 )
		{
			tempMove.first = file-i;
			tempMove.second = rank-i;
			m_PossibleMoveAvailable.push_back( tempMove );
		}
	}
}

void PiecesRules::SetRookPossibleMove( std::pair< int, int > pos )
{
	std::pair< int, int > tempMove;

	int file = 0;
	int rank = 0; 

	file = Square::GetFileFromPosition( pos );
	rank = Square::GetRankFromPosition( pos );

	for( int i = -8; i < 8; i++ )
	{		
		if( !IsMoveOutOfBound( file+i, rank) && i != 0 )
		{
			tempMove.first = file+i;
			tempMove.second = rank;
			m_PossibleMoveAvailable.push_back( tempMove );
		}

		if( !IsMoveOutOfBound( file, rank+i) && i != 0 )
		{
			tempMove.first = file;
			tempMove.second = rank+i;
			m_PossibleMoveAvailable.push_back( tempMove );
		}

	}
}

void PiecesRules::SetBishopPossibleMove( std::pair< int, int > pos )
{
	std::pair< int, int > tempMove;

	int file = 0;
	int rank = 0; 

	file = Square::GetFileFromPosition( pos );
	rank = Square::GetRankFromPosition( pos );

	for( int i = -8; i < 8; i++ )
	{		
		if( !IsMoveOutOfBound( file+i, rank+i) && i != 0 )
		{
			tempMove.first = file+i;
			tempMove.second = rank+i;
			m_PossibleMoveAvailable.push_back( tempMove );
		}

		if( !IsMoveOutOfBound( file-i, rank+i) && i != 0 )
		{
			tempMove.first = file-i;
			tempMove.second = rank+i;
			m_PossibleMoveAvailable.push_back( tempMove );
		}

		if( !IsMoveOutOfBound( file+i, rank-i) && i != 0 )
		{
			tempMove.first = file+i;
			tempMove.second = rank-i;
			m_PossibleMoveAvailable.push_back( tempMove );
		}

		if( !IsMoveOutOfBound( file-i, rank-i) && i != 0 )
		{
			tempMove.first = file-i;
			tempMove.second = rank-i;
			m_PossibleMoveAvailable.push_back( tempMove );
		}
	}
}

void PiecesRules::SetKnightPossibleMove( std::pair< int, int > pos )
{
	std::pair< int, int > tempMove;

	int file = 0;
	int rank = 0; 
	int temp = 0;

	file = Square::GetFileFromPosition( pos );
	rank = Square::GetRankFromPosition( pos );

	for( int i = -2; i < 3; i++ )
	{
		if( i%2 == 0 )
		{
			temp = 1;
		}
		else
		{
			temp = 2;
		}

		if( !IsMoveOutOfBound( file+i, rank+temp) && i != 0 )
		{
			tempMove.first = file+i;
			tempMove.second = rank+temp;
			m_PossibleMoveAvailable.push_back( tempMove );
		}

		if( !IsMoveOutOfBound( file+i, rank-temp) && i != 0 )
		{
			tempMove.first = file+i;
			tempMove.second = rank-temp;
			m_PossibleMoveAvailable.push_back( tempMove );
		}
	}
}

PiecesRules::VectorMoves PiecesRules::SetPawnsPossibleMove( std::pair< int, int > pos, int colorPiece )
{
	m_PossibleMoveAvailable.clear();

	std::pair< int, int > tempMove;

	int file = 0;
	int rank = 0; 
	int temp = 0;
	int temp2 = 0;

	file = Square::GetFileFromPosition( pos );
	rank = Square::GetRankFromPosition( pos );

	//This logic needs to be improved...
	//for( int i = -8; i < 8; i++ )
	{
		if( colorPiece == Piece::PieceColor::WHITE )
		{
			if( rank == Square::RANK_2 )
			{
				temp2 = 2;
				temp = 1;
			}
			else
			{
				temp = 1; 
			}
		}
		else
		{
			if( rank == Square::RANK_7 )
			{
				temp2 = -2;
				temp = -1;
			}
			else
			{
				temp = -1;
			}
		}

		if( !IsMoveOutOfBound( file, rank+temp) )
		{
			tempMove.first = file;
			tempMove.second = rank+temp;
			m_PossibleMoveAvailable.push_back( tempMove );
		}

		if( !IsMoveOutOfBound( file, rank+temp2 ) && ( ( colorPiece == Piece::PieceColor::WHITE && rank == Square::RANK_2 ) || 
			(colorPiece == Piece::PieceColor::BLACK && rank == Square::RANK_7 ) ) )
		{
			tempMove.first = file;
			tempMove.second = rank+temp2;
			m_PossibleMoveAvailable.push_back( tempMove );
		}

	}

	return m_PossibleMoveAvailable;
}

bool PiecesRules::IsMoveOutOfBound( int file, int rank )
{
	if( file < 0 || file >= Square::NUM_FILE || rank < 0 || rank >= Square::NUM_RANK )
		return true;
	return false;
}

bool PiecesRules::IsMoveAvailable( int file, int rank )
{
	bool isAvailable = false;

	for( VectorMoves::iterator it = m_PossibleMoveAvailable.begin(); it != m_PossibleMoveAvailable.end(); it++ )
	{
		if( (*it).first == file && (*it).second == rank )
		{
			isAvailable = true;
			break;
		}
	}

	return isAvailable;
}
