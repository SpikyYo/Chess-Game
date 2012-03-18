/*
	Square.h
*/

#ifndef SQUARE_H
#define SQUARE_H

#include<iostream>

class Square
{
public :

	/************ Chess board **************/
	//    __ __ __ __ __ __ __ __
	// 8 |  |  |  |  |  |  |  |  |
	//    __ __ __ __ __ __ __ __
	// 7 |  |  |  |  |  |  |  |  |
	//    __ __ __ __ __ __ __ __
	// 6 |  |  |  |  |  |  |  |  |
	//    __ __ __ __ __ __ __ __
	// 5 |  |  |  |  |  |  |  |  |
	//    __ __ __ __ __ __ __ __
	// 4 |  |  |  |  |  |  |  |  |
	//    __ __ __ __ __ __ __ __
	// 3 |  |  |  |  |  |  |  |  |
	//    __ __ __ __ __ __ __ __
	// 2 |  |  |  |  |  |  |  |  |
	//    __ __ __ __ __ __ __ __
	// 1 |  |  |  |  |  |  |  |  |
	//    __ __ __ __ __ __ __ __
	//    A  B  C  D  E  F  G  H 
	//
	/***************************************/

	static const int SQUARE_DIMENSION = 50;
	static const int NUM_FILE = 8;
	static const int NUM_RANK = 8;

	enum SquareColor { DARK=0, LIGHT=1 };
	enum File { A_FILE=0, B_FILE, C_FILE, D_FILE, E_FILE, F_FILE, G_FILE, H_FILE };  //Collums
	enum Rank { RANK_1=0, RANK_2, RANK_3, RANK_4, RANK_5, RANK_6, RANK_7, RANK_8 };  //Rows

	Square(int color, int file, int rank);
	Square(int color, std::pair< int, int> position );
	Square(Square* square);
	~Square();

	int GetSquareColor() {return m_SquareColor; }
	void SetSquareColor(int squareColor) { m_SquareColor = squareColor; }
	int GetFile() {return m_File; }
	void SetFile(int file) { m_File = file; }
	int GetRank() {return m_Rank; }
	void SetRank(int rank) { m_Rank = rank; }
	bool IsOccupied() {return m_IsOccupied; }
	void SetIsOccupied(bool value) { m_IsOccupied = value; }
	std::pair< int, int > GetPosition() {return m_Position; }
	void SetPosition(int x, int y) { 
		m_Position.first = x;
		m_Position.second = y; }

	static std::pair< int, int > GetPositionFromFileRank( int file, int rank );
	static int GetFileFromPosition( std::pair< int, int > position );
	static int GetRankFromPosition( std::pair< int, int > position );
	static int GetXFromPosition( std::pair< int, int > position ) {
		return position.first; };
	static int GetYFromPosition( std::pair< int, int > position ) {
		return position.second; };

private :
	int m_SquareColor;
	int m_File;
	int m_Rank;
	bool m_IsOccupied;

	/*
		m_Postion.first = xpos (File (A, B, C,...))
		m_Position.second = ypos (RANK (1, 2, 3,...))
	*/
	std::pair< int, int > m_Position;

};

#endif