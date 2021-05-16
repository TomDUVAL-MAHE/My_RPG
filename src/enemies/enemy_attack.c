/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** penemyr_attack
*/

#include "my_game.h"
#include "my_enemy.h"

void enemy_is_killing_player(player_t *player)
{
    if (!player->is_dying && player->stats.pv <= 0) {
        player->is_dying = true;
        player->anim_rect = PLAYER_DIE_RECT;
        player->stats.xp += player->stats.xp_max;
        player->anim_cooldown = PLAYER_ANIMATION_COOLDOWN * 2;
    }
}

void enemy_attack(enemy_t *enemy, player_t *player)
{
    enemy->is_attacking = true;
    if (enemy->weapon_type == SWORD || enemy->weapon_type == AXE \
        || enemy->weapon_type == PICKAXE)
        enemy_basic_attack(enemy, player);
    if (enemy->weapon_type == LONG_SWORD)
        enemy_long_sword_attack(enemy, player);
}