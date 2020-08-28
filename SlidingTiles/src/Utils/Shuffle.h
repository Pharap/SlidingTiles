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

#include <stddef.h>

#include "Swap.h"

namespace Utils
{
	template<typename Type, size_t size, typename PRNG>
	void shuffle(Type (& array)[size], PRNG && generator)
	{
		for(size_t index = (size - 1); index > 0; --index)
		{
			using Utils::swap;
			const size_t otherIndex = static_cast<size_t>(generator() % (index + 1));
			swap(array[index], array[otherIndex]);
		}
	}
}