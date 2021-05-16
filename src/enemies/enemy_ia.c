/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** enemy_ia
*/

#include "my_enemy.h"
#include "my_game.h"

sfVector2f enemy_ia_get_move(my_game_t *rpg, enemy_t *enemy, player_t *player)
{
    sfVector2f move;
    float dif_left = enemy->hitbox.left - player->hitbox.left;
    float dif_top = enemy->hitbox.top - player->hitbox.top;

    if (dif_left < 0)
        move.x = (dif_left < -12 ? 12 : -dif_left);
    else
        move.x = (dif_left > 12 ? -12 : -dif_left);
    if (dif_top < 0)
        move.y = (dif_top < -12 ? 12 : -dif_top);
    else
        move.y = (dif_top > 12 ? -12 : -dif_top);
    move.x *= (float){rpg->elapsed_microsecond} / 100000.0;
    move.y *= (float){rpg->elapsed_microsecond} / 100000.0;
    return (move);
}

void enemy_ia_move(my_game_t *rpg, enemy_t *enemy)
{
    sfFloatRect detection_area = {enemy->hitbox.left - 384, \
        enemy->hitbox.top - 216, 384 * 2 + enemy->hitbox.top, \
        216 * 2 + enemy->hitbox.height};
    sfVector2f move;

    if (sfFloatRect_intersects(&detection_area, \
    &rpg->game->player->hitbox, NULL)) {
        enemy->is_walking = true;
        move = enemy_ia_get_move(rpg, enemy, rpg->game->player);
        enemy_move(enemy, move, rpg, false);
    } else {
        enemy->is_walking = false;
        enemy->anim_rect.left = 0;
    }
}

void enemy_ia_attack(player_t *player, enemy_t *enemy)
{
    int width = 64;
    int height = 64;
    sfFloatRect attack_aera;

    if (enemy->is_attacking)
        return;
    attack_aera.left = enemy->hitbox.left - width;
    attack_aera.top = enemy->hitbox.top - height;
    attack_aera.width = width * 2 + enemy->hitbox.width;
    attack_aera.height = height * 2 + enemy->hitbox.height;

    if (sfFloatRect_intersects(&attack_aera, &player->hitbox, NULL))
        enemy_attack(enemy, player);
}

void enemy_ia_management(my_game_t *rpg, enemy_list_t *e_list)
{
    enemy_node_t *ptr;

    if (!e_list)
        return;
    ptr = e_list->first;
    while (ptr) {
        if (ptr->enemy->tile.x != 0 || ptr->enemy->tile.y != 0) {
            enemy_ia_move(rpg, ptr->enemy);
            enemy_ia_attack(rpg->game->player, ptr->enemy);
        }
        ptr = ptr->next;
    }
}