/*
	Square.cpp
*/

#include"Square.h";

Square::Square(int color, int file, int rank) :
	m_SquareColor(color),
	m_File(file),
	m_Rank(rank)
{
}

Square::Square(int color, std::pair< int, int> position ) :
	m_SquareColor(color)
{
	m_Position.first = position.first;
	m_Position.second = position.second;
}

Square::~Square()
{
}
