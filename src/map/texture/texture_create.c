/*
** EPITECH PROJECT, 2021
** texture_create
** File description:
** desc
*/

#include "my_map.h"

textures_t *texture_create(void)
{
    textures_t *textures = malloc(sizeof(textures_t) * 2);

    textures[0] = texture_load("assets/textures/tiles/ground.legend");
    textures[1] = texture_load("assets/textures/tiles/build.legend");
    if (textures[0].nb_texture == 0) {
        return (NULL);
    }
    return (textures);
}