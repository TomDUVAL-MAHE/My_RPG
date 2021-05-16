/*
** EPITECH PROJECT, 2020
** button.c
** File description:
** function button
*/

#include "my_inventory.h"

void inventory_convert_inventory_list_to_new_list_two(inventory_t *inventory, \
char ***inventory_list, char **new_list, int *storage)
{
    for (int j = 0; j < inventory->cases_number.x; j++) {
        if (my_strcmp(inventory_list[storage[0]][j], "EMPTY") != 0) {
            new_list[storage[1]] = my_strdup(inventory_list[storage[0]][j]);
            storage[1] += 1;
        } else
            storage[2] += 1;
    }
}

int inventory_convert_inventory_list_to_new_list(inventory_t *inventory, \
char ***inventory_list, char **new_list)
{
    int *storage = malloc(sizeof(int) * 3);

    storage[1] = 0;
    storage[2] = 0;
    for (int i = 0; i < inventory->cases_number.y; i++) {
        storage[0] = i;
        inventory_convert_inventory_list_to_new_list_two(inventory, \
        inventory_list, new_list, storage);
    }
    for (int i = 0; i < storage[2]; i++) {
        new_list[storage[1] + i] = my_strdup("EMPTY");
    }
    return (storage[1] + storage[2]);
}

void inventory_update_list_with_new_list(char ***inventory_list, \
int total, char **new_list, inventory_t *inventory)
{
    int actual_y = 0;
    int actual_x = 0;

    for (int i = 0; i < total; i++) {
        inventory_list[actual_y][actual_x] = my_strdup(new_list[i]);
        if (actual_x + 1 < inventory->cases_number.x)
            actual_x++;
        else {
            actual_x = 0;
            actual_y += 1;
        }
    }
}

void inventory_add_item_to_list(inventory_t *inventory, item_t *items, \
char ***inventory_list, char *item_name)
{
    sfVector2i empty_pos = {0, 0};

    inventory_update_list(inventory, items, inventory_list);
    empty_pos = inventory_list_get_empty_pos(inventory, inventory_list);
    if (empty_pos.x == -1)
        return;
    inventory_list[empty_pos.y][empty_pos.x] = my_strdup(item_name);
    inventory_fill_with_list(inventory, items, inventory_list);
}

void inventory_in_changement(inventory_t *inventory, sfVector2i mouse_pos, \
sfRenderWindow *window)
{
    sfRectangleShape *sprite = sfRectangleShape_create();

    if (inventory->is_movement == true) {
        sfRectangleShape_setOrigin(sprite, (sfVector2f){inventory->cases\
            [inventory->movement_pos.y][inventory->movement_pos.x].size.x / 2\
            , inventory->cases[inventory->movement_pos.y]\
            [inventory->movement_pos.x].size.y / 2});
        sfRectangleShape_setPosition(sprite, (sfVector2f){mouse_pos.x, \
            mouse_pos.y});
        sfRectangleShape_setTexture(sprite, inventory->movement_texture, true);
        sfRectangleShape_setSize(sprite, inventory->cases[inventory->\
        movement_pos.y][inventory->movement_pos.x].size);
        sfRenderWindow_drawRectangleShape(window, sprite, NULL);
    }
    sfRectangleShape_destroy(sprite);
}