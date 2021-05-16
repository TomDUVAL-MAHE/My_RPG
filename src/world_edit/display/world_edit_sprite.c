/*
** EPITECH PROJECT, 2021
** world_edit_sprite
** File description:
** desc
*/

#include "my_world_edit.h"

void world_edit_sprite_thickness(world_edit_t *world_edit, \
sfRectangleShape *shape, int i)
{
    if (i == world_edit->texture_selected) {
        sfRectangleShape_setOutlineThickness(shape, 1);
    } else {
        sfRectangleShape_setOutlineThickness(shape, 0);
    }
}

int world_edit_draw_sprite(world_edit_t *world_edit, \
sfRectangleShape *shape, sfVector2f pos, sfVector2i m_pos)
{
    int value = 0;

    if (m_pos.x > pos.x && m_pos.x < pos.x + 105 && m_pos.y > pos.y && \
    m_pos.y < pos.y + 105) {
        if (world_edit->status == CLICK) {
            value = 1;
        }
        sfRectangleShape_setSize(shape, (sfVector2f){80, 80});
        sfRectangleShape_setPosition(shape, (sfVector2f){pos.x + 5, pos.y + 5});
    } else {
        sfRectangleShape_setSize(shape, (sfVector2f){90, 90});
        sfRectangleShape_setPosition(shape, pos);
    }
    return (value);
}

void second_build(map_t *map, int val, sfVector2i s)
{
    if ((s.y - 1) * map->size.x + (s.x - 1) >= 0) {
        map->tiles[(s.y) * map->size.x + (s.x - 1)].building = val;
        map->tiles[(s.y - 1) * map->size.x + (s.x)].building = val;
        map->tiles[(s.y - 1) * map->size.x + (s.x - 1)].building = val;
    }
}

void world_edit_set_build(world_edit_t *world_edit, map_t *map)
{
    int val = (world_edit->texture_selected == 0) ? 0 : 99;
    int sel = world_edit->texture_selected;
    sfVector2i s = world_edit->tile_selected;
    int building = map->tiles[s.y * map->size.x + s.x].building;

    if (sel == 1 || (sel == 0 && building == 1)) {
        if ((s.y - 1) * map->size.x + (s.x - 1) >= 0) {
            map->tiles[(s.y - 1) * map->size.x + (s.x)].building = val;
            map->tiles[(s.y - 1) * map->size.x + (s.x - 1)].building = val;
        }
    }
    if (sel == 2 || (sel == 0 && building == 2)) {
        second_build(map, val, s);
    }
    if (sel == 3 || (sel == 0 && building == 3))
        if ((s.y - 1) * map->size.x + (s.x) >= 0)
            map->tiles[(s.y - 1) * map->size.x + (s.x)].building = val;
    map->tiles[s.y * map->size.x + s.x].building = sel;
}

void world_edit_sprite(sfRenderWindow *window, world_edit_t *world_edit, \
map_t *map)
{
    sfRectangleShape *shape = sfRectangleShape_create();
    sfVector2f pos = {world_edit->pos.x + 8, world_edit->pos.y + 100};
    sfVector2i m_pos = sfMouse_getPositionRenderWindow(window);

    for (int i = 0; i <= map->textures[1].nb_texture; i++) {
        world_edit_sprite_thickness(world_edit, shape, i);
        if (world_edit_draw_sprite(world_edit, shape, pos, m_pos)) {
            world_edit->texture_selected = i;
        }
        sfRectangleShape_setTexture(shape, map->textures[1].texture[i], sfTrue);
        sfRenderWindow_drawRectangleShape(window, shape, NULL);
        pos.x += 98;
        if (pos.x + 98 > world_edit->pos.x + world_edit->size.x) {
            pos.x = world_edit->pos.x + 8;
            pos.y += 105;
        }
        if (m_pos.x < world_edit->pos.x && \
            sfMouse_isButtonPressed(sfMouseLeft))
            world_edit_set_build(world_edit, map);
    }
    sfRectangleShape_destroy(shape);
}