/*
** EPITECH PROJECT, 2020
** progressbar.c
** File description:
** function progressbar
*/

#include "progress_bar.h"

progressbar_t progressbar_create(sfVector2f pos, float initial, \
sfVector2f size, bool is_display)
{
    progressbar_t progress;

    progress.back = sfRectangleShape_create();
    progress.cursor = sfCircleShape_create();
    progress.back_pos = pos;
    sfRectangleShape_setPosition(progress.back, pos);
    progress.back_size = size;
    sfRectangleShape_setSize(progress.back, size);
    progress.is_display = is_display;
    progress.progress = initial;
    sfCircleShape_setOrigin(progress.cursor, (sfVector2f){size.y / 2 + \
        size.y / 4, size.y / 2 + size.y / 4});
    sfCircleShape_setPosition(progress.cursor, (sfVector2f){pos.x + \
        size.x * initial, pos.y * 1.5 + pos.y * 0.25});
    progress.cursor_pos = (sfVector2f){pos.x + size.x * initial, \
        pos.y * 1.5 + pos.y * 0.25};
    sfCircleShape_setRadius(progress.cursor, size.y / 2 + size.y / 4);
    return (progress);
}

void progressbar_set_texture(progressbar_t *progress, \
char *texture_back, char *texture_cursor)
{
    progress->texture_back = sfTexture_createFromFile(texture_back, NULL);
    progress->texture_cursor = sfTexture_createFromFile(texture_cursor, NULL);
    sfRectangleShape_setTexture(progress->back, progress->texture_back, true);
    sfCircleShape_setTexture(progress->cursor, progress->texture_cursor, \
    true);
    progress->have_texture = true;
}

void progressbar_set_color(progressbar_t *progress, sfColor color_back, \
sfColor color_cursor)
{
    progress->color_back = color_back;
    progress->color_cursor = color_cursor;
    sfRectangleShape_setFillColor(progress->back, color_back);
    sfCircleShape_setFillColor(progress->cursor, color_cursor);
    progress->have_texture = false;
}

void progressbar_display(progressbar_t *progress, sfRenderWindow *window)
{
    if (progress->is_display == true) {
        sfRenderWindow_drawRectangleShape(window, progress->back, NULL);
        sfRenderWindow_drawCircleShape(window, progress->cursor, NULL);
    }
}

void progressbar_update_cursor_pos(progressbar_t *progress, \
sfRenderWindow *window)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(window);
    sfVector2i pos_2;

    for (int i = 0; i < 1500; i++);
    if (pos.x >= progress->cursor_pos.x - sfCircleShape_getRadius\
    (progress->cursor) && pos.x <= progress->cursor_pos.x + \
    sfCircleShape_getRadius(progress->cursor) && pos.y >= \
    progress->cursor_pos.y - sfCircleShape_getRadius(progress->cursor) && \
    pos.y <= progress->cursor_pos.y + sfCircleShape_getRadius\
    (progress->cursor)) {
        pos_2 = sfMouse_getPositionRenderWindow(window);
        progressbar_update_cursor_moove(progress, pos_2);
    }
}