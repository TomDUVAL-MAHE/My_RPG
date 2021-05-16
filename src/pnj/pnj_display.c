/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** enemy_display
*/

#include "my_game.h"
#include "my_pnj.h"

void pnj_walk_animation(my_game_t *rpg, pnj_t *pnj)
{
    if (pnj->anim_cooldown <= 0) {
        pnj->anim_rect.left += PNJ_ANIMATION_RECT_WIDTH;
        pnj->anim_cooldown = PNJ_ANIMATION_COOLDOWN;
        pnj->anim_rect.left = (pnj->anim_rect.left >= 9 * \
        PNJ_ANIMATION_RECT_WIDTH ? PNJ_ANIMATION_RECT_WIDTH : \
        pnj->anim_rect.left);
    }
    pnj->anim_cooldown -= rpg->elapsed_microsecond;
}

void pnj_animation(my_game_t *rpg, pnj_t *pnj)
{
    if (pnj->is_walking == true)
        pnj_walk_animation(rpg, pnj);
}

void pnjs_display(my_game_t *rpg, pnj_list_t *pnj_list, int i, int j)
{
    pnj_node_t *ptr;

    if (!pnj_list)
        return;
    ptr = pnj_list->first;
    while (ptr) {
        if (i == ptr->pnj->tile.y && j == ptr->pnj->tile.x) {
            pnj_animation(rpg, ptr->pnj);
            sfSprite_setTextureRect(ptr->pnj->sprite, ptr->pnj->anim_rect);
            sfRenderWindow_drawSprite\
            (rpg->window.window, ptr->pnj->sprite, NULL);
        }
        ptr = ptr->next;
    }
}