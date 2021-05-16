/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** enemy_move_two
*/

#include "my_enemy.h"
#include "my_game.h"
#include <stdbool.h>

bool enemy_move_two(enemy_t *enemy, my_game_t *rpg, sfVector2f move, bool force)
{
    enemy->tile = return_actual_tile(rpg, (sfVector2f)\
    {enemy->hitbox.left + enemy->hitbox.width / 2 + \
        rpg->game->map->origin.x, enemy->hitbox.top + \
        enemy->hitbox.height + rpg->game->map->origin.y});
    if ((enemy->is_attacking || enemy->is_dying) && force == false)
        return (true);
    if (move.x == 0 && move.y == 0) {
        enemy->anim_rect.left = 0;
        enemy->is_walking = false;
        return (false);
    }
    return (false);
}