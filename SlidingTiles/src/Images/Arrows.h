#pragma once

//
// Copyright (C) 2020 Pharap (@Pharap)
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#include <stdint.h>
#include <avr/pgmspace.h>

namespace Images
{
	constexpr uint8_t arrowWidth = 8;
	constexpr uint8_t arrowHeight = 8;

	constexpr uint8_t arrowUpIndex = 0;
	constexpr uint8_t arrowRightIndex = 1;
	constexpr uint8_t arrowDownIndex = 2;
	constexpr uint8_t arrowLeftIndex = 3;

	constexpr uint8_t arrows[] PROGMEM
	{
		// Dimensions
		arrowWidth, arrowHeight,

		// Frame 0 - North
		0x00, 0x08, 0x0C, 0x7E, 0x7E, 0x0C, 0x08, 0x00,

		// Frame 1 - East
		0x00, 0x18, 0x18, 0x18, 0x7E, 0x3C, 0x18, 0x00,

		// Frame 2 - South
		0x00, 0x10, 0x30, 0x7E, 0x7E, 0x30, 0x10, 0x00,

		// Frame 3 - West
		0x00, 0x18, 0x3C, 0x7E, 0x18, 0x18, 0x18, 0x00,
	};
}