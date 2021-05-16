/*
** EPITECH PROJECT, 2021
** world_edit_save
** File description:
** desc
*/

#include "my_world_edit.h"
#include "my.h"

void display_world_edit_save(sfRenderWindow *window, world_edit_t *world_edit)
{
    sfVector2f size = {150, 20};
    sfVector2f pos = {world_edit->pos.x + 10, world_edit->pos.y + 100};

    sfRectangleShape_setPosition(world_edit->save->shape, pos);
    sfRectangleShape_setSize(world_edit->save->shape, size);
    sfRenderWindow_drawRectangleShape(window, world_edit->save->shape, NULL);
}

void input(sfRenderWindow *window, world_edit_t *world_edit)
{
    sfRectangleShape *shape = sfRectangleShape_create();
    sfVector2f pos = {world_edit->pos.x + 10, world_edit->pos.y + 100};

    sfRectangleShape_setFillColor(shape, sfWhite);
    sfRectangleShape_setPosition(shape, pos);
    sfRenderWindow_drawRectangleShape(window, shape, NULL);
    sfRectangleShape_destroy(shape);
}

void world_edit_save(sfRenderWindow *window, world_edit_t *world_edit, \
map_t *map)
{
    input(window, world_edit);
    display_world_edit_save(window, world_edit);
    world_edit->save->save_name = malloc(sizeof(char) * \
    (my_strlen("test_map") + 1));
    my_strcpy(world_edit->save->save_name, "The_map");
    write_map_save(world_edit->save, map);
    we_button_set_color(world_edit->buttons[world_edit->menu], \
    (sfColor){100, 100, 100, 255});
    world_edit->menu = MENU;
}