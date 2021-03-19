#include <ChessFw/Piece.hpp>

namespace ChessFw
{

Piece::Type Piece::GetType() const
{
	return type;
}

Piece::Color Piece::GetColor() const
{
	return color;
}

}