#include "CellMap.h"
#include <cstring>

cellmap::cellmap(unsigned int w, unsigned int h)
{
   width = w;
   height = h;
   length = w * h;
   cells = new unsigned char[length];  // cell storage
   memset(cells, 0, length);  // clear all cells, to start
}

cellmap::~cellmap()
{
   delete[] cells;
}

void cellmap::copy_cells(cellmap *sourcemap)
{
   memcpy(cells, sourcemap->cells, length);
}

void cellmap::set_cell(unsigned int x, unsigned int y)
{
   unsigned char *cell_ptr =
         cells + (y * width + x);

   *(cell_ptr) = 1;
}

void cellmap::clear_cell(unsigned int x, unsigned int y)
{
   uint8_t *cell_ptr =
         cells + (y * width) + x;

   *(cell_ptr) = 0;
}

uint8_t cellmap::cell_state(int x, int y)
{
  uint8_t *cell_ptr;

  if ((x < 0) || (x >= width) || (y < 0) || (y >= height))
    return 0;   // Border case

  cell_ptr = cells + (y * width) + x;
  return *cell_ptr;
}

void cellmap::next_generation(cellmap* next_map)
{
   unsigned int x, y, neighbor_count;

   for (y=0; y<height; y++) {
      for (x=0; x<width; x++) {
         // Figure out how many neighbors this cell has
         neighbor_count = cell_state(x-1, y-1) + cell_state(x, y-1) +
               cell_state(x+1, y-1) + cell_state(x-1, y) +
               cell_state(x+1, y) + cell_state(x-1, y+1) +
               cell_state(x, y+1) + cell_state(x+1, y+1);
         if (cell_state(x, y) == 1) {
            // The cell is on; does it stay on?
            if ((neighbor_count != 2) && (neighbor_count != 3)) {
               next_map->clear_cell(x, y);    // turn it off
            }
         } else {
            // The cell is off; does it turn on?
            if (neighbor_count == 3) {
               next_map->set_cell(x, y);      // turn it on
            }
         }
      }
   }
}

std::size_t cellmap::getWidth() { return width; }
std::size_t cellmap::getHeight() {return height;}