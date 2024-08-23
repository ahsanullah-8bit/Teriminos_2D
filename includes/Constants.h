#pragma once
#include <iostream>

namespace
{
	constexpr int32_t GRID_HEIGHT = 20;
	constexpr int32_t GRID_WIDTH = 12;

	constexpr float CELL_SIZE = 25.6f;
	constexpr float CELL_SCALE = 0.4f;

	constexpr int32_t WHEIGHT = (float)CELL_SIZE * GRID_HEIGHT;
	constexpr int32_t WWIDTH = (float)CELL_SIZE * GRID_WIDTH;

	const std::string color_chars = "BGLOYPR";
	const std::string piece_chars = "ILSZOJT";

#ifndef STATUS_FLAG
#define STATUS_FLAG
	enum STATUS
	{
		GAME_OVER,
		PLAYING
	};
#endif
}