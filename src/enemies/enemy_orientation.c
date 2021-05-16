/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** enemy_orientation
*/

#include "my_game.h"

void enemy_orientate(enemy_t *enemy)
{
    sfIntRect up_rect = ENEMY_WALK_UP_RECT;
    sfIntRect down_rect = ENEMY_WALK_DOWN_RECT;
    sfIntRect left_rect = ENEMY_WALK_LEFT_RECT;
    sfIntRect right_rect = ENEMY_WALK_RIGHT_RECT;

    if (enemy->orientation == UP) {
        enemy->anim_rect.top = up_rect.top;
    }
    if (enemy->orientation == DOWN) {
        enemy->anim_rect.top = down_rect.top;
    }
    if (enemy->orientation == LEFT) {
        enemy->anim_rect.top = left_rect.top;
    }
    if (enemy->orientation == RIGHT) {
        enemy->anim_rect.top = right_rect.top;
    }
    sfSprite_setTextureRect(enemy->sprite, enemy->anim_rect);
}

void enemy_chose_orientation_two(sfVector2f move, int count, \
orientation orient, enemy_t *enemy)
{
    if (move.x > 0) {
        count++;
        orient = RIGHT;
    }
    if (count == 1) {
        enemy->orientation = orient;
        enemy_orientate(enemy);
    }
}

void enemy_chose_orientation(enemy_t *enemy, sfVector2f move)
{
    int count = 0;
    orientation orient;

    if (move.y < 0) {
        count++;
        orient = UP;
    }
    if (move.y > 0) {
        count++;
        orient = DOWN;
    }
    if (move.x < 0) {
        count++;
        orient = LEFT;
    }
    enemy_chose_orientation_two(move, count, orient, enemy);
}

void define_enemy_orientation(sfVector2f move, enemy_t *enemy)
{
    if (move.y <= 0) {
        if (move.x < move.y)
            enemy->orientation = LEFT;
        else
            enemy->orientation = UP;
    }
    if (move.y > 0) {
        if (move.x > move.y)
            enemy->orientation = RIGHT;
        else
            enemy->orientation = DOWN;
    }
    enemy_orientate(enemy);
}