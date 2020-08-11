#include <iostream>
#include <string>

#include "ParseRLE.h"
#include "CellMap.h"
#include "Board.h"
#include "LifeSim.h"


using namespace std;

int main(int argc, char const *argv[])
{
  if (argc != 2) 
  {
    cout << "usage : GameOfLife < RLE File >"<<endl;
    return 0;
  }

    std::string filePath(argv[1]);
    ParseRLE parser(filePath);

    cellmap *current_map = new cellmap(parser.GetWidth(), parser.GetHeight());
    Board board(parser.GetWidth(), parser.GetHeight(),
                1024.0f / parser.GetWidth());

    parser.apply_preset(current_map);
    LifeSim sim(current_map, 5);

    // while(sim.getGeneration()<1000000){
    //   sim.step(current_map);
    // }

    while (board.isOpen()) {
      board.displayBoard(current_map);

      sim.syncStep(current_map);

      if (board.checkForClose()) board.close();
  }

  delete current_map;
  return 0;
}