/*
** EPITECH PROJECT, 2021
** main
** File description:
** desc
*/

#include "my_inventory_scene.h"

void inventory_texture_get_path_two(char *name, char *path)
{
    if (name[0] == 'W') {
        my_strcat(path, "weapons/weapon");
        name += my_strlen(name) - 1;
        name[0] += 1;
        my_strcat(path, name);
        my_strcat(path, ".png");
    }
    if (name[0] == 'B' || name[0] == 'P' || name[1] == 'X') {
        my_strcat(path, "weapons/");
        my_strcat(path, my_strlowcase(name));
        my_strcat(path, ".png");
    }
}

void inventory_texture_get_path(char *name, char *path)
{
    if (name[0] == 'H') {
        my_strcat(path, "hats/");
        my_strcat(path, my_strlowcase(name));
        my_strcat(path, ".png");
    }
    if (name[0] == 'S') {
        my_strcat(path, "legs/legs");
        my_strcat(path, name + my_strlen(name) - 1);
        my_strcat(path, ".png");
    }
    inventory_texture_get_path_two(name, path);
}

sfIntRect setup_area(int dir)
{
    if (dir == 0)
        return (PLAYER_WALK_DOWN_RECT);
    if (dir == 1)
        return (PLAYER_WALK_LEFT_RECT);
    if (dir == 2)
        return (PLAYER_WALK_UP_RECT);
    if (dir == 3)
        return (PLAYER_WALK_RIGHT_RECT);
    return ((sfIntRect){0, 0, 0, 0});
}

sfTexture *inventory_texture(char *buffer, int dir)
{
    char *name = my_strdup(buffer);
    char *path = malloc(sizeof(char) * 1000);
    sfIntRect area = setup_area(dir);

    path[0] = '\0';
    my_strcat(path, "assets/characters/player/");
    if (name[0] == 'A' && name[1] != 'X') {
        my_strcat(path, "armors/");
        my_strcat(path, my_strlowcase(name));
        my_strcat(path, ".png");
    }
    inventory_texture_get_path(name, path);
    if (dir == 4)
        return (sfTexture_createFromFile(path, NULL));
    return (sfTexture_createFromFile(path, &area));
}

void inventory_scene_update_picture_sexe(inventory_scene_t *inventory_scene, \
bool is_man)
{
    sfIntRect area = setup_area(inventory_scene->dir);

    if (is_man)
        sfRectangleShape_setTexture(inventory_scene->picture_list[1], \
        sfTexture_createFromFile("assets/characters/player/man.png", \
        &area), true);
    if (!is_man)
        sfRectangleShape_setTexture(inventory_scene->picture_list[1], \
        sfTexture_createFromFile("assets/characters/player/woman.png", \
        &area), true);
}