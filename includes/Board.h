#pragma once
#include "Constants.h"
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <vector>
#include <unordered_map>

namespace Tetris
{
	class Board
	{
	public:
		Board();
		void update(sf::Keyboard::Key& key, bool&);

		void drawToConsole();

	private:
		void move(std::vector<sf::Vector2i>& piece, int xOffset, int yOffset);
		void rotatePiece(std::vector<sf::Vector2i>& piece);
		bool isColliding(const std::vector<sf::Vector2i>& figure, int xOffset, int yOffset);
		bool isGameOverCollision(const std::vector<sf::Vector2i>& piece);
		void checkForFilledLines();
		void re_write(std::vector<sf::Vector2i>& tochange, std::vector<sf::Vector2i>& with);

	public:
		std::vector<std::vector<char>> board;
		std::vector<sf::Vector2i> piece;
		char color_char;

		// CONSTANTS
		const std::unordered_map<char, std::vector<sf::Vector2i>> piece_areas =	// ILSZOJT
		{
			{'I', {{0, 0}, {0, 1}, {0, 2}, {0, 3}}},
			{'J', {{1, 0}, {1, 1}, {1, 2}, {0, 2}}},
			{'L', {{0, 0}, {0, 1}, {0, 2}, {1, 2}}},
			{'O', {{0, 0}, {1, 0}, {0, 1}, {1, 1}}},
			{'S', {{1, 0}, {2, 0}, {0, 1}, {1, 1}}},
			{'T', {{0, 0}, {1, 0}, {2, 0}, {1, 1}}},
			{'Z', {{0, 0}, {1, 0}, {1, 1}, {2, 1}}}
		};
	};
}