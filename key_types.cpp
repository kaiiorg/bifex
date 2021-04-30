#include "key_types.h"

namespace ie
{
  int ResourceTypeToInt(ResourceType type)
  {
    return type;
  }

  ResourceType IntToResourceType(int type)
  {
    switch (type)
    {
    case TYPE_BMP:
      return TYPE_BMP;
    case TYPE_MVE:
      return TYPE_MVE;
    case TYPE_WAV:
      return TYPE_WAV;
    case TYPE_PLT:
      return TYPE_PLT;
    case TYPE_BAM:
      return TYPE_BAM;
    case TYPE_WED:
      return TYPE_WED;
    case TYPE_CHU:
      return TYPE_CHU;
    case TYPE_TIS:
      return TYPE_TIS;
    case TYPE_MOS:
      return TYPE_MOS;
    case TYPE_ITM:
      return TYPE_ITM;
    case TYPE_SPL:
      return TYPE_SPL;
    case TYPE_BCS:
      return TYPE_BCS;
    case TYPE_IDS:
      return TYPE_IDS;
    case TYPE_CRE:
      return TYPE_CRE;
    case TYPE_ARE:
      return TYPE_ARE;
    case TYPE_DLG:
      return TYPE_DLG;
    case TYPE_2DA:
      return TYPE_2DA;
    case TYPE_GAM:
      return TYPE_GAM;
    case TYPE_STO:
      return TYPE_STO;
    case TYPE_WMP:
      return TYPE_WMP;
    case TYPE_EFF:
      return TYPE_EFF;
    case TYPE_BC:
      return TYPE_BC;
    case TYPE_CHR:
      return TYPE_CHR;
    case TYPE_VVC:
      return TYPE_VVC;
    case TYPE_VEF:
      return TYPE_VEF;
    case TYPE_PRO:
      return TYPE_PRO;
    case TYPE_BIO:
      return TYPE_BIO;
    case TYPE_WBM:
      return TYPE_WBM;
    case TYPE_FNT:
      return TYPE_FNT;
    case TYPE_GUI:
      return TYPE_GUI;
    case TYPE_SQL:
      return TYPE_SQL;
    case TYPE_PVRZ:
      return TYPE_PVRZ;
    case TYPE_GLSL:
      return TYPE_GLSL;
    case TYPE_MENU:
      return TYPE_MENU;
    case TYPE_MENU2:
      return TYPE_MENU;
    case TYPE_TTF:
      return TYPE_TTF;
    case TYPE_PNG:
      return TYPE_PNG;
    case TYPE_BAH:
      return TYPE_BAH;
    case TYPE_INI:
      return TYPE_INI;
    case TYPE_SRC:
      return TYPE_SRC;
    case TYPE_UNKNOWN:
    default:
      return TYPE_UNKNOWN;
    }
  }

  std::string ResourceTypeToFileExtString(ResourceType type)
  {
    switch (type)
    {
    case TYPE_BMP:
      return ".bmp";
    case TYPE_MVE:
      return ".mve";
    case TYPE_WAV:
      return ".wav";
    case TYPE_PLT:
      return ".plt";
    case TYPE_BAM:
      return ".bam";
    case TYPE_WED:
      return ".wed";
    case TYPE_CHU:
      return ".chu";
    case TYPE_TIS:
      return ".tis";
    case TYPE_MOS:
      return ".mos";
    case TYPE_ITM:
      return ".itm";
    case TYPE_SPL:
      return ".spl";
    case TYPE_BCS:
      return ".bcs";
    case TYPE_IDS:
      return ".ids";
    case TYPE_CRE:
      return ".cre";
    case TYPE_ARE:
      return ".are";
    case TYPE_DLG:
      return ".dlg";
    case TYPE_2DA:
      return ".2da";
    case TYPE_GAM:
      return ".gam";
    case TYPE_STO:
      return ".sto";
    case TYPE_WMP:
      return ".wmp";
    case TYPE_EFF:
      return ".eff";
    case TYPE_BC:
      return ".bc";
    case TYPE_CHR:
      return ".chr";
    case TYPE_VVC:
      return ".vvc";
    case TYPE_VEF:
      return ".vef";
    case TYPE_PRO:
      return ".pro";
    case TYPE_BIO:
      return ".bio";
    case TYPE_WBM:
      return ".wbm";
    case TYPE_FNT:
      return ".fnt";
    case TYPE_GUI:
      return ".gui";
    case TYPE_SQL:
      return ".sql";
    case TYPE_PVRZ:
      return ".pvrz";
    case TYPE_GLSL:
      return ".glsl";
    case TYPE_MENU:
      return ".menu";
    case TYPE_MENU2:
      return ".menu";
    case TYPE_TTF:
      return ".ttf";
    case TYPE_PNG:
      return ".png";
    case TYPE_BAH:
      return ".bah";
    case TYPE_INI:
      return ".ini";
    case TYPE_SRC:
      return ".src";
    case TYPE_UNKNOWN:
    default:
      return "";
    }
  }
}