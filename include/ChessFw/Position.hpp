#pragma once

namespace ChessFw
{

enum class File : unsigned
{
	A,
	B,
	C,
	D,
	E,
	F,
	G,
	H,

	None
};

enum class Rank : unsigned
{
	One,
	Two,
	Three,
	Four,
	Five,
	Six,
	Seven,
	Eight,

	None
};

class Position final
{
public:
	constexpr Position()
		: file(File::None)
		, rank(Rank::None) {}

	constexpr Position(const File file, const Rank rank)
		: file(file)
		, rank(rank) {}

public:
	friend constexpr bool operator==(const Position &lhs, const Position &rhs)
	{
		return lhs.file == rhs.file && lhs.rank == rhs.rank;
	}

	friend constexpr bool operator!=(const Position &lhs, const Position &rhs)
	{
		return !(lhs == rhs);
	}

public:
	File file;
	Rank rank;
};

/**
 * This function is used to convert ChessFw::File or ChessFw::Rank to an unsigned int easily
 * @tparam T The type (Either ChessFw::File or ChessFw::Rank)
 * @param t The value of the file or rank
 * @return File or rank as unsigned int
 */
template<typename T>
unsigned ToUnsigned(const T t)
{
	return static_cast<unsigned>(t);
}

}