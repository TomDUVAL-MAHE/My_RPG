/*
** EPITECH PROJECT, 2021
** we_button_display
** File description:
** desc
*/

#include "my_world_edit.h"

void we_button_display(sfRenderWindow *window, we_button_t *button)
{
    sfRenderWindow_drawRectangleShape(window, button->shape, NULL);
    sfRenderWindow_drawText(window, button->text, NULL);
}