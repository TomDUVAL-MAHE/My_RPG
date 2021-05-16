/*
** EPITECH PROJECT, 2021
** button_set_texture
** File description:
** desc
*/

#include "my_button.h"

void button_set_texture(button_t *button, char *filename, button_status status)
{
    if (status < 1 || status > 3)
        return;
    if (button->texture[status - 1])
        sfTexture_destroy(button->texture[status - 1]);
    button->texture[status - 1] = sfTexture_createFromFile(filename, NULL);
    sfRectangleShape_setTexture(button->shape, button->texture[0], sfTrue);
}