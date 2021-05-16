/*
** EPITECH PROJECT, 2021
** texture_load
** File description:
** desc
*/

#include "my_map.h"

textures_t texture_load(char *pathname)
{
    textures_t texture = {0, NULL};
    char *buf = readfile(pathname);
    char **buf_tab;
    sfImage *image = sfImage_createFromColor(100, 100, sfTransparent);

    if (buf == NULL)
        return (texture);
    buf_tab = my_strtok(buf, "\n\t\0");
    for (int i = 0; buf_tab[i]; i++)
        texture.nb_texture++;
    texture.texture = malloc(sizeof(sfTexture *) * (2 + texture.nb_texture));
    texture.texture[0] = sfTexture_createFromImage(image, &(sfIntRect)\
    {0, 0, 0, 0});
    for (int i = 1; i <= texture.nb_texture; i++)
        texture.texture[i] = sfTexture_createFromFile(buf_tab[i - 1], NULL);
    texture.texture[texture.nb_texture + 1] = NULL;
    for (int i = 0; buf_tab[i]; i++)
        free(buf_tab[i]);
    free(buf);
    sfImage_destroy(image);
    return (texture);
}