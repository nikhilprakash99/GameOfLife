#include <iostream>
#include "Board.h"

using namespace std;

int main(int argc, char const *argv[])
{
  Board board(50,40,24.0f);

  bool a[256][256];

  for (int i = 0; i < 50; i++){
    for (int j = 0; j < 40; j++)
    {
      a[i][j] = (i + j) % 2;
    }
  }
  
    while (board.isOpen()) {
      board.displayBoard(a);

      if (board.checkForClose())
        board.close();
    }

  return 0;
}
