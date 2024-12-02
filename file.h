#pragma once

#include <string>
#include <string_view>
#include <vector>

namespace File
{
    [[nodiscard]] std::vector<std::string> LoadFrom(std::string_view filename);
    [[nodiscard]] std::vector<std::string> Split(std::string string, std::string_view delimiter);
}