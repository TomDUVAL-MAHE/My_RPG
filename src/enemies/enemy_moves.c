/*
** EPITECH PROJECT, 10021
** RPG
** File description:
** enemy_moves
*/

#include "my_enemy.h"
#include "my_game.h"
#include <stdbool.h>

bool is_colision_ennemy(my_game_t *rpg, enemy_t *enemy)
{
    sfVector2i pos = return_actual_tile(rpg, (sfVector2f)\
    {enemy->hitbox.left + enemy->hitbox.width / 2 + rpg->game->map->origin.x, \
        enemy->hitbox.top + enemy->hitbox.height + rpg->game->map->origin.y});

    if (rpg->game->map->tiles[pos.y * rpg->game->map->size.x + pos.x].ground \
        == 9)
        return (false);
    if (rpg->game->map->tiles[pos.y * rpg->game->map->size.x + pos.x].building \
        != 0)
        return (false);
    return (true);
}

bool check_enemy_move_x(enemy_t *enemy, sfVector2f move, my_game_t *rpg)
{
    sfFloatRect temp = enemy->hitbox;

    temp.left += move.x;
    if (is_colision_ennemy(rpg, enemy) == false)
        return (false);
    return (true);
}

bool check_enemy_move_y(enemy_t *enemy, sfVector2f move, my_game_t *rpg)
{
    sfFloatRect temp = enemy->hitbox;

    temp.left += move.y;
    if (is_colision_ennemy(rpg, enemy) == false)
        return (false);
    return (true);
}

bool check_enemy_move(player_t *player, enemy_t *enemy, sfVector2f move)
{
    sfFloatRect temp = enemy->hitbox;

    temp.left += move.x;
    temp.top += move.y;
    if (sfFloatRect_intersects(&temp, &(player->hitbox), NULL))
        return (false);
    return (true);
}

void enemy_move(enemy_t *enemy, sfVector2f move, my_game_t *rpg, bool force)
{
    if (enemy_move_two(enemy, rpg, move, force) == true)
        return;
    if (check_enemy_move(rpg->game->player, enemy, move) || force == true) {
        if (!force)
            define_enemy_orientation(move, enemy);
        sfSprite_setPosition(enemy->sprite, \
        (sfVector2f){ENEMY_SPRITE_BASIC_POS_X, ENEMY_SPRITE_BASIC_POS_Y});
        if (check_enemy_move_x(enemy, move, rpg) == true || force == true)
            enemy->hitbox.left += move.x;
        else
            enemy->hitbox.left -= move.x;
        if (check_enemy_move_y(enemy, move, rpg) == true || force == true)
            enemy->hitbox.top += move.y;
        else
            enemy->hitbox.top -= move.y;
    } else {
        enemy->anim_rect.left = 0;
        enemy->is_walking = false;
    }
}