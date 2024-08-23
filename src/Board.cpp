#include "Board.h"
#include "Constants.h"
#include <SFML/Window/Keyboard.hpp>
#include <algorithm>

namespace Tetris
{
	Board::Board() : board(GRID_HEIGHT, std::vector<char>(GRID_WIDTH, ' '))
	{
		piece = piece_areas.at(piece_chars[rand() % 7]);
		color_char = color_chars[rand() % 6];
	}

	// Each tick
	void Board::update(sf::Keyboard::Key& key, bool& isGameOver) // as char for now
	{
		if (isColliding(piece, 0, 1))
		{
			// Check for game over collision before respawning
			if (isGameOverCollision(piece))
			{
				isGameOver = true;
				return;
			}

			piece = piece_areas.at(piece_chars[rand() % 7]);
			color_char = color_chars[rand() % 6];
			checkForFilledLines();
			return;
		}

		auto piece_t(piece);
		if (key == sf::Keyboard::Left)
			move(piece_t, -1, 0);
		else if (key == sf::Keyboard::Up)
			rotatePiece(piece_t);
		else if (key == sf::Keyboard::Right)
			move(piece_t, 1, 0);
		else
			move(piece_t, 0, 1);

		if (!isColliding(piece_t, 0, 0))
			re_write(piece, piece_t);
	}
	///////////////////////////////////////// ///////////////// ///////////// /////////
	// Rotates the piece
	void Board::rotatePiece(std::vector<sf::Vector2i>& piece)
	{
		sf::Vector2i center_of_rot = piece[1];
		for (auto& vec : piece)
		{
			int x_diff = vec.x - center_of_rot.x;
			int y_diff = vec.y - center_of_rot.y;

			vec.x = center_of_rot.x + y_diff;
			vec.y = center_of_rot.y - x_diff;
		}
	}

	// Check for collision with borders and other pieces
	bool Board::isColliding(const std::vector<sf::Vector2i>& figure, int xOffset, int yOffset)
	{
		for (const auto& vec : figure)
		{
			int x = vec.x + xOffset;
			int y = vec.y + yOffset;
			if (x < 0 || x >= GRID_WIDTH || y >= GRID_HEIGHT ||
                (std::find(figure.begin(), figure.end(), sf::Vector2i(x, y)) == figure.end() && board[y][x] != ' '))
				return true;
		}

		return false;
	}

	// Just checks if any y is still at 0
	bool Board::isGameOverCollision(const std::vector<sf::Vector2i>& piece)
	{
		for (const auto& vec : piece)
			if (vec.y <= 0 && board[vec.y][vec.x] != ' ')
				return true;

		return false;
	}

	// Check lines and remove them if any possible
	void Board::checkForFilledLines()
	{
		for (int i = board.size() - 1; i > 0; i--)
		{
			if (std::find_if(board[i].begin(), board[i].end(), [](char& ch) { return ch == ' '; }) != board[i].end())
				continue;

			// Remove a line
			std::copy(board[i - 1].begin(), board[i - 1].end(), board[i].begin());
		}
	}
	void Board::move(std::vector<sf::Vector2i>& piece, int xOffset, int yOffset)
	{
		std::for_each(piece.begin(), piece.end(),
			[xOffset, yOffset](sf::Vector2i& vec)
			{
				vec.x += xOffset;
				vec.y += yOffset;
			});
	}

	// Clear the old piece from board and write new one
	void Board::re_write(std::vector<sf::Vector2i>& tochange, std::vector<sf::Vector2i>& with)
	{
		std::for_each(tochange.begin(), tochange.end(), [&board = board](sf::Vector2i& vec) { board[vec.y][vec.x] = ' '; });

		// Didn't passed the color_char, that might cause problems
		std::for_each(with.begin(), with.end(), [&board = board, &color_char = color_char](const sf::Vector2i& vec) { board[vec.y][vec.x] = color_char; });

		tochange = std::move(with);
	}

	//// Draw the board to the console
	//void Board::drawToConsole()
	//{
	//	system("cls");
	//	std::for_each(board.begin(), board.end(), [](const std::vector<char>& vec2) {
	//		for (char ch : vec2)
	//			std::cout << ch;
	//		std::cout << "\n";
	//		});
	//}
}
