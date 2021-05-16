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
#include "my_player.h"

int player_fill(my_game_t *rpg, char **buffer_list)
{
    player_t *player = rpg->game->player;

    if (my_array_get_size(buffer_list) != 2) {
        write(2, "Invalid Player Save.\n", 20);
        return (-1);
    }
    rpg->game->player->hitbox.left = my_getnbr(buffer_list[0]);
    rpg->game->player->hitbox.top = my_getnbr(buffer_list[1]);
    player_move(rpg, rpg->game->player);
    for (int i = 0; i < 5; i++)
        sfSprite_setPosition(rpg->game->player->sprites[i], \
        (sfVector2f){PLAYER_SPRITE_BASIC_POS_X, PLAYER_SPRITE_BASIC_POS_Y});
    return (0);
}

int player_upload(my_game_t *rpg, char *path)
{
    char *buffer = load_file_in_mem(path);
    char **buffer_list = NULL;

    if (buffer == NULL)
        return (-1);
    buffer_list = my_str_to_word_array_separators(buffer, ";");
    if (player_fill(rpg, buffer_list) == -1) {
        my_array_free(buffer_list);
        return (-1);
    }
    my_array_free(buffer_list);
    return (0);
}

int load_player(my_game_t *rpg, char *save_name)
{
    char *path = malloc(sizeof(char) * (my_strlen("saves/player/player") + \
    my_strlen(save_name) + 1));

    path[0] = '\0';
    my_strcat(path, "saves/player/player");
    my_strcat(path, save_name);
    if (player_upload(rpg, path) == -1)
        return (-1);
    return (0);
}