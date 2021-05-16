/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** enemy_attack_basic
*/

#include "my_game.h"
#include "my_enemy.h"

void enemy_basic_attack_up(enemy_t *enemy)
{
    if (enemy->orientation == UP) {
        enemy->attack_hitbox.top = enemy->hitbox.top - 20;
    } else {
        enemy->anim_rect.top = enemy->anim_rect.top + \
        ENEMY_ANIMATION_RECT_Y_OFFSET * 2;
        enemy->attack_hitbox.top = enemy->hitbox.top + \
        enemy->hitbox.height - 10;
    }
    enemy->attack_hitbox = ENEMY_BASIC_ATTACK_Y_RECT;
    if (enemy->orientation == UP)
        enemy->attack_hitbox.top -= enemy->attack_hitbox.height / 2;
    else
        enemy->attack_hitbox.top += enemy->hitbox.height - \
        enemy->attack_hitbox.height / 2;
}

void enemy_basic_attack_left(enemy_t *enemy)
{
    if (enemy->orientation == LEFT) {
        enemy->anim_rect.top = enemy->anim_rect.top + \
        ENEMY_ANIMATION_RECT_Y_OFFSET;
        enemy->attack_hitbox.left = enemy->hitbox.left - 30;
    } else {
        enemy->anim_rect.top = enemy->anim_rect.top + \
        ENEMY_ANIMATION_RECT_Y_OFFSET * 3;
        enemy->attack_hitbox.left = enemy->hitbox.left + \
        enemy->hitbox.width - 10;
    }
    enemy->attack_hitbox = ENEMY_BASIC_ATTACK_X_RECT;
    if (enemy->orientation == LEFT)
        enemy->attack_hitbox.left -= enemy->attack_hitbox.width / 2;
    else
        enemy->attack_hitbox.left += enemy->hitbox.width - \
        enemy->attack_hitbox.width / 2;
}

void enemy_basic_attack(enemy_t *enemy, player_t *player)
{
    enemy->anim_rect = ENEMY_ATTACK_BASIC_RECT;
    if (enemy->orientation == UP || enemy->orientation == DOWN) {
        enemy_basic_attack_up(enemy);
    } else {
        enemy_basic_attack_left(enemy);
    }
    if (sfFloatRect_intersects(&enemy->attack_hitbox, &player->hitbox, NULL)) {
        player->stats.pv -= enemy->stats.attack;
        enemy_is_killing_player(player);
    }
    enemy->attack_hitbox = ENEMY_REINIT_ATTACK_RECT;
}