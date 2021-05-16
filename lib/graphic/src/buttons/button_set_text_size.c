/*
** EPITECH PROJECT, 2021
** button_setTextSize
** File description:
** desc
*/

#include "my_button.h"

void button_set_text_size(button_t *button, int size)
{
    button->text_size = size;
    sfText_setCharacterSize(button->text, size);
}