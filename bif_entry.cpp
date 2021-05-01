#include "bif_entry.h"

namespace ie
{
  BifEntry::BifEntry() {}
  BifEntry::~BifEntry() {}

  void BifEntry::ReadFromFile(std::ifstream &file, bool is_tileset)
  {
    file.read((char *)&resource_locator, 4);
    file.read((char *)&offset, 4);
    if (is_tileset)
      file.read((char *)&tile_count, 4);
    file.read((char *)&size, 4);
    file.read((char *)&raw_type, 2);
    file.read((char *)&pad, 2);

    type = IntToResourceType(raw_type);
  }

  uint32_t BifEntry::GetResourceLocator()
  {
    return resource_locator;
  }

  uint32_t BifEntry::GetSize()
  {
    return size;
  }

  std::string BifEntry::GetType()
  {
    return ResourceTypeToFileExtString(type);
  }

  bool BifEntry::SaveResourceToFile()
  {
    return true;
  }

}