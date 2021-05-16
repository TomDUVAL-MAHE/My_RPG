/*
** EPITECH PROJECT, 2021
** main
** File description:
** desc
*/

#include "my_inventory_scene.h"

sfRectangleShape *picture_setup(sfTexture *texture, sfVector2f pos, \
sfVector2f size)
{
    sfRectangleShape *shape = sfRectangleShape_create();

    sfRectangleShape_setPosition(shape, pos);
    sfRectangleShape_setSize(shape, size);
    sfRectangleShape_setTexture(shape, texture, true);
    return (shape);
}

void inventory_scene_picture_list_setup_three(sfVector2u window_size, \
sfRectangleShape **picture_list)
{
    picture_list[6] = picture_setup(sfTexture_createFromFile\
    ("empty.png", NULL), (sfVector2f)\
    {window_size.x * 0.005, \
        window_size.y * 0.16 + window_size.y * 0.03}, (sfVector2f)\
    {window_size.x * 0.35, window_size.y * 0.57});
    picture_list[7] = picture_setup(sfTexture_createFromFile\
    ("empty.png", NULL), (sfVector2f)\
    {window_size.x * 0.005, \
        window_size.y * 0.16 + window_size.y * 0.03}, (sfVector2f)\
    {window_size.x * 0.35, window_size.y * 0.57});
    picture_list[8] = picture_setup(sfTexture_createFromFile\
    ("assets/inventory/trash.png", NULL), (sfVector2f)\
    {window_size.x * 0.882, \
        window_size.y * 0.779}, (sfVector2f)\
    {window_size.x * 0.06, window_size.y * 0.10});
}

void inventory_scene_picture_list_setup_two(sfVector2u window_size, \
sfRectangleShape **picture_list)
{
    picture_list[3] = picture_setup(sfTexture_createFromFile\
    ("assets/inventory/skills.png", NULL), (sfVector2f)\
    {window_size.x * 0.52, window_size.y * 0.04}, \
    (sfVector2f){window_size.x * 0.417, window_size.y * 0.13});
    picture_list[4] = picture_setup(sfTexture_createFromFile\
    ("empty.png", NULL), (sfVector2f)\
    {window_size.x * 0.005, \
        window_size.y * 0.16 + window_size.y * 0.03}, (sfVector2f)\
    {window_size.x * 0.35, window_size.y * 0.57});
    picture_list[5] = picture_setup(sfTexture_createFromFile\
    ("empty.png", NULL), (sfVector2f)\
    {window_size.x * 0.005, \
        window_size.y * 0.16 + window_size.y * 0.03}, (sfVector2f)\
    {window_size.x * 0.35, window_size.y * 0.57});
    inventory_scene_picture_list_setup_three(window_size, picture_list);
}

sfRectangleShape **inventory_scene_picture_list_setup(sfVector2u window_size)
{
    sfRectangleShape **picture_list = malloc(sizeof(sfRectangleShape *) * 9);
    sfIntRect area = PLAYER_WALK_DOWN_RECT;

    picture_list[0] = picture_setup(sfTexture_createFromFile\
    ("assets/inventory/back.png", NULL), (sfVector2f){0, 0}, \
    (sfVector2f){window_size.x, window_size.y});
    picture_list[1] = picture_setup(sfTexture_createFromFile\
    ("assets/characters/player/man.png", &area), (sfVector2f)\
    {window_size.x * 0.005, \
        window_size.y * 0.16 + window_size.y * 0.03}, (sfVector2f)\
    {window_size.x * 0.35, window_size.y * 0.57});
    picture_list[2] = picture_setup(sfTexture_createFromFile\
    ("assets/inventory/inventory.png", NULL), (sfVector2f)\
    {window_size.x * 0.06, window_size.y * 0.04}, \
    (sfVector2f){window_size.x * 0.417, window_size.y * 0.13});
    inventory_scene_picture_list_setup_two(window_size, picture_list);
    return (picture_list);
}

void inventory_scene_setup_case_limit(inventory_scene_t *inventory_scene)
{
    inventory_case_add_type_limit(inventory_scene->inventory_two, 1, \
    (sfVector2i){0, 1});
    inventory_case_add_type_limit(inventory_scene->inventory_two, 5, \
    (sfVector2i){0, 0});
    inventory_case_add_type_limit(inventory_scene->inventory_two, 9, \
    (sfVector2i){0, 2});
    inventory_case_add_type_limit(inventory_scene->inventory_two, 6, \
    (sfVector2i){0, 3});
    inventory_case_add_type_limit(inventory_scene->inventory_two, 8, \
    (sfVector2i){0, 4});
}