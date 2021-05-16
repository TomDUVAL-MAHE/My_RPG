/*
** EPITECH PROJECT, 2021
** button_display
** File description:
** display a button
*/

#include "my_button.h"

void button_display(sfRenderWindow *window, button_t *button)
{
    sfRenderWindow_drawRectangleShape(window, button->shape, NULL);
    sfRenderWindow_drawText(window, button->text, NULL);
}