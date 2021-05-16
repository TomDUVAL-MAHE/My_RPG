/*
** EPITECH PROJECT, 2021
** we_button_set_size
** File description:
** desc
*/

#include "my_world_edit.h"

void we_button_set_size(we_button_t *button, sfVector2f size)
{
    button->size.width = size.x;
    button->size.height = size.y;
    sfRectangleShape_setSize(button->shape, size);
}