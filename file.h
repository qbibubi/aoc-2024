#pragma once

#include <string>
#include <string_view>
#include <vector>

namespace File
{
    constinit std::string_view ExampleFile = "example.txt";
    constinit std::string_view InputFile = "input.txt";

    [[nodiscard]] std::vector<std::string> LoadFrom(std::string_view filename);
    [[nodiscard]] std::vector<std::string> Split(std::string string, std::string_view delimiter);
}