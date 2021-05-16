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

void save_stats_two(my_game_t *rpg, FILE *save)
{
    fwrite(text_convert_int_to_char(rpg->game->player->stats.xp), \
    my_strlen(text_convert_int_to_char(rpg->game->player->stats.xp)), \
    1, save);
    fwrite("\n", 1, 1, save);
    fwrite(text_convert_int_to_char(rpg->game->player->stats.xp_max), \
    my_strlen(text_convert_int_to_char(rpg->game->player->stats.xp_max)), \
    1, save);
    fwrite("\n", 1, 1, save);
    fwrite(text_convert_int_to_char(rpg->game->player->stats.level), \
    my_strlen(text_convert_int_to_char(rpg->game->player->stats.level)), \
    1, save);
}

void save_stats(my_game_t *rpg, char *save_name)
{
    FILE *save = return_file_descriptor(save_name, \
    "saves/stats/stats");

    fwrite(text_convert_int_to_char(rpg->game->player->stats.attack), \
    my_strlen(text_convert_int_to_char(rpg->game->player->stats.attack)), \
    1, save);
    fwrite("\n", 1, 1, save);
    fwrite(text_convert_int_to_char(rpg->game->player->stats.pv), \
    my_strlen(text_convert_int_to_char(rpg->game->player->stats.pv)), \
    1, save);
    fwrite("\n", 1, 1, save);
    fwrite(text_convert_int_to_char(rpg->game->player->stats.pv_max), \
    my_strlen(text_convert_int_to_char(rpg->game->player->stats.pv_max)), \
    1, save);
    fwrite("\n", 1, 1, save);
    save_stats_two(rpg, save);
    fclose(save);
}