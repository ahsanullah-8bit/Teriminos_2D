#include "Board.h"
#include "Constants.h"
#include "Renderer.h"
#include <cstddef>
#include <filesystem>

namespace Tetris
{
    Renderer::Renderer(Board* pboard_ptr) : window(sf::VideoMode(WWIDTH, WHEIGHT), "Tetris"),
        mboard_ptr(pboard_ptr), texture()
	{
		std::filesystem::path images_path = std::filesystem::current_path() / "images";

		// Load textures
		texture.loadFromFile((images_path / "Texture.png").string());
	}

	void Renderer::render()
	{
		window.clear(sf::Color::White);

		auto& board = mboard_ptr->board;

        for (size_t y = 0; y < board.size(); ++y)
            for (size_t x = 0; x < board[y].size(); ++x)
			{
				if (board[y][x] == ' ')
					continue;

				sf::Sprite sprite(texture, sf::IntRect(sprite_locations.at(board[y][x]), 0, 64, 64));
				sprite.setScale(CELL_SCALE, CELL_SCALE);
				sprite.setPosition(x * CELL_SIZE, y * CELL_SIZE);
				window.draw(sprite);
			}

		window.display();
	}
}
