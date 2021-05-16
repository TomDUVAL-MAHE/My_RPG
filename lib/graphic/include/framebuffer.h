/*
** EPITECH PROJECT, 2021
** framebuffer
** File description:
** desc
*/

#ifndef FRAMEBUFFER_H_
#define FRAMEBUFFER_H_

#include <SFML/Graphics.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct my_framebuffer {
    sfUint8 *pixels;
    sfVector2f size;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    bool is_display;
} framebuffer_t;

//FRAMEBUFFER_LINE.C//

void framebuffer_draw_line(framebuffer_t *buff, sfVector2i from, \
sfVector2i to, sfColor color);

//FRAMEBUFFER.C//

framebuffer_t framebuffer_create(sfVector2f size, sfVector2f pos, \
bool is_display);
void framebuffer_display(framebuffer_t *framebuffer, sfRenderWindow *window);
void framebuffer_put_pixel(framebuffer_t *framebuffer, sfVector2f pos, \
sfColor color);
void framebuffer_put_circle(framebuffer_t *framebuffer, sfVector2i pos, \
int radius, sfColor color);
void framebuffer_fill_all_pixel(framebuffer_t *framebuffer, sfColor color);

#endif /* !FRAMEBUFFER_H_ */