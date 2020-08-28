#include "CreditsState.h"

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

void CreditsState::update(Game & game)
{
	Arduboy2 & arduboy = game.getArduboy();

	if(arduboy.justPressed(B_BUTTON))
	{
		game.changeState(GameState::TitleScreen);
	}
}

template<size_t size>
void printCreditsList(Arduboy2 & arduboy, const char * title, const char * const (& array)[size])
{
	arduboy.println(Utils::asFlashStringHelper(title));

	for(size_t index = 0; index < size; ++index)
	{
		arduboy.print(F("  "));
		arduboy.println(Utils::readFlashStringPointer(&array[index]));
	}
}

void CreditsState::render(Game & game)
{
	Arduboy2 & arduboy = game.getArduboy();

	// List Programmers
	printCreditsList(arduboy, Strings::programmersTitle, Strings::programmers);

	// Blank Line
	arduboy.println();

	// List Artists
	printCreditsList(arduboy, Strings::artistsTitle, Strings::artists);

	// Blank Line
	arduboy.println();

	// Print Licence
	arduboy.print(Utils::asFlashStringHelper(Strings::licenceName));
}