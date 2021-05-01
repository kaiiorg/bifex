#ifndef bif_entry_h
#define bif_entry_h
#include <cstdint>
#include <string>
#include <iostream>
#include <fstream>

#include "key_types.h"

namespace ie
{
  class BifEntry
  {
  private:
    uint32_t resource_locator; // Locator index from the key file
    uint32_t offset;           // Offset from the start of the bif file to find this entry
    uint32_t size;             // Size in bytes of this entry
    uint16_t raw_type;         // The type of this entry, see key_types.h
    uint16_t pad;              // IESDP labels this as unknown, but I think it might just be for padding

    uint32_t tile_count; // Only used if type == TYPE_TIS, but we have to know this beforehand for some stupid reason

    ResourceType type;
  public:
    BifEntry();
    ~BifEntry();
    void ReadFromFile(std::ifstream &file, bool is_tileset = false);
    uint32_t GetResourceLocator();
    uint32_t GetSize();
    std::string GetType();
    bool SaveResourceToFile();
  };
}

#endif