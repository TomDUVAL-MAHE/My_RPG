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

void enemy_change_stats(char **enemy_information, enemy_list_t *enemy_list)
{
    enemy_node_t *ptr;

    if (!enemy_list->first)
        return;
    ptr = enemy_list->first;
    ptr->enemy->stats.attack = my_getnbr(enemy_information[2]);
    ptr->enemy->stats.pv = my_getnbr(enemy_information[3]);
    ptr->enemy->stats.pv_max = my_getnbr(enemy_information[4]);
    ptr->enemy->stats.xp = my_getnbr(enemy_information[5]);
    ptr->enemy->stats.xp_max = my_getnbr(enemy_information[6]);
    ptr->enemy->stats.level = my_getnbr(enemy_information[7]);
}

int enemy_fill(my_game_t *rpg, char **buffer_list)
{
    char **enemy_information = NULL;

    for (int i = 0; buffer_list[i][0] != '\0'; i++) {
        enemy_information = my_str_to_word_array_separators\
        (buffer_list[i], ";");
        if (enemy_information[0][0] == 'A')
            return (0);
        if (my_array_get_size(enemy_information) != 9) {
            my_array_free(enemy_information);
            write(2, "Invalid Enemy Save.\n", 20);
            return (-1);
        }
        create_new_enemy(rpg->game->enemy_list, \
        my_getnbr(enemy_information[8]), 1, (sfVector2i)\
        {my_getnbr(enemy_information[0]), my_getnbr(enemy_information[1])});
        enemy_change_stats(enemy_information, rpg->game->enemy_list);
        my_array_free(enemy_information);
    }
    return (0);
}

int enemy_upload(my_game_t *rpg, char *path)
{
    char *buffer = load_file_in_mem(path);
    char **buffer_list = NULL;

    if (buffer == NULL)
        return (-1);
    buffer_list = my_str_to_word_array_separators(buffer, "\n");
    if (enemy_fill(rpg, buffer_list) == -1) {
        my_array_free(buffer_list);
        return (-1);
    }
    my_array_free(buffer_list);
    return (0);
}

int load_enemy(my_game_t *rpg, char *save_name)
{
    char *path = malloc(sizeof(char) * (my_strlen("saves/enemy/enemy") + \
    my_strlen(save_name) + 1));

    path[0] = '\0';
    my_strcat(path, "saves/enemy/enemy");
    my_strcat(path, save_name);
    if (enemy_upload(rpg, path) == -1)
        return (-1);
    return (0);
}