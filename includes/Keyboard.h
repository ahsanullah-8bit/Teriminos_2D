#pragma once
#include "Renderer.h"
#include "Constants.h"
#include <SFML/Graphics.hpp>

namespace Tetris
{
	struct KeyBoard
	{
	public:
		static sf::Keyboard::Key getInput(Renderer& renderer)
		{
			sf::Event event;
			while (renderer.window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					renderer.window.close();

				if (event.type == sf::Event::KeyPressed)
					return event.key.code;
			}

			return sf::Keyboard::Unknown;
		}
	};
}