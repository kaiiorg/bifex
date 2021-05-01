#ifndef key_h
#define key_h
#include <iostream>
#include <cstdint>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <filesystem>
namespace fs = std::filesystem;

#include "key_entry.h"
#include "bif.h"

namespace ie
{
  class Key
  {
  private:
    char signature[4];              // File signature string
    char version[4];                // File version string
    uint32_t bifCount;              // Count of bif files in bif file section
    uint32_t resourceCount;         // Count of resource files in resource file section
    uint32_t bifSectionOffset;      // Offset to start of bif file section in the key file
    uint32_t resourceSectionOffset; // Offset to start of resource file section in the key file

    // Data parsed from the key file
    std::vector<KeyBifEntry> bifEntries;
    std::map<uint32_t, std::vector<KeyResourceEntry>> resourceEntries;

    // Data read from various bif files
    std::vector<Bif> bifs;
  
  public:
    Key();
    ~Key();

    bool ReadFromFile(std::ifstream &file);

    bool ReadBifs();

    bool DumpKeyToCsv(std::ofstream &file);
    void DumpKeyBifEntriesToConsole();
    void DumpKeyResourceEntriesToConsole();
  };
}

#endif