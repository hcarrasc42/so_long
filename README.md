This project was built as part of the 42 cursus by hcarrasc42.

# so_long

> _Collect everything, then find the exit — in as few moves as you can._

A small 2D tile-based game written in C with the **MiniLibX** graphics library.
The player moves around a map, collects every item, and then reaches the exit —
while the program counts each move.

![Language](https://img.shields.io/badge/language-C-blue?style=flat-square)
![Graphics](https://img.shields.io/badge/graphics-MiniLibX-purple?style=flat-square)
![Norm](https://img.shields.io/badge/norm-42-black?style=flat-square)

## 📖 About

`so_long` introduces graphics programming and event handling: opening a window,
loading image sprites, rendering a grid-based map, and reacting to keyboard
input through an event loop. The map is described in a plain-text `.ber` file
made of tiles:

| Char | Meaning |
|------|---------|
| `1` | wall |
| `0` | floor (walkable) |
| `P` | player start |
| `C` | collectible |
| `E` | exit |

The player must gather **all** collectibles before the exit opens.

## ✨ Key Features

- **Map parsing and validation:** the file is read with `get_next_line`, and the
  program checks that it is rectangular, fully enclosed by walls, uses only valid
  characters, and contains exactly one player, one exit, and at least one
  collectible.
- **Sprite rendering:** wall, floor, player, collectible, and exit are loaded
  from `.xpm` images and drawn tile by tile.
- **Event-driven movement:** `WASD` moves the player, `ESC` (and the window's
  close button) quits. Walls block movement; collectibles are picked up on
  contact.
- **Move counter:** every valid move is printed to the terminal.
- **Win condition:** reaching the exit after collecting everything ends the game.
- **Clean shutdown:** window, images, and map memory are released on exit.

## 🛠 Technologies

| Component | Detail |
|-----------|--------|
| Language | C (`-Wall -Werror -Wextra`) |
| Graphics | MiniLibX (window, images, hooks, event loop) |
| I/O | `get_next_line` (bundled) for reading the map |
| Build system | GNU Make |

## 🏗 Architecture

A single `t_game` struct holds everything: the MiniLibX pointer and window, the
parsed `t_map` (the tile grid plus width/height), each sprite (`t_sprite` with
its image data), the player position, and the counters for moves and remaining
collectibles.

```
main()
  └── check_args()     — validate argument + .ber extension
  └── get_map()        — read + validate the map into a grid
  └── mlx_init / new_window
  └── ft_sprites()     — load and place all tiles
  └── key hooks        — press_key() moves the player, updates counters
  └── mlx_loop()       — event loop until win / quit
```

## 🚀 How to Run

```sh
make
./so_long maps/map.ber
```

Controls: **W / A / S / D** to move, **ESC** to quit.

## 📂 Project Structure

```
so_long/
├── makefile
├── inc/               # main.h (structs, prototypes), colors.h
├── srcs/
│   ├── main.c         # setup + event loop
│   ├── map.c          # read the map
│   ├── check.c        # argument + map validation
│   ├── sprite.c       # load and draw sprites
│   ├── hook.c         # keyboard handling, movement, win/lose
│   ├── utils.c        # error handling, cleanup
│   └── get_next_line/ # bundled line reader
├── maps/              # example .ber maps
├── sprites/           # .xpm tile images
└── minilibx/          # MiniLibX graphics library
```

## 💡 What This Project Demonstrates

- **Graphics and event programming** with MiniLibX: windows, images, hooks, loop.
- **File parsing and strict validation** of a structured text format.
- **Grid/state modelling** and simple game logic in C.
- **Manual resource management** for windows, images, and dynamic memory.
