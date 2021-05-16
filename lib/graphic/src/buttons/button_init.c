/*
** EPITECH PROJECT, 2021
** buttons_init
** File description:
** init a new button
*/

#include "my_button.h"

sfColor *button_init_color(void)
{
    sfColor *color = malloc(sizeof(sfColor) * 3);

    if (!color)
        return (NULL);
    for (int i = 0; i < 3; i++)
        color[i] = sfTransparent;
    return (color);
}

sfTexture **button_init_texture(void)
{
    sfTexture **textures = malloc(sizeof(sfTexture *) * 3);

    if (!textures)
        return (NULL);
    for (int i = 0; i < 3; i++)
        textures[i] = NULL;
    return (textures);
}

button_t *button_init(void)
{
    button_t *button = malloc(sizeof(button_t));

    button->color = button_init_color();
    button->texture = button_init_texture();
    button->shape = sfRectangleShape_create();
    button->size = (sfIntRect){0, 0, 0, 0};
    sfRectangleShape_setPosition(button->shape, (sfVector2f){0, 0});
    sfRectangleShape_setFillColor(button->shape, button->color[0]);
    sfRectangleShape_setSize(button->shape, (sfVector2f){1, 1});
    button->text = sfText_create();
    button->text_color = sfBlack;
    button->text_size = 32;
    sfText_setPosition(button->text, (sfVector2f){0, 0});
    sfText_setCharacterSize(button->text, button->text_size);
    sfText_setFillColor(button->text, button->text_color);
    button->font = NULL;
    button->str = NULL;
    button->action = NULL;
    button->status = ACTIVE;
    return (button);
}