/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** player_moves_three
*/

#include "my_game.h"

void player_move_x(my_game_t *rpg, player_t *player, sfVector2f move)
{
    sfFloatRect hitbox_x = player->hitbox;

    hitbox_x.left += move.x;
    if (sfFloatRect_intersects(&(rpg->game->cam_area), &(hitbox_x), NULL))
        player->hitbox.left += move.x;
    else {
        move_all_enemy(rpg, (sfVector2f){-move.x, 0}, rpg->game->enemy_list, \
        true);
        move_all_pnj(rpg, (sfVector2f){-move.x, 0}, rpg->game->pnj_list, true);
        map_move_origin(rpg->game->map, (sfVector2f){move.x, 0});
    }
}

void player_move_y(my_game_t *rpg, player_t *player, sfVector2f move)
{
    sfFloatRect hitbox_y = player->hitbox;

    hitbox_y.top += move.y;
    if (sfFloatRect_intersects(&(rpg->game->cam_area), &(hitbox_y), NULL))
        player->hitbox.top += move.y;
    else {
        move_all_enemy(rpg, (sfVector2f){0, -move.y}, rpg->game->enemy_list, \
        true);
        move_all_pnj(rpg, (sfVector2f){0, -move.y}, rpg->game->pnj_list, true);
        map_move_origin(rpg->game->map, (sfVector2f){0, move.y});
    }
}

sfVector2i return_actual_tiles(my_game_t *rpg, sfVector2f pos, int i)
{
    for (int j = rpg->game->map->camera.x - 15; j < \
    rpg->game->map->camera.x + 15; j++) {
        if (j > 0 && i > 0 && j < rpg->game->map->size.x && i < \
            rpg->game->map->size.y && in_tile(rpg->game->map->tiles\
            [i * rpg->game->map->size.x + j], pos) == 1)
            return ((sfVector2i){j, i});
    }
    return ((sfVector2i){-1, 0});
}

sfVector2i return_actual_tile(my_game_t *rpg, sfVector2f pos)
{
    sfVector2i r = {0, 0};

    for (int i = rpg->game->map->camera.y - 15; i < \
    rpg->game->map->camera.y + 15; i++) {
        r = return_actual_tiles(rpg, pos, i);
        if (r.x != -1)
            return (r);
    }
    return ((sfVector2i){0, 0});
}