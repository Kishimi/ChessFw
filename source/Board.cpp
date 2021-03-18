#include <ChessFw/Board.hpp>

namespace ChessFw
{

Board::Board(const std::string &fen)
	: colorToMove(Piece::White)
{
}

void Board::HalfMove(const std::string &move)
{
	/**
	 * TODO:
	 * - Check if the move is valid
	 *   - If so, execute it
	 *   - else throw an InvalidMoveException or something
	 *     (it's up to the application to prevent the player doing invalid moves)
	 */

	// Change the color to move
	colorToMove = colorToMove == Piece::White
		? Piece::Black : Piece::White;
}

bool Board::IsValidMove(const std::string &move) const
{
	return true;
}

Piece::Color Board::Checkmate() const
{
	return colorToMove; // TODO: Checkmate algorithm
}

Piece::Color Board::ColorToMove() const
{
	return colorToMove;
}

}