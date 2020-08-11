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
   unsigned char *cell_ptr = cells + (y * width + x);
   int xoleft, xoright, yoabove, yobelow;

   xoleft = -1;
   yoabove = -width;
   xoright = 1;
   yobelow = width;

   *(cell_ptr)|=0x01;

   if(y>0){
         *(cell_ptr + yoabove) += 2;
      if(x>0)
         *(cell_ptr + yoabove + xoleft) += 2;
      if(x<width-1)
         *(cell_ptr + yoabove + xoright) += 2;      
   }

   if(y<height-1){
         *(cell_ptr + yobelow) += 2;
      if(x>0)
         *(cell_ptr + yobelow + xoleft) += 2;
      if(x<width-1)
         *(cell_ptr + yobelow + xoright) += 2;
   }

   if(x>0)
      *(cell_ptr + xoleft) += 2;
   if(x<width-1)
      *(cell_ptr + xoright) += 2;
}

void cellmap::clear_cell(unsigned int x, unsigned int y)
{
   unsigned char *cell_ptr = cells + (y * width + x);
   int xoleft, xoright, yoabove, yobelow;

   xoleft = -1;
   yoabove = -width;
   xoright = 1;
   yobelow = width;

   *(cell_ptr)&=~0x01;

   if(y>0){
         *(cell_ptr + yoabove) -= 2;
      if(x>0)
         *(cell_ptr + yoabove + xoleft) -= 2;
      if(x<width-1)
         *(cell_ptr + yoabove + xoright) -= 2;      
   }

   if(y<height-1){
         *(cell_ptr + yobelow) -= 2;
      if(x>0)
         *(cell_ptr + yobelow + xoleft) -= 2;
      if(x<width-1)
         *(cell_ptr + yobelow + xoright) -= 2;
   }

   if(x>0)
      *(cell_ptr + xoleft) -= 2;
   if(x<width-1)
      *(cell_ptr + xoright) -= 2;
}

uint8_t cellmap::cell_state(int x, int y)
{
  uint8_t *cell_ptr;
  cell_ptr = cells + (y * width) + x;
  return *cell_ptr& 0x01;
}

std::size_t cellmap::getWidth() { return width; }
std::size_t cellmap::getHeight() {return height;}
const uint8_t* cellmap::getCellsPtr() { return (const uint8_t *)cells; }