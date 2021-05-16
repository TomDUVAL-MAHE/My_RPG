/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** player_moves_two
*/

#include "my_game.h"

bool is_player_moving(player_t *player)
{
    int x = 0;
    int y = 0;

    if (player->move_up)
        y--;
    if (player->move_down)
        y++;
    if (player->move_left)
        x--;
    if (player->move_right)
        x++;
    if (x != 0 || y != 0)
        return (true);
    return (false);
}

sfVector2f player_get_move(my_game_t *rpg, player_t* player)
{
    float multiplier = (float) {rpg->elapsed_microsecond} / 100000;
    sfVector2f move = {0, 0};

    if (player->move_up)
        move.y += -20;
    if (player->move_down)
        move.y += 20;
    if (player->move_left)
        move.x += -20;
    if (player->move_right)
        move.x += 20;
    move.x *= multiplier;
    move.y *= multiplier;
    player_chose_orientation(player, move);
    return (move);
}

void move_all_enemy(my_game_t *rpg, sfVector2f move, \
enemy_list_t *enemy_list, bool force)
{
    enemy_node_t *ptr;

    if (!enemy_list)
        return;
    ptr = enemy_list->first;
    while (ptr) {
        enemy_move(ptr->enemy, move, rpg, force);
        if (ptr->enemy->is_attacking && ptr->enemy->weapon_type == LONG_SWORD) {
            sfSprite_setPosition(ptr->enemy->sprite, \
            (sfVector2f) {ENEMY_PTR_SPRITE_LONG_POS_X, \
                ENEMY_PTR_SPRITE_LONG_POS_Y});
        } else {
            sfSprite_setPosition(ptr->enemy->sprite, \
            (sfVector2f) {ENEMY_PTR_SPRITE_BASIC_POS_X, \
                ENEMY_PTR_SPRITE_BASIC_POS_Y});
        }
        ptr = ptr->next;
    }
}

void move_all_pnj(my_game_t *rpg, sfVector2f move, \
pnj_list_t *pnj_list, bool force)
{
    pnj_node_t *ptr;

    if (!pnj_list)
        return;
    ptr = pnj_list->first;
    while (ptr) {
        pnj_move(ptr->pnj, move, rpg, force);
        ptr = ptr->next;
    }
}