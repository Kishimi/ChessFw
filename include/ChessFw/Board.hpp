#pragma once

#include <string>
#include <vector>

#include "Piece.hpp"

namespace ChessFw
{

class Board final
{
public:
	/**
	 * This creates a board using fen notation
	 * @param Fen A string in fen notation
	 */
	Board(const std::string &fen);

public:
	/**
	 * This function makes a half move on the board
	 * @param move The move in san notation, move is executed for the color to move
	 */
	void HalfMove(const std::string &move);

	/**
	 * This function makes a move on the board, both moves should be in the SAN notation
	 * @param white White move in SAN notation
	 * @param black Black move in SAN notation
	 */
	void Move(const std::string &white, const std::string &black);

	/**
	 * Check wether a move is a valid move or not
	 * @param  move The move in san notation
	 * @return      [description]
	 */
	bool IsValidMove(const std::string &move) const;

	/**
	 * Check wether there is checkmate on the board or not
	 * @return Zero if not, else the color that won
	 */
	Piece::Color Checkmate() const;

	/**
	 * Get the current color to move
	 * @return Piece::Color being the color that has the next move
	 */
	Piece::Color ColorToMove() const;

private:
	Piece::Color colorToMove;
	std::vector<Piece> pieces;
};

}