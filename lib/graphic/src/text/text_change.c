/*
** EPITECH PROJECT, 2021
** text.c
** File description:
** text.c
*/

#include "my_text.h"

void text_change_pos(text_t *text, sfVector2f pos)
{
    text->pos = pos;
    sfText_setPosition(text->text, pos);
}

void text_change_buffer(text_t *text, char *buffer)
{
    text->buffer = buffer;
    sfText_setString(text->text, buffer);
}

void text_change_font(text_t *text, sfFont *font)
{
    text->font = font;
    sfText_setFont(text->text, font);
}

void text_change_fill_color(text_t *text, sfColor color)
{
    text->fill_color = color;
    sfText_setFillColor(text->text, color);
}

void text_change_outline_color(text_t *text, sfColor color)
{
    text->outline_color = color;
    sfText_setOutlineColor(text->text, color);
}