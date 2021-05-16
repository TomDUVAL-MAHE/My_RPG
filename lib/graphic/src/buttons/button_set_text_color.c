/*
** EPITECH PROJECT, 2021
** button_setTextColor
** File description:
** desc
*/

#include "my_button.h"

void button_set_text_color(button_t *button, sfColor color)
{
    button->text_color = color;
    sfText_setFillColor(button->text, color);
}