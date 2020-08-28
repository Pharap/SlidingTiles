#include "TitleScreenState.h"

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

#include "../Images.h"
#include "../Utils.h"
#include "../Strings.h"
#include "../Game.h"
#include "../GameState.h"

struct MenuEntry
{
	const char * text;
	GameState state;
};

constexpr MenuEntry menuEntries[] PROGMEM
{
	{ Strings::play, GameState::Gameplay },
	{ Strings::credits, GameState::Credits },
};

constexpr uint8_t firstIndex = 0;
constexpr uint8_t lastIndex = (Utils::getSize(menuEntries) - 1);

void TitleScreenState::update(Game & game)
{
	Arduboy2 & arduboy = game.getArduboy();

	if(arduboy.justPressed(UP_BUTTON))
		if(this->selectedIndex > firstIndex)
			--this->selectedIndex;

	if(arduboy.justPressed(DOWN_BUTTON))
		if(this->selectedIndex < lastIndex)
			++this->selectedIndex;

	if(arduboy.justPressed(A_BUTTON))
	{
		auto nextState = static_cast<GameState>(pgm_read_byte(&menuEntries[this->selectedIndex].state));
		game.changeState(nextState);
	}
}

void TitleScreenState::render(Game & game)
{
	Arduboy2 & arduboy = game.getArduboy();

	// Draw Title Image

	constexpr int16_t titleX = Utils::calculateCentreOffsetX(Images::titleWidth, Arduboy2::width());
	constexpr int16_t titleY = 4;

	Sprites::drawOverwrite(titleX, titleY, Images::title, 0);

	// Draw Menu Options

	constexpr int16_t textX = 16;
	constexpr int16_t baseTextY = ((titleY + Images::titleHeight) + 8);

	// Iterate through all menu entries
	for(size_t index = 0; index < Utils::getSize(menuEntries); ++index)
	{
		// Calculate the y coordinate
		const int16_t textY = (baseTextY + (index * Utils::Font::glyphHeight));

		// Set the cursor
		arduboy.setCursor(textX, textY);

		// Draw the cursor
		arduboy.print((index == this->selectedIndex) ? F("\x10") : F(" "));

		// Read the text
		const auto text = reinterpret_cast<const char *>(pgm_read_ptr(&menuEntries[index].text));

		// Print the text
		arduboy.print(Utils::asFlashStringHelper(text));
	}
}