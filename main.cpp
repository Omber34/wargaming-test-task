#include "utility.h"

#include <iostream>


int main(int argc, const char** argv)
{
  if (argc != 2)
  {
    std::cout << "Wrong nuber of arguments.\n";
    std::cout << "Usage wargaming_test_task <path to dir>\n";
    return -1;
  }

  const std::filesystem::path directoryPath = argv[1];
  if (!std::filesystem::is_directory(directoryPath))
  {
    std::cerr << directoryPath << " is not a path to existing directory.";
    return -1;
  }

  try
  {
    const auto similarFileSets = findSimilarFileSets(directoryPath);

    for (const auto& fileSet: similarFileSets)
    {
      for (const auto& file: fileSet)
        std::cout << file << "\n";

      std::cout << "---------------------------------\n";
    }
  }
  catch (const std::exception& error)
  {
    std::cerr << error.what() << "\n";
    return -2;
  }

  return 0;
}

