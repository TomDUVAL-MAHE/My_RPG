/*
** EPITECH PROJECT, 2021
** button_is_click
** File description:
** desc
*/

#include "my_button.h"

bool button_is_click(button_t *button, sfVector2i pos)
{
    if (button->status == INACTIVE)
        return (false);
    if (button->status != HOVER) {
        button_is_hover(button, pos);
    }
    if (button->status == HOVER) {
        button_set_status(button, CLICK);
        return (true);
    }
    return (false);
}