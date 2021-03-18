#pragma once

#include <string>
#include <exception>
#include <algorithm>
#include <regex>

#include "Piece.hpp"
#include "Position.hpp"

namespace ChessFw
{

/**
 * Interface decode SAN strings following the FIDE standard
 */
class San final
{
public:
	static Position GetDeparture(const std::string &move);

	/**
	 * This functions gets the destination of a move described in san notation. (Kxe5 returns Position(e, 5))
	 * @param  move The move in san notation
	 * @return      The destination as described in move. If no rank or file is specified,
	 *              which is legal in some cases, RankNone or FileNone is set to be rank or file.
	 */
	static Position GetDestination(const std::string &move);

	/**
	 * This function gets the type of a piece as described in the san notation
	 * @param  move The move in san notation
	 * @return The type of the piece
	 */
	static Piece::Type GetPiece(const std::string &move);

	/**
	 * This function reads out of if the the move is indicating to capture
	 * Important note: Just because a move does not indicate to capture, it doesn't mean it wont capture.
	 * @param  move [description]
	 * @return      [description]
	 */
	static bool IndicatesCapture(const std::string &move);

	/**
	 * This function checks if a san notation is valid or not
	 * @param move The move string in san notation
	 * @return true if it's valid san notation
	 */
	static bool IsValid(const std::string &move);
};

/**
 * This class is an exception that is thrown when any of the functions in the ChessFw::San class is called with an invalid san string
 */
class InvalidSanException final : public std::exception
{
public:
	InvalidSanException(const std::string &move, const std::string &what);

public:
	const char* what() const noexcept override;

private:
	std::string _what;
};

}