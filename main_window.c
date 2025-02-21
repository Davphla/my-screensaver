/*
** EPITECH PROJECT, 2020
** main_window
** File description:
** Manage all the basic stuff with the window, with all default parameters
*/

#include "include/screensaver.h"

void clock_management(sv_head_t *head)
{
    if (sfClock_getElapsedTime
    (head->option->clock).microseconds > (1000000 / FRAME_RATE)) {
        head->option->c_frame += 1 * head->option->c_frame_mode;
        sfClock_restart(head->option->clock);
    }
}

void manage_event(sfRenderWindow *window, sfEvent event,
sv_head_t **head, framebuffer_t **framebuffer)
{
    int key = 0;

    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event.type == sfEvtKeyPressed) {
        key = event.key.code;
        if (key == 71 || key == 72) {
            (*head)->id += (key == 72 && (*head)->id < MAX_ID);
            (*head)->id -= (key == 71 && 1 < (*head)->id);
            fb_restart(*framebuffer, 0);
            (*head)->option->c_frame = 0;
            (*head)->option->c_frame_mode = 1;
        }
        if (event.key.code == 73) {
            srand(time(NULL));
            (*head)->option->seed = rand() / 100000;
        }
    }
}

int manage_windows(sv_head_t *head)
{
    framebuffer_t *framebuffer = fb_create(HEIGHT_WINDOW, LENGTH_WINDOW);
    sfEvent event;
    sfRenderWindow *window = sfRenderWindow_create
    (window_mode, "Screensaver", sfResize | sfClose, NULL);

    if (!window)
        return (EXIT_FAILURE);
    sfRenderWindow_setFramerateLimit(window, FRAME_RATE);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event))
            manage_event(window, event, &head, &framebuffer);
        framebuffer = (func_ptr[head->id - 1])(framebuffer, head->option);
        sfTexture_updateFromPixels(head->texture,
        framebuffer->pixels, HEIGHT_WINDOW, LENGTH_WINDOW, 0, 0);
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, head->sprite, NULL);
        sfRenderWindow_display(window);
        clock_management(head);
    }
    main_destroy(head, framebuffer, window);
    return (0);
}
