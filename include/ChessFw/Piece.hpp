#pragma once

namespace ChessFw
{

class Piece final
{
public:
	enum Type : unsigned
	{
		King,
		Queen,
		Bishop,
		Knight,
		Rook,
		Pawn,

		None
	};

	enum Color : unsigned
	{
		White,
		Black,

		NoColor
	};

public:
	constexpr Piece()
		: type(Type::None)
		, color(Color::NoColor) {}

	constexpr Piece(const Type type, const Color color)
		: type(type)
		, color(color) {}

public:
	/**
	 * Get the type of a piece
	 * @return The type of the piece
	 */
	Type GetType() const;

	/**
	 * Get the color of a piece
	 * @return The color of the piece
	*/
	Color GetColor() const;

private:
	Type type;
	Color color;
};

}