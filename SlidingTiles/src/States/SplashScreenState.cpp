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

void SplashScreenState::update(Game & game)
{
	Arduboy2 & arduboy = game.getArduboy();

	if(arduboy.justPressed(A_BUTTON))
	{
		game.changeState(GameState::TitleScreen);
	}
}

void SplashScreenState::render(Game & game)
{
	// Draw Pharap Logo

	constexpr int16_t pharapLogoX = Utils::calculateCentreOffsetX(Images::pharapLogoWidth, Arduboy2::width() / 2);
	constexpr int16_t pharapLogoY = 4; //Utils::calculateCentreOffsetY(Images::pharapLogoHeight, Arduboy2::height());

	Sprites::drawOverwrite(pharapLogoX, pharapLogoY, Images::pharapLogo, 0);

	// Draw Dreamer2345 Logo

	constexpr int16_t dreamer2345LogoX = (Arduboy2::width() / 2) + Utils::calculateCentreOffsetX(Images::dreamer2345LogoWidth, Arduboy2::width() / 2) - 4;
	constexpr int16_t dreamer2345LogoY = 4; //Utils::calculateCentreOffsetY(Images::dreamer2345LogoHeight, Arduboy2::height());

	Sprites::drawOverwrite(dreamer2345LogoX, dreamer2345LogoY, Images::dreamer2345Logo, 0);
	
	// Get Arduboy

	Arduboy2 & arduboy = game.getArduboy();

	// Draw Pharap Name

	constexpr int16_t pharapNameX = Utils::Font::calculateCentreOffsetX(Strings::pharap, Arduboy2::width() / 2);
	constexpr int16_t pharapNameY = (pharapLogoY + Images::pharapLogoHeight + 4);

	arduboy.setCursor(pharapNameX, pharapNameY);
	arduboy.print(Utils::asFlashStringHelper(Strings::pharap));

	// Draw Dreamer2345 Name

	constexpr int16_t dreamer2345NameX = (Arduboy2::width() / 2) + Utils::Font::calculateCentreOffsetX(Strings::dreamer2345, Arduboy2::width() / 2) - 4;
	constexpr int16_t dreamer2345NameY = (dreamer2345LogoY + Images::dreamer2345LogoHeight + 4);

	arduboy.setCursor(dreamer2345NameX, dreamer2345NameY);
	arduboy.print(Utils::asFlashStringHelper(Strings::dreamer2345));
}