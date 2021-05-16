/*
** EPITECH PROJECT, 2020
** progressbar_two.c
** File description:
** function progressbar
*/

#include "progress_bar.h"

void progressbar_change_display(progressbar_t *progress, bool is_display)
{
    progress->is_display = is_display;
}

void progressbar_update_cursor_moove(progressbar_t *progress, sfVector2i pos_2)
{
    if (pos_2.x >= progress->back_pos.x + 50 && pos_2.x <= \
    progress->back_pos.x + progress->back_size.x - 50) {
        progress->cursor_pos = (sfVector2f){pos_2.x, \
            progress->cursor_pos.y};
        sfCircleShape_setPosition(progress->cursor, progress->cursor_pos);
        progress->progress = (progress->cursor_pos.x - \
        progress->back_pos.x) / \
        (progress->back_size.x);
    }
}