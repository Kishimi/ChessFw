#include <ChessFw/Piece.hpp>

namespace ChessFw
{

void Piece::SetPosition(const Position &position)
{
	this->position = position;
	wasMoved = true;
}

Position Piece::GetPosition() const
{
	return position;
}

void Piece::SetTypeAndColor(const Type type, const Color color)
{
	this->type = type;
	this->color = color;
}

void Piece::SetType(const Type type)
{
	this->type = type;
}

Piece::Type Piece::GetType() const
{
	return type;
}

void Piece::SetColor(const Color color)
{
	this->color = color;
}

Piece::Color Piece::GetColor() const
{
	return color;
}

bool Piece::IsFirstMove() const
{
	return !wasMoved;
}

}