#include <iostream>
#include <string>

#include "ParseRLE.h"
#include "CellMap.h"
#include "Board.h"
#include "LifeSim.h"


using namespace std;

int main(int argc, char const *argv[])
{
  // std::string filePath(argv[1]);
  std::string filePath("/home/nikhilprakash99/dev/GameOfLife/RLE/R-Pentomino6.rle");
  ParseRLE parser(filePath);

  cellmap *current_map = new cellmap(parser.GetWidth(), parser.GetHeight());
  Board board(parser.GetWidth(), parser.GetHeight(),1024.0f / parser.GetWidth());
  
  parser.apply_preset(current_map);
  LifeSim sim(current_map, 5);

  while(sim.getGeneration()<10000){
    sim.step(current_map);
  }

  // while (board.isOpen()) {
  //   board.displayBoard(current_map);

  //   // sim.syncStep(current_map);

  //   if (board.checkForClose()) board.close();
  // }

  delete current_map;
  return 0;
}