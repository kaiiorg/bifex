#include "bif.h"

namespace ie
{
  Bif::Bif() {}
  Bif::~Bif() {}

  bool Bif::ReadFromFile(std::ifstream &file)
  {
    file.read((char *)&signature, 4);
    file.read((char *)&version, 4);
    file.read((char *)&fileCount, 4);
    file.read((char *)&tilesetCount, 4);
    file.read((char *)&fileOffset, 4);

    // Skip to the file entry section
    file.seekg(fileOffset);
    // Loop through each file and read the entry information in, but not the actual data itself
    for (int i = 0; i < fileCount; i++)
    {
      BifEntry bifEntry;
      bifEntry.ReadFromFile(file);
      fileEntries.push_back(bifEntry);
    }

    // We should be at the tileset section now
    for (int i = 0; i > tilesetCount; i++)
    {
      BifEntry bifEntry;
      bifEntry.ReadFromFile(file, true);
      fileEntries.push_back(bifEntry);
    }

    return true;
  }

  void Bif::DumpFileEntriesToConsole() {
    std::cout << "File entries: " << std::endl;
    for (int i = 0; i < fileEntries.size(); i++) {
      std::cout << "\tFile entry #" << i + 1 << ":" << std::endl;
      std::cout << "\tSize: " << fileEntries[i].GetSize() << std::endl;
      std::cout << "\tType: " << fileEntries[i].GetType() << std::endl;
    }
  }
}