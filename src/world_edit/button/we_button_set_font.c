/*
** EPITECH PROJECT, 2021
** we_button_set_font
** File description:
** desc
*/

#include "my_world_edit.h"

void we_button_set_font(we_button_t *button, char *font)
{
    button->font = sfFont_createFromFile(font);
    sfText_setFont(button->text, button->font);
}