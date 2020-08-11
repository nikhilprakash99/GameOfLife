#include "ParseRLE.h"

#include <fstream>
#include <cstdio>
#include <cstring>

ParseRLE::ParseRLE(std::string path):
width{0},
height{0},
preset{""}
{
  ReadSettingsFromFile(path);
}

void ParseRLE::ReadSettingsFromFile(std::string path){
  std::fstream file;
  file.open(path, std::ios::in);
  std::string dump;

  file >> dump >> dump >> dump >> dump >> dump;
  sscanf(dump.c_str(),"%lu,", &width);
  file >> dump >> dump >> dump;
  sscanf(dump.c_str(),"%lu,", &height);
  file >> dump >> dump >> dump >> preset;

  file.close();
}

void ParseRLE::apply_preset(cellmap *map){
	std::string sign;
	char state;
	int number = 0;
	std::size_t column = 0;
	std::size_t row = 0;

   std::size_t length = preset.size();

   for (int i = 0; i < length; i++) {
     sign.clear();
     	while (isdigit(preset[i]))
		{
			sign += preset[i++];
		}

		if (sign.size() == 0)
			number = 1;
      else
         number = std::stoi(sign);

      state = preset[i];

      switch(state)
      {
         case '$' :
            column = 0;
            row += number;
            break;
         case 'o' :
           for (int j = 0; j < number; j++){
             map->set_cell(column++, row);
           } 
           break;
         case 'b' :
           for (int j = 0; j < number; j++){
             column++;
           }
           break;
         case '!' :
           return;
      }
   }
}

std::size_t ParseRLE::GetWidth() const { return width; }
std::size_t ParseRLE::GetHeight() const { return height; }
std::string ParseRLE::GetPreset() const { return preset; }