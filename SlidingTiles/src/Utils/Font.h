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

#include "Layout.h"

namespace Utils
{
	namespace Font
	{
		constexpr uint8_t glyphWidth = 6;
		constexpr uint8_t glyphHeight = 8;

		template<size_t size>
		constexpr size_t calculateStringWidth(const char (&)[size])
		{
			return (((size - 1) * glyphWidth) - 1);
		}

		template<size_t size>
		constexpr size_t calculateStringHeight(const char (&)[size])
		{
			return (glyphHeight - 1);
		}

		template<size_t size>
		constexpr int16_t calculateCentreOffsetX(const char (& string)[size], uint8_t width)
		{
			return Utils::calculateCentreOffsetX(calculateStringWidth(string), width);
		}

		template<size_t size>
		constexpr int16_t calculateCentreOffsetY(const char (&)[size], uint8_t height)
		{
			return Utils::calculateCentreOffsetY(glyphHeight, height);
		}
	}
}