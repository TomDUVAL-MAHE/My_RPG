/*
** EPITECH PROJECT, 2021
** button_destroy
** File description:
** destroy a button
*/

#include "my_button.h"

void button_destroy(button_t *button)
{
    for (int i = 0; i < 3; i++)
        if (button->texture[i])
            sfTexture_destroy(button->texture[i]);
    free(button->texture);
    free(button->color);
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