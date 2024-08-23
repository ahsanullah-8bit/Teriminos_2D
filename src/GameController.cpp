#include "GameController.h"
#include "Keyboard.h"
#include <thread>


namespace Tetris
{
	GameController::GameController() : board(), renderer(&board) {}

	void GameController::play()
	{
		bool isGameOver = false;
		while (renderer.window.isOpen())
		{
			sf::Keyboard::Key key = KeyBoard::getInput(renderer);
			board.update(key, isGameOver);
			//board.drawToConsole();
			renderer.render();

			// This is not a good approach but we'll see...
			if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
				!sf::Keyboard::isKeyPressed(sf::Keyboard::Left) &&
				!sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				std::this_thread::sleep_for(std::chrono::milliseconds(200));

			if (isGameOver)
				renderer.window.close();
		}
	}
}