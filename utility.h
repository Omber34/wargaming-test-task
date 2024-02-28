#pragma once

#include <vector>
#include <string>
#include <filesystem>

std::vector<std::vector<std::filesystem::path>> findSimilarFileSets(const std::filesystem::path& directoryPath);

