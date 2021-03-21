#pragma once

#include "Position.hpp"

namespace ChessFw
{

class Move final
{
public:
	/**
	 * Default constructor
	 */
	constexpr Move()
		: origin()
		, destination() {}

	/**
	 * Construct a move with a origin and a destination
	 * @param  origin      The origin of the move
	 * @param  destination The destination of the move
	 */
	constexpr Move(const Position &origin, const Position &destination)
		: origin(origin)
		, destination(destination) {}

public:
	/**
	 * Get the origin of the move, or from where it's executed
	 * @return The origin of the move
	 */
	constexpr Position GetOrigin() const
	{
		return origin;
	}

	/**
	 * Get the destination of the move
	 * @return The destination of the move
	 */
	constexpr Position GetDestination() const
	{
		return destination;
	}

private:
	Position origin, destination;
};

}