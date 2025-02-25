# My Screensaver - Graphical Effects Renderer

My Screensaver is a graphical effects renderer written in C. It displays various animations using **CSFML**.
It was realized in the context of learning graphic rendering and CSFML, further used all along my studies.
This project explores rendering techniques that are useful for developing complex animations and visual effects.

This project has 2 differents animations
- Random circle animation using frame buffer, changeable using `UP_ARROW`
- Fake 3D effect inspired by [Spu7nix level](https://www.youtube.com/watch?v=UKqMBAxxun8&pp=ygUHU3B1N25peA%3D%3D)

## Compilation
:warning: This project depends on **CSFML**, which is a binding of **SFML** in C. You must install it before compiling the project.

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

## Author 🚀
- [**David Gozlan**](https://github.com/Davphla)
