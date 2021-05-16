/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** player_display
*/

#include "my_game.h"

void player_attack_animation(my_game_t *rpg, player_t *player)
{
    int offset_x;
    int max_width;

    if (player->weapon_type == LONG_SWORD)
        offset_x = PLAYER_ANIMATION_RECT_LONG_WIDTH;
    else
        offset_x = PLAYER_ANIMATION_RECT_WIDTH;
    player_get_attack_anim_specifities(player, &max_width);
    if (player->anim_cooldown <= 0) {
        player->anim_rect.left += offset_x;
        player->anim_cooldown = PLAYER_ANIMATION_COOLDOWN;
        if (player->anim_rect.left > max_width) {
            player_reset_attack_animation(player);
        }
    }
    player->anim_cooldown -= rpg->elapsed_microsecond;
}

void player_die_animation(my_game_t *rpg, player_t *player)
{
    for (int i = 0; i < 5; i++)
        sfSprite_setPosition(player->sprites[i], (sfVector2f)\
        {PLAYER_SPRITE_BASIC_POS_X, PLAYER_SPRITE_BASIC_POS_Y});
    if (player->anim_cooldown <= 0) {
        player->anim_rect.left += PLAYER_ANIMATION_RECT_WIDTH;
        player->anim_cooldown = PLAYER_ANIMATION_COOLDOWN * 2;
        if (player->anim_rect.left >= PLAYER_DIE_MAX_LEFT) {
            player->destroyed = true;
        }
    }
    player->anim_cooldown -= rpg->elapsed_microsecond;
}

void player_animation(my_game_t *rpg, player_t *player)
{
    if (player->is_dying) {
        player_die_animation(rpg, player);
        return;
    }
    if (player->is_attacking) {
        player_attack_animation(rpg, player);
        return;
    }
    if (player->is_walking) {
        player_walk_animation(rpg, player);
        return;
    }
}

void player_display(my_game_t *rpg, player_t *player)
{
    player_animation(rpg, player);
    for (int i = 0; i < 5; i++) {
        sfSprite_setTextureRect(player->sprites[i], player->anim_rect);
        sfRenderWindow_drawSprite(rpg->window.window, player->sprites[i], NULL);
    }
    if (player->orientation == UP) {
        sfRenderWindow_drawSprite(rpg->window.window, \
        player->sprites[PLAYER_TAB_WEAPON], NULL);
        sfRenderWindow_drawSprite(rpg->window.window, \
        player->sprites[PLAYER_TAB_ARMOR], NULL);
    }
    arrow_display(rpg, player);
}
