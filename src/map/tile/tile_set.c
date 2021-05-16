/*
** EPITECH PROJECT, 2021
** tile_set
** File description:
** desc
*/

#include "my_map.h"
#include <math.h>

sfVector2f iso_projection(int x, int y, int z, int zoom)
{
    sfVector2f point = {x, y};

    x *= zoom;
    y *= zoom;
    point.x = cos((360 - 45 / 2) * M_PI / 180) * x;
    point.x -= cos(45 / 2 * M_PI / 180) * y;
    point.y = sin(35 / 2 * M_PI / 180) * y;
    point.y += sin(35 / 2 * M_PI / 180) * x - z;
    return (point);
}

tile_t tile_set(int ground, int building, int zoom)
{
    tile_t tile;

    tile.ground = ground;
    tile.building = building;
    tile.vector = malloc(sizeof(sfVector2f) * 4);
    tile.vector[0] = iso_projection(0, 0, 0, zoom);
    tile.vector[1] = iso_projection((0 + 1), 0, 0, zoom);
    tile.vector[2] = iso_projection((0 + 1), (0 + 1), 0, zoom);
    tile.vector[3] = iso_projection(0, (0 + 1), 0, zoom);
    tile.shape = sfConvexShape_create();
    sfConvexShape_setPointCount(tile.shape, 4);
    sfConvexShape_setPoint(tile.shape, 0, tile.vector[0]);
    sfConvexShape_setPoint(tile.shape, 1, tile.vector[1]);
    sfConvexShape_setPoint(tile.shape, 2, tile.vector[2]);
    sfConvexShape_setPoint(tile.shape, 3, tile.vector[3]);
    return (tile);
}