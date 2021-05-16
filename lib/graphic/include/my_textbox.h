/*
** EPITECH PROJECT, 2021
** my_textbox
** File description:
** desc
*/

#ifndef MY_TEXTBOX_H_
#define MY_TEXTBOX_H_

#include <SFML/Graphics.h>
#include <stdbool.h>
#include "my_text.h"

typedef struct textbox {
    sfRectangleShape *background;
    text_t text;
    sfColor color;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f size;
    bool have_texture;
    bool is_display;
} textbox_t;

//TEXTBOX.C//

textbox_t textbox_create(sfVector2f pos, sfVector2f size, bool have_texture);
void textbox_set_text(textbox_t *textbox, int size, char *buffer, sfFont* font);
void textbox_set_texture(textbox_t *textbox, sfTexture *texture);
void textbox_set_color(textbox_t *textbox, sfColor color);
void textbox_display(textbox_t *textbox, sfRenderWindow *window);

//TEXTBOX_TWO.C//

void textbox_change_display(textbox_t *textbox, bool is_display);
void textbox_destroy(textbox_t *textbox);

#endif /* !MY_TEXTBOX_H_ */