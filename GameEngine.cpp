/*
	GameEngine.cpp
*/

#include"GameEngine.h"

GameEngine::GameEngine()
{
}

GameEngine::~GameEngine()
{
}

bool GameEngine::init()
{
	if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
		return false;

	m_screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

	m_WhitePieces.reserve(8);
	m_BlackPieces.reserve(8);
	InitPiecesPosition();

	if( m_screen == NULL )
		return false;

	SDL_WM_SetCaption("Chess game!", NULL);

	return true;
}

void GameEngine::InitPiecesPosition()
{
	int xPos[] = {0, 94, 190, 285, 380, 480};
	SDL_Rect tempRect;

	for( int i = 0; i < 6; i++)
	{
		tempRect.x = xPos[i];
		tempRect.y = 0;
		tempRect.w = 50;
		tempRect.h = 50;

		m_BlackPieces.push_back(tempRect);

		tempRect.x = xPos[i];
		tempRect.y = 80;
		tempRect.w = 50;
		tempRect.h = 50;

		m_WhitePieces.push_back(tempRect);

		//if( i == 0 || i == 1 )
		//	xPos += 90;
		//else
		//	xPos += 100;
	}
}

SDL_Surface* GameEngine::LoadImage( std::string filename )
{
	SDL_Surface* loadedImage = NULL;
	SDL_Surface* optimizedImage = NULL;

	loadedImage = SDL_LoadBMP( filename.c_str() );

	if( loadedImage )
	{
		optimizedImage = SDL_DisplayFormat( loadedImage );
		SDL_FreeSurface( loadedImage );

		if( optimizedImage != NULL )
		{
			Uint32 colorKey = SDL_MapRGB(optimizedImage->format, 0xFF, 0xFF, 0xFF );
			SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, colorKey );
		}
	}

	return optimizedImage;
}

void GameEngine::ApplySurface( SDL_Surface* source, SDL_Surface* destination, int xDest, int yDest, int xSrc, int ySrc, int width, int height )
{
	SDL_Rect srcOffSet;
	SDL_Rect offSet;

	srcOffSet.x = xSrc;
	srcOffSet.y = ySrc;
	srcOffSet.w = width;
	srcOffSet.h = height;

	offSet.x = xDest;
	offSet.y = yDest;

	SDL_BlitSurface( source, &srcOffSet, destination, &offSet );
}

void GameEngine::DrawChessBoard()
{
	int xPos = 0; 
	int yPos = 0; 
	bool isDarkSquare = false;

	for(int i=0; i<8; i++)  //8 should not be hardcoded...  NUM_RANKS
	{
		for(int j=0; j<8; j++)  //8 should not be hardcoded... NUM_FILES
		{
			if (isDarkSquare )
				ApplySurface( GetDarkSquare(), GetScreen(), xPos, yPos, 0, 0, 50, 50 ); //50 should not be hardcoded... SQUARE_DIM
			else
				ApplySurface( GetLightSquare(), GetScreen(), xPos, yPos, 0, 0, 50, 50 );

			isDarkSquare = !isDarkSquare;

			xPos += 50;
		}

		isDarkSquare = !isDarkSquare;

		xPos = 0;
		yPos += 50;
	}

	SDL_Flip( GetScreen() );

}

void GameEngine::DrawPieces()
{
	int xPos = 0;
	int piecesOrder[] = {2, 4, 3, 1, 0, 3, 4, 2};

	//Back row
	for(int i = 0; i < 8; i++)
	{
		//White pieces
		ApplySurface(m_Pieces, GetScreen(), xPos, 350, m_WhitePieces[ piecesOrder[i] ].x, m_WhitePieces[ piecesOrder[i] ].y, m_WhitePieces[ piecesOrder[i] ].w, m_WhitePieces[ piecesOrder[i] ].h );

		//Black Pieces
		ApplySurface(m_Pieces, GetScreen(), xPos, 0, m_BlackPieces[ piecesOrder[i] ].x, m_BlackPieces[ piecesOrder[i] ].y, m_BlackPieces[ piecesOrder[i] ].w, m_BlackPieces[ piecesOrder[i] ].h );

		xPos += 50;
	}

	xPos = 0;

	//Pawns
	for(int i = 0; i < 8; i++)
	{
		//White pieces
		ApplySurface(m_Pieces, GetScreen(), xPos, 300, m_WhitePieces[5].x, m_WhitePieces[5].y, m_WhitePieces[5].w, m_WhitePieces[5].h );

		//Black Pieces
		ApplySurface(m_Pieces, GetScreen(), xPos, 50, m_BlackPieces[5].x, m_BlackPieces[5].y, m_BlackPieces[5].w, m_BlackPieces[5].h );

		xPos += 50;
	}

	SDL_Flip( GetScreen() );
}

/********************   SCALING METHOD USED FROM THE SDL WEB RESSOURCE ***********************************/
SDL_Surface* GameEngine::ScaleSurface(SDL_Surface* surface, Uint16 width, Uint16 height)
{
	if( !surface || !width || !height )
		return 0;

	SDL_Surface* rect = SDL_CreateRGBSurface( surface->flags, width, height, 
		surface->format->BitsPerPixel, surface->format->Rmask, 
		surface->format->Gmask, surface->format->Bmask, surface->format->Amask );

	double stretchFactorX = (static_cast<double>(width) / static_cast<double>(surface->w));
	double stretchFactorY = (static_cast<double>(height) / static_cast<double>(surface->h));

	for(int y = 0; y < surface->h; y++)
		for(int x = 0; x < surface->w; x++)
			for(int oY = 0; oY < stretchFactorY; oY++)
				for(int oX = 0; oX < stretchFactorX; oX++)
					DrawPixel(rect, static_cast<int>( stretchFactorX*x ) + oX,
						static_cast<int>( stretchFactorY*y ) + oY, 
						ReadPixel( surface, x, y ) );
}

void GameEngine::DrawPixel(SDL_Surface* surface, int x, int y, int pixel)
{
	int bpp = surface->format->BytesPerPixel;

	Uint8* p = (Uint8*)surface->pixels + y * surface->pitch + x * bpp;

	switch(bpp)
	{
	case 1:
		*p = pixel;
		break;

	case 2:
		*(Uint16*)p = pixel;
		break;

	case 3:
		if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
		{
			p[0] = (pixel >> 16) & 0xff;
			p[1] = (pixel >> 8) & 0xff;
			p[2] = pixel & 0xff;
		}
		else
		{
			p[0] = pixel & 0xff;
			p[1] = (pixel >> 8) & 0xff;
			p[2] = (pixel >> 16) & 0xff;
		}
		break;

	case 4:
		*(Uint32*)p = pixel;
		break;
	}

}

Uint32 GameEngine::ReadPixel(SDL_Surface* surface, int x, int y)
{
	int bpp = surface->format->BytesPerPixel;

	Uint8* p = (Uint8*)surface->pixels + y * surface->pitch + x * bpp;

	switch(bpp)
	{
	case 1:
		return *p;
		break;

	case 2:
		return *(Uint16*)p;
		break;

	case 3:
		if( SDL_BYTEORDER == SDL_BIG_ENDIAN )
			return p[0] << 16 | p[1] << 8 | p[2];
		else
			return p[0] | p[1] << 8 | p[2] << 16;
		break;

	case 4:
		return *(Uint32*)p;
		break;

	default:
		return 0;
	}
}
/*********************************************************************************************/

bool GameEngine::LoadFiles()
{
	m_darkSquare = LoadImage( "images/Dark_Square.bmp" );
	m_lightSquare = LoadImage( "images/Light_Square.bmp" );
	m_Pieces = LoadImage( "images/Chess_symbols_set3.bmp" );

	if( m_darkSquare == NULL || m_lightSquare == NULL || m_Pieces == NULL )
		return false;

	return true;
}

void GameEngine::CleanUp()
{
	SDL_FreeSurface( m_darkSquare ); //Because the image has been loaded..
	SDL_FreeSurface( m_lightSquare );
	SDL_FreeSurface( m_Pieces );

	SDL_Quit();
}
