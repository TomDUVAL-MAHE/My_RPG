/*
** EPITECH PROJECT, 2021
** we_button
** File description:
** desc
*/

#include "my_world_edit.h"

we_button_t *we_button_create(void)
{
    we_button_t *button = malloc(sizeof(we_button_t));

    button->color = sfBlack;
    button->font = NULL;
    button->shape = sfRectangleShape_create();
    button->size = (sfIntRect){0, 0, 50, 50};
    sfRectangleShape_setPosition(button->shape, (sfVector2f){0, 0});
    sfRectangleShape_setFillColor(button->shape, button->color);
    sfRectangleShape_setSize(button->shape, (sfVector2f){50, 50});
    button->text = sfText_create();
    button->text_color = sfWhite;
    button->text_size = 32;
    sfText_setPosition(button->text, (sfVector2f){0, 0});
    sfText_setCharacterSize(button->text, 32);
    sfText_setFillColor(button->text, sfWhite);
    button->str = NULL;
    button->texture = NULL;
    button->status = ACTIVE;
    return (button);
}