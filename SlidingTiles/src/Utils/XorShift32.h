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
	template<uint32_t x, uint32_t y, uint32_t z>
	uint32_t xorshift32(uint32_t state)
	{
		state ^= (state << x);
		state ^= (state >> y);
		state ^= (state << z);
		return state;
	}

	template<uint32_t x, uint32_t y, uint32_t z>
	class XorShift32
	{
	public:
		using result_type = uint32_t;

	public:
		static constexpr result_type (min)() { return 0; }
		static constexpr result_type (max)() { return ~0; }

	private:
		result_type initialState;
		result_type state;

	public:
		constexpr XorShift32() :
			initialState { 1 }, state { 1 }
		{
		}

		constexpr XorShift32(result_type seed) :
			initialState { seed }, state { seed }
		{
		}

		template<typename SeedSequence>
		XorShift32(SeedSequence sequence)
		{
			sequence.generate(&this->initialState, &this->initialState + 1);
			this->state = this->initialState;
		}

		void seed()
		{
			this->initialState = 1;
			this->state = 1;
		}

		void seed(result_type newSeed)
		{
			this->initialState = newSeed;
			this->state = newSeed;
		}

		template<typename SeedSequence>
		void seed(SeedSequence sequence)
		{
			sequence.generate(&this->initialState, &this->initialState + 1);
			this->state = this->initialState;
		}
		
		void discard(unsigned long long count)
		{
			for(unsigned long long counter = 0; counter < count; ++counter)
				this->state = xorshift32<x, y, z>(this->state);
		}

		result_type operator ()()
		{
			this->state = xorshift32<x, y, z>(this->state);
			return this->state;
		}

		friend bool operator ==(const XorShift32<x, y, z> & left, const XorShift32<x, y, z> & right)
		{
			return (left.state == right.state);
		}

		friend bool operator !=(const XorShift32<x, y, z> & left, const XorShift32<x, y, z> & right)
		{
			return (left.state != right.state);
		}
	};

	using SkullPRNG = XorShift32<13, 17, 5>;
}