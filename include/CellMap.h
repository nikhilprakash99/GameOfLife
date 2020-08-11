#ifndef GAMEOFLIFE_CELLMAP
#define GAMEOFLIFE_CELLMAP

#include <cstdint>

class cellmap {
private:
   uint8_t *cells;
   std::size_t width;
   std::size_t height;
   std::size_t length;
public:
   cellmap(unsigned int w, unsigned int h);
   ~cellmap(void);
   void copy_cells(cellmap *sourcemap);
   void set_cell(unsigned int x, unsigned int y);
   void clear_cell(unsigned int x, unsigned int y);
   uint8_t cell_state(int x, int y);
   void next_generation(cellmap *next_map);
   std::size_t getWidth();
   std::size_t getHeight();
};

#endif // GAMEOFLIFE_CELLMAP