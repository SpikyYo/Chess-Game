/*
	GameEngine.h
*/

#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <iostream>
#include <vector>
#include "SDL.h"

const int SCREEN_WIDTH = 400;
const int  SCREEN_HEIGHT = 400;
const int SCREEN_BPP = 32;

class GameEngine
{
public :
	GameEngine();
	~GameEngine();

	SDL_Surface* LoadImage( std::string filename );
	void ApplySurface( SDL_Surface* source, SDL_Surface* destination, int xDest, int yDest, int xSrc=0, int ySrc=0, int width=0, int height=0 );

	void DrawChessBoard();
	void DrawPieces();
	bool init();
	void InitPiecesPosition();
	bool LoadFiles();
	void CleanUp();

	SDL_Surface* ScaleSurface(SDL_Surface* surface, Uint16 width, Uint16 height);
	void DrawPixel(SDL_Surface* surface, int x, int y, int pixel);
	Uint32 ReadPixel(SDL_Surface* surface, int x, int y);
	
	SDL_Surface* GetScreen() {return m_screen; }
	SDL_Surface* GetDarkSquare() {return m_darkSquare; }
	SDL_Surface* GetLightSquare() {return m_lightSquare; }

private :
	SDL_Surface* m_screen;
	SDL_Surface* m_darkSquare;
	SDL_Surface* m_lightSquare;
	SDL_Surface* m_Pieces;
	std::vector< SDL_Rect > m_BlackPieces;
	std::vector< SDL_Rect > m_WhitePieces;

};

#endif