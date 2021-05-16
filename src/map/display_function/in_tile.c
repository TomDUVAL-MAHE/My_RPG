/*
** EPITECH PROJECT, 2021
** hover_and_click
** File description:
** desc
*/

#include "my_map.h"

int on_right(sfVector2f pos1, sfVector2f pos2, sfVector2f point)
{
    sfVector2f vector1 = {pos2.x - pos1.x, pos2.y - pos1.y};
    sfVector2f vector2 = {point.x - pos1.x, point.y - pos1.y};
    int res = vector1.x * vector2.y - vector1.y * vector2.x;

    if (res >= 0)
        return (1);
    return (0);
}

int in_tile(tile_t tile, sfVector2f point)
{
    int res = 0;
    sfVector2f pos1 = {tile.pos.x, tile.pos.y};
    sfVector2f pos2 = { \
        tile.pos.x + tile.vector[1].x, tile.pos.y + tile.vector[1].y};

    for (int i = 0; i < 4; i++) {
        pos1.x = tile.pos.x + tile.vector[i].x;
        pos1.y = tile.pos.y + tile.vector[i].y;
        if (i + 1 < 4) {
            pos2.x = tile.pos.x + tile.vector[i + 1].x;
            pos2.y = tile.pos.y + tile.vector[i + 1].y;
        } else {
            pos2.x = tile.pos.x + tile.vector[0].x;
            pos2.y = tile.pos.y + tile.vector[0].y;
        }
        res += on_right(pos1, pos2, point);
    }
    if (res == 4)
        return (1);
    return (0);
}