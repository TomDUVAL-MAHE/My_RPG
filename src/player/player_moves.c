/*
** EPITECH PROJECT, 10021
** RPG
** File description:
** player_moves
*/

#include "my_game.h"

bool player_colision_with_enemy(player_t *player, enemy_list_t *enemy_list)
{
    enemy_node_t *ptr;
    sfFloatRect inter;

    if (!enemy_list) {
        return (false);
    }
    ptr = enemy_list->first;
    while (ptr) {
        sfFloatRect_intersects(&(player->hitbox), \
        &(ptr->enemy->hitbox), &inter);
        if (inter.width > 50 && inter.height > 50)
            return (true);
        ptr = ptr->next;
    }
    return (false);
}

bool player_colision_with_pnj(player_t *player, pnj_list_t *pnj_list)
{
    pnj_node_t *ptr;
    sfFloatRect inter;

    if (!pnj_list) {
        return (false);
    }
    ptr = pnj_list->first;
    while (ptr) {
        sfFloatRect_intersects(&(player->hitbox), &(ptr->pnj->hitbox), &inter);
        if (inter.width > 50 && inter.height > 50)
            return (true);
        ptr = ptr->next;
    }
    return (false);
}

bool is_colision(my_game_t *rpg, player_t *player)
{
    sfVector2i pos = return_actual_tile(rpg, (sfVector2f)\
    {player->hitbox.left + player->hitbox.width / 2 + \
        rpg->game->map->origin.x, player->hitbox.top + \
        player->hitbox.height + rpg->game->map->origin.y});

    if (rpg->game->map->tiles[pos.y * \
        rpg->game->map->size.x + pos.x].ground == 9)
        return (true);
    if (rpg->game->map->tiles[pos.y * \
        rpg->game->map->size.x + pos.x].building != 0)
        return (true);
    if (player_colision_with_enemy(player, \
        rpg->game->enemy_list) == true)
        return (true);
    if (player_colision_with_pnj(player, \
        rpg->game->pnj_list) == true)
        return (true);
    return (false);
}

void player_move_colision(my_game_t *rpg, player_t *player, sfVector2f move)
{
    player_move_x(rpg, player, move);
    if (is_colision(rpg, player) == true) {
        move.x *= -1;
        player_move_x(rpg, player, move);
    }
    player_move_y(rpg, player, move);
    if (is_colision(rpg, player) == true) {
        move.y *= -1;
        player_move_y(rpg, player, move);
    }
}

void player_move(my_game_t *rpg, player_t *player)
{
    sfVector2f move;

    if (player->is_attacking)
        return;
    if (is_player_moving(player) == false && !player->is_dying) {
        player->anim_rect.left = 0;
        player->is_walking = false;
        return;
    }
    move = player_get_move(rpg, player);
    quest_end_move(rpg);
    player_move_colision(rpg, player, move);
    quest_end_gtv(rpg);
    quest_end_gtp(rpg);
    quest_end_gti(rpg);
    quest_end_gtm(rpg);
    quest_end_gtb(rpg);
    enter_a_zone(player->hitbox, rpg);
    for (int i = 0; i < 5; i++)
        sfSprite_setPosition(player->sprites[i], \
        (sfVector2f){PLAYER_SPRITE_BASIC_POS_X, PLAYER_SPRITE_BASIC_POS_Y});
}
