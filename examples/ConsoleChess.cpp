#include <iostream>
#include <string>
#include <thread>
#include <chrono>

#include <ChessFw/ChessFw.hpp>

int main()
{
	ChessFw::Board board = ChessFw::Board::Presets::Default();
	// ChessFw::Engine<> engine;

	while (!board.GameOver())
	{
		system("clear");

		// draw files
		std::cout << "\n    ";
		for (unsigned char c = 'a'; c <= 'h'; c++)
			std::cout << c << " ";
		std::cout << "\n\n";

		// draw board
		auto pieces = board.GetPieces();
		for (unsigned x = 0, y = 0; const ChessFw::Piece &piece : pieces)
		{
			// draw ranks
			if (x == 0)
				std::cout << " " << y + 1 << "  ";

			std::string pieceChar = ".";
			
			if (piece.GetColor() == ChessFw::Piece::White)
				switch (piece.GetType())
				{
					case ChessFw::Piece::King:
						pieceChar = "♚";
						break;

					case ChessFw::Piece::Queen:
						pieceChar = "♛";
						break;

					case ChessFw::Piece::Bishop:
						pieceChar = "♝";
						break;

					case ChessFw::Piece::Knight:
						pieceChar = "♞";
						break;

					case ChessFw::Piece::Rook:
						pieceChar = "♜";
						break;

					case ChessFw::Piece::Pawn:
						pieceChar = "♟";
						break;

					default:
						break;
				}

			if (piece.GetColor() == ChessFw::Piece::Black)
				switch (piece.GetType())
				{
					case ChessFw::Piece::King:
						pieceChar = "♔";
						break;

					case ChessFw::Piece::Queen:
						pieceChar = "♕";
						break;

					case ChessFw::Piece::Bishop:
						pieceChar = "♗";
						break;

					case ChessFw::Piece::Knight:
						pieceChar = "♘";
						break;

					case ChessFw::Piece::Rook:
						pieceChar = "♖";
						break;

					case ChessFw::Piece::Pawn:
						pieceChar = "♙";
						break;

					default:
						break;
				}

			std::cout << pieceChar << " ";

			x++;

			// draw ranks
			if (x >= ChessFw::Board::files)
			{
				x = 0;
				y++;
				std::cout << " " << y << "\n";
			}
		}

		// draw files
		std::cout << "\n    ";
		for (unsigned char c = 'a'; c <= 'h'; c++)
			std::cout << c << " ";

		std::cout << "\n";
		std::string sMove;
		while (sMove.size() != 4 && sMove != "quit")
		{
			std::cout << (board.ColorToMove() == ChessFw::Piece::White ? "White: " : "Black: ");
			std::cin >> sMove;
		}

		if (sMove == "quit")
			break;

		ChessFw::Move move(
				ChessFw::Position(sMove[0] - 'a', sMove[1] - '1'),
				ChessFw::Position(sMove[2] - 'a', sMove[3] - '1'));

		board.HalfMove(move);

		std::cout << "\n";
	}

	return 0;
}