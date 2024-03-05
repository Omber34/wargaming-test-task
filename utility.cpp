#include "utility.h"
#include <fstream>
#include <map>

#include <string>
#include <future>
#include <vector>

#include "md5.h"

namespace
{
  namespace fs = std::filesystem;

  std::string getFileMD5Hash(const fs::path& filePath)
  {
    std::ifstream file(filePath, std::ios::binary | std::ios::in);

    if (!file.is_open())
      throw std::logic_error("Can't open file: " + filePath.string() + ".");

    const auto fragmentSize = 512U;
    std::string fileContent;
    fileContent.resize(fragmentSize);
    MD5 hash;

    while (!file.eof())
    {
      file.read(&fileContent[0], fragmentSize);
      const auto readSize = file.gcount();
      hash.update(fileContent.c_str(), readSize);
    }
    hash.finalize();

    return hash.hexdigest();
  }

  std::vector<fs::path> getAbsPathsInDirectory(const fs::path& directoryPath) {
    std::vector<fs::path> filesList;
    for (const auto& entry : fs::recursive_directory_iterator(directoryPath)) {
      if (fs::is_regular_file(entry)) {
        filesList.push_back(fs::absolute(entry.path()));
      }
    }

    return filesList;
  }
}

std::vector<std::vector<std::filesystem::path>> findSimilarFileSets(const std::filesystem::path &directoryPath)
{
  std::vector<fs::path> files = getAbsPathsInDirectory(directoryPath);

  std::map<std::string, std::vector<fs::path>> hashToPaths;
  for (const auto& filePath: files)
  {
    const auto hash = getFileMD5Hash(filePath);
    hashToPaths[hash].push_back(filePath);
  }

  std::vector<std::vector<fs::path>> result;
  for (const auto& [_, paths] : hashToPaths) {
    if (paths.size() > 1)
      result.push_back(paths);
  }

  return result;
}

