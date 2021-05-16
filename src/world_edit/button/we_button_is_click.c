/*
** EPITECH PROJECT, 2021
** we_button_is_click
** File description:
** desc
*/

#include "my_world_edit.h"

int we_button_is_click(we_button_t *button, sfRenderWindow *window, \
sfMouseButton mouse)
{
    if (button->status == INACTIVE)
        return (0);
    if (we_button_is_hover(button, sfMouse_getPositionRenderWindow(window))) {
        if (sfMouse_isButtonPressed(mouse) == sfTrue) {
            button->status = CLICK;
            return (1);
        }
        button->status = HOVER;
        return (0);
    }
    button->status = ACTIVE;
    return (0);
}