# My Screensaver - Graphical Effects Renderer

## Overview
My Screensaver is a graphical effects renderer written in C. It displays various animations using **CSFML**.

This project explores rendering techniques that are useful for developing complex animations and visual effects, which can later be used in other graphical applications such as video games.

## Compilation
The project is compiled using a `Makefile` with the following rules:

- `make` - Compiles the binary (`my_screensaver`).
- `make clean` - Removes object files.
- `make fclean` - Removes binaries and object files.
- `make re` - Cleans and recompiles the project.

## Usage
```sh
./my_screensaver [OPTIONS] animation_id
```

### Parameters
- `animation_id` - Integer representing the animation to display (1 to MAX_ID).
- `OPTIONS`:
  - `-h` - Displays the usage information.
  - `-d` - Displays the list of available animations with their descriptions.

### Example Usage
```sh
./my_screensaver 5   # Runs animation with ID 5
./my_screensaver -h  # Shows usage information
./my_screensaver -d  # Lists all animations
```
## User Interactions
- `LEFT_ARROW` - Switch to the previous animation.
- `RIGHT_ARROW` - Switch to the next animation.

## Authorized Functions
The following functions are allowed:

### C Standard Library
- `malloc`, `free`, `memset`, `rand`, `srand`, `time`
- File handling: `fopen`, `fread`, `fwrite`, `fclose`

### CSFML Library
- `sfRenderWindow_create`, `sfRenderWindow_destroy`, `sfRenderWindow_isOpen`, `sfRenderWindow_close`
- `sfRenderWindow_pollEvent`, `sfRenderWindow_setFramerateLimit`, `sfRenderWindow_clear`
- `sfRenderWindow_drawSprite`, `sfRenderWindow_display`
- `sfSprite_create`, `sfSprite_destroy`, `sfSprite_setTexture`
- `sfTexture_create`, `sfTexture_destroy`, `sfTexture_updateFromPixels`
- `sfColor_fromInteger`, `sfColor_toInteger`
- `sfClock_create`, `sfClock_copy`, `sfClock_destroy`, `sfClock_getElapsedTime`, `sfClock_restart`

### Math Library
- All mathematical functions are allowed.

## Project Structure
```
.
├── src
│   ├── main.c
│   ├── animations.c
│   ├── ... (other source files)
├── include
│   ├── my_screensaver.h
├── bonus (optional bonus files)
├── Makefile
├── README.md
```

## Author 🚀
- **David Gozlan** (GitHub: `davphla`)
