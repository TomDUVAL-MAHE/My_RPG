/*
** EPITECH PROJECT, 2021
** we_button_set_color
** File description:
** desc
*/

#include "my_world_edit.h"

void we_button_set_color(we_button_t *button, sfColor color)
{
    button->color = color;
    sfRectangleShape_setFillColor(button->shape, color);
}