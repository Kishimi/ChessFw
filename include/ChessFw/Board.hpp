#pragma once

#include <string>
#include <vector>

#include "Piece.hpp"
#include "Move.hpp"

namespace ChessFw
{

class Board final
{
public:
	struct Presets final
	{
		static std::vector<Piece> Default();
	};

public:
	constexpr static unsigned files = 8;
	constexpr static unsigned ranks = 8;

public:
	Board(const std::vector<Piece> &pieces);

public:
	/**
	 * This function does half a move on the board. 
	 * @param move The move to do.
	 */
	void HalfMove(const Move &move);

	/**
	 * This function does a full move on the board
	 * @param whiteMove The move for white
	 * @param blackMove The move for black
	*/
	void FullMove(const Move &whiteMove, const Move &blackMove);

	/**
	 * Get a copy of all the pieces on the board
	 * @return All the pieces on the board
	 */
	std::vector<Piece> GetPieces() const;

	/**
	 * Check wether there's checkmate or not
	 * @return True if checkmate (ChessFw::Board::ColorToMove() will return the color that lost)
	 */
	bool CheckMate() const;

	/**
	 * Get the color that has to move
	 * @return The color that has the next move
	 */
	auto ColorToMove() const -> Piece::Color;

private:
	std::vector<Piece> pieces;
};

}