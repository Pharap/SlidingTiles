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

namespace Utils
{
	constexpr int16_t calculateCentreOffset(uint8_t innerDimension, uint8_t outerDimension)
	{
		return ((static_cast<int16_t>(outerDimension) - static_cast<int16_t>(innerDimension)) / 2);
	}

	constexpr int16_t calculateCentreOffsetX(uint8_t innerWidth, uint8_t outerWidth)
	{
		return calculateCentreOffset(innerWidth, outerWidth);
	}

	constexpr int16_t calculateCentreOffsetY(uint8_t innerHeight, uint8_t outerHeight)
	{
		return calculateCentreOffset(innerHeight, outerHeight);
	}
}