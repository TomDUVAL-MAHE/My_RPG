/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** enemy_display_two
*/

#include "my_game.h"

void enemy_get_attack_anim_specifities(enemy_t *enemy, int *max_width)
{
    if (enemy->weapon_type == LONG_SWORD)
        *max_width = ENEMY_ATTACK_LONG_MAX_LEFT;
    if (enemy->weapon_type == SWORD)
        *max_width = ENEMY_ATTACK_BASIC_MAX_LEFT;
    if (enemy->weapon_type == BOW)
        *max_width = ENEMY_ATTACK_BOW_MAX_LEFT;
}

void enemy_reset_attack_animation(enemy_t *enemy)
{
    enemy->anim_rect = ENEMY_WALK_UP_RECT;
    enemy_orientate(enemy);
    enemy->is_attacking = false;
    enemy->anim_rect.left = 0;
    sfSprite_setPosition(enemy->sprite, (sfVector2f)\
    {ENEMY_SPRITE_BASIC_POS_X, ENEMY_SPRITE_BASIC_POS_Y});
    sfSprite_setTextureRect(enemy->sprite, enemy->anim_rect);
}

void enemy_attack_animation(my_game_t *rpg, enemy_t *enemy)
{
    int offset_x;
    int max_width;

    if (enemy->weapon_type == LONG_SWORD)
        offset_x = ENEMY_ANIMATION_RECT_LONG_WIDTH;
    else
        offset_x = ENEMY_ANIMATION_RECT_WIDTH;
    enemy_get_attack_anim_specifities(enemy, &max_width);
    if (enemy->anim_cooldown <= 0) {
        enemy->anim_rect.left += offset_x;
        enemy->anim_cooldown = ENEMY_ANIMATION_COOLDOWN;
        if (enemy->anim_rect.left > max_width) {
            enemy_reset_attack_animation(enemy);
        }
    }
    enemy->anim_cooldown -= rpg->elapsed_microsecond;
}