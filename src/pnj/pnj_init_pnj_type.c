/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** enemy_init_enemy_type
*/

#include "my_pnj.h"

void check_woman(pnj_type e_type, char **path)
{
    if (e_type == WOMAN_ONE)
        *path = "assets/pnj/women0.png";
    if (e_type == WOMAN_TWO) {
        *path = "assets/pnj/women1.png";
    }
    if (e_type == WOMAN_THREE)
        *path = "assets/pnj/women2.png";
}

void check_child(pnj_type e_type, char **path)
{
    if (e_type == CHILD_ONE)
        *path = "assets/pnj/child1.png";
    if (e_type == CHILD_TWO) {
        *path = "assets/pnj/child2.png";
    }
    if (e_type == CHILD_THREE)
        *path = "assets/pnj/child3.png";
}

void check_fisherman(pnj_type e_type, char **path)
{
    if (e_type == FISHERMAN_ONE)
        *path = "assets/pnj/fisherman1.png";
    if (e_type == FISHERMAN_TWO) {
        *path = "assets/pnj/fisherman2.png";
    }
    if (e_type == FISHERMAN_THREE)
        *path = "assets/pnj/black_smith.png";
}

void check_guardian(pnj_type e_type, char **path)
{
    if (e_type == GUARDIAN_ONE)
        *path = "assets/pnj/guardian0.png";
    if (e_type == GUARDIAN_TWO) {
        *path = "assets/pnj/guardian1.png";
    }
    if (e_type == GUARDIAN_THREE)
        *path = "assets/pnj/guardian2.png";
}

char *get_path_from_pnj_type(pnj_type e_type)
{
    char *path;

    check_men(e_type, &path);
    check_woman(e_type, &path);
    check_child(e_type, &path);
    check_fisherman(e_type, &path);
    check_guardian(e_type, &path);
    return (path);
}