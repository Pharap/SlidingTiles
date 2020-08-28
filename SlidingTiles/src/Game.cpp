#include "Game.h"

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

Arduboy2 & Game::getArduboy()
{
	return this->arduboy;
}

const Arduboy2 & Game::getArduboy() const
{
	return this->arduboy;
}

void Game::changeState(GameState gameState)
{
	this->gameState = gameState;
}

void Game::setup()
{
	this->arduboy.begin();
}

void Game::loop()
{
	if(!this->arduboy.nextFrame())
		return;

	this->arduboy.pollButtons();

	this->arduboy.clear();

	switch(this->gameState)
	{
		case GameState::SplashScreen:
			splashScreenState.update(*this);
			splashScreenState.render(*this);
			break;

		case GameState::TitleScreen:
			titleScreenState.update(*this);
			titleScreenState.render(*this);
			break;
			
		case GameState::Gameplay:
			gameplayState.update(*this);
			gameplayState.render(*this);
			break;
			
		case GameState::Credits:
			creditsState.update(*this);
			creditsState.render(*this);
			break;

		default:
			this->arduboy.println(F("Error: Invalid State\nPlease report this problem\nto the author."));
			break;
	}

	this->arduboy.display();
}