#ifndef key_entry_h
#define key_entry_h
#include <cstdint>
#include <string>
#include <iostream>
#include <fstream>

#include "key_types.h"

namespace ie
{
  class KeyBifEntry
  {
  private:
    const uint32_t byte_count = 12;
    // Length of bif file
    uint32_t size;
    // Offset to the start of the bif file's name in the key file
    uint32_t name_offset;
    // Length of the bif file's name including \0
    uint16_t name_length;
    // This isn't used, but its here if we need it
    // (MSB) xxxx xxxx ABCD EFGH (LSB)
    // Bits marked A to F determine on which CD the file is stored (A = CD6, F = CD1)
    // Bit G determines if the file is in the \cache directory
    // Bit H determines if the file is in the \data directory
    uint16_t location_bitfield;

    // The parsed information from the data above:
    std::string name;

  public:
    KeyBifEntry();
    ~KeyBifEntry();

    bool ReadFromFile(std::ifstream &file);

    uint32_t GetSize();
    std::string GetName();
  };

  class KeyResourceEntry
  {
  private:
    const uint32_t byte_count = 12;
    std::string resource_name;         // Name of resource, up to 8 characters long
    uint16_t raw_type;                 // Type of resource. See key_types.h
    uint32_t raw_resource_locator; // The raw resource locator, has the source index, tileset index, and the nontileset index imbeded in it

    // The parsed information from the data above:
    ResourceType type;
    uint16_t source_index; // Index of the bif file entry this resource belongs to
    uint16_t tileset_index;
    uint16_t nontileset_index;

  public:
    KeyResourceEntry();
    ~KeyResourceEntry();

    bool ReadFromFile(std::ifstream &file);
    uint16_t GetSourceIndex();
    std::string GetType();
    std::string GetName();
    std::string GetFullFileName();
  };
}

#endif