#include "key.h"

namespace ie
{
  Key::Key() {}
  Key::~Key() {}

  bool Key::ReadFromFile(std::ifstream &file)
  {
    file.read((char *)&signature, 4);
    file.read((char *)&version, 4);
    file.read((char *)&bifCount, 4);
    file.read((char *)&resourceCount, 4);
    file.read((char *)&bifSectionOffset, 4);
    file.read((char *)&resourceSectionOffset, 4);

    std::cout << "Key file statistics: " << std::endl;
    std::cout << "\tSignature: " << signature[0] << signature[1] << signature[2] << signature[3] << std::endl;
    std::cout << "\tVersion: " << version[0] << version[1] << version[2] << version[3] << std::endl;
    std::cout << "\tBif Count: " << bifCount << std::endl;
    std::cout << "\tResource Count: " << resourceCount << std::endl;
    std::cout << "\tBif Section Offset: " << bifSectionOffset << std::endl;
    std::cout << "\tResource Section Offset: " << resourceSectionOffset << std::endl
              << std::endl;

    // Skip to the bif section
    file.seekg(bifSectionOffset);
    // Loop through each bif file resource and read them in
    for (int i = 0; i < bifCount; i++)
    {
      KeyBifEntry keyBifEntry;
      keyBifEntry.ReadFromFile(file);
      bifEntries.push_back(keyBifEntry);
    }

    // Skip to the resource section
    file.seekg(resourceSectionOffset);

    // Loop through each resource and read them in
    for (int i = 0; i < resourceCount; i++)
    {
      KeyResourceEntry keyResourceEntry;
      keyResourceEntry.ReadFromFile(file);
      resourceEntries.push_back(keyResourceEntry);
    }

    return true;
  }

  bool Key::DumpKeyToCsv(std::ofstream &file)
  {
    file << "Resource Entry,File Name,Bif File" << std::endl;
    for (int i = 0; i < resourceEntries.size(); i++)
    {
      uint16_t source_index = resourceEntries[i].GetSourceIndex();
      file << i << "," << resourceEntries[i].GetFullFileName() << "," << bifEntries[source_index].GetName() << std::endl;
    }

    return true;
  }

  void Key::DumpKeyBifEntriesToConsole()
  {
    std::cout << "Key bif entries: " << std::endl;
    for (int i = 0; i < bifEntries.size(); i++)
    {
      std::cout << "\tBif Entry #" << i + 1 << ":" << std::endl;
      std::cout << "\tSize: " << bifEntries[i].GetSize() << std::endl;
      std::cout << "\tName: " << bifEntries[i].GetName() << std::endl
                << std::endl;
    }
  }

  void Key::DumpKeyResourceEntriesToConsole()
  {
    std::cout << "Key resource entries: " << std::endl;
    for (int i = 0; i < resourceEntries.size(); i++)
    {
      std::cout << "\tResource Entry #" << i + 1 << ":" << std::endl;
      std::cout << "\tFile Name: " << resourceEntries[i].GetFullFileName() << std::endl
                << std::endl;
    }
  }
}