#pragma once

#include <stdint.h>
#include <avr/pgmspace.h>

namespace Tiles
{
	constexpr uint8_t skullWidth = 16;
	constexpr uint8_t skullHeight = 16;

	constexpr uint8_t skull[] PROGMEM
	{
		// Dimensions
		skullWidth, skullHeight,

		// Frame 0 - Skull_0x0
		0x00, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE,
		0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F, 0xDF, 0xEF, 0xF7, 0xF7,

		// Frame 1 - Skull_0x1
		0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE,
		0xF7, 0xF7, 0xF7, 0xF7, 0xF7, 0xF7, 0xF7, 0xF7, 0xF7, 0xF7, 0xF7, 0xF7, 0xF7, 0xF7, 0xF7, 0xF7,

		// Frame 2 - Skull_0x2
		0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xAA, 0x56, 0x00,
		0xF7, 0xEF, 0xDF, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xAA, 0x55, 0x00,

		// Frame 3 - Skull_1x0
		0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0x01,
		0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE0, 0xDF, 0xBF, 0xBF, 0x7C,

		// Frame 4 - Skull_1x1
		0x00, 0x00, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x00, 0x00, 0x01,
		0xF8, 0xF8, 0xFC, 0xFF, 0x7F, 0x7F, 0xFF, 0xFF, 0xFF, 0x7F, 0x7F, 0xFF, 0xFC, 0xF8, 0xF8, 0x7C,

		// Frame 5 - Skull_1x2
		0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xAA, 0x55, 0x00,
		0xBF, 0xBF, 0xDF, 0xE0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xAA, 0x55, 0x00,

		// Frame 6 - Skull_2x0
		0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0x00, 0x3F, 0x5F, 0x3F, 0x5F, 0x3F, 0x5F, 0x3F, 0x5F, 0x3F, 0x5F, 0x3F, 0x5F, 0x3F, 0x5F, 0x3F,

		// Frame 7 - Skull_2x1
		0xF0, 0xEF, 0xEF, 0xEF, 0xE0, 0xE0, 0xEF, 0xEF, 0xEF, 0xE0, 0xE0, 0xEF, 0xEF, 0xEF, 0xF0, 0xFF,
		0x5F, 0x3F, 0x5F, 0x3F, 0x5F, 0x3F, 0x5F, 0x3F, 0x5F, 0x3F, 0x5F, 0x3F, 0x5F, 0x3F, 0x5F, 0x3F,

		// Frame 8 - Skull_2x2
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xAA, 0x55, 0x00,
		0x5F, 0x3F, 0x5F, 0x3F, 0x5F, 0x3F, 0x5F, 0x3F, 0x5F, 0x3F, 0x5F, 0x3F, 0x5F, 0x2A, 0x55, 0x00,
	};
}