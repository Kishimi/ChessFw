#include <iostream>
#include <string>

#include <ChessFw/ChessFw.hpp>

int main()
{
	ChessFw::Board board = ChessFw::Board::Presets::Default();
	// ChessFw::Engine<> engine;

	while (!board.CheckMate())
	{
		system("clear");

		if (board.ColorToMove() == ChessFw::Piece::White)
			std::cout << "White: ";
		else if (board.ColorToMove() == ChessFw::Piece::Black)
			std::cout << "Black: ";

		std::string move;
		std::getline(std::cin, move);

		board.HalfMove(ChessFw::San::ToMove(move));
		// board.Move(move, engine.GetMove());

		auto pieces = board.GetPieces();
		for (unsigned x = 0; const ChessFw::Piece& piece : pieces)
		{
			if (x >= ChessFw::Board::files)
			{
				x = 0;
				std::cout << "\n";
			}

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
				pieceChar -= ('a' - 'A'); // to lowercase

			std::cout << pieceChar;

			x++;
		}

		std::cout << "\n";
	}

	return 0;
}