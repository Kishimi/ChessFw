#pragma once

#include <SFML/Graphics.hpp>

class Game final
{
public:
	void Run();

private:
	void HandleEvents();

private:
	sf::RenderWindow window;
};