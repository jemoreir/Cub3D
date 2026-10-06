This project has been created as part of the 42 curriculum by jemoreir and mlucena-.

# cub3D

## Description

cub3D is a 42 project inspired by early first-person games such as Wolfenstein 3D. Its goal is to create a realistic 3D representation of the inside of a maze using ray-casting techniques.

The program reads a `.cub` configuration file containing the map, wall textures, and floor and ceiling colors. It then renders the maze from a first-person perspective using MiniLibX.

The project focuses on ray casting, graphical rendering, map parsing and validation, player movement, collision detection, texture handling, and memory management.

The program must:

- display a 3D representation of a maze using ray casting;
- use MiniLibX for graphical rendering;
- accept a map file with the `.cub` extension;
- display different textures depending on which side of a wall is hit;
- define floor and ceiling colors using RGB values;
- allow the player to move through the maze;
- allow the player to rotate the point of view;
- prevent the player from moving through walls;
- close properly when pressing `ESC`;
- close properly when clicking the window close button;
- validate the map and configuration before starting the game;
- properly manage allocated memory and graphical resources.

## Instructions

Compile the project using:

```bash
make
```

The Makefile also provides the following rules:

```bash
make clean
make fclean
make re
```

Run the program by passing a valid `.cub` map file as argument:

```bash
./cub3d map.cub
```

Example:

```bash
./cub3d maps/example.cub
```

The program requires exactly one `.cub` file containing the map configuration, texture paths, and floor and ceiling colors.

## Resources

The following resources were useful for understanding the main concepts required for this project:

- 42 cub3D subject
- MiniLibX documentation
- C standard library and Linux manual pages
- Ray-casting tutorials and explanations based on the techniques used in early first-person games
- Documentation related to file handling, memory management, and mathematical functions in C

### AI Usage

AI was used only as a support tool for writing and organizing this `README.md`.

It was used to:

- Researching and understanding mathematical and technical concepts.
- Debugging assistance.

