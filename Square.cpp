/*
	Square.cpp
*/

#include"Square.h";

Square::Square(int color, int file, int rank) :
	m_SquareColor(color),
	m_File(file),
	m_Rank(rank)
{
	m_Position = GetPositionFromFileRank(file, rank);
}

Square::Square(int color, std::pair< int, int> position ) :
	m_SquareColor(color)
{
	m_Position.first = position.first;
	m_Position.second = position.second;

	m_File = GetFileFromPosition(m_Position);
	m_Rank = GetRankFromPosition(m_Position);
}

Square::Square(Square* square) :
	m_SquareColor(square->GetSquareColor()),
	m_File(square->GetFile()),
	m_Rank(square->GetRank())
{
	m_Position = square->GetPositionFromFileRank( square->GetFile(), square->GetRank() );
}

Square::~Square()
{
}

std::pair< int, int > Square::GetPositionFromFileRank( int file, int rank )
{
	int x = 0; 
	int y = 0;

	x = file * Square::SQUARE_DIMENSION;
	y = ((Square::NUM_RANK-1) - rank) * Square::SQUARE_DIMENSION;

	return std::make_pair(x, y);
}

int Square::GetFileFromPosition( std::pair< int, int > position )
{
	int file = 0;

	if( position.first == 0 )
		file = Square::A_FILE;
	else
		file = position.first / Square::SQUARE_DIMENSION;

	return file;
}

int Square::GetRankFromPosition( std::pair< int, int > position )
{
	int rank = 0;

	if( position.second == 0 )
		rank = Square::RANK_8;
	else
		rank = ((Square::NUM_RANK-1) - (position.second / Square::SQUARE_DIMENSION) );

	return rank;
}

