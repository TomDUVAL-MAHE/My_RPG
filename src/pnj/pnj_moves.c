/*
** EPITECH PROJECT, 10021
** RPG
** File description:
** enemy_moves
*/

#include "my_pnj.h"
#include "my_game.h"
#include <stdbool.h>

void define_orientation_with_intersect(sfFloatRect npc, \
sfFloatRect player, pnj_t *pnj)
{
    float dif_top = (player.top + player.height / 2 - \
    (npc.top + npc.height / 2)) / npc.height * 100;
    float dif_left = (player.left + player.width / 2 - \
    (npc.left + npc.width / 2)) / npc.width * 100;

    if (dif_top < 0) {
        if (dif_left < dif_top)
            pnj->orientation = LEFT;
        else
            pnj->orientation = UP;
    }
    if (dif_top > 0) {
        if (dif_left > dif_top)
            pnj->orientation = RIGHT;
        else
            pnj->orientation = DOWN;
    }
    pnj_orientate(pnj);
}

bool check_pnj_move(player_t *player, pnj_t *pnj, sfVector2f move)
{
    sfFloatRect temp = pnj->hitbox;
    sfFloatRect intersect;

    temp.left += move.x;
    temp.top += move.y;
    if (sfFloatRect_intersects(&temp, &(player->hitbox), &intersect)) {
        return (false);
    }
    return (true);
}

void pnj_move_hitbox(my_game_t *rpg, pnj_t *pnj, \
sfVector2f move, bool force)
{
    if (check_pnj_move(rpg->game->player, pnj, move) || force == true) {
        pnj->hitbox.left += move.x;
        pnj->hitbox.top += move.y;
        sfSprite_setPosition(pnj->sprite, \
        (sfVector2f){PNJ_SPRITE_BASIC_POS_X, PNJ_SPRITE_BASIC_POS_Y});
        pnj_chose_orientation(pnj, move);
    } else {
        pnj->anim_rect.left = 0;
        pnj->is_walking = false;
    }
    if (force) {
        pnj->end.x += move.x;
        pnj->end.y += move.y;
        pnj->start.x += move.x;
        pnj->start.y += move.y;
    }
}

void pnj_move(pnj_t *pnj, sfVector2f move, my_game_t *rpg, bool force)
{
    pnj->tile = return_actual_tile(rpg, (sfVector2f)\
    {pnj->hitbox.left + pnj->hitbox.width / 2 + \
        rpg->game->map->origin.x, pnj->hitbox.top + \
        pnj->hitbox.height + rpg->game->map->origin.y});
    if (pnj->tile.x == 0 && pnj->tile.y == 0 && !force)
        return;
    if (move.x == 0 && move.y == 0) {
        pnj->anim_rect.left = 0;
        pnj->is_walking = false;
        return;
    }
    pnj_move_hitbox(rpg, pnj, move, force);
}