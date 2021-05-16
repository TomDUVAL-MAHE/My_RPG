/*
** EPITECH PROJECT, 2021
** desc
** File description:
** scene_display_three
*/

#include "my_game.h"

void game_scene_display_entities(my_game_t *rpg)
{
    int i = 0;
    int j = 0;
    sfVector2i pos = return_actual_tile(rpg, (sfVector2f)\
    {rpg->game->player->hitbox.left + rpg->game->player->hitbox.width / 2 + \
        rpg->game->map->origin.x, rpg->game->player->hitbox.top + \
        rpg->game->player->hitbox.height + rpg->game->map->origin.y});

    map_display(rpg->window.window, rpg->game->map);
    i = (rpg->game->map->camera.y - 15 > 0) ? rpg->game->map->camera.y - 15 : 0;
    for (; i < rpg->game->map->camera.y + 15 && i < rpg->game->map->size.y; \
    i++) {
        for (; j < rpg->game->map->camera.x + 15 && \
        j < rpg->game->map->size.x; j++) {
            draw_build(rpg->window.window, rpg->game->map, i, j);
            player_player_display(i, j, rpg, pos);
            enemies_display(rpg, rpg->game->enemy_list, i, j);
            pnjs_display(rpg, rpg->game->pnj_list, i, j);
        }
        game_scene_display_entitiess(rpg, &j);
    }
}