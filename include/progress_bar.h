/*
** EPITECH PROJECT, 2021
** progress_bar.h
** File description:
** progress_bar
*/

#ifndef PROGRESS_BAR_H_
#define PROGRESS_BAR_H_

#include <SFML/Graphics.h>
#include <stdbool.h>

typedef struct progressbar {
    sfRectangleShape *back;
    sfCircleShape *cursor;
    bool have_texture;
    sfTexture *texture_back;
    sfTexture *texture_cursor;
    sfColor color_back;
    sfColor color_cursor;
    sfVector2f back_pos;
    sfVector2f cursor_pos;
    sfVector2f back_size;
    bool is_display;
    float progress;
} progressbar_t;

//PROGRESSBAR.C//

progressbar_t progressbar_create(sfVector2f pos, float initial, \
sfVector2f size, bool is_display);
void progressbar_set_texture(progressbar_t *progress, \
char *texture_back, char *texture_cursor);
void progressbar_set_color(progressbar_t *progress, sfColor color_back, \
sfColor color_cursor);
void progressbar_display(progressbar_t *progress, sfRenderWindow *window);
void progressbar_update_cursor_pos(progressbar_t *progress, \
sfRenderWindow *window);

//PROGRESSBAR_TWO.C//

void progressbar_change_display(progressbar_t *progress, bool is_display);
void progressbar_update_cursor_moove(progressbar_t *progress, sfVector2i pos_2);

#endif /* !PROGRESS_BAR_H_ */