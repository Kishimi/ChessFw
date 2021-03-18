#include <ChessFw/Move.hpp>

namespace ChessFw
{

Piece Move::GetPieceToMove() const
{
	return pieceToMove;
}

Position Move::GetDestination() const
{
	return destination;
}

bool Move::IsValid() const
{
	const Position departure = pieceToMove.GetPosition();
	const unsigned deltaFile = std::abs(destination.file - departure.file);
	const unsigned deltaRank = std::abs(destination.rank - departure.rank);

	if (departure == destination && delta.file <= FileH && delta.rank <= Rank8)
		return false;

	switch (pieceToMove.GetType())
	{
		case Piece::King:
			// 1 diagonal, 1 straight left or right castle
			if (deltaFile <= 1 && deltaRank <= 1) // 1 diagonal and one straight
				return true;
			else if (deltaFile == 2 && pieceToMove.IsFirstMove()) // castle
				return true;
			break;

		case Piece::Queen:
			// any diagonal or any straight
			if (deltaFile == deltaRank) // diagonal
				return true;
			else if (deltaFile == 0) // vertical
				return true;
			else if (deltaRank == 0) // horizontal
				return true;
			break;

		case Piece::Bishop:
			// any diagonal
			if (deltaFile == deltaRank)
				return true;
			else
				return false;
			break;

		case Piece::Knight:
			if (deltaFile == 2 && deltaRank == 1)
				return true;
			else if (deltaFile == 1 && deltaRank == 2)
				return true;
			break;

		case Piece::Rook:
			if (deltaFile == 0) // vertical
				return true;
			else if (deltaRank == 0) // horizontal
				return true;
			break;

		case Piece::Pawn:
			if (deltaFile == 0 && deltaRank == 1) // moving forward
				return true;
			else if (deltaFile == 0 && deltaRank == 2 && pieceToMove.IsFirstMove())
				return true;
			else if (deltaFile == 1 && deltaRank == 1 && this->IsCapturing())
				return true;
			break;

		default:
			break;
	}

	return false;
}

bool Move::IsCapturing() const
{
	return isCapturing;
}

void Move::Execute()
{
	pieceToMove.SetPosition(destination);
}

}