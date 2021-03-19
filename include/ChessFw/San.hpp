#pragma once

#include <string>

#include "Move.hpp"

namespace ChessFw
{

class San final
{
public:
	/**
	 * Parse a move in san format to a ChessFw::Move
	 * @param move The move in san format
	 * @return The move as ChessFw::Move
	 */
	static Move ToMove(const std::string &move);
};

}