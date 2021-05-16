/*
** EPITECH PROJECT, 2021
** RPG-TESTS
** File description:
** button_set_status
*/

#include "my_button.h"

void button_set_status(button_t *button, button_status status)
{
    button->status = status;
    if (status == INACTIVE)
        return;
    if (button->texture[status - 1])
        sfRectangleShape_setTexture(button->shape, \
        button->texture[status - 1], sfTrue);
    else
        sfRectangleShape_setFillColor(button->shape, button->color[status - 1]);
}