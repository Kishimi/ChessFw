#pragma once

#include "Position.hpp"

namespace ChessFw
{

class Piece final
{
public:
	enum Type
	{
		None,

		Pawn,
		Rook,
		Knight,
		Bishop,
		Queen,
		King
	};

	enum Color
	{
		White,
		Black
	};

public:
	constexpr Piece()
		: type(Type::None) {}

	/**
	 * This constructs a piece just with a type
	 * @param  type The type of the piece
	 */
	constexpr Piece(const Type type)
		: type(type) {}

	/**
	 * This constructs a piece with a type, color and position
	 * @param  type The type of the piece (ChessFw::Piece::Pawn, ChessFw::Piece::King, ...)
	 * @param  color The color of the piece (ChessFw::Piece::White or ChessFw::Piece::Black)
	 */
	constexpr Piece(const Type type, const Color color, const Position &position)
		: type(static_cast<Type>(type | color))
		, position(position) {}

public:
	/**
	 * This function sets the position of the piece
	 * @param position The position to move to
	 */
	void SetPosition(const Position &position);
	
	/**
	 * Get the position of the piece
	 * @return A copy of the position of this piece
	 */
	Position GetPosition() const;

	/**
	 * This function sets the type and color of this piece
	 * @param type  The type of the piece (ChessFw::Piece::Pawn, ChessFw::Piece::King, ...)
	 * @param color The color of the piece (ChessFw::Piece::White or ChessFw::Piece::Black)
	 */
	void SetTypeAndColor(const Type type, const Color color);

	/**
	 * This function sets only the type of the piece, not the color
	 * @param type The type of the piece (ChessFw::Piece::Pawn, ChessFw::Piece::King, ...)
	 */
	void SetType(const Type type);

	/**
	 * Get the type of the piece
	 * @return The type of the piece
	 */
	Type GetType() const;

	/**
	 * This function sets the color of piece
	 * @param Color The color for the piece (ChessFw::Piece::White or ChessFw::Piece::Black)
	 */
	void SetColor(const Color color);

	/**
	 * Get the color of the piece
	 * @return The color of the piece
	 */
	Color GetColor() const;

	/**
	 * Check if the piece was moved, or if it's the first move
	 * @return True if it's the piece was moved or not
	 */
	bool IsFirstMove() const;

// Some operators

	constexpr bool operator==(const Type type) const
	{
		return this->type == type;
	}

	constexpr bool operator!=(const Type type) const
	{
		return this->type != type;
	}

private:
	Type type;
	Color color;
	Position position;
	bool wasMoved = false;
};

}