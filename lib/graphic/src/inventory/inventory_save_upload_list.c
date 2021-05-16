/*
** EPITECH PROJECT, 2020
** button.c
** File description:
** function button
*/

#include "my_inventory.h"
#include <stdio.h>

void inventory_save_list(inventory_t *inventory, char ***inventory_list, \
char *inventory_save_path, item_t *items)
{
    FILE *list_file = fopen(inventory_save_path, "w+");

    inventory_update_list(inventory, items, inventory_list);
    for (int i = 0; i < inventory->cases_number.y; i++) {
        for (int j = 0; j < inventory->cases_number.x; j++) {
            fwrite(inventory_list[i][j], my_strlen(inventory_list[i][j]), \
            1, list_file);
            fwrite(";", 1, 1, list_file);
        }
        fwrite("\n", 1, 1, list_file);
    }
    fclose(list_file);
}

int inventory_get_length(char *buffer, inventory_t *inventory)
{
    int count = 0;

    for (int i = 0; i < my_strlen(buffer) - 1; i++) {
        if (buffer[i] == '\n' && count == inventory->cases_number.x) {
            count = 0;
        } else if (buffer[i] == '\n')
            return (-1);
        if (buffer[i] == ';')
            count++;
    }
    return (inventory->cases_number.x);
}

int inventory_upload_list(inventory_t *inventory, char ***inventory_list, \
char *inventory_save_path, item_t *items)
{
    char *buffer = get_file_buffer(inventory_save_path);
    int item_number = item_get_nbr(buffer);
    int item_length = inventory_get_length(buffer, inventory);

    if (item_length != inventory->cases_number.x || item_number != \
    inventory->cases_number.y) {
        write(1, "Invalid Configuration file\n", 28);
        return (-1);
    }
    transform_item_buffer(buffer);
    for (int i = 0; i < inventory->cases_number.y; i++) {
        for (int j = 0; j < inventory->cases_number.x; j++) {
            inventory_list[i][j] = my_strdup(buffer);
            buffer += my_strlen(buffer) + 1;
        }
        buffer += my_strlen(buffer) + 1;
    }
    inventory_fill_with_list(inventory, items, inventory_list);
    return (0);
}