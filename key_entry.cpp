#include "key_entry.h"

namespace ie
{
  KeyBifEntry::KeyBifEntry() {}
  KeyBifEntry::~KeyBifEntry() {}

  bool KeyBifEntry::ReadFromFile(std::ifstream &file)
  {
    file.read((char *)&size, 4);
    file.read((char *)&name_offset, 4);
    file.read((char *)&name_length, 2);
    file.read((char *)&location_bitfield, 2);

    // Get the current file pointer postion
    int current_pos = file.tellg();

    // Seek to the position of the name
    file.seekg(name_offset);

    // Read the name in
    std::getline(file, name, '\0');

    // Seek back to the position we left off at
    file.seekg(current_pos);

    return true;
  }

  uint32_t KeyBifEntry::GetSize()
  {
    return size;
  }
  std::string KeyBifEntry::GetName()
  {
    return name;
  }

  KeyResourceEntry::KeyResourceEntry() {}
  KeyResourceEntry::~KeyResourceEntry() {}

  bool KeyResourceEntry::ReadFromFile(std::ifstream &file)
  {
    char temp_resource_name[8];
    file.read((char *)&temp_resource_name, 8);
    file.read((char *)&raw_type, 2);
    file.read((char *)&raw_resource_locator, 4);

    type = IntToResourceType(raw_type);
    for (int i = 0; i < 8; i++)
    {
      if (temp_resource_name[i] == ' ' || temp_resource_name[i] == '\0')
        break;
      resource_name += temp_resource_name[i];
    }

    // Parse out the source_index, tileset_index, nontileset_index
    /*
    A: bits 31-20: source index (the ordinal value giving the index of the corresponding BIF entry)
    B: bits 19-14: tileset index
    C: bits 13- 0: non-tileset file index (any 12 bit value, so long as it matches the value used in the BIF file)

    AAAAAAAAAAABBBBBBBCCCCCCCCCCCCCC
    11111111111000000000000000000000, 0xffe00000
    00000000000111111100000000000000, 0x1fc000
    00000000000000000011111111111111, 0x3ff
    */
    source_index = (raw_resource_locator & 0xffe00000) >> 21;
    tileset_index = (raw_resource_locator & 0x1fc000) >> 14;
    nontileset_index = raw_resource_locator & 0x3ff;

    return true;
  }

  uint16_t KeyResourceEntry::GetSourceIndex()
  {
    return source_index;
  }

  std::string KeyResourceEntry::GetType()
  {
    return ResourceTypeToFileExtString(type);
  }

  std::string KeyResourceEntry::GetName()
  {
    return resource_name;
  }

  std::string KeyResourceEntry::GetFullFileName()
  {
    return GetName() + GetType();
  }
}