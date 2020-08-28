#pragma once

//
//  Copyright (C) 2020 Pharap (@Pharap)
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//       http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//

#include <stdint.h>
#include <stddef.h>

#include <Arduboy2.h>

#include "Layout.h"

namespace Utils
{
	template<uint8_t margin = 2, size_t size>
	void drawCentredTextBox(Arduboy2 & arduboy, const char (& text)[size])
	{
		constexpr int16_t textX = Utils::Font::calculateCentreOffsetX(text, Arduboy2::width());
		constexpr int16_t textY = Utils::Font::calculateCentreOffsetY(text, Arduboy2::height());

		constexpr uint8_t textWidth = Utils::Font::calculateStringWidth(text);
		constexpr uint8_t textHeight = Utils::Font::calculateStringHeight(text);

		constexpr uint8_t textBoxMargin = margin;

		constexpr int16_t textBoxX = (textX - textBoxMargin);
		constexpr int16_t textBoxY = (textY - textBoxMargin);
		constexpr uint8_t textBoxWidth = (textWidth + (textBoxMargin * 2));
		constexpr uint8_t textBoxHeight = (textHeight + (textBoxMargin * 2));

		arduboy.fillRect(textBoxX, textBoxY, textBoxWidth, textBoxHeight, BLACK);
		arduboy.drawRect(textBoxX, textBoxY, textBoxWidth, textBoxHeight, WHITE);

		arduboy.setCursor(textX, textY);
		arduboy.print(Utils::asFlashStringHelper(text));
	}
}