/*
** EPITECH PROJECT, 2021
** button_setColor
** File description:
** desc
*/

#include "my_button.h"

void button_set_color(button_t *button, sfColor color, button_status status)
{
    if (status < 1 || status > 3)
        return;
    button->color[status - 1] = color;
    sfRectangleShape_setFillColor(button->shape, color);
}