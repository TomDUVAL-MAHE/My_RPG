/*
** EPITECH PROJECT, 2021
** we_button_set_position
** File description:
** desc
*/

#include "my_world_edit.h"

void we_button_set_position(we_button_t *button, sfVector2f pos)
{
    button->size.left = pos.x;
    button->size.top = pos.y;
    sfRectangleShape_setPosition(button->shape, pos);
    pos.x += 10;
    sfText_setPosition(button->text, pos);
}