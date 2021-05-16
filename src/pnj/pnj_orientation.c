/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** enemy_orientation
*/

#include "my_game.h"
#include "my_pnj.h"

void pnj_orientate(pnj_t *pnj)
{
    sfIntRect up_rect = PNJ_WALK_UP_RECT;
    sfIntRect down_rect = PNJ_WALK_DOWN_RECT;
    sfIntRect left_rect = PNJ_WALK_LEFT_RECT;
    sfIntRect right_rect = PNJ_WALK_RIGHT_RECT;

    if (pnj->orientation == UP) {
        pnj->anim_rect.top = up_rect.top;
    }
    if (pnj->orientation == DOWN) {
        pnj->anim_rect.top = down_rect.top;
    }
    if (pnj->orientation == LEFT) {
        pnj->anim_rect.top = left_rect.top;
    }
    if (pnj->orientation == RIGHT) {
        pnj->anim_rect.top = right_rect.top;
    }
}

void pnj_chose_orientation_two(pnj_t *pnj, sfVector2f move, \
int count, orientation orient)
{
    if (move.x < 0) {
        count++;
        orient = LEFT;
        pnj->is_walking = true;
    }
    if (move.x > 0) {
        count++;
        orient = RIGHT;
        pnj->is_walking = true;
    }
    if (count == 1) {
        pnj->orientation = orient;
        pnj_orientate(pnj);
    }
}

void pnj_chose_orientation(pnj_t *pnj, sfVector2f move)
{
    int count = 0;
    orientation orient;

    pnj->is_walking = false;
    if (move.y < 0) {
        count++;
        orient = UP;
        pnj->is_walking = true;
    }
    if (move.y > 0) {
        count++;
        orient = DOWN;
        pnj->is_walking = true;
    }
    pnj_chose_orientation_two(pnj, move, count, orient);
}