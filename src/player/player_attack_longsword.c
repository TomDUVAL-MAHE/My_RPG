/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** player_attack_longsword
*/

#include "my_game.h"

void player_long_sword_attack_up(player_t *player)
{
    if (player->orientation == DOWN)
        player->attack_hitbox.top = player->anim_rect.top + \
        PLAYER_ANIMATION_RECT_LONG_Y_OFFSET * 2;
    if (player->orientation == UP)
        player->attack_hitbox.top = player->hitbox.top - 20;
    else
        player->attack_hitbox.top = player->hitbox.top + \
        player->hitbox.height - 10;
    player->attack_hitbox = PLAYER_LONG_ATTACK_Y_RECT;
    if (player->orientation == UP)
        player->attack_hitbox.top -= player->attack_hitbox.height / 2;
    else
        player->attack_hitbox.top += player->hitbox.height - \
        player->attack_hitbox.height / 2;
}

void player_long_sword_attack_left(player_t *player)
{
    if (player->orientation == LEFT)
        player->anim_rect.top = player->anim_rect.top + \
        PLAYER_ANIMATION_RECT_LONG_Y_OFFSET;
    else
        player->anim_rect.top = player->anim_rect.top + \
        PLAYER_ANIMATION_RECT_LONG_Y_OFFSET * 3;
    if (player->orientation == LEFT)
        player->attack_hitbox.left = player->hitbox.left - 30;
    else
        player->attack_hitbox.left = player->hitbox.left + \
        player->hitbox.width - 10;
    player->attack_hitbox = PLAYER_LONG_ATTACK_X_RECT;
    if (player->orientation == LEFT)
        player->attack_hitbox.left -= player->attack_hitbox.width / 5 * 4;
    else
        player->attack_hitbox.left += player->hitbox.width - \
        player->attack_hitbox.width / 5;
}

void player_long_sword_attack(player_t *player, my_game_t *rpg)
{
    for (int i = 0; i < 5; i++)
        sfSprite_setPosition(player->sprites[i], \
        (sfVector2f){PLAYER_SPRITE_LONG_POS_X, PLAYER_SPRITE_LONG_POS_Y});
    player->anim_rect = PLAYER_ATTACK_LONG_RECT;
    if (player->orientation == UP || player->orientation == DOWN) {
        player_long_sword_attack_up(player);
    } else {
        player_long_sword_attack_left(player);
    }
    player_hit_ennemy(player, rpg->game->enemy_list, rpg);
    player->attack_hitbox = PLAYER_REINIT_ATTACK_RECT;
}
