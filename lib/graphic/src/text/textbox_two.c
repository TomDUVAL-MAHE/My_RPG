/*
** EPITECH PROJECT, 2021
** textbox_two.c
** File description:
** textbox_two.c
*/

#include "my_textbox.h"

void textbox_change_display(textbox_t *textbox, bool is_display)
{
    textbox->is_display = is_display;
    textbox->text.is_display = is_display;
}

void textbox_destroy(textbox_t *textbox)
{
    sfRectangleShape_destroy(textbox->background);
    sfTexture_destroy(textbox->texture);
    text_destroy(&(textbox->text));
}