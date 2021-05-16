/*
** EPITECH PROJECT, 2021
** button_is_hover
** File description:
** desc
*/

#include "my_button.h"

bool button_is_hover(button_t *button, sfVector2i pos)
{
    if (button->status == INACTIVE)
        return (false);
    if (sfIntRect_contains(&(button->size), pos.x, pos.y)) {
        button_set_status(button, HOVER);
        return (true);
    }
    button_set_status(button, ACTIVE);
    return (false);
}