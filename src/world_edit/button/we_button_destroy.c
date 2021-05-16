/*
** EPITECH PROJECT, 2021
** we_button_destroy
** File description:
** desc
*/

#include "my_world_edit.h"

void we_button_destroy(we_button_t *button)
{
    if (button->texture != NULL)
        sfTexture_destroy(button->texture);
    if (button->shape != NULL)
        sfRectangleShape_destroy(button->shape);
    if (button->font != NULL)
        sfFont_destroy(button->font);
    if (button->text != NULL)
        sfText_destroy(button->text);
    if (button->str != NULL)
        free(button->str);
    free(button);
}