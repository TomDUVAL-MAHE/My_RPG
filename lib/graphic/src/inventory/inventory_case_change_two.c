/*
** EPITECH PROJECT, 2020
** button.c
** File description:
** function button
*/

#include "my_inventory_case.h"

void inventory_case_change_pos(inventory_case_t *cases, sfVector2f pos)
{
    cases->pos = pos;
    sfRectangleShape_setPosition(cases->sprite, pos);
}

void inventory_case_change_size(inventory_case_t *cases, sfVector2f size)
{
    cases->size = size;

    sfRectangleShape_setSize(cases->sprite, size);
}

void inventory_case_change_texture(inventory_case_t *cases, sfTexture *texture)
{
    cases->texture = texture;
    sfRectangleShape_setTexture(cases->sprite, texture, true);
}

void inventory_case_change_display(inventory_case_t *cases, bool is_display)
{
    cases->is_display = is_display;
}

void inventory_case_info_text_change_font(inventory_case_t *cases, \
sfFont *font)
{
    text_change_font(&(cases->info.text), font);
}
