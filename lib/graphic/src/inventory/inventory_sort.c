/*
** EPITECH PROJECT, 2020
** button.c
** File description:
** function button
*/

#include "my_inventory.h"

void inventory_sort_by_name(char **new_list, int total)
{
    int change = 0;

    for (int i = 1; i < total; i++) {
        if (my_strcmp(new_list[i], new_list[i - 1]) < 0 && \
        my_strcmp(new_list[i], "EMPTY") != 0 && \
        my_strcmp(new_list[i - 1], "EMPTY") != 0) {
            char *save = my_strdup(new_list[i]);
            new_list[i] = my_strdup(new_list[i - 1]);
            new_list[i - 1] = save;
            change = 1;
        }
    }
    if (change == 1)
        inventory_sort_by_name(new_list, total);
}

void inventory_sort_by_attack(char **new_list, int total, item_t *items)
{
    int change = 0;

    for (int i = 1; i < total; i++) {
        if (my_strcmp(new_list[i], "EMPTY") != 0 && \
        my_strcmp(new_list[i - 1], "EMPTY") != 0 && \
        (item_return_attack(items, new_list[i]) > \
        item_return_attack(items, new_list[i - 1]))) {
            char *save = my_strdup(new_list[i]);
            new_list[i] = my_strdup(new_list[i - 1]);
            new_list[i - 1] = save;
            change = 1;
        }
    }
    if (change == 1)
        inventory_sort_by_attack(new_list, total, items);
}

void inventory_sort_by_health(char **new_list, int total, item_t *items)
{
    int change = 0;

    for (int i = 1; i < total; i++) {
        if (my_strcmp(new_list[i], "EMPTY") != 0 && \
        my_strcmp(new_list[i - 1], "EMPTY") != 0  \
        && (item_return_health(items, new_list[i]) > \
        item_return_health(items, new_list[i - 1]))) {
            char *save = my_strdup(new_list[i]);
            new_list[i] = my_strdup(new_list[i - 1]);
            new_list[i - 1] = save;
            change = 1;
        }
    }
    if (change == 1)
        inventory_sort_by_health(new_list, total, items);
}

void inventory_sort_by_type(char **new_list, int total, item_t *items)
{
    int change = 0;

    for (int i = 1; i < total; i++) {
        if (my_strcmp(new_list[i], "EMPTY") != 0 && \
        my_strcmp(new_list[i - 1], "EMPTY") != 0  \
        && (item_return_type(items, new_list[i]) > \
        item_return_type(items, new_list[i - 1]))) {
            char *save = my_strdup(new_list[i]);
            new_list[i] = my_strdup(new_list[i - 1]);
            new_list[i - 1] = save;
            change = 1;
        }
    }
    if (change == 1)
        inventory_sort_by_type(new_list, total, items);
}

void inventory_sort_list(inventory_t *inventory, item_t *items, \
char ***inventory_list, char *sort_type)
{
    char **new_list = malloc(sizeof(char *) * \
    (inventory->cases_number.y * (inventory->cases_number.x)));
    int empty_number = 0;

    inventory_update_list(inventory, items, inventory_list);
    empty_number = inventory_convert_inventory_list_to_new_list\
    (inventory, inventory_list, new_list);
    if (my_strcmp(sort_type, "NAME") == 0)
        inventory_sort_by_name(new_list, empty_number);
    if (my_strcmp(sort_type, "ATTACK") == 0)
        inventory_sort_by_attack(new_list, empty_number, items);
    if (my_strcmp(sort_type, "HEALTH") == 0)
        inventory_sort_by_health(new_list, empty_number, items);
    if (my_strcmp(sort_type, "TYPE") == 0)
        inventory_sort_by_type(new_list, empty_number, items);
    inventory_update_list_with_new_list(inventory_list, \
    empty_number, new_list, inventory);
    inventory_fill_with_list(inventory, items, inventory_list);
}