#ifndef bif_h
#define bif_h
#include <cstdint>
#include <vector>
#include <iostream>
#include <fstream>

#include "bif_entry.h"

namespace ie
{
  class Bif
  {
  private:
    char signature[4];     // File signature string
    char version[4];       // File version string
    uint32_t fileCount;    // Count of files in file section
    uint32_t tilesetCount; // Count of tileset files in tileset file section
    uint32_t fileOffset;   // Offset to start of file section in the bif file

    // Data parsed from the bif file
    std::vector<BifEntry> fileEntries;

  public:
    Bif();
    ~Bif();

    bool ReadFromFile(std::ifstream &file);

    void DumpFileEntriesToConsole();
  };
}

#endif