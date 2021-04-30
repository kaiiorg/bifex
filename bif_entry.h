#ifndef bif_entry_h
#define bif_entry_h
#include <cstdint>
#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;

namespace ie
{
  class BifEntry
  {
  private:
    uint32_t resource_locator; // Locator index from the key file
    uint32_t offset;           // Offset from the start of the bif file to find this entry
    uint32_t size;             // Size in bytes of this entry
    uint16_t type;             // The type of this entry, see key_types.h
    uint16_t pad;              // IESDP labels this as unknown, but I think it might just be for padding

    uint32_t tile_count; // Only used if type == TYPE_TIS

  public:
    BifEntry();
    ~BifEntry();
    void SetDataFromFile();
    uint32_t GetResourceLocator();
    uint32_t GetSize();
    bool SaveResourceToFile();
  };
}

#endif