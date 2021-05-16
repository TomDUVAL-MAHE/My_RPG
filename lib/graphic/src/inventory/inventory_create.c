/*
** EPITECH PROJECT, 2020
** button.c
** File description:
** function button
*/

#include "my_inventory.h"

inventory_t *inventory_create(sfVector2f pos, sfVector2i cases_number, \
sfVector2i cases_size, sfVector2i cases_espacement)
{
    inventory_t *inventory = malloc(sizeof(inventory_t) * 1);

    inventory->pos = pos;
    inventory->cases_number = cases_number;
    inventory->cases_size = cases_size;
    inventory->cases_espacement = cases_espacement;
    inventory->is_display = false;
    inventory->is_movement = false;
    inventory->movement_buffer = NULL;
    inventory->movement_pos = (sfVector2i){0, 0};
    inventory->movement_texture = NULL;
    inventory_define_total_size(inventory);
    return (inventory);
}

void inventory_background_create(inventory_t *inventory, sfTexture \
*texture, sfColor color, bool have_texture)
{
    inventory->background = sfRectangleShape_create();
    sfRectangleShape_setSize(inventory->background, inventory->size);
    sfRectangleShape_setPosition(inventory->background, inventory->pos);
    if (have_texture)
        sfRectangleShape_setTexture(inventory->background, texture, true);
    else
        sfRectangleShape_setFillColor(inventory->background, color);
}

void inventory_cases_create_two(inventory_t *inventory, int i, \
sfTexture *texture, sfTexture *info_texture)
{
    for (int j = 0; j < inventory->cases_number.x; j++) {
        inventory->cases[i][j] = inventory_case_create((sfVector2f)\
        {inventory->pos.x + inventory->cases_espacement.x + (j * \
            (inventory->cases_size.x + inventory->cases_espacement.x)), \
            inventory->pos.y + inventory->cases_espacement.y + (i * \
            (inventory->cases_size.y + inventory->cases_espacement.y))}, \
        (sfVector2f){inventory->cases_size.x, inventory->cases_size.y}, \
        texture);
        inventory_case_create_info(&(inventory->cases[i][j]), 2, \
        (sfVector2f){0, 0}, info_texture);
        inventory_case_add_type_limit(inventory, -1, (sfVector2i){j, i});
    }
}

void inventory_cases_create_three(inventory_t *inventory, int i, sfFont *font)
{
    for (int j = 0; j < inventory->cases_number.x; j++) {
        inventory_case_create_info_text(&(inventory->cases[i][j]), \
        20, "Coucou", font);
        inventory->empty_cases[i][j] = sfRectangleShape_create();
        sfRectangleShape_setPosition((inventory->empty_cases[i][j]), \
        (sfVector2f){inventory->pos.x + inventory->cases_espacement.x + \
            (j * (inventory->cases_size.x + inventory->cases_espacement.x)), \
            inventory->pos.y + inventory->cases_espacement.y + (i * \
            (inventory->cases_size.y + inventory->cases_espacement.y))});
        sfRectangleShape_setSize((inventory->empty_cases[i][j]), \
        (sfVector2f){inventory->cases_size.x, inventory->cases_size.y});
        sfRectangleShape_setTexture((inventory->empty_cases[i][j]), \
        sfTexture_createFromFile("assets/inventory/empty_case.png", NULL), \
        true);
    }
}

void inventory_cases_create(inventory_t *inventory, sfTexture *texture, \
sfTexture *info_texture, sfFont *font)
{
    inventory->cases = malloc(sizeof(inventory_case_t *) * \
    (inventory->cases_number.y + 1));
    inventory->empty_cases = malloc(sizeof(sfRectangleShape **) * \
    (inventory->cases_number.y + 1));
    for (int i = 0; i < inventory->cases_number.y; i++) {
        inventory->cases[i] = malloc(sizeof(inventory_case_t) * \
        (inventory->cases_number.x + 1));
        inventory->empty_cases[i] = malloc(sizeof(sfRectangleShape *) * \
        (inventory->cases_number.x + 1));
        inventory_cases_create_two(inventory, i, texture, info_texture);
        inventory_cases_create_three(inventory, i, font);
    }
}