/*
** EPITECH PROJECT, 2020
** button.c
** File description:
** function button
*/

#include "my_inventory.h"

inventory_case_t inventory_case_create(sfVector2f pos, sfVector2f size, \
sfTexture *texture)
{
    inventory_case_t cases;

    cases.texture = texture;
    cases.sprite = sfRectangleShape_create();
    sfRectangleShape_setTexture(cases.sprite, texture, true);
    cases.pos = pos;
    sfRectangleShape_setPosition(cases.sprite, pos);
    cases.size = size;
    sfRectangleShape_setSize(cases.sprite, size);
    cases.is_display = false;
    return (cases);
}

void inventory_case_create_info(inventory_case_t *cases, int dir, \
sfVector2f size, sfTexture *texture)
{
    sfVector2f pos = {cases->pos.x, cases->pos.y};

    if (dir == 0)
        pos.y -= (cases->size.y / 10);
    if (dir == 1) {
        pos.y -= (cases->size.y / 10);
        pos.x += cases->size.x * 0.9;
    }
    if (dir == 2)
        pos.y += (cases->size.y * 1.2);
    if (dir == 3) {
        pos.y += (cases->size.y * 1.2);
        pos.x += cases->size.x * 0.9;
    }
    cases->info = textbox_create(pos, size, true);
    textbox_set_texture(&(cases->info), texture);
    textbox_change_display(&(cases->info), true);
}

void inventory_case_create_info_text(inventory_case_t *cases, int size, \
char *buffer, sfFont *font)
{
    sfVector2f new_size = {((my_strlen(buffer) / 2) * size) * 1.2 + 10, \
        size * 1.3};

    textbox_set_text(&(cases->info), size, buffer, font);
    inventory_case_info_change_size(cases, new_size);
}

void inventory_case_destroy(inventory_case_t *cases)
{
    sfTexture_destroy(cases->texture);
    sfRectangleShape_destroy(cases->sprite);
    textbox_destroy(&(cases->info));
}

void inventory_case_add_type_limit(inventory_t *inventory, \
int type_limit, sfVector2i pos)
{
    inventory->cases[pos.y][pos.x].type_limit = type_limit;
}