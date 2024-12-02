#include "file.h"

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
#include <optional>

namespace
{
	using namespace std::string_view_literals;

	[[maybe_unused]] constinit auto ExampleFile = "day2/example.txt"sv;
	[[maybe_unused]] constinit auto InputFile = "day2/input.txt"sv;
	[[maybe_unused]] constinit auto CustomFile = "day2/custom.txt"sv;

	[[nodiscard]] int StringToInt(std::string const& string)
	{
		int number{};
		std::from_chars(string.data(), string.data() + string.size(), number);

		return number;
	}

	[[nodiscard]] bool IsVectorUnsafe(std::vector<int> const& vector)
	{
		static auto Modulus = [](int const number) -> int { 
			return (number < 0) ? number * -1 : number; 
		};

		std::optional<int> previous = std::nullopt;
		for (size_t i = 0; i < vector.size() - 1; ++i)
		{
			if (!previous)
			{
				previous = vector[i] - vector[i + 1];
			}

			if (*previous == 0)
			{
				return true;
			}

			auto const current = vector[i] - vector[i + 1];
			if (current == 0)
			{
				return true;
			}

			if (Modulus(current) > 3 || Modulus(*previous) > 3)
			{
				return true;
			}

			if ((*previous < 0 && current > 0) || (*previous > 0 && current < 0))
			{
				return true;
			}

			*previous = current;
		}

		return false;
	}

	template<typename T>
	void PrintVec(std::vector<T> const& vec)
	{
		for (auto const v : vec)
		{
			std::cout << v << " ";
		}
		std::cout << std::endl;
	}
}

int main()
{
	auto example = File::LoadFrom(CustomFile);

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

	size_t safeReports = 0;
	for (auto const& vector : vectors)
	{
		bool unsafe = IsVectorUnsafe(vector);
		if (!unsafe)
		{
			++safeReports;
			continue;
		}

		std::vector<int> badLevelPositions{};
		std::optional<int> previous = std::nullopt;
		for (size_t i = 0; i < vector.size() - 1; ++i)
		{
			if (!previous)
			{
				previous = vector[i] - vector[i + 1];
				if (*previous == 0)
				{
					badLevelPositions.push_back(i);
					continue;
				}				
			}

			auto const current = vector[i] - vector[i + 1];
			if (current == 0)
			{
				badLevelPositions.push_back(i);
			}

			static auto Modulus = [](int const number) -> int { return (number < 0) ? number * -1 : number; };
			if (Modulus(current) > 3 || Modulus(*previous) > 3)
			{
				badLevelPositions.push_back(i);
			}

			if ((*previous < 0 && current > 0) || (*previous > 0 && current < 0))
			{
				badLevelPositions.push_back(i);
			}
					
			previous = current;
		}

		for (auto const& number: badLevelPositions)
		{
			auto copy = vector;
			copy.erase(copy.begin() + number);

			unsafe = IsVectorUnsafe(copy);
			if (!unsafe)
			{
				PrintVec(copy);
				++safeReports;
				break;
			}
		}
	}

	std::cout << safeReports;
	return 0;
}
