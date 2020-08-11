#ifndef GAMEOFLIFE_RLEPARSER
#define GAMEOFLIFE_RLEPARSER

#include <string>
#include <cstdint>

#include "CellMap.h"

class ParseRLE
{
public:
  ParseRLE(std::string path);
  void ReadSettingsFromFile(std::string path);
  std::size_t GetWidth() const;
  std::size_t GetHeight() const;
  std::string GetPreset() const;
  void apply_preset(cellmap *map);
 private:
  std::size_t width;
  std::size_t height;
  std::string preset;
};


#endif //GAMEOFLIFE_RLEPARSER