#pragma once

#include <stdint.h>

enum class GameState : uint8_t
{
	SplashScreen,
	TitleScreen,
	Gameplay,
	Credits,
};