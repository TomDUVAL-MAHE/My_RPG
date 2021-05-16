/*
** EPITECH PROJECT, 2021
** button_setPosition
** File description:
** desc
*/

#include "my_button.h"

void button_set_position(button_t *button, sfVector2f pos)
{
    button->size.left = pos.x;
    button->size.top = pos.y;
    sfRectangleShape_setPosition(button->shape, pos);
    pos.x += 10;
    sfText_setPosition(button->text, pos);
}