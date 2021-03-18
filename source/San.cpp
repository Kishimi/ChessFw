#include <ChessFw/San.hpp>

namespace ChessFw
{

Position San::GetDeparture(const std::string &move)
{
	/**
	 * See ChessFw::San::GetDestination(), almost the same applies.
	 */
	
	if (!IsValid(move))
		throw InvalidSanException(move, "ChessFw::San::GetDeparture() => invalid SAN");
	
	unsigned file = FileNone;
	unsigned rank = RankNone;

	unsigned long pos1 = 0, pos2 = 1;

	if (San::GetPiece(move) != Piece::Pawn)
	{
		// To have a departure without a pawn, the move string must be at least 3 characters long
		// Ked => departure is e, destination is d. There is no shorter variant
		if (move.size() < 3)
			return Position(FileNone, RankNone);

		// Just expect the departure at the 2nd and 3rd character.
		// Though, it might be that the destination is there:
		// Be5 means a bishop will move to e5, but it doesn't mean it will depart there.
		// There are a few solutions to this:
		// - Just assume that it's the departure, and then compare it do the destination.
		//   If the departure and destination are equal, we return FileNone and RankNone,
		//   since no move in chess allows to stay on the same square.
		// - Check against the length of the move string:
		//     => If move.size() - 1 == pos2 && move.size() - 2 == pos1 the departure wasn't specified.
		//   If that condition is not true, there is either an 'x' indicating that this is a capturing move,
		//   or the departure. (Bxe5) -> condition is false (Qe5e6) -> condition is false
		//
		// For now, I think the first solution is enough.

		pos1 = 1;
		pos2 = 2;
	}

	if (std::isalpha(move.at(pos1)) && std::isdigit(move.at(1)))
	{
		file = move.at(pos1) - 'a';
		rank = move.at(pos2) - '1';
	}
	else if (std::isalpha(move.at(pos1)))
		file = move.at(pos1) - 'a';
	else if (std::isdigit(move.at(pos1)))
		rank = move.at(pos1) - '1';
	else
		throw InvalidSanException(move, "ChessFw::San::GetDeparture() => invalid SAN");

	if ((file < FileA || file > FileH || rank < Rank1 || rank > Rank8) && (file != FileNone && rank != RankNone))
		throw InvalidSanException(move, "ChessFw::San::GetDeparture() => invalid departure");

	return Position(static_cast<File>(file), static_cast<Rank>(rank));
}

Position San::GetDestination(const std::string &move)
{
	/**
	 * All notation variants that need to be supported (sadly :<)
	 * - Be5 => Bishop moves to e5
	 * - Bxe5 => Bishop captures e5
	 * - e5 => Pawn moves to e5
	 * - exd5 => Pawn onfile e captures d5
	 * - ed5 => Only pawn on file e captures d5
	 * - ed => Only pawn on file e captures the pawn he can capture
	 *
	 * Not quite sure, but I think this implementation satisfies all those cases
	 */
	
	if (!IsValid(move))
		throw InvalidSanException(move, "ChessFw::San::GetDestination() => invalid SAN");
	
	// just shortcuts
	const unsigned long pos1 = move.size() - 2;
	const unsigned long pos2 = move.size() - 1;

	unsigned file = FileNone;
	unsigned rank = RankNone;

	// pos1 = file, pos2 = rank
	if (std::isalpha(move[pos1]) && std::isdigit(move[pos2]))
	{
		file = move.at(pos1) - 'a';
		rank = move.at(pos2) - '1';
	}
	else if (std::isalpha(move.at(pos2)))
		file = move.at(pos2) - 'a';
	else if (std::isdigit(move.at(pos2)))
		rank = move.at(pos2) - '1';
	else
		throw InvalidSanException(move, "ChessFw::San::GetDestination() => invalid SAN");

	// make sure the position even exists
	if (file >= FileA && file <= FileNone && rank >= Rank1 && rank <= RankNone)
		throw InvalidSanException(move, "ChessFw::San::GetDestination() => invalid destination");

	return Position(static_cast<File>(file), static_cast<Rank>(rank));
}

Piece::Type San::GetPiece(const std::string &move)
{
	/**
	 * Identifying the piece that moves is really easy,
	 * if the first letter in move is not uppercase, it's a pawn move,
	 * else just check against all piece identifiers (K, Q, R, B or N)
	 */
	
	if (!IsValid(move))
		throw InvalidSanException(move, "ChessFw::San::GetPiece() => invalid SAN");
	
	if (std::islower(move.at(0)))
		return Piece::Pawn;
	else
		switch (move.at(0))
		{
			case 'K':
				return Piece::King;

			case 'Q':
				return Piece::Queen;

			case 'B':
				return Piece::Bishop;

			case 'N':
				return Piece::Knight;

			case 'R':
				return Piece::Rook;

			default:
				throw InvalidSanException(move, "ChessFw::San::GetPiece() => invalid piece");
		}

	throw InvalidSanException(move, "ChessFw::San::GetPiece() => invalid SAN");
}

bool San::IndicatesCapture(const std::string &move)
{
	// The san notation has to have at least two characters, and can't be longer than 6 characters.
	if (!IsValid(move))
		throw InvalidSanException(move, "ChessFw::San::Get() => invalid SAN");

	// If the san has an 'x' in it, it is a capturing move
	return move.find('x') != std::string::npos;
}

bool San::IsValid(const std::string &move)
{
	// A san notation can be at minimum two characters, at max six.
	if (move.size() < 2 || move.size() > 6)
		return false;

	// Regex to match san notation (in the most cases)
	return std::regex_match(move, std::regex("^([KQBNR]?[a-h]?[1-8]?x?(?=.)[a-h]?[1-8]?)$"));
}

InvalidSanException::InvalidSanException(const std::string &move, const std::string &what)
{
	using namespace std::string_literals;

	_what = move + ": "s + what;
}

const char* InvalidSanException::what() const noexcept
{
	return _what.c_str();
}

}