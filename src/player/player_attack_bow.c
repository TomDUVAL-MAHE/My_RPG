/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** player_attack_bow
*/

#include "my_game.h"

void player_bow_attack_up(player_t *player)
{
    if (player->orientation == DOWN)
        player->anim_rect.top = player->anim_rect.top + \
        PLAYER_ANIMATION_RECT_Y_OFFSET * 2;
    if (player->orientation == UP)
        player->attack_hitbox.top = player->hitbox.top - 20;
    else
        player->attack_hitbox.top = player->hitbox.top + \
        player->hitbox.height - 10;
    player->attack_hitbox = PLAYER_BASIC_ATTACK_Y_RECT;
    if (player->orientation == UP)
        player->attack_hitbox.top -= player->attack_hitbox.height / 2;
    else
        player->attack_hitbox.top += player->hitbox.height - \
        player->attack_hitbox.height / 2;
}

void player_bow_attack_left(player_t *player)
{
    if (player->orientation == LEFT) {
        player->anim_rect.top = player->anim_rect.top \
        + PLAYER_ANIMATION_RECT_Y_OFFSET;
        player->attack_hitbox.left = player->hitbox.left - 30;
    } else {
        player->anim_rect.top = player->anim_rect.top \
        + PLAYER_ANIMATION_RECT_Y_OFFSET * 3;
        player->attack_hitbox.left = player->hitbox.left + \
        player->hitbox.width - 10;
    }
    if (player->orientation == LEFT)
        player->attack_hitbox.left -= player->attack_hitbox.width / 2;
    else
        player->attack_hitbox.left += player->hitbox.width -\
        player->attack_hitbox.width / 2;
}

void player_bow_attack(player_t *player)
{
    player->anim_rect = PLAYER_ATTACK_BOW_RECT;
    if (player->orientation == UP || player->orientation == DOWN) {
        player_bow_attack_up(player);
    } else {
        player_bow_attack_left(player);
    }
}