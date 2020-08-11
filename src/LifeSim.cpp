#include "LifeSim.h"

#include <chrono>
#include <cstring>

LifeSim::LifeSim(cellmap *current_map,unsigned rate){
  generation = 0;
  temp_cells = new unsigned char[current_map->getWidth()*current_map->getHeight()];
  setRate(rate);
}

void LifeSim::setRate(unsigned int simRate){
  rate = simRate;
  step_period = std::chrono::milliseconds(1000 / rate);
  next_step = std::chrono::high_resolution_clock::now() + step_period;
}

unsigned LifeSim::getRate(){
  return rate;
}

bool LifeSim::syncStep(cellmap *current_map){
  auto now = std::chrono::high_resolution_clock::now();
  if (now < next_step)
    return false;
  step(current_map);
  next_step = now + step_period;
  return true;
}

void LifeSim::step(cellmap *current_map){
  generation++;

   unsigned int x, y, count;
   unsigned int h = current_map->getHeight(), w = current_map->getWidth();
   unsigned char *cell_ptr=NULL;
   std::size_t length = h * w;

   memcpy(temp_cells, current_map->cells, length);

   cell_ptr = temp_cells;     
   for (y=0; y<h; y++) {      
    x = 0;
    do { // skip empty and irrelevant cells
        while (*cell_ptr == 0) {
          cell_ptr++; 
          if (++x >= w) break;
        }
        if (x == w) continue;

        // Active cell encountered
        // check if its state needs to be changed
        count = *cell_ptr >> 1; // no. of neighboring cells
        if (*cell_ptr & 0x01) {
          // game of life rule
          if ((count != 2) && (count != 3)) {
              current_map->clear_cell(x, y);
          }
        } else {
          // Cell is off. turn it on if it has 3 neighbors
          if (count == 3) {
              current_map->set_cell(x, y);
          }
        }
        // next cell
        cell_ptr++;
    } while (++x < w);
   }
}

LifeSim::~LifeSim(){
  delete temp_cells;
}

unsigned LifeSim::getGeneration(){
  return generation;
}