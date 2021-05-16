/*
** EPITECH PROJECT, 2020
** button.c
** File description:
** function button
*/

#include "my_inventory.h"

void inventory_fill_cases_two(inventory_case_t *cases, bool is_here, \
sfTexture *texture, char *info)
{
    if (is_here == true) {
        inventory_case_change_display(cases, true);
        inventory_case_change_texture(cases, texture);
        inventory_case_info_text_change_buffer(cases, info);
    } else {
        inventory_case_change_display(cases, false);
    }
}

void inventory_fill_cases(inventory_t *inventory, bool **is_here, \
sfTexture ***texture, char ***info)
{
    for (int i = 0; i < inventory->cases_number.y; i++) {
        for (int j = 0; j < inventory->cases_number.x; j++)
            inventory_fill_cases_two(&(inventory->cases[i][j]), \
            is_here[i][j], texture[i][j], info[i][j]);
    }
}

void inventory_fill_case(inventory_t *inventory, sfVector2i pos, \
char *info, sfTexture *texture)
{
    inventory_case_change_display(&(inventory->cases[pos.y][pos.x]), true);
    inventory_case_change_texture(&(inventory->cases[pos.y][pos.x]), texture);
    inventory_case_info_text_change_buffer(&(inventory->cases[pos.y]\
    [pos.x]), info);
}

sfVector2i inventory_list_get_empty_pos_two(inventory_t *inventory, \
char ***inventory_list, int i)
{
    for (int j = 0; j < inventory->cases_number.x; j++) {
        if (my_strcmp(inventory_list[i][j], "EMPTY") == 0)
            return ((sfVector2i){j, i});
    }
    return ((sfVector2i){-1, -1});
}

sfVector2i inventory_list_get_empty_pos(inventory_t *inventory, \
char ***inventory_list)
{
    sfVector2i r = {0, 0};

    for (int i = 0; i < inventory->cases_number.y; i++) {
        r = inventory_list_get_empty_pos_two(inventory, inventory_list, i);
        if (r.x != -1)
            return (r);
    }
    return ((sfVector2i){-1, -1});
}