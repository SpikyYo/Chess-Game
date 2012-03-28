/*
	GameLogic.cpp
*/

#include"GameLogic.h";

GameLogic::GameLogic() : 
	m_IsPieceSelected(false),
	m_CancelMove(false),
	m_SelectedPiece(NULL),
	m_PlayerTurn(Piece::WHITE)  //White start
{
}

GameLogic::~GameLogic()
{
}

bool GameLogic::ClickSquare( ChessBoard *cb, PiecesRules *pr, std::pair< int, int > pos )
{
	m_CancelMove = false;
	bool refresh = false;

	if( m_IsPieceSelected )
	{
		//Cancel the current move?..
		if( cb->GetPieceAtSpecificSquare( Square::GetFileFromPosition(pos), Square::GetRankFromPosition(pos) ) != m_SelectedPiece )
		{
			//if( ( cb->GetPieceAtSpecificSquare( Square::GetFileFromPosition(pos), Square::GetRankFromPosition(pos) ) == NULL || 
			//	(cb->GetPieceAtSpecificSquare( Square::GetFileFromPosition(pos), Square::GetRankFromPosition(pos) ) )->GetPieceColor() != m_SelectedPiece->GetPieceColor() ) && 
			//	pr->IsMoveAvailable( Square::GetFileFromPosition(pos), Square::GetRankFromPosition(pos) ) )
			if( pr->IsMoveAvailable( Square::GetFileFromPosition(pos), Square::GetRankFromPosition(pos) ) )
			{
				if( cb->GetPieceAtSpecificSquare( Square::GetFileFromPosition(pos), Square::GetRankFromPosition(pos) ) == NULL )
				{
					cb->PutPieceAtSpecificSquare( m_SelectedPiece, Square::GetFileFromPosition(pos), Square::GetRankFromPosition(pos) );
				}
				else if( ( cb->GetPieceAtSpecificSquare( Square::GetFileFromPosition(pos), Square::GetRankFromPosition(pos) ) )->GetPieceColor() != m_SelectedPiece->GetPieceColor() )
				{
					cb->RemovePieceFromSpecificSquare( Square::GetFileFromPosition(pos), Square::GetRankFromPosition(pos) );
					cb->PutPieceAtSpecificSquare( m_SelectedPiece, Square::GetFileFromPosition(pos), Square::GetRankFromPosition(pos) );
				}

				//cb->PutPieceAtSpecificSquare( m_SelectedPiece, Square::GetFileFromPosition(pos), Square::GetRankFromPosition(pos) );
				m_IsPieceSelected = false;
			
				if( m_PlayerTurn == Piece::WHITE )
					m_PlayerTurn = Piece::BLACK;
				else
					m_PlayerTurn = Piece::WHITE;

				refresh = true;
			}
		}
		else
		{
			m_IsPieceSelected = false;
			m_SelectedPiece = NULL;
			refresh = true;
			m_CancelMove = true;
		}
	}
	else
	{
		m_SelectedPiece = cb->GetPieceAtSpecificSquare( Square::GetFileFromPosition(pos), Square::GetRankFromPosition(pos) );

		if( m_SelectedPiece != NULL )
		{
			if( m_SelectedPiece->GetPieceColor() == m_PlayerTurn )
			{
				m_IsPieceSelected = true;
				refresh = true;
			}
			else
			{
				m_SelectedPiece = NULL;
			}
		}
	}

	return refresh;
}