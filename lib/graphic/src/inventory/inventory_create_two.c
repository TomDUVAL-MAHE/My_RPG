/*
** EPITECH PROJECT, 2020
** button.c
** File description:
** function button
*/

#include "my_inventory.h"

void inventory_define_total_size(inventory_t *inventory)
{
    sfVector2f size = {0, 0};

    size.x = (inventory->cases_number.x * (inventory->cases_size.x + \
    inventory->cases_espacement.x)) + inventory->cases_espacement.x;
    size.y = (inventory->cases_number.y * (inventory->cases_size.y + \
    inventory->cases_espacement.y)) + inventory->cases_espacement.y;
    inventory->size = size;
}

sfVector2i inventory_cursor_is_in_cases(inventory_t *inventory, \
sfVector2i mouse_pos, int i)
{
    for (int j = 0; j < inventory->cases_number.x; j++) {
        if (mouse_pos.x >= inventory->cases[i][j].pos.x && \
        mouse_pos.x <= inventory->cases[i][j].pos.x + \
        inventory->cases[i][j].size.x && mouse_pos.y >= \
        inventory->cases[i][j].pos.y && mouse_pos.y <= \
        inventory->cases[i][j].pos.y + inventory->cases[i][j].size.y) {
            return ((sfVector2i){j, i});
        }
    }
    return ((sfVector2i){-1, -1});
}