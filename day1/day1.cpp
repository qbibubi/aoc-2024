#include "day1.h"

#include "../file.h"

#include <charconv>
#include <vector>
#include <iostream>
#include <algorithm>

namespace
{	
	using namespace std::string_view_literals;

	constinit auto ExampleFile = "example.txt"sv;
	constinit auto InputFile = "input.txt"sv;

	[[nodiscard]] std::pair<std::vector<int>, std::vector<int>> ParseInput(std::vector<std::string> const& input)
	{
		std::pair<std::vector<int>, std::vector<int>> result{};

		for (auto const& line : input)
		{
			auto numberStrings = File::Split(line, "   ");

			for (auto i = 0; i < 2; ++i)
			{
				auto& numberString = numberStrings[i];

				int number{};
				std::from_chars(numberString.data(), numberString.data() + numberString.size(), number);

				if (i == 0)
				{
					result.first.push_back(number);
				}
				else
				{
					result.second.push_back(number);
				}
			}
		}

		return result;
	}
}

void Day1::Part1()
{
	auto example = File::LoadFrom(InputFile);
	auto parsedExample = ParseInput(example);

	auto& left = parsedExample.first;
	auto& right = parsedExample.second;

	std::sort(left.begin(), left.end());
	std::sort(right.begin(), right.end());

	auto result = 0u;
	for (size_t i = 0; i < parsedExample.first.size(); ++i)
	{
		auto difference = left[i] - right[i];
		if (difference < 0)
		{
			difference *= -1;
		}

		result += difference;
	}

	std::cout << result << std::endl;
}

void Day1::Part2()
{
	auto example = File::LoadFrom(InputFile);
	auto parsedExample = ParseInput(example);

	auto& left = parsedExample.first;
	auto& right = parsedExample.second;

	std::vector<int> similarityScoreNumbers{};

	for (auto const& leftNumber : left)
	{
		auto occurences = 0;

		for (auto const& rightNumber : right)
		{
			if (rightNumber != leftNumber)
			{
				continue;
			}

			occurences += 1;
		}

		similarityScoreNumbers.push_back(leftNumber * occurences);
	}

	auto result = 0;
	for (auto const& number : similarityScoreNumbers)
	{
		result += number;
	}

	std::cout << result;
}
