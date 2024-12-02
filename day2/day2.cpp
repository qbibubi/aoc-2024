#include "day2.h"

#include <iostream>

#include "../file.h"

namespace Day2
{
    void Part1()
    {
		/*auto example = File::LoadFrom(InputFile);

		std::vector<std::vector<int>> vectors;

		for (auto const& line : example)
		{
			auto splitLine = File::Split(line, " ");
			std::vector<int> temp;

			for (auto const& string : splitLine)
			{
				temp.push_back(StringToInt(string));
			}

			vectors.push_back(temp);
		}

		size_t safeReports = vectors.size();
		for (auto const& vector : vectors)
		{
			bool unsafe = false;

			auto previousDifference = vector[0] - vector[1];
			if (previousDifference == 0)
			{
				--safeReports;
				continue;
			}

			for (size_t i = 1; i < vector.size() - 1; ++i)
			{
				auto const difference = vector[i] - vector[i + 1];
				if (difference == 0)
				{
					unsafe = true;
					break;
				}

				static auto Modulus = [](int const number) -> int {
					return (number < 0) ? number * -1 : number;
				};

				if (Modulus(difference) > 3 || Modulus(previousDifference) > 3)
				{
					unsafe = true;
					break;
				}

				if ((previousDifference < 0 && difference > 0) || (previousDifference > 0 && difference < 0))
				{
					unsafe = true;
					break;
				}

				previousDifference = difference;
			}

			if (!unsafe)
			{
				for (auto const& n : vector)
				{
					std::cout << n << " ";
				}
				std::cout << std::endl;
			}

			if (unsafe)
			{
				--safeReports;
			}
		}

		std::cout << safeReports;*/
    }

    void Part2()
    {
    }
}