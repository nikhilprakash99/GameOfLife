# GameOfLife
An efficient C++ implementation of Conway's Game of Life using SFML for visualization

## Description

This Project contains a simple but efficient implementation of Conway's game Of Life.We can visualize the simulations with the help of SFML. The application can also parse and simulate patterns from .rle files used by golly.

![Image Of Simulation](./Documentation/Sample%20Output.png)

## Dependancies

The projects uses **Simple and Fast Multimedia Library (SFML)** for handling graphics and animations. SFML is a fast and light weight library that has support for all popular operating systems (Windows, Linux and MacOS). For more details visit [here](https://www.sfml-dev.org/)

### Installation

For debian based systems

```bash
sudo apt install libsfml-dev
```

for manual installation visit [here](https://medium.com/@Rewieer/install-sfml-2-5-1-on-ubuntu-18-04-and-clion-9e0dfe86e87f)

## Usage

The executable file GameOfLife is located inside the bin folder. we can visualize the simulation by running the executable with an RLE file's path as argument

for example

```bash
cd PROJECT_ROOT/bin

./GameOfLife ../RLE/R-Pentomino.rle
```


## Roadmap

 - [ ] Add Unit testing
 - [ ] add more effective algorithms like Qlife, Hashlife etc
 - [ ] Better Documentation
 - [ ] Improved UI layout and support,Interface to draw custom patterns
 - [ ] various modes of operation


## License

The Project is open source and is distributed under the [MIT](https://choosealicense.com/licenses/mit/) License
