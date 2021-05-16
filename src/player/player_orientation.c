/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** player_orientation
*/

#include "my_game.h"
#include "arrow.h"

void player_orientate(player_t *player)
{
    sfIntRect up_rect = PLAYER_WALK_UP_RECT;
    sfIntRect down_rect = PLAYER_WALK_DOWN_RECT;
    sfIntRect left_rect = PLAYER_WALK_LEFT_RECT;
    sfIntRect right_rect = PLAYER_WALK_RIGHT_RECT;

    if (player->orientation == UP) {
        player->anim_rect.top = up_rect.top;
    }
    if (player->orientation == DOWN) {
        player->anim_rect.top = down_rect.top;
    }
    if (player->orientation == LEFT) {
        player->anim_rect.top = left_rect.top;
    }
    if (player->orientation == RIGHT) {
        player->anim_rect.top = right_rect.top;
    }
}

void player_chose_orientations(player_t *player, sfVector2f move, int count, \
orientation orient)
{
    if (move.x > 0) {
        count++;
        orient = RIGHT;
        player->is_walking = true;
    }
    if (count == 1) {
        player->orientation = orient;
        player_orientate(player);
    }
}

void player_chose_orientation(player_t *player, sfVector2f move)
{
    int count = 0;
    orientation orient;

    player->is_walking = false;
    if (move.y < 0) {
        count++;
        orient = UP;
        player->is_walking = true;
    }
    if (move.y > 0) {
        count++;
        orient = DOWN;
        player->is_walking = true;
    }
    if (move.x < 0) {
        count++;
        orient = LEFT;
        player->is_walking = true;
    }
    player_chose_orientations(player, move, count, orient);
}