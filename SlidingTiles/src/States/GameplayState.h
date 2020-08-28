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

#include "../Utils.h"

enum class GameplaySubstate : uint8_t
{
	Ready,
	Playing,
	Victory,
};

class Game;

class GameplayState
{
public:
	static constexpr uint8_t tileWidth = 16;
	static constexpr uint8_t tileHeight = 16;

private:
	static constexpr uint8_t gridWidth = 3;
	static constexpr uint8_t gridHeight = 3;
	static constexpr uint8_t gridTopIndex = 0;
	static constexpr uint8_t gridBottomIndex = 2;
	static constexpr uint8_t gridLeftIndex = 0;
	static constexpr uint8_t gridRightIndex = 2;

	static constexpr uint8_t gridRenderWidth = (gridWidth * tileWidth);
	static constexpr uint8_t gridRenderHeight = (gridHeight * tileHeight);

	static constexpr uint8_t gridCentredX = Utils::calculateCentreOffsetX(gridRenderWidth, Arduboy2::width());
	static constexpr uint8_t gridCentredY = Utils::calculateCentreOffsetY(gridRenderHeight, Arduboy2::height());

	static constexpr uint8_t gridOffsetX = gridCentredX;
	static constexpr uint8_t gridOffsetY = gridCentredY;

private:
	GameplaySubstate state = GameplaySubstate::Ready;
	const uint8_t * imageTiles = nullptr;
	uint8_t tileIndices[gridHeight][gridWidth];
	uint8_t cursorX;
	uint8_t cursorY;
	uint32_t moveCount;

public:
	void update(Game & game);
	void render(Game & game);

private:
	void updateReadyState(Game & game);
	void updatePlayingState(Game & game);
	void updateVictoryState(Game & game);

private:
	void drawReadyState(Game & game);
	void drawPlayingState(Game & game);
	void drawVictoryState(Game & game);

private:
	bool isSuccessful() const;
	void reset();
	void solve();
	void randomise(uint32_t seed);

private:
	void drawGrid(Arduboy2 & arduboy);
	void drawFrame();
	void drawTiles();
	void drawCursor(Arduboy2 & arduboy);
	void drawCursorArrows();
	void drawHUD(Arduboy2 & arduboy);
};