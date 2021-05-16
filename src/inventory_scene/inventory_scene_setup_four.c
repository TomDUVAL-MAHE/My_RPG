/*
** EPITECH PROJECT, 2021
** main
** File description:
** desc
*/

#include "my_inventory_scene.h"

void inventory_scene_setup_empty_picture(inventory_scene_t *inventory_scene)
{
    sfRectangleShape_setTexture(inventory_scene->inventory_two->empty_cases\
    [0][0], sfTexture_createFromFile("assets/items/hat0.png", NULL), true);
    sfRectangleShape_setTexture(inventory_scene->inventory_two->empty_cases\
    [1][0], sfTexture_createFromFile("assets/items/armor0.png", NULL), true);
    sfRectangleShape_setTexture(inventory_scene->inventory_two->empty_cases\
    [2][0], sfTexture_createFromFile("assets/items/shoes0.png", NULL), true);
    sfRectangleShape_setTexture(inventory_scene->inventory_two->empty_cases\
    [3][0], sfTexture_createFromFile("assets/items/ring0.png", NULL), true);
    sfRectangleShape_setTexture(inventory_scene->inventory_two->empty_cases\
    [4][0], sfTexture_createFromFile("assets/items/sabre0.png", NULL), true);
}

void inventory_scene_setup_text(inventory_scene_t *inventory_scene)
{
    inventory_scene->text[1] = text_create((sfVector2f)\
    {inventory_scene->window_size.x * 0.06, inventory_scene->window_size.y \
        * 0.75 + inventory_scene->window_size.y * 0.085}, "LVL : X -> Y / Z XP"\
    , sfFont_createFromFile("assets/fonts/arial.ttf"), true);
    text_change_fill_color(&(inventory_scene->text[1]), sfWhite);
    text_change_char_size(&(inventory_scene->text[1]), \
    inventory_scene->window_size.y * 0.04);
    inventory_scene->text[2] = text_create((sfVector2f)\
    {inventory_scene->window_size.x * 0.10, inventory_scene->window_size.y \
        * 0.69 + inventory_scene->window_size.y * 0.025}, "ATTACK : X"\
    , sfFont_createFromFile("assets/fonts/arial.ttf"), true);
    text_change_fill_color(&(inventory_scene->text[2]), sfWhite);
    text_change_char_size(&(inventory_scene->text[2]), \
    inventory_scene->window_size.y * 0.04);
}

void inventory_scene_setup_five(inventory_scene_t *inventory_scene)
{
    inventory_scene->text = malloc(sizeof(text_t) * 5);
    inventory_scene->text[0] = text_create((sfVector2f)\
    {inventory_scene->window_size.x * 0.12, inventory_scene->window_size.y \
        * 0.75 + inventory_scene->window_size.y * 0.025}, "PV : X / Y", \
    sfFont_createFromFile("assets/fonts/arial.ttf"), true);
    text_change_fill_color(&(inventory_scene->text[0]), sfWhite);
    text_change_char_size(&(inventory_scene->text[0]), \
    inventory_scene->window_size.y * 0.04);
    inventory_scene_setup_text(inventory_scene);
    inventory_scene_setup_empty_picture(inventory_scene);
}

void inventory_scene_setup_four(inventory_scene_t *inventory_scene)
{
    inventory_scene->level_bar = malloc(sizeof(sfRectangleShape *) * 2);
    inventory_scene->level_bar[0] = sfRectangleShape_create();
    sfRectangleShape_setFillColor(inventory_scene->level_bar[0], \
    (sfColor){0, 0, 0, 0});
    sfRectangleShape_setOutlineColor(inventory_scene->level_bar[0], sfCyan);
    sfRectangleShape_setOutlineThickness(inventory_scene->level_bar[0], 2);
    sfRectangleShape_setSize(inventory_scene->level_bar[0], (sfVector2f)\
    {inventory_scene->window_size.x * 0.23, inventory_scene->window_size.y \
        * 0.04});
    inventory_scene_setup_level_bar(inventory_scene);
}