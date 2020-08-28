#include "GameplayState.h"

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
#include "../Tiles.h"

#define CHEAT_MODE

void GameplayState::update(Game & game)
{
	switch(this->state)
	{
		case GameplaySubstate::Ready:
			this->updateReadyState(game);
			break;
		
		case GameplaySubstate::Playing:
			this->updatePlayingState(game);
			break;
		
		case GameplaySubstate::Victory:
			this->updateVictoryState(game);
			break;
	}
}

void GameplayState::render(Game & game)
{
	switch(this->state)
	{
		case GameplaySubstate::Ready:
			this->drawReadyState(game);
			break;
		
		case GameplaySubstate::Playing:
			this->drawPlayingState(game);
			break;
		
		case GameplaySubstate::Victory:
			this->drawVictoryState(game);
			break;
	}
}

void GameplayState::updateReadyState(Game & game)
{
	Arduboy2 & arduboy = game.getArduboy();

	if(arduboy.justPressed(A_BUTTON))
	{
		this->randomise(arduboy.generateRandomSeed());
		this->state = GameplaySubstate::Playing;
	}

	if(arduboy.justPressed(B_BUTTON))
	{
		game.changeState(GameState::TitleScreen);
	}
}

void GameplayState::updatePlayingState(Game & game)
{
	Arduboy2 & arduboy = game.getArduboy();

	if(arduboy.justPressed(LEFT_BUTTON))
	{
		if(this->cursorX < gridRightIndex)
		{
			const uint8_t oldCursorX = this->cursorX;
			const uint8_t oldCursorY = this->cursorY;

			++this->cursorX;

			Utils::swap(this->tileIndices[this->cursorY][this->cursorX], this->tileIndices[oldCursorY][oldCursorX]);

			++this->moveCount;
		}
	}

	if(arduboy.justPressed(RIGHT_BUTTON))
	{
		if(this->cursorX > gridLeftIndex)
		{
			const uint8_t oldCursorX = this->cursorX;
			const uint8_t oldCursorY = this->cursorY;

			--this->cursorX;

			Utils::swap(this->tileIndices[this->cursorY][this->cursorX], this->tileIndices[oldCursorY][oldCursorX]);

			++this->moveCount;
		}
	}

	if(arduboy.justPressed(UP_BUTTON))
	{
		if(this->cursorY < gridBottomIndex)
		{
			const uint8_t oldCursorX = this->cursorX;
			const uint8_t oldCursorY = this->cursorY;

			++this->cursorY;

			Utils::swap(this->tileIndices[this->cursorY][this->cursorX], this->tileIndices[oldCursorY][oldCursorX]);

			++this->moveCount;
		}
	}

	if(arduboy.justPressed(DOWN_BUTTON))
	{
		if(this->cursorY > gridTopIndex)
		{
			const uint8_t oldCursorX = this->cursorX;
			const uint8_t oldCursorY = this->cursorY;

			--this->cursorY;

			Utils::swap(this->tileIndices[this->cursorY][this->cursorX], this->tileIndices[oldCursorY][oldCursorX]);

			++this->moveCount;
		}
	}

	#if defined(CHEAT_MODE)
	if(arduboy.justPressed(A_BUTTON) && arduboy.pressed(B_BUTTON))
	{
		this->solve();
		this->state = GameplaySubstate::Victory;
	}
	#endif

	if(this->isSuccessful())
		this->state = GameplaySubstate::Victory;
}

void GameplayState::updateVictoryState(Game & game)
{
	Arduboy2 & arduboy = game.getArduboy();

	if(arduboy.justPressed(A_BUTTON))
	{
		this->reset();
		this->state = GameplaySubstate::Ready;
	}

	if(arduboy.justPressed(B_BUTTON))
	{
		game.changeState(GameState::TitleScreen);
	}
}

void GameplayState::drawReadyState(Game & game)
{
	Arduboy2 & arduboy = game.getArduboy();

	this->drawFrame();
	this->drawGrid(arduboy);
	this->drawHUD(arduboy);

	Utils::drawCentredTextBox(arduboy, Strings::readyQuestion);
}

void GameplayState::drawPlayingState(Game & game)
{
	Arduboy2 & arduboy = game.getArduboy();

	this->drawFrame();
	this->drawTiles();
	this->drawCursor(arduboy);
	this->drawHUD(arduboy);
}

void GameplayState::drawVictoryState(Game & game)
{
	Arduboy2 & arduboy = game.getArduboy();

	this->drawFrame();
	this->drawTiles();
	this->drawHUD(arduboy);

	Utils::drawCentredTextBox(arduboy, Strings::victoryStatement);
}

// Test if the tiles are in a winning position
bool GameplayState::isSuccessful() const
{
	uint8_t index = 0;

	for(uint8_t y = 0; y < 3; ++y)
		for(uint8_t x = 0; x < 3; ++x)
		{
			if(this->tileIndices[y][x] != index)
				return false;

			++index;
		}

	return true;
}

// Reset the game state
void GameplayState::reset()
{
	this->imageTiles = nullptr;
	this->moveCount = 0;
}

// Automatically solve the puzzle
void GameplayState::solve()
{
	uint8_t index = 0;

	for(uint8_t y = 0; y < 3; ++y)
		for(uint8_t x = 0; x < 3; ++x)
		{
			this->tileIndices[y][x] = index;
			++index;
		}
}

// Randomise the tiles
void GameplayState::randomise(uint32_t seed)
{
	Utils::SkullPRNG generator { seed };

	const uint8_t index = (generator() % Utils::getSize(Tiles::tilesets));
	this->imageTiles = static_cast<const uint8_t *>(pgm_read_ptr(&Tiles::tilesets[index]));

	uint8_t indices[9];

	for(uint8_t index = 0; index < 9; ++index)
		indices[index] = index;

	Utils::shuffle(indices, Utils::move(generator));

	uint8_t frameIndex = 0;

	for(uint8_t y = 0; y < 3; ++y)
		for(uint8_t x = 0; x < 3; ++x)
		{
			const uint8_t index = indices[frameIndex];

			if(index == 0)
			{
				this->cursorX = x;
				this->cursorY = y;
			}

			this->tileIndices[y][x] = index;
			++frameIndex;
		}
}

// Draw a grid of plain rectangles
void GameplayState::drawGrid(Arduboy2 & arduboy)
{
	for(uint8_t y = 0; y < 3; ++y)
		for(uint8_t x = 0; x < 3; ++x)
		{
			const int16_t tileX = (gridOffsetX + (x * tileWidth));
			const int16_t tileY = (gridOffsetY + (y * tileHeight));

			arduboy.fillRect(tileX, tileY, tileWidth, tileHeight, BLACK);
			arduboy.drawRect(tileX, tileY, tileWidth, tileHeight, WHITE);
		}
}

// Draw the picture frame around the image
void GameplayState::drawFrame()
{
	constexpr uint8_t frameMarginWidth = 8;
	constexpr uint8_t frameMarginHeight = 8;

	constexpr int16_t drawX = (gridOffsetX - frameMarginWidth);
	constexpr int16_t drawY = (gridOffsetY - frameMarginHeight);

	Sprites::drawOverwrite(drawX, drawY, Images::frame, 0);
}

void GameplayState::drawTiles()
{
	// TODO: consider removing the nullptr check
	if(this->imageTiles == nullptr)
		return;

	for(uint8_t y = 0; y < 3; ++y)
		for(uint8_t x = 0; x < 3; ++x)
		{
			const int16_t drawX = (gridOffsetX + (x * tileWidth));
			const int16_t drawY = (gridOffsetY + (y * tileHeight));

			const uint8_t frameIndex = this->tileIndices[y][x];

			Sprites::drawOverwrite(drawX, drawY, this->imageTiles, frameIndex);
		}
}

// Draws the cursor
void GameplayState::drawCursor(Arduboy2 & arduboy)
{
	// Calculate the top left corner as a reference point
	const int16_t drawX = (gridOffsetX + (this->cursorX * tileWidth));
	const int16_t drawY = (gridOffsetY + (this->cursorY * tileHeight));

	arduboy.fillRect(drawX, drawY, tileWidth, tileHeight, BLACK);
	arduboy.drawRect(drawX, drawY, tileWidth, tileHeight, WHITE);

	this->drawCursorArrows();
}

// Draws arrows indicating the directions in which the tiles can slide
void GameplayState::drawCursorArrows()
{
	// Calculate the top left corner as a reference point
	const int16_t x = (gridOffsetX + (this->cursorX * tileWidth));
	const int16_t y = (gridOffsetY + (this->cursorY * tileHeight));

	constexpr int16_t topX = ((tileWidth /2) - (Images::arrowWidth / 2));
	constexpr int16_t topY = (0 - (Images::arrowWidth / 2));

	// Draw the down arrow at the top
	if(this->cursorY > gridTopIndex)
		Sprites::drawOverwrite(x + topX, y + topY, Images::arrows, Images::arrowDownIndex);

	constexpr int16_t bottomX = ((tileWidth /2) - (Images::arrowWidth / 2));
	constexpr int16_t bottomY = (tileHeight -(Images::arrowWidth / 2));

	// Draw the up arrow at the bottom
	if(this->cursorY < gridBottomIndex)
		Sprites::drawOverwrite(x + bottomX, y + bottomY, Images::arrows, Images::arrowUpIndex);

	constexpr int16_t leftX = (0 - (Images::arrowWidth / 2));
	constexpr int16_t leftY = ((tileHeight /2) - (Images::arrowHeight / 2));

	// Draw the right arrow on the left
	if(this->cursorX > gridLeftIndex)
		Sprites::drawOverwrite(x + leftX, y + leftY, Images::arrows, Images::arrowRightIndex);

	constexpr int16_t rightX = (tileWidth - (Images::arrowWidth / 2));
	constexpr int16_t rightY = ((tileHeight /2) - (Images::arrowHeight / 2));

	// Draw the left arrow on the right
	if(this->cursorX < gridRightIndex)
		Sprites::drawOverwrite(x + rightX, y + rightY, Images::arrows, Images::arrowLeftIndex);
}

// Draw the HUD
void GameplayState::drawHUD(Arduboy2 & arduboy)
{
	arduboy.println(Utils::asFlashStringHelper(Strings::moves));
	arduboy.println(this->moveCount);
}