/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** enemy_init
*/

#include "my_pnj.h"
#include <stdlib.h>

sfSprite *pnj_sprite_init(pnj_t *pnj)
{
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, pnj->texture, sfFalse);
    sfSprite_setTextureRect(sprite, pnj->anim_rect);
    sfSprite_setPosition(sprite, \
    (sfVector2f){PNJ_SPRITE_BASIC_POS_X, PNJ_SPRITE_BASIC_POS_Y});
    sfSprite_scale(sprite, (sfVector2f){2, 2});
    return (sprite);
}

void pnj_init_values(pnj_t *pnj, sfVector2i pos, sfVector2i end)
{
    pnj->orientation = DOWN;
    pnj->move_up = false;
    pnj->move_down = false;
    pnj->move_left = false;
    pnj->move_right = false;
    pnj->is_walking = false;
    pnj->hitbox.width = PNJ_HITBOX_WIDTH;
    pnj->hitbox.height = PNJ_HITBOX_HEIGHT;
    pnj->hitbox.left = pos.x;
    pnj->hitbox.top = pos.y;
    pnj->anim_rect = PNJ_WALK_DOWN_RECT;
    pnj->anim_cooldown = PNJ_ANIMATION_COOLDOWN;
    pnj->tile = (sfVector2i){0, 0};
    pnj->end = (sfVector2f){end.x, end.y};
    pnj->start = (sfVector2f){pos.x, pos.y};
}

pnj_t *pnj_create(char *texture_path, sfVector2i pos, sfVector2i end)
{
    pnj_t *pnj = malloc(sizeof(pnj_t));

    if (!pnj)
        return (NULL);
    pnj_init_values(pnj, pos, end);
    pnj->texture = sfTexture_createFromFile(texture_path, NULL);
    if (!pnj->texture) {
        free(pnj);
        return (NULL);
    }
    pnj->sprite = pnj_sprite_init(pnj);
    if (!pnj->sprite) {
        free(pnj->texture);
        free(pnj);
        return (NULL);
    }
    return (pnj);
}

void pnj_destroy(pnj_t *pnj)
{
    if (!pnj)
        return;
    if (pnj->sprite)
        sfSprite_destroy(pnj->sprite);
    if (pnj->texture)
        sfTexture_destroy(pnj->texture);
    free(pnj);
}

int create_new_pnj(pnj_list_t *pnj_list, pnj_type e_type, \
sfVector2i pos, sfVector2i end)
{
    char *path = NULL;
    pnj_t *pnj = NULL;

    path = get_path_from_pnj_type(e_type);
    pnj = pnj_create(path, pos, end);
    if (!pnj)
        return (-1);
    pnj->e_type = e_type;
    pnj_list_insert_beginning(pnj_list, pnj);
    return (0);
}