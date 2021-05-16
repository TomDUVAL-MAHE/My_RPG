/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** enemy_init
*/

#include "my_enemy.h"
#include <stdlib.h>

sfSprite *enemy_sprite_init(enemy_t *enemy)
{
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, enemy->texture, sfFalse);
    sfSprite_setTextureRect(sprite, enemy->anim_rect);
    sfSprite_setPosition(sprite, \
    (sfVector2f){ENEMY_SPRITE_BASIC_POS_X, ENEMY_SPRITE_BASIC_POS_Y});
    sfSprite_scale(sprite, (sfVector2f){2, 2});
    return (sprite);
}

void enemy_init_values(enemy_t *enemy, enemy_type e_type, \
sfVector2i pos, int lvl)
{
    enemy->type = e_type;
    enemy->orientation = DOWN;
    enemy->move_up = false;
    enemy->move_down = false;
    enemy->move_left = false;
    enemy->move_right = false;
    enemy->is_walking = false;
    enemy->is_dying = false;
    enemy->destroyed = false;
    enemy->is_attacking = false;
    enemy->hitbox.width = ENEMY_HITBOX_WIDTH;
    enemy->hitbox.height = ENEMY_HITBOX_HEIGHT;
    enemy->hitbox.left = pos.x;
    enemy->hitbox.top = pos.y;
    enemy->weapon_type = LONG_SWORD;
    enemy->anim_rect = ENEMY_WALK_DOWN_RECT;
    enemy->anim_cooldown = ENEMY_ANIMATION_COOLDOWN;
    enemy->attack_hitbox = ENEMY_REINIT_ATTACK_RECT;
    setup_enemy_caracteristique_from_type(enemy, e_type, lvl);
    enemy->tile = (sfVector2i){0, 0};
}

enemy_t *enemy_create(enemy_type e_type, int lvl, sfVector2i pos)
{
    enemy_t *enemy = malloc(sizeof(enemy_t));
    char *path = NULL;

    if (!enemy)
        return (NULL);
    path = get_path_and_weapon_type_from_enemy_type(e_type);
    enemy_init_values(enemy, e_type, pos, lvl);
    enemy->texture = sfTexture_createFromFile(path, NULL);
    if (!enemy->texture) {
        free(enemy);
        return (NULL);
    }
    enemy->sprite = enemy_sprite_init(enemy);
    if (!enemy->sprite) {
        free(enemy->texture);
        free(enemy);
        return (NULL);
    }
    return (enemy);
}

void enemy_destroy(enemy_t *enemy)
{
    if (!enemy)
        return;
    if (enemy->sprite)
        sfSprite_destroy(enemy->sprite);
    if (enemy->texture)
        sfTexture_destroy(enemy->texture);
    free(enemy);
}

int create_new_enemy(enemy_list_t *enemy_list, enemy_type e_type, \
int lvl, sfVector2i pos)
{
    enemy_t *enemy = NULL;

    enemy = enemy_create(e_type, lvl, pos);
    if (!enemy)
        return (-1);
    enemy_list_insert_beginning(enemy_list, enemy);
    return (0);
}