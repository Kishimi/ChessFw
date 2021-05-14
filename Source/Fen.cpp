#include <ChessFw/Fen.hpp>

namespace ChessFw
{

std::vector<Piece> Fen::GetPieces(const std::string &fen)
{
	std::vector<Piece> pieces;

	for (auto itr = fen.begin(); itr != fen.end() && pieces.size() < 8 * 8; itr++)
	{
		char c = *itr;

		if (std::isalpha(c))
		{
			Piece::Type type = Piece::None;

			// Uppercase character means it's a white piece
			Piece::Color color = std::isupper(c) ? Piece::White : Piece::Black;

			// Also, since we know the color already, we make every piece uppercase
			c = std::toupper(c);

			switch (c)
			{
			case 'K':
				type = Piece::King;
				break;

			case 'Q':
				type = Piece::Queen;
				break;

			case 'B':
				type = Piece::Bishop;
				break;

			case 'N':
				type = Piece::Knight;
				break;

			case 'R':
				type = Piece::Rook;
				break;

			case 'P':
				type = Piece::Pawn;
				break;

			default:
				break; // TODO: Throw an exception
			}

			pieces.push_back(Piece(type, color));
		}
		else if (std::isdigit(c))
		{
			const unsigned num = c - '0';

			for (unsigned i = 0; i < num; i++)
				pieces.push_back(Piece());

			continue;
		}
		else if (c == '/')
			continue;
	}

	return pieces;
}

}