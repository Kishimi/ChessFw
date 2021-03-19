#include <iostream>
#include <string>

#include <ChessFw/ChessFw.hpp>

int main()
{
	ChessFw::Board board = ChessFw::Fen::GetPieces("8/8/8/2k5/4K3/8/8/8");
	// ChessFw::Engine<> engine;

	while (!board.CheckMate())
	{
		std::cout << "\n  ";
		for (unsigned char c = 'A'; c <= 'H'; c++)
			std::cout << c << " ";
		std::cout << "\n  ";

		auto pieces = board.GetPieces();
		for (unsigned x = 0, y = 0; const ChessFw::Piece &piece : pieces)
		{
			char pieceChar = '.';
			
			switch (piece.GetType())
			{
				case ChessFw::Piece::King:
					pieceChar = 'K';
					break;

				case ChessFw::Piece::Queen:
					pieceChar = 'Q';
					break;

				case ChessFw::Piece::Bishop:
					pieceChar = 'B';
					break;

				case ChessFw::Piece::Knight:
					pieceChar = 'N';
					break;

				case ChessFw::Piece::Rook:
					pieceChar = 'R';
					break;

				case ChessFw::Piece::Pawn:
					pieceChar = 'P';
					break;

				default:
					break;
			}

			if (piece.GetColor() == ChessFw::Piece::Black)
				pieceChar = std::tolower(pieceChar);

			std::cout << pieceChar << " ";

			x++;

			if (x >= ChessFw::Board::files)
			{
				x = 0;
				y++;
				std::cout << y << "\n  ";
			}
		}

		std::cout << "\n";

		if (board.ColorToMove() == ChessFw::Piece::White)
			std::cout << "White: ";
		else if (board.ColorToMove() == ChessFw::Piece::Black)
			std::cout << "Black: ";

		std::string move;
		std::getline(std::cin, move);

		system("cls");

		board.HalfMove(ChessFw::San::ToMove(move));
		// board.Move(move, engine.GetMove());
	}

	return 0;
}