/*
** EPITECH PROJECT, 2021
** main
** File description:
** desc
*/

#include "my_game.h"

char ***create_inventory_list(sfVector2i size, item_t *items)
{
    char ***list = malloc(sizeof(char **) * (size.y + 1000));

    if (items) {}
    for (int i = 0; i < size.y; i++) {
        list[i] = malloc(sizeof(char *) * (size.x + 1000));
        for (int j = 0; j < size.x; j++) {
            list[i][j] = my_strdup("EMPTY");
        }
    }
    return (list);
}

inventory_t *inventory_scene_create_inv_one(sfRenderWindow *window, \
sfVector2u window_size, item_t *items, char ***inventory_list)
{
    inventory_t *inventory;

    if (window) {}
    inventory = inventory_create((sfVector2f){window_size.x * 0.57, \
        window_size.y * 0.23}, (sfVector2i){5, 5}, (sfVector2i){window_size.x \
        * 0.06, window_size.y * 0.1}, (sfVector2i){window_size.x * 0.015, \
        window_size.y * 0.03});
    inventory_background_create(inventory, sfTexture_createFromFile\
    ("assets/carpet.png", NULL), (sfColor){0, 0, 0, 0}, false);
    inventory_change_display(inventory, true);
    inventory_cases_create(inventory, sfTexture_createFromFile\
    ("empty.png", NULL), sfTexture_createFromFile("empty.png", NULL), \
    sfFont_createFromFile("assets/fonts/arial.ttf"));
    inventory_fill_with_list(inventory, items, inventory_list);
    return (inventory);
}

inventory_t *inventory_scene_create_inv_two(sfRenderWindow *window, \
sfVector2u window_size, item_t *items, char ***inventory_list)
{
    inventory_t *inventory;

    if (window) {}
    inventory = inventory_create((sfVector2f){window_size.x * 0.32, \
        window_size.y * 0.23}, (sfVector2i){1, 5}, (sfVector2i){window_size.x \
        * 0.06, window_size.y * 0.1}, (sfVector2i){window_size.x * 0.015, \
        window_size.y * 0.03});
    inventory_background_create(inventory, sfTexture_createFromFile\
    ("assets/carpet.png", NULL), (sfColor){0, 0, 0, 0}, false);
    inventory_change_display(inventory, true);
    inventory_cases_create(inventory, sfTexture_createFromFile\
    ("empty.png", NULL), sfTexture_createFromFile("empty.png", NULL), \
    sfFont_createFromFile("assets/fonts/arial.ttf"));
    inventory_fill_with_list(inventory, items, inventory_list);
    return (inventory);
}

void inventory_scene_display_inv_two(inventory_t *inventory_one, \
sfRenderWindow *window)
{
    inventory_display(inventory_one, window);
    inventory_display_info(inventory_one, window, \
    sfMouse_getPositionRenderWindow(window));
    inventory_in_changement(inventory_one, \
    sfMouse_getPositionRenderWindow(window), window);
}

void inventory_scene_display_inv_one(inventory_t *inventory_one, \
sfRenderWindow *window)
{
    inventory_display(inventory_one, window);
    inventory_display_info(inventory_one, window, \
    sfMouse_getPositionRenderWindow(window));
    inventory_in_changement(inventory_one, \
    sfMouse_getPositionRenderWindow(window), window);
}