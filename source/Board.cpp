#include <ChessFw/Board.hpp>

namespace ChessFw
{

Board::Board(const std::vector<Piece> &pieces)
	: pieces(pieces)
{
}

void Board::HalfMove(const Move &move)
{
}

void Board::FullMove(const Move &whiteMove, const Move &blackMove)
{
	this->HalfMove(whiteMove);
	this->HalfMove(blackMove);
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
}

std::vector<Position> Board::GetStraightMoves(const Position &position, const unsigned steps) const
{
	return std::vector<Position>();
}

std::vector<Position> Board::GetDiagonalMoves(const Position &position, const unsigned steps) const
{
	return std::vector<Position>();
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