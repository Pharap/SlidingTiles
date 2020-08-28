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

#include <Arduboy2.h>

#include "GameState.h"
#include "States.h"

class Game
{
private:
	GameState gameState = GameState::SplashScreen;
	Arduboy2 arduboy;

	SplashScreenState splashScreenState;
	TitleScreenState titleScreenState;
	GameplayState gameplayState;
	CreditsState creditsState;

public:
	Arduboy2 & getArduboy();
	const Arduboy2 & getArduboy() const;

public:
	void changeState(GameState gameState);

public:
	void setup();
	void loop();
};