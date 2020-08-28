#pragma once

namespace Strings
{
	constexpr char pharap[] PROGMEM = "Pharap";
	constexpr char dreamer2345[] PROGMEM = "Dreamer2345";

	constexpr const char * programmers[] PROGMEM
	{
		pharap,
	};

	constexpr const char * artists[] PROGMEM
	{
		dreamer2345,
		pharap,
	};

	constexpr char licenceName[] PROGMEM = "Apache Licence 2.0";
}