#include <iostream>
#include "utility.h"

int main(int argc, const char** argv)
{
  if (argc != 2)
  {
    std::cout << "Wrong nuber of arguments.\n";
    std::cout << "Usage wargaming_test_task <path to dir>\n";
    return -1;
  }

  const std::filesystem::path directoryPath = argv[1];

  const auto similarFileSets = findSimilarFileSets(directoryPath);

  for (const auto& fileSet: similarFileSets)
  {
    for (const auto& file: fileSet)
      std::cout << file << "\n";

    std::cout << "---------------------------------\n";
  }

  return 0;
}

