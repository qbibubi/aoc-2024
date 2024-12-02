#include <iostream>
#include <cstdint>
#include <fstream>
#include <iomanip>
#include <vector>
#include <array>
#include <list>
#include <unordered_map>
#include <string>
#include <string_view>
#include <format>
#include <algorithm>
#include <charconv>

#include "file.h"

#include "day1/day1.h"
#include "day2/day2.h"

namespace
{
	using namespace std::string_view_literals;

	constinit auto ExampleFile = "example.txt"sv;
	constinit auto InputFile = "input.txt"sv;

	[[nodiscard]] int StringToInt(std::string const& string)
	{
		int number{};
		std::from_chars(string.data(), string.data() + string.size(), number);

		return number;
	}
}

int main()
{
	auto example = File::LoadFrom(ExampleFile);

	std::vector<std::vector<int>> vectors;

	for (auto const& line : example)
	{
		auto splitLine = File::Split(line , " ");
		std::vector<int> temp;
		
		for (auto const& string : splitLine)
		{
			temp.push_back(StringToInt(string));
		}

		vectors.push_back(temp);
	}



}
