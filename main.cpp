#include <iostream>
#include <filesystem>
#include <vector>

namespace fs = std::filesystem;

std::vector<fs::path> getFilesInDirectory(const fs::path& directoryPath) {
  std::vector<fs::path> filesList;
  for (const auto& entry : fs::recursive_directory_iterator(directoryPath)) {
    if (fs::is_regular_file(entry)) {
      filesList.push_back(entry.path());
    }
  }

  return filesList;
}

int main(int argc, const char** argv)
{
  if (argc != 2)
  {
    std::cout << "Wrong nuber of arguments.\n";
    std::cout << "Usage wargaming_test_task <path to dir>\n";
    return -1;
  }

  const fs::path directoryPath = argv[1];

  std::vector<fs::path> files = getFilesInDirectory(directoryPath);

  std::cout << "Files in directory and subdirectories:" << std::endl;

  for (const auto& file : files) {
    std::cout << file << std::endl;
  }

  return 0;
}
