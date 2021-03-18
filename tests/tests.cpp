#include <iostream>

#include <ChessFw/San.hpp>
#include <ChessFw/Piece.hpp>

/**
 * This is a quickly crafted test framework xD
 */

using TestFn = void(*)();
std::vector<std::pair<std::string, TestFn>> tests;

/**
 * Helper struct to add tests in global scope (because we can't call funtions in global scope afaik)
 */
struct AddTest final
{
	AddTest(const std::string& name, TestFn fn)
	{
		tests.push_back({ name, fn });
	}
};

/**
 * Add a test to run. The test function should return void.
 * @param  name The name of the test
 */
#define TEST(name) \
	void name(); \
	AddTest __global_add_test_##name(#name, name); \
	void name()

/**
 * Assert a expression to be true
 * @param  expr The expression
 */
#define ASSERT(expr) \
	if (!(expr)) \
		throw std::runtime_error(#expr)

/**
 * Try catch shortcut
 * @param  stmt   Statement in try block
 * @param  result Boolean variable set to true if the try failed.
 * @return        [description]
 */
#define TRY(stmt, result) \
	result = false; \
	try \
	{ \
		stmt; \
	} \
	catch (...) \
	{ \
		result = true; \
	}

/**
 * Declare your tests here
 */
TEST(ChessFwSanGetPiece)
{
	ChessFw::Piece piece;
	
	// These should all work fine
	//
	piece = ChessFw::San::GetPiece("Ke6");
	ASSERT(piece == ChessFw::Piece::King);

	piece = ChessFw::San::GetPiece("Qxd");
	ASSERT(piece == ChessFw::Piece::Queen);

	piece = ChessFw::San::GetPiece("Bxa5");
	ASSERT(piece == ChessFw::Piece::Bishop);

	piece = ChessFw::San::GetPiece("Nf7");
	ASSERT(piece == ChessFw::Piece::Knight);

	piece = ChessFw::San::GetPiece("Rh1");
	ASSERT(piece == ChessFw::Piece::Rook);

	piece = ChessFw::San::GetPiece("ed");
	ASSERT(piece == ChessFw::Piece::Pawn);

	bool getPieceFailed = false;

	// These should all fail
	//
	TRY(piece = ChessFw::San::GetPiece("Hxb2"), getPieceFailed);
	ASSERT(getPieceFailed && "Hxb2");

	TRY(piece = ChessFw::San::GetPiece("H"), getPieceFailed);
	ASSERT(getPieceFailed && "H");

	TRY(piece = ChessFw::San::GetPiece("Qe5xb56"), getPieceFailed);
	ASSERT(getPieceFailed && "Qe5xb56");
}

TEST(ChessFwSanIsValid)
{
	ASSERT(ChessFw::San::IsValid("Kxe4"));
	ASSERT(!ChessFw::San::IsValid("Qx"));
	ASSERT(ChessFw::San::IsValid("h4"));
	ASSERT(!ChessFw::San::IsValid("d"));
	ASSERT(ChessFw::San::IsValid("Re4xe6"));
	ASSERT(!ChessFw::San::IsValid("Gf7"));
	ASSERT(!ChessFw::San::IsValid("xa4"));
}

/**
 * Tests being run
 */

int main()
{
	int num_failed = 0;

	std::cout << "Running tests...\n----------------\n";
	for (auto&[name, test] : tests)
	{
		try
		{
			test();
		}
		catch (const std::exception& e)
		{
			std::cout << "[FAIL] => " << name << ": " << e.what() << "\n";
			num_failed++;
			continue;
		}

		std::cout << "[PASS] => " << name << "\n";
	}

	std::cout << "----------------\n> Results <\n";
	std::cout << "Total : " << tests.size() << "\n";
	std::cout << "Passed: " << tests.size() - num_failed << "\n";
	std::cout << "Failed: " << num_failed << "\n";

	return static_cast<bool>(num_failed);
}