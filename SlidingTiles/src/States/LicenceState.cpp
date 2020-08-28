#include "LicenceState.h"

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

void LicenceState::update(Game & game)
{
	Arduboy2 & arduboy = game.getArduboy();

	if(arduboy.justPressed(B_BUTTON))
	{
		game.changeState(GameState::TitleScreen);
	}
}

void LicenceState::render(Game & game)
{
	Arduboy2 & arduboy = game.getArduboy();
}