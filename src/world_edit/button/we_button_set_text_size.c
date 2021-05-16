/*
** EPITECH PROJECT, 2021
** we_button_set_text_size
** File description:
** desc
*/

#include "my_world_edit.h"

void we_button_set_text_size(we_button_t *button, int size)
{
    button->text_size = size;
    sfText_setCharacterSize(button->text, size);
}