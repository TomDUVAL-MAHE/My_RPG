/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** player_init
*/

#include "my_game.h"

void player_init_values(player_t *player, my_game_t *rpg)
{
    player->hitbox.left = (float) {rpg->window.size.x} / 2 - \
    player->hitbox.width / 2;
    player->hitbox.top = (float) {rpg->window.size.y} / 2 - \
    player->hitbox.height / 2;
    player->anim_rect = PLAYER_WALK_DOWN_RECT;
    player->anim_cooldown = PLAYER_ANIMATION_COOLDOWN;
    player->weapon_type = SWORD;
    player->attack_hitbox = PLAYER_REINIT_ATTACK_RECT;
    player->zone = -2;
}

void player_init_value(player_t *player, my_game_t *rpg)
{
    player->orientation = DOWN;
    player->move_up = false;
    player->move_down = false;
    player->move_left = false;
    player->move_right = false;
    player->is_walking = false;
    player->is_attacking = false;
    player->is_dying = false;
    player->dead = false;
    player->destroyed = false;
    player->hitbox.width = PLAYER_HITBOX_WIDTH;
    player->hitbox.height = PLAYER_HITBOX_HEIGHT;
    player_init_values(player, rpg);
}

stats_t player_setup_stats(void)
{
    stats_t stats;

    stats.attack = 1;
    stats.level = 1;
    stats.pv = 4;
    stats.pv_max = 5;
    stats.xp = 0;
    stats.xp_max = 10;
    return (stats);
}

player_t *player_create(my_game_t *rpg)
{
    player_t *player = malloc(sizeof(player_t));
    if (!player)
        return (NULL);
    player_init_value(player, rpg);
    player->textures = player_textures_init();
    if (!player->textures) {
        free(player);
        return (NULL);
    }
    player->sprites = player_sprites_init(player);
    player->stats = player_setup_stats();
    if (!player->sprites) {
        free(player->textures);
        free(player);
        return (NULL);
    }
    player->arrow = NULL;
    return (player);
}

void player_destroy(player_t *player)
{
    for (int i = 0; i < 5; i++) {
        sfSprite_destroy(player->sprites[i]);
        sfTexture_destroy(player->textures[i]);
    }
    free(player->textures);
    free(player);
}
