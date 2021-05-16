/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** main_menu_play_part_buttons.c
*/

#include "my_game.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include "my_world_edit.h"
#include "my_quest.h"

FILE *return_file_descriptor(char *save_name, char *first_path)
{
    char *path = malloc(sizeof(char) * (my_strlen(first_path) + \
    my_strlen(save_name) + 1));
    FILE *save = NULL;

    path[0] = '\0';
    my_strcat(path, first_path);
    my_strcat(path, save_name);
    save = fopen(path, "w+");
    free(path);
    return (save);
}

void save_gestion(my_game_t *rpg)
{
    save_inventory(rpg, rpg->save_name);
    save_skills(rpg, rpg->save_name);
    save_stats(rpg, rpg->save_name);
    save_player(rpg, rpg->save_name);
    save_map(rpg->game->map, rpg->save_name);
    save_quest(rpg, rpg->save_name);
    save_enemy(rpg, rpg->save_name);
    save_pnj(rpg, rpg->save_name);
}