#ifndef GAMEOFLIFE_BOARD
#define GAMEOFLIFE_BOARD

#include <SFML/Graphics.hpp>
#include "CellMap.h"

class Board: public sf::RenderWindow{
  public:
  
   Board();
   Board(size_t boardWidth,size_t boardHeight, double cell_size = 3.0f);
   void displayBoard(cellmap *map, sf::Color color = sf::Color(144, 238, 144));
   bool checkForClose();

  private:
   sf::RectangleShape cell;
   size_t boardWidth;
   size_t boardHeight;
};

#endif // GAMEOFLIFE_BOARD