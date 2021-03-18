#pragma once

#include <limits>

namespace ChessFw
{

/**
 * This enum is just a nice feature to allow passing files as A, B, C, etc. instead of numbers (1, 2, 3, ...) just like chess
 */
enum File : unsigned
{
	FileA,
	FileB,
	FileC,
	FileD,
	FileE,
	FileF,
	FileG,
	FileH,

	FileNone = std::numeric_limits<unsigned>::max()
};

/**
 * Because we have the file enum, lets just have a rank enum
 */
enum Rank : unsigned
{
	Rank1,
	Rank2,
	Rank3,
	Rank4,
	Rank5,
	Rank6,
	Rank7,
	Rank8,

	RankNone = std::numeric_limits<unsigned>::max()
};

class Position final
{
public:
	/**
	 * Create a position with default values (0, 0)
	 */
	constexpr Position()
		: file(FileNone)
		, rank(RankNone) {}

		/**
		 * Constructs a position
		 * @param  file The file of the position (or x position)
		 * @param  rank The rank of the position (or y position)
		 */
	constexpr Position(const File file, const Rank rank)
		: file(file)
		, rank(rank) {}

public:

	/**
	 * Compare two positions for equality
	 * @param lhs The lefthandside value of the comparison
	 * @param rhs The righthandside value of the comparison
	 * @return True if both values are equal
	 */
	friend constexpr bool operator==(const Position &lhs, const Position &rhs)
	{
		return lhs.file == rhs.file && lhs.rank == rhs.rank;
	}

	/**
	 * Compare two positions for inequality
	 * @param lhs The lefthandside value of the comparison
	 * @param rhs The righthandside value of the comparison
	 */
	friend constexpr bool operator!=(const Position &lhs, const Position &rhs)
	{
		return !(lhs == rhs);
	}

public:
	File file;
	Rank rank;
};

}