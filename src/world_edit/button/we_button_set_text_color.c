/*
** EPITECH PROJECT, 2021
** we_button_set_text_color
** File description:
** desc
*/

#include "my_world_edit.h"

void we_button_set_text_color(we_button_t *button, sfColor color)
{
    button->text_color = color;
    sfText_setFillColor(button->text, color);
}