/*
** EPITECH PROJECT, 2021
** button_setFont
** File description:
** desc
*/

#include "my_button.h"

void button_set_font(button_t *button, char *font)
{
    if (button->font)
        sfFont_destroy(button->font);
    button->font = sfFont_createFromFile(font);
    sfText_setFont(button->text, button->font);
}