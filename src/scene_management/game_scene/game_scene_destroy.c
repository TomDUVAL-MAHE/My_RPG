/*
** EPITECH PROJECT, 2021
** game_scene_init
** File description:
** desc
*/

#include "my_game.h"

void game_scene_destroy(game_scene *game)
{
    if (!game)
        return;
    if (game->map)
        map_destroy(game->map);
    if (game->enemy_list)
        enemy_list_destroy(game->enemy_list);
    if (game->player)
        player_destroy(game->player);
    free(game);
    game = NULL;
}