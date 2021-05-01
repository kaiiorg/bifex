#include <iostream>
#include <fstream>
#include <cstdint>
#include <string>
#include <vector>

#include <filesystem>
namespace fs = std::filesystem;

#include "key.h"

fs::path keyFilePath("./test_data/chitin.key");
fs::path outputCsvPath("./test_data/output.csv");

void usage();
void dump(ie::Key key);
void keyFileExists(fs::path keyFilePath);

int main(int argc, char **argv)
{
  keyFileExists(keyFilePath);
  // Open the key file
  std::ifstream keyFileStream;
  keyFileStream.open(keyFilePath, std::ios::binary | std::ios::in);
  // Create the key object
  ie::Key key;

  // Parse the key file
  bool key_parse_success = key.ReadFromFile(keyFileStream);
  // Read the bif files
  bool bif_parse_success = key.ReadBifs();

  std::cout << "Successfully parsed the key file: " << key_parse_success << std::endl;
  std::cout << "Successfully parsed bif files: " << bif_parse_success << std::endl;

  dump(key);

  return 0;
}

void usage()
{
}

void dump(ie::Key key)
{
  //key.DumpKeyBifEntriesToConsole();
  //key.DumpKeyResourceEntriesToConsole();
  /*
  std::ofstream outputCsvStream;
  outputCsvStream.open(outputCsvPath);
  key.DumpKeyToCsv(outputCsvStream);
  outputCsvStream.close();
  */
}

void keyFileExists(fs::path keyFilePath)
{
  // Make sure the key file exists
  if (!fs::exists(keyFilePath))
  {
    std::cout << "The key file " << keyFilePath << " does not exist!" << std::endl;
    exit(1);
  }
  else
  {
    std::cout << "Found key file " << keyFilePath << std::endl;
  }
}