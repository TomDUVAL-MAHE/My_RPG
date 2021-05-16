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

void save_player(my_game_t *rpg, char *save_name)
{
    FILE *save = return_file_descriptor(save_name, \
    "saves/player/player");

    fwrite(text_convert_int_to_char(rpg->game->player->hitbox.left), \
    my_strlen(text_convert_int_to_char(rpg->game->player->hitbox.left)), \
    1, save);
    fwrite(";", 1, 1, save);
    fwrite(text_convert_int_to_char(rpg->game->player->hitbox.top), \
    my_strlen(text_convert_int_to_char(rpg->game->player->hitbox.top)), \
    1, save);
    fclose(save);
}