#include <ChessFw/Board.hpp>

namespace ChessFw
{

Board::Board(const std::vector<Piece> &pieces)
	: pieces(pieces)
	, colorToMove(Piece::White)
{
}

bool Board::HalfMove(const Move &move)
{
	const std::vector<Position> possibleMoves = this->GetPossibleMoves(move.GetOrigin());

	if (std::find(possibleMoves.begin(), possibleMoves.end(), move.GetDestination()) == possibleMoves.end())
		return false;

	std::cout << "\tIs possible\n";

	Piece &origin = this->GetPiece(move.GetOrigin());
	Piece &destination = this->GetPiece(move.GetDestination());

	if (origin.GetColor() != colorToMove)
		return false;

	destination = origin;
	origin = Piece();

	colorToMove = colorToMove == Piece::White ? Piece::Black : Piece::White;

	return true;
}

bool Board::FullMove(const Move &whiteMove, const Move &blackMove)
{
	return this->HalfMove(whiteMove) && this->HalfMove(blackMove);
}

std::vector<Piece> Board::GetPieces() const
{
	return pieces;
}

bool Board::CheckMate() const
{
	return false;
}

Piece::Color Board::ColorToMove() const
{
	return Piece::White;
}

bool Board::IsValidMove(const Move &move) const
{
	const std::vector<Position> possibleMoves = this->GetPossibleMoves(move.GetOrigin());
	return std::find(possibleMoves.begin(), possibleMoves.end(), move.GetDestination()) != possibleMoves.end();
}

std::vector<Position> Board::GetPossibleMoves(const Position &position) const
{
	std::vector<Position> moves;
	const Piece &piece = this->GetPiece(position);
	
	switch (piece.GetType())
	{
		case Piece::King:
		{
			const std::vector<Position> straightMoves = this->GetStraightMoves(position, 1);
			const std::vector<Position> diagonalMoves = this->GetDiagonalMoves(position, 1);

			// append the moves
			moves.insert(moves.end(), straightMoves.begin(), straightMoves.end());
			moves.insert(moves.end(), diagonalMoves.begin(), diagonalMoves.end());
		} break;
	}

	return moves;
}

std::vector<Position> Board::GetStraightMoves(const Position &position, const unsigned steps) const
{
	std::vector<Position> moves;

	// as long as there is no piece in the way, we can go left
	bool canGoLeft = true;
	bool canGoRight = true;
	bool canGoUp = true;
	bool canGoDown = true;

	for (unsigned step = 1; step <= steps; step++)
	{
		// left
		if (ToUnsigned(position.file) >= step && canGoLeft)
		{
			Position left(ToUnsigned(position.file) - step, position.rank);

			moves.push_back(left);
			if (this->GetPiece(left).GetType() != Piece::None)
				canGoLeft = false;
		}

		// right
		if (ToUnsigned(position.file) + step <= ToUnsigned(File::H) && canGoRight)
		{
			Position right(ToUnsigned(position.file) + step, position.rank);

			moves.push_back(right);
			if (this->GetPiece(right).GetType() != Piece::None)
				canGoRight = false;
		}

		// up
		if (ToUnsigned(position.rank) <= step && canGoUp)
		{
			Position up(position.file, ToUnsigned(position.rank) - step);

			moves.push_back(up);
			if (this->GetPiece(up).GetType() != Piece::None)
				canGoUp = false;
		}

		// down
		if (ToUnsigned(position.rank) + step <= ToUnsigned(Rank::Eight) && canGoDown)
		{
			Position down(position.file, ToUnsigned(position.rank) + step);

			moves.push_back(down);
			if (this->GetPiece(down).GetType() != Piece::None)
				canGoDown = false;
		}
	}

	return moves;
}

std::vector<Position> Board::GetDiagonalMoves(const Position &position, const unsigned steps) const
{
	std::vector<Position> moves;

	for (unsigned step = 1; step <= steps; step++)
	{
		// up-left
		if (ToUnsigned(position.file) <= step && ToUnsigned(position.rank) <= step)
		{
			Position up_left(ToUnsigned(position.file) - step, ToUnsigned(position.rank) - step);

			if (this->GetPiece(up_left).GetType() == Piece::None)
				moves.push_back(up_left);
			else

		}

		// up-right
		// down-left
		// down-right
	}
}

Piece& Board::GetPiece(const Position &position)
{
	// convert the 2d position into a 1d index
	unsigned long index = ToUnsigned(position.file) + ToUnsigned(position.rank) * Board::files;
	return pieces.at(index);
}

const Piece &Board::GetPiece(const Position &position) const
{
	// convert the 2d position into a 1d index
	unsigned long index = ToUnsigned(position.file) + ToUnsigned(position.rank) * Board::files;
	return pieces.at(index);
}

std::vector<Piece> Board::Presets::Default()
{
	return Fen::GetPieces("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");
}

}