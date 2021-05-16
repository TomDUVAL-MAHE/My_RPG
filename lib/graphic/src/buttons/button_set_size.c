/*
** EPITECH PROJECT, 2021
** button_setSize
** File description:
** desc
*/

#include "my_button.h"

void button_set_size(button_t *button, sfVector2f size)
{
    button->size.width = size.x;
    button->size.height = size.y;
    sfRectangleShape_setSize(button->shape, size);
}