#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>

namespace Tetris
{
	class Renderer
	{
	public:
		Renderer(class Board* pboard_ptr);
		void render();

	public:
		sf::RenderWindow window;

	private:
		class Board* mboard_ptr;
		sf::Texture texture;

		const std::unordered_map<char, int> sprite_locations =
		{
			{'B', 0},
			{'G', 64},
			{'L', 128},
			{'O', 192},
			{'Y', 256},
			{'P', 320},
			{'R', 384}
		};
	};
}