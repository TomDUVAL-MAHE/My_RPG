/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** enemy_init_enemy_type
*/

#include "my_enemy.h"

void check_boss(enemy_type e_type, char **path)
{
    if (e_type == BOSS)
        *path = "assets/enemies/boss.png";
}

void check_wolf(enemy_type e_type, char **path)
{
    if (e_type == WOLF)
        *path = "assets/enemies/wolf.png";
}

void check_orc(enemy_type e_type, char **path)
{
    if (e_type == ORC_LONGSWORD)
        *path = "assets/enemies/orclongepee.png";
    if (e_type == ORC_SCYTHE)
        *path = "assets/enemies/orcfaux.png";
    if (e_type == ORC_SPEAR)
        *path = "assets/enemies/orchalbaerd.png";
}

char *get_path_and_weapon_type_from_enemy_type(enemy_type e_type)
{
    char *path;

    check_boss(e_type, &path);
    check_wolf(e_type, &path);
    check_orc(e_type, &path);
    return (path);
}