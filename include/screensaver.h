/*
** EPITECH PROJECT, 2020
** screensaver.h
** File description:
** All definition used in the project : My screensaver
*/

#ifndef screensaver
#define screensaver

//Include
#include "fml.h"
#include "my.h"
#include "option.h"

//Definition
#define MAX_ID 3

//Others

//Structures

typedef struct option {
    int seed;
    char c_frame_mode;
    long c_frame;
    sfClock *clock;
} option_t;

typedef struct sv_head {
    int id;
    sfTexture *texture;
    sfSprite *sprite;
    option_t *option;
} sv_head_t;

//Prototype
int manage_windows(sv_head_t *head);
void head_destroy(sv_head_t *head);
void main_destroy(sv_head_t *head,
framebuffer_t *framebuffer, sfRenderWindow *window);
sv_head_t *head_initialize(char **av);

framebuffer_t *effect_1(framebuffer_t *framebuffer, option_t *option);
framebuffer_t *effect_2(framebuffer_t *framebuffer, option_t *option);
framebuffer_t *effect_3(framebuffer_t *framebuffer, option_t *option);

//Variable
static const sfVideoMode window_mode =
{HEIGHT_WINDOW, LENGTH_WINDOW, COLORS_BITS};

static framebuffer_t *(*const func_ptr[MAX_ID])
(framebuffer_t *, option_t *) = {effect_1, effect_2, effect_3};

#endif /* !screensaver */