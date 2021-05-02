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
      resourceEntries[keyResourceEntry.GetSourceIndex()].push_back(keyResourceEntry);
    }

    return true;
  }

  bool Key::ReadBifs()
  {
    int existCount = 0;
    int notExistCount = 0;
    // Read the bif entry information from each bif file
    for (int i = 0; i < resourceEntries.size(); i++)
    {
      fs::path basePath("./test_data");
      fs::path bifPath(bifEntries[i].GetName());
      basePath /= bifPath;
      if (fs::exists(basePath))
      {
        std::ifstream bifFile;
        bifFile.open(basePath, std::ios::binary | std::ios::in);
        Bif bif;
        bif.ReadFromFile(bifFile);
        bifs.push_back(bif);
      }
    }

    std::cout << "Files exist: " << existCount << std::endl;
    std::cout << "Files not exist: " << notExistCount << std::endl;

    return true;
  }

  bool Key::ExtractAllBifs(fs::path outdir)
  {
    // Check that a dir exists at the outdir location
    if (!fs::exists(outdir) || !fs::is_directory(outdir))
      return false;

    // Loop through each bif file
    for (int i = 0; i < resourceEntries.size(); i++)
    {
      // Build the output directory path
      fs::path bdir = outdir / bifEntries[i].GetName();
      // If the output directory doesn't exist, make it
      if (!fs::exists(bdir))
      {
        std::cout << "Making directories for " << bdir << std::endl;
        fs::create_directories(bdir);
      }
      // If the output path isn't a directory, something has gone wrong; skip this bif file.
      if (!fs::is_directory(bdir))
        continue;
      
      // Open the bif file
      


      // Loop through each resource for this bif file and extract it
      for (int j = 0; j < resourceEntries[i].size(); j++)
      {
        // Build the path
        fs::path outputFilePath = bdir / resourceEntries[i][j].GetFullFileName();
        // Open the output file
        std::ofstream &outFile(outputFile, std::ios::binary);
      }
    }

    return true;
  }

  bool Key::DumpKeyToCsv(std::ofstream &file)
  {
    file << "Resource Entry,File Name,Bif File" << std::endl;
    for (int i = 0; i < resourceEntries.size(); i++)
    {
      for (int j = 0; j < resourceEntries[i].size(); j++)
      {
        uint16_t source_index = resourceEntries[i][j].GetSourceIndex();
        file << i << "-" << j << "," << resourceEntries[i][j].GetFullFileName() << "," << bifEntries[source_index].GetName() << std::endl;
      }
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
      for (int j = 0; j < resourceEntries[i].size(); j++)
      {
        std::cout << "\tResource Entry #" << i << "-" << j << ":" << std::endl;
        std::cout << "\tFile Name: " << resourceEntries[i][j].GetFullFileName() << std::endl
                  << std::endl;
      }
    }
  }
}