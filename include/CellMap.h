#ifndef GAMEOFLIFE_CELLMAP
#define GAMEOFLIFE_CELLMAP

#include <cstdint>

class cellmap {
private:
   std::size_t width;
   std::size_t height;
   std::size_t length;
public:
   uint8_t *cells;
   cellmap(unsigned int w, unsigned int h);
   ~cellmap(void);
   void copy_cells(cellmap *sourcemap);
   void set_cell(unsigned int x, unsigned int y);
   void clear_cell(unsigned int x, unsigned int y);
   uint8_t cell_state(int x, int y);
   std::size_t getWidth();
   std::size_t getHeight();
   const uint8_t *getCellsPtr();
};

#endif // GAMEOFLIFE_CELLMAP