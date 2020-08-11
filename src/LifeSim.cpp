#include "LifeSim.h"

#include <chrono>
#include <algorithm>

LifeSim::LifeSim(cellmap *current_map, unsigned rate){
  generation = 0;
  next_map = new cellmap(current_map->getWidth(), current_map->getHeight());
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
  next_map->copy_cells(current_map);
  next_map->next_generation(current_map);
  generation++;
}

LifeSim::~LifeSim(){
  delete next_map;
}

unsigned LifeSim::getGeneration(){
  return generation;
}