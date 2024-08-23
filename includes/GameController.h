#pragma once
#include "Board.h"
#include "Renderer.h"


namespace Tetris
{
	class GameController
	{
	public:
		GameController();
		void play();

	private:
		Board board;
		Renderer renderer;
	};
}