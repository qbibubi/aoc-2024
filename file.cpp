#include "file.h"

#include <fstream>
#include <iostream>
#include <format>

namespace File
{
    std::vector<std::string> LoadFrom(std::string_view filename)
    {
		std::fstream input(filename.data(), std::ios::in | std::ios::binary);
		if (!input)
		{
			std::cout << std::format("Failed to open\n");
			return {};
		}

		std::vector<std::string> result{};
		std::string line{};
		while (std::getline(input, line))
		{
			result.push_back(line);
		}

		return result;
    }

    std::vector<std::string> Split(std::string string, std::string_view delimiter)
    {
		std::vector<std::string> result{};

		size_t startPosition = 0;
		size_t endPosition;

		std::string token{};
		while ((endPosition = string.find(delimiter, startPosition)) != std::string::npos)
		{
			token = string.substr(startPosition, endPosition - startPosition);
			startPosition = endPosition + delimiter.length();
			result.push_back(token);
		}

		result.push_back(string.substr(startPosition));
		return result;
    }
}
