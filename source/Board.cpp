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
	return Piece::NoColor;
}

}