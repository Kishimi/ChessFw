#pragma once

#include <iostream>

#include <string>
#include <vector>

#include "Piece.hpp"
#include "Move.hpp"
#include "Position.hpp"
#include "Fen.hpp"

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
	 * @return True if the move was executed
	 */
	bool HalfMove(const Move &move);

	/**
	 * This function does a full move on the board
	 * @param whiteMove The move for white
	 * @param blackMove The move for black
	 * @return True if both moves were executed
	*/
	bool FullMove(const Move &whiteMove, const Move &blackMove);

	/**
	 * Get a copy of all the pieces on the board
	 * @return All the pieces on the board
	 */
	std::vector<Piece> GetPieces() const;

	/**
	 * Check wether the game is over or not
	 * @return True if the game is over
	 */
	bool GameOver() const;

	/**
	 * Check wether it's a draw or not
	 * @return True if it's a draw
	 */
	bool Draw() const;

	/**
	 * Check wether there's check or not
	 * @return True if check (ChessFw::Board::ColorToMove is the color in check)
	 */
	bool Check() const;

	/**
	 * Check wether there's checkmate or not
	 * @return True if checkmate (ChessFw::Board::ColorToMove() will return the color that lost)
	 */
	bool Mate() const;

	/**
	 * Get the color that has to move
	 * @return The color that has the next move
	 */
	Piece::Color ColorToMove() const;

private:
	/**
	 * Check wether a move is valid or not
	 * @param move The move to check
	 * @return True if the move is valid
	 */
	bool IsValidMove(const Move &move) const;

	/**
	 * Get all possible moves for a piece
	 * @param position The position of the piece
	 * @return List of possible moves
	 */
	std::vector<Position> GetPossibleMoves(const Position &position) const;

	/**
	 * Get all straight moves possible from a position
	 * @param position The position where the piece is
	 * @param steps How many straight steps are max possible.
	 * @return All straight moves possible from that position
	 */
	std::vector<Position> GetStraightMoves(const Position &position, const unsigned steps = 8) const;

	/**
	 * Get all diagonal moves possible from a position
	 * @param position The position where the piece is
	 * @param steps How many diagonal steps are max possible.
	 * @return All diagonal moves possible from that position
	 */
	std::vector<Position> GetDiagonalMoves(const Position &position, const unsigned steps = 8) const;

	/**
	 * Get a piece at a specific position
	 * @param position The position to get the piece from
	 * @return The piece at that position
	 */
	Piece& GetPiece(const Position &position);
	const Piece& GetPiece(const Position &position) const;

private:
	std::vector<Piece> pieces;
	Piece::Color colorToMove;
};

}