/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** main_menu_play_part_buttons.c
*/

#include "my_game.h"
#include "cut_scene.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

int create_new_save_two(char *save_name, my_game_t *rpg)
{
    if (create_new_save_quest(save_name) == -1)
        return (-1);
    if (create_new_save_stats(save_name) == -1)
        return (-1);
    if (create_new_save_enemy(save_name) == -1)
        return (-1);
    if (create_new_save_pnj(save_name) == -1)
        return (-1);
    if (create_new_save_map(save_name) == -1)
        return (-1);
    if (first_cut_scene(rpg) == -1)
        return (-1);
    return (0);
}

int create_new_save(char *save_name, my_game_t *rpg)
{
    if (create_new_save_global(save_name) == -1)
        return (-1);
    if (create_new_save_inventory(save_name) == -1)
        return (-1);
    if (create_new_save_player(save_name) == -1)
        return (-1);
    if (create_new_save_inventory_two(save_name) == -1)
        return (-1);
    if (create_new_save_skill(save_name) == -1)
        return (-1);
    return (create_new_save_two(save_name, rpg));
}