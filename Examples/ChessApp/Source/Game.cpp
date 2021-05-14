#include "Game.hpp"

void Game::Run()
{
	window.create(sf::VideoMode(1280, 720), "ChessApp");

	while (window.isOpen())
	{
		this->HandleEvents();

		window.clear();
		window.display();
	}
}

void Game::HandleEvents()
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
}