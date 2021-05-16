/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** enemy_display
*/

#include "my_game.h"

void enemy_walk_animation(my_game_t *rpg, enemy_t *enemy)
{
    if (enemy->anim_cooldown <= 0) {
        enemy->anim_rect.left += ENEMY_ANIMATION_RECT_WIDTH;
        enemy->anim_cooldown = ENEMY_ANIMATION_COOLDOWN;
        enemy->anim_rect.left = (enemy->anim_rect.left >= 9 * \
        ENEMY_ANIMATION_RECT_WIDTH ? ENEMY_ANIMATION_RECT_WIDTH : \
        enemy->anim_rect.left);
    }
    enemy->anim_cooldown -= rpg->elapsed_microsecond;
}

void enemy_die_animation(my_game_t *rpg, enemy_t *enemy)
{
    sfSprite_setPosition(enemy->sprite, (sfVector2f)\
    {ENEMY_SPRITE_BASIC_POS_X, ENEMY_SPRITE_BASIC_POS_Y});
    if (enemy->anim_cooldown <= 0) {
        enemy->anim_rect.left += ENEMY_ANIMATION_RECT_WIDTH;
        enemy->anim_cooldown = ENEMY_ANIMATION_COOLDOWN * 2;
        if (enemy->anim_rect.left >= ENEMY_DIE_MAX_LEFT) {
            enemy->destroyed = true;
        }
    }
    enemy->anim_cooldown -= rpg->elapsed_microsecond;
}

void enemy_animation(my_game_t *rpg, enemy_t *enemy)
{
    if (enemy->is_dying) {
        enemy_die_animation(rpg, enemy);
        return;
    }
    if (enemy->is_attacking) {
        enemy_attack_animation(rpg, enemy);
        return;
    }
    if (enemy->is_walking) {
        enemy_walk_animation(rpg, enemy);
        return;
    }
}

void enemies_display(my_game_t *rpg, enemy_list_t *enemy_list, int i, int j)
{
    enemy_node_t *ptr;
    enemy_node_t *temp;

    if (!enemy_list)
        return;
    ptr = enemy_list->first;
    while (ptr) {
        if (i == ptr->enemy->tile.y && j == ptr->enemy->tile.x) {
            enemy_animation(rpg, ptr->enemy);
            sfSprite_setTextureRect(ptr->enemy->sprite, ptr->enemy->anim_rect);
            sfRenderWindow_drawSprite(rpg->window.window, \
            ptr->enemy->sprite, NULL);
        }
        if (ptr->enemy->destroyed) {
            temp = ptr;
            ptr = ptr->next;
            enemy_list_destroy_a_selected_node_in_list(enemy_list, temp);
            temp = NULL;
        } else
            ptr = ptr->next;
    }
}