/*
** EPITECH PROJECT, 2021
** we_button_is_hover
** File description:
** desc
*/

#include "my_world_edit.h"

int we_button_is_hover(we_button_t *button, sfVector2i pos)
{
    int res = 0;

    if (button->status == INACTIVE)
        return (0);
    res += (pos.x >= button->size.left) ? 1 : 0;
    res += (pos.x <= button->size.left + button->size.width) ? 1 : 0;
    res += (pos.y >= button->size.top) ? 1 : 0;
    res += (pos.y <= button->size.top + button->size.height) ? 1 : 0;
    if (res == 4) {
        button->status = HOVER;
        return (1);
    }
    button->status = ACTIVE;
    return (0);
}