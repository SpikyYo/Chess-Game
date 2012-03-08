/*
	Square.h
*/

#ifndef SQUARE_H
#define SQUARE_H

#include<iostream>

class Square
{
public :
	//typedef int SquareColor;
	//typedef char File;
	//typedef int Rank;
	static const int SQUARE_DIMENSION = 50;
	enum SquareColor { DARK=0, LIGHT=1 };
	enum File { A_FILE=0, B_FILE, C_FILE, D_FILE, E_FILE, F_FILE, G_FILE, H_FILE };
	enum Rank { RANK_1, RANK_2, RANK_3, RANK_4, RANK_5, RANK_6, RANK_7, RANK_8 };

	Square(int color, int file, int rank);
	Square(int color, std::pair< int, int> position );
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

private :
	int m_SquareColor;
	std::pair< int, int > m_Position;
	int m_File;
	int m_Rank;
	bool m_IsOccupied;

};

#endif