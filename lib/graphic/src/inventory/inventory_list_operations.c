/*
** EPITECH PROJECT, 2020
** button.c
** File description:
** function button
*/

#include "my_inventory.h"

void inventory_fill_with_list_two(item_t *items, inventory_t \
*inventory, char ***inventory_list, int i)
{
    for (int j = 0; j < inventory->cases_number.x; j++) {
        if (my_strcmp(inventory_list[i][j], "EMPTY") == 0)
            inventory_case_change_display(&(inventory->cases[i][j]), \
            false);
        else {
            inventory_case_change_display(&(inventory->cases[i][j]), true);
            inventory_case_change_texture(&(inventory->cases[i][j]), \
            item_return_texture(items, inventory_list[i][j]));
            inventory_case_info_text_change_buffer(&(inventory->\
            cases[i][j]), item_return_info(items, inventory_list[i][j]));
        }
    }
}

void inventory_fill_with_list(inventory_t *inventory, \
item_t *items, char ***inventory_list)
{
    for (int i = 0; i < inventory->cases_number.y; i++) {
        inventory_fill_with_list_two(items, inventory, inventory_list, i);
    }
}

void inventory_update_list_two(inventory_t *inventory, \
item_t *items, char ***inventory_list, int i)
{
    for (int j = 0; j < inventory->cases_number.x; j++) {
        inventory_list[i][j] = my_strdup(item_return_name(items, \
        inventory->cases[i][j].texture));
        if (inventory->cases[i][j].is_display == false)
            inventory_list[i][j] = my_strdup("EMPTY");
    }
}

void inventory_update_list(inventory_t *inventory, item_t *items, \
char ***inventory_list)
{
    for (int i = 0; i < inventory->cases_number.y; i++) {
        inventory_update_list_two(inventory, items, inventory_list, i);
    }
}

char ***inventory_create_malloc_list(inventory_t *inventory)
{
    char ***list = malloc(sizeof(char **) * (inventory->cases_number.y + 2));

    for (int i = 0; i < inventory->cases_number.y; i++) {
        list[i] = malloc(sizeof(char *) * (inventory->cases_number.x + 2));
    }
    return (list);
}