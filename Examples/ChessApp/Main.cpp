#include <SFML/Graphics.hpp>
#include <ChessFw/ChessFw.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "ChessFw - ChessApp");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
				case sf::Event::Closed:
					window.close();
					break;

				default:
					break;
			}
		}

		window.clear();
		window.display();
	}

	return 0;
}