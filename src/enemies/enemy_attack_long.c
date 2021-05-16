/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** enemy_attack_long
*/

#include "my_enemy.h"
#include "my_game.h"

void enemy_long_sword_attack_up(enemy_t *enemy)
{
    if (enemy->orientation == UP) {
        enemy->attack_hitbox.top = enemy->hitbox.top - 20;
    } else {
        enemy->anim_rect.top = enemy->anim_rect.top + \
        ENEMY_ANIMATION_RECT_LONG_Y_OFFSET * 2;
        enemy->attack_hitbox.top = enemy->hitbox.top + \
        enemy->hitbox.height - 10;
    }
    enemy->attack_hitbox = ENEMY_LONG_ATTACK_Y_RECT;
    if (enemy->orientation == UP)
        enemy->attack_hitbox.top -= enemy->attack_hitbox.height / 2;
    else
        enemy->attack_hitbox.top += enemy->hitbox.height - \
        enemy->attack_hitbox.height / 2;
}

void enemy_long_sword_attack_left(enemy_t *enemy)
{
    if (enemy->orientation == LEFT) {
        enemy->anim_rect.top = enemy->anim_rect.top + \
        ENEMY_ANIMATION_RECT_LONG_Y_OFFSET;
        enemy->attack_hitbox.left = enemy->hitbox.left - 30;
    } else {
        enemy->anim_rect.top = enemy->anim_rect.top + \
        ENEMY_ANIMATION_RECT_LONG_Y_OFFSET * 3;
        enemy->attack_hitbox.left = enemy->hitbox.left + \
        enemy->hitbox.width - 10;
    }
    enemy->attack_hitbox = ENEMY_LONG_ATTACK_X_RECT;
    if (enemy->orientation == LEFT)
        enemy->attack_hitbox.left -= enemy->attack_hitbox.width / 5 * 4;
    else
        enemy->attack_hitbox.left += enemy->hitbox.width - \
        enemy->attack_hitbox.width / 5;
}

void enemy_long_sword_attack(enemy_t *enemy, player_t *player)
{
    sfSprite_setPosition(enemy->sprite, (sfVector2f)\
    {ENEMY_SPRITE_LONG_POS_X, ENEMY_SPRITE_LONG_POS_Y});
    enemy->anim_rect = ENEMY_ATTACK_LONG_RECT;
    if (enemy->orientation == UP || enemy->orientation == DOWN) {
        enemy_long_sword_attack_up(enemy);
    } else {
        enemy_long_sword_attack_left(enemy);
    }
    if (sfFloatRect_intersects(&enemy->attack_hitbox, &player->hitbox, NULL)) {
        player->stats.pv -= enemy->stats.attack;
        enemy_is_killing_player(player);
    }
    enemy->attack_hitbox = ENEMY_REINIT_ATTACK_RECT;
}