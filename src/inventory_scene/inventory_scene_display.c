/*
** EPITECH PROJECT, 2021
** main
** File description:
** desc
*/

#include "my_inventory_scene.h"

void inventory_scene_display_picture_list(sfRectangleShape **picture_list, \
sfRenderWindow *window, int dir)
{
    for (int i = 1; i < 9; i++) {
        sfRenderWindow_drawRectangleShape(window, picture_list[i], NULL);
    }
    if (dir == 2) {
        sfRenderWindow_drawRectangleShape(window, picture_list[7], NULL);
        sfRenderWindow_drawRectangleShape(window, picture_list[5], NULL);
    }
}

void inventory_scene_display_bar(inventory_scene_t *inventory_scene, \
sfRenderWindow *window)
{
    sfRenderWindow_drawRectangleShape(window, inventory_scene->health_bar[0], \
    NULL);
    sfRenderWindow_drawRectangleShape(window, inventory_scene->health_bar[1], \
    NULL);
    sfRenderWindow_drawRectangleShape(window, inventory_scene->level_bar[0], \
    NULL);
    sfRenderWindow_drawRectangleShape(window, inventory_scene->level_bar[1], \
    NULL);
    sfRenderWindow_drawRectangleShape(window, inventory_scene->attack_bar, \
    NULL);
}

void inventory_scene_display_text(inventory_scene_t *inventory_scene, \
sfRenderWindow *window)
{
    for (int i = 0; i < 3; i++) {
        text_display(&(inventory_scene->text[i]), window);
    }
    sfRenderWindow_drawRectangleShape(window, \
    inventory_scene->arrow_button[0], NULL);
    sfRenderWindow_drawRectangleShape(window, \
    inventory_scene->arrow_button[1], NULL);
}

void inventory_scene_display(inventory_scene_t *inventory_scene, \
sfRenderWindow *window)
{
    sfRenderWindow_drawRectangleShape(window, inventory_scene->\
    picture_list[0], NULL);
    sfRenderWindow_drawRectangleShape(window, \
    inventory_scene->sorting_button, NULL);
    inventory_scene_display_bar(inventory_scene, window);
    inventory_scene_display_text(inventory_scene, window);
    inventory_scene_display_inv_one(inventory_scene->inventory_one, window);
    inventory_scene_display_picture_list(inventory_scene->picture_list, \
    window, inventory_scene->dir);
    inventory_scene_display_inv_one(inventory_scene->inventory_two, window);
    inventory_display_info(inventory_scene->inventory_one, window, \
    sfMouse_getPositionRenderWindow(window));
    inventory_in_changement(inventory_scene->inventory_one, \
    sfMouse_getPositionRenderWindow(window), window);
}