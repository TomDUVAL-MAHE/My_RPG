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

void save_enemy_two(FILE *save, enemy_node_t *ptr)
{
    fwrite(text_convert_int_to_char((float)ptr->enemy->hitbox.left), \
    my_strlen(text_convert_int_to_char((float)ptr->enemy->hitbox.left)), \
    1, save);
    fwrite(";", 1, 1, save);
    fwrite(text_convert_int_to_char((float)ptr->enemy->hitbox.top), \
    my_strlen(text_convert_int_to_char((float)ptr->enemy->hitbox.top)), \
    1, save);
    fwrite(";", 1, 1, save);
    fwrite(text_convert_int_to_char((float)ptr->enemy->stats.attack), \
    my_strlen(text_convert_int_to_char((float)ptr->enemy->stats.attack)), \
    1, save);
    fwrite(";", 1, 1, save);
    fwrite(text_convert_int_to_char((float)ptr->enemy->stats.pv), \
    my_strlen(text_convert_int_to_char((float)ptr->enemy->stats.pv)), \
    1, save);
    fwrite(";", 1, 1, save);
    fwrite(text_convert_int_to_char((float)ptr->enemy->stats.pv_max), \
    my_strlen(text_convert_int_to_char((float)ptr->enemy->stats.pv_max)), \
    1, save);
}

void save_enemy_three(FILE *save, enemy_node_t *ptr)
{
    fwrite(";", 1, 1, save);
    fwrite(text_convert_int_to_char((float)ptr->enemy->stats.xp), \
    my_strlen(text_convert_int_to_char((float)ptr->enemy->stats.xp)), \
    1, save);
    fwrite(";", 1, 1, save);
    fwrite(text_convert_int_to_char((float)ptr->enemy->stats.xp_max), \
    my_strlen(text_convert_int_to_char((float)ptr->enemy->stats.xp_max)), \
    1, save);
    fwrite(";", 1, 1, save);
    fwrite(text_convert_int_to_char((float)ptr->enemy->stats.level), \
    my_strlen(text_convert_int_to_char((float)ptr->enemy->stats.level)), \
    1, save);
    fwrite(";", 1, 1, save);
    fwrite(text_convert_int_to_char((int)ptr->enemy->type), \
    my_strlen(text_convert_int_to_char((float)ptr->enemy->type)), \
    1, save);
    fwrite(";", 1, 1, save);
    fwrite("\n", 1, 1, save);
}

void save_enemy(my_game_t *rpg, char *save_name)
{
    FILE *save = return_file_descriptor(save_name, "saves/enemy/enemy");
    enemy_node_t *ptr;

    if (!rpg->game->enemy_list->first) {
        fwrite("A", 1, 1, save);
        fclose(save);
        return;
    }
    ptr = rpg->game->enemy_list->first;
    while (ptr) {
        save_enemy_two(save, ptr);
        save_enemy_three(save, ptr);
        ptr = ptr->next;
    }
    fclose(save);
}