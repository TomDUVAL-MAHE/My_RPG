/*
** EPITECH PROJECT, 2021
** world_edit_texture
** File description:
** desc
*/

#include "my_world_edit.h"
#include "my.h"

void world_edit_texture_thickness(world_edit_t *world_edit, \
sfRectangleShape *shape, int i)
{
    if (i == world_edit->texture_selected) {
        sfRectangleShape_setOutlineThickness(shape, 1);
    } else {
        sfRectangleShape_setOutlineThickness(shape, 0);
    }
}

int world_edit_draw_textures(world_edit_t *world_edit, \
sfRectangleShape *shape, sfVector2f pos, sfVector2i m_pos)
{
    int value = 0;

    if (m_pos.x > pos.x && m_pos.x < pos.x + 105 && \
    m_pos.y > pos.y && m_pos.y < pos.y + 105) {
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

void world_edit_texture(sfRenderWindow *window, world_edit_t *world_edit,  \
map_t *map)
{
    sfRectangleShape *shape = sfRectangleShape_create();
    sfVector2f pos = {world_edit->pos.x + 8, world_edit->pos.y + 100};
    sfVector2i m_pos = sfMouse_getPositionRenderWindow(window);
    int i = world_edit->scroll_texture;

    for (; i < map->textures[0].nb_texture; i++) {
        world_edit_texture_thickness(world_edit, shape, i);
        if (world_edit_draw_textures(world_edit, shape, pos, m_pos))
            world_edit->texture_selected = i;
        sfRectangleShape_setTexture(shape, map->textures[0].texture[i], sfTrue);
        sfRenderWindow_drawRectangleShape(window, shape, NULL);
        pos.x += 98;
        if (pos.x + 98 > world_edit->pos.x + world_edit->size.x)
            pos = (sfVector2f){world_edit->pos.x + 8, pos.y + 105};
        if (m_pos.x < world_edit->pos.x && sfMouse_isButtonPressed(sfMouseLeft)\
            && world_edit->texture_selected != 0)
            map->tiles[world_edit->tile_selected.y * map->size.x + \
            world_edit->tile_selected.x].ground = world_edit->texture_selected;
    }
    sfRectangleShape_destroy(shape);
}