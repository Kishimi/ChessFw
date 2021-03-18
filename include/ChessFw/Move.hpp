#pragma once

#include "Piece.hpp"
#include "Position.hpp"

namespace ChessFw
{

class Move final
{
public:


public:
	/**
	 * @return Where the piece to move wants to go
	 */
	Position GetDestination() const;

	/**
	 * Check wether the move is allowed or not
	 * @return True if the move is allowed
	 */
	bool IsValid() const;

	/**
	 * Check wether the move captures or not
	 * @return True if the move is capturing
	 */
	bool IsCapturingMove() const;

	/**
	 * This function executes the move.
	 * It will will set the pieces position to the destination.
	 */
	void Execute();

private:
	Piece &pieceToMove;
	Position destination;
	bool isCapturing;
};

}