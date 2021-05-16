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

int stats_fill(my_game_t *rpg, char **buffer_list)
{
    if (my_array_get_size(buffer_list) != 6) {
        write(2, "Invalid Stats Save.\n", 20);
        return (-1);
    }
    rpg->game->player->stats.attack = my_getnbr(buffer_list[0]);
    rpg->game->player->stats.pv = my_getnbr(buffer_list[1]);
    rpg->game->player->stats.pv_max = my_getnbr(buffer_list[2]);
    rpg->game->player->stats.xp = my_getnbr(buffer_list[3]);
    rpg->game->player->stats.xp_max = my_getnbr(buffer_list[4]);
    rpg->game->player->stats.level = my_getnbr(buffer_list[5]);
    return (0);
}

int stats_upload(my_game_t *rpg, char *path)
{
    char *buffer = load_file_in_mem(path);
    char **buffer_list = NULL;

    if (buffer == NULL)
        return (-1);
    buffer_list = my_str_to_word_array_separators(buffer, "\n");
    if (stats_fill(rpg, buffer_list) == -1) {
        my_array_free(buffer_list);
        return (-1);
    }
    my_array_free(buffer_list);
    return (0);
}

int load_stats(my_game_t *rpg, char *save_name)
{
    char *path = malloc(sizeof(char) * (my_strlen("saves/stats/stats") + \
    my_strlen(save_name) + 1));

    path[0] = '\0';
    my_strcat(path, "saves/stats/stats");
    my_strcat(path, save_name);
    if (stats_upload(rpg, path) == -1)
        return (-1);
    return (0);
}