/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** player_display_two
*/

#include "my_game.h"

void player_set_sprite_pose(player_t *player, float x, float y)
{
    for (int i = 0; i < 5; i++) {
        sfSprite_setPosition(player->sprites[i], (sfVector2f){x, y});
        sfSprite_setTextureRect(player->sprites[i], player->anim_rect);
    }
}

void player_walk_animation(my_game_t *rpg, player_t *player)
{
    if (player->anim_cooldown <= 0) {
        player->anim_rect.left += PLAYER_ANIMATION_RECT_WIDTH;
        player->anim_cooldown = PLAYER_ANIMATION_COOLDOWN;
        player->anim_rect.left = (player->anim_rect.left >= 9 * \
        PLAYER_ANIMATION_RECT_WIDTH ? PLAYER_ANIMATION_RECT_WIDTH : \
        player->anim_rect.left);
    }
    player->anim_cooldown -= rpg->elapsed_microsecond;
}

void player_get_attack_anim_specifities(player_t *player, int *max_width)
{
    if (player->weapon_type == LONG_SWORD)
        *max_width = PLAYER_ATTACK_LONG_MAX_LEFT;
    if (player->weapon_type == SWORD || player->weapon_type == PICKAXE \
        || player->weapon_type == AXE)
        *max_width = PLAYER_ATTACK_BASIC_MAX_LEFT;
    if (player->weapon_type == BOW)
        *max_width = PLAYER_ATTACK_BOW_MAX_LEFT;
    if (player->weapon_type == CROSSBOW)
        *max_width = PLAYER_ATTACK_CROSSBOW_MAX_LEFT;
}

void player_reset_attack_animation(player_t *player)
{
    player->anim_rect = PLAYER_WALK_UP_RECT;
    player_orientate(player);
    player->is_attacking = false;
    player->anim_rect.left = 0;
    if (player->weapon_type == BOW || player->weapon_type == CROSSBOW)
        player->arrow = arrow_creation(player->orientation, \
        player->hitbox.left + player->hitbox.width / 2, \
        player->hitbox.top + player->hitbox.height / 2, 2);
    player_set_sprite_pose(player, PLAYER_SPRITE_BASIC_POS_X, \
    PLAYER_SPRITE_BASIC_POS_Y);
}