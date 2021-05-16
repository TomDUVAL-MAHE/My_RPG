/*
** EPITECH PROJECT, 2021
** we_button_texture
** File description:
** desc
*/

#include "my_world_edit.h"

void we_button_set_texture(we_button_t *button, char *filename)
{
    button->texture = sfTexture_createFromFile(filename, NULL);
    sfRectangleShape_setTexture(button->shape, button->texture, sfTrue);
}