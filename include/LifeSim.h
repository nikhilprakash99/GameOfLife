#ifndef GAMEOFLIFE_LIFESIM
#define GAMEOFLIFE_LIFESIM

#include <chrono>

#include "CellMap.h"

class LifeSim {
  public:
   LifeSim(cellmap *current_map, unsigned rate=15);
   void step(cellmap *current_map);
   bool syncStep(cellmap *current_map);
   void setRate(unsigned int rate);
   unsigned getRate();
   unsigned getGeneration();
   ~LifeSim();

  private:
   unsigned rate;
   unsigned generation;
   cellmap *next_map;
   std::chrono::milliseconds step_period;
   std::chrono::high_resolution_clock::time_point next_step;
};

#endif // GAMEOFLIFE_LIFESIM