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
		, color(Color::NoColor)
		, isFirstMove(true) {}

	constexpr Piece(const Type type, const Color color, const bool isFirstMove = true)
		: type(type)
		, color(color)
		, isFirstMove(isFirstMove) {}

public:
	/**
	 * Get the type of a piece
	 * @return The type of the piece
	 */
	constexpr Type GetType() const
	{
		return type;
	}

	/**
	 * Get the color of a piece
	 * @return The color of the piece
	*/
	constexpr Color GetColor() const
	{
		return color;
	}

	constexpr bool IsFirstMove() const
	{
		return isFirstMove;
	}

private:
	Type type;
	Color color;
	bool isFirstMove;
};

}