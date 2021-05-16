/*
** EPITECH PROJECT, 2021
** my_text
** File description:
** desc
*/

#ifndef MY_TEXT_H_
#define MY_TEXT_H_

#include <SFML/Graphics.h>
#include <stdbool.h>
#include <stdlib.h>
#include "my.h"

typedef struct text {
    sfVector2f pos;
    char *buffer;
    sfFont* font;
    sfColor fill_color;
    sfColor outline_color;
    int char_size;
    float thickness;
    sfText *text;
    bool is_display;
} text_t;

//TEXT.C//

text_t text_create(sfVector2f pos, char *buffer, sfFont* font, bool is_display);
void text_display(text_t *text, sfRenderWindow *window);
char *my_stncat(char *dest, char const *src, int nb);
void convert_rec(int nb, char *str);
char *text_convert_int_to_char(int nb);

//TEXT_CHANGE.C//

void text_change_pos(text_t *text, sfVector2f pos);
void text_change_buffer(text_t *text, char *buffer);
void text_change_font(text_t *text, sfFont *font);
void text_change_fill_color(text_t *text, sfColor color);
void text_change_outline_color(text_t *text, sfColor color);

//TEXT_CHANGE_TWO.C//

void text_change_thickness(text_t *text, float thick);
void text_change_char_size(text_t *text, int size);
void text_change_is_display(text_t *text, bool is_display);
void text_destroy(text_t *text);

#endif /* !MY_TEXT_H_ */