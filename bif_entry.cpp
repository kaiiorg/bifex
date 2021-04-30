#include "bif_entry.h"

namespace ie
{
  BifEntry::BifEntry() {}
  BifEntry::~BifEntry() {}

  void BifEntry::SetDataFromFile() {}

  uint32_t BifEntry::GetResourceLocator()
  {
    return resource_locator;
  }

  uint32_t BifEntry::GetSize()
  {
    return size;
  }

  bool BifEntry::SaveResourceToFile()
  {
    return true;
  }

}