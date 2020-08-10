#include "Board.h"

Board::Board(): Board(128,128){}

Board::Board(size_t board_width,size_t board_height, double cell_size):
boardHeight(board_height),
boardWidth(board_width)
{
  setFramerateLimit(60);
  cell.setSize({cell_size, cell_size});
  cell.setFillColor(sf::Color::Black);
  create(sf::VideoMode(board_width*cell.getSize().x,board_height*cell.getSize().y, 32),
        "Conway's Game of Life",sf::Style::Titlebar|sf::Style::Close);
}

void Board::displayBoard(bool a[256][256],sf::Color color) {
  checkForClose();
  clear();
  auto size = cell.getSize();
  for (std::size_t y{0}; y < boardHeight; y++)
    for (std::size_t x{0}; x < boardWidth; x++)
      if (a[x][y]) {
        cell.setPosition(x * size.x, y* size.y);
        cell.setFillColor(color);
        draw(cell);
      }
  display();
}

bool Board::checkForClose(){
  sf::Event event;
  while (pollEvent(event)) {
    if (event.type == sf::Event::Closed) return true;
  }
}