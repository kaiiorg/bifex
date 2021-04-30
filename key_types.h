#ifndef key_types_h
#define key_types_h
#include <string>

// Many thanks to the Infinity Engine Structures Description Project for this information
// https://gibberlings3.github.io/iesdp/

namespace ie
{
  // Resource types with their code
  // Source: https://gibberlings3.github.io/iesdp/file_formats/general.htm
  enum ResourceType
  {
    TYPE_UNKNOWN = 0x0000,
    TYPE_BMP = 0x0001,
    TYPE_MVE = 0x0002,
    TYPE_WAV = 0x0004,
    TYPE_PLT = 0x0006,
    TYPE_BAM = 0x03e8,
    TYPE_WED = 0x03e9,
    TYPE_CHU = 0x03ea,
    TYPE_TIS = 0x03eb,
    TYPE_MOS = 0x03ec,
    TYPE_ITM = 0x03ed,
    TYPE_SPL = 0x03ee,
    TYPE_BCS = 0x03ef,
    TYPE_IDS = 0x03f0,
    TYPE_CRE = 0x03f1,
    TYPE_ARE = 0x03f2,
    TYPE_DLG = 0x03f3,
    TYPE_2DA = 0x03f4,
    TYPE_GAM = 0x03f5,
    TYPE_STO = 0x03f6,
    TYPE_WMP = 0x03f7,
    //TYPE_CHR2 = 0x03f8,
    TYPE_EFF = 0x03f8,
    TYPE_BC = 0x03f9,
    TYPE_CHR = 0x03fa,
    TYPE_VVC = 0x03fb,
    TYPE_VEF = 0x03fc,
    TYPE_PRO = 0x03fd,
    TYPE_BIO = 0x03fe,
    TYPE_WBM = 0x03ff,
    TYPE_FNT = 0x0400,
    TYPE_GUI = 0x0402,
    TYPE_SQL = 0x0403,
    TYPE_PVRZ = 0x0404,
    TYPE_GLSL = 0x0405,
    TYPE_MENU = 0x0408,
    TYPE_MENU2 = 0x0409,
    TYPE_TTF = 0x040a,
    TYPE_PNG = 0x040b,
    TYPE_BAH = 0x044c,
    TYPE_INI = 0x0802,
    TYPE_SRC = 0x0803
  };

  int ResourceTypeToInt(ResourceType type);
  ResourceType IntToResourceType(int type);
  std::string ResourceTypeToFileExtString(ResourceType type);
}

#endif