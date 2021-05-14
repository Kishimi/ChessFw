#pragma once

#include <string>
#include <vector>

#include "Piece.hpp"

namespace ChessFw
{

/**
 * This class is used to decode fen notation
 */
class Fen final
{
public:
	/**
	 * This functions decodes a string in fen notation to a list of pieces
	 * @param fen The fen notation
	 * @return A list of pieces matching the fen notation, throws when something is wrong
	 */
	static std::vector<Piece> GetPieces(const std::string &fen);
};

}