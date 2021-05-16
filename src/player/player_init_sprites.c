/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** player_init_sprites
*/

#include "my_game.h"

sfTexture **player_textures_init(void)
{
    sfTexture **textures = malloc(sizeof(*textures) * 6);

    if (!textures)
        return (NULL);
    textures[5] = NULL;
    textures[PLAYER_TAB_BODY] = \
    sfTexture_createFromFile(PLAYER_MAN_BODY_PATH, NULL);
    textures[PLAYER_TAB_HAT] = \
    sfTexture_createFromFile(PLAYER_HAT_PATH, NULL);
    textures[PLAYER_TAB_ARMOR] = \
    sfTexture_createFromFile(PLAYER_ARMOR_PATH, NULL);
    textures[PLAYER_TAB_LEGS] = \
    sfTexture_createFromFile(PLAYER_LEGS_PATH, NULL);
    textures[PLAYER_TAB_WEAPON] = \
    sfTexture_createFromFile(PLAYER_WEAPON_PATH, NULL);
    return (textures);
}

void player_sprites_inits(player_t *player, sfSprite **sprites)
{
    sfSprite_setTexture(sprites[PLAYER_TAB_BODY], \
    player->textures[PLAYER_TAB_BODY], sfFalse);
    sfSprite_setTexture(sprites[PLAYER_TAB_HAT], \
    player->textures[PLAYER_TAB_HAT], sfFalse);
    sfSprite_setTexture(sprites[PLAYER_TAB_ARMOR], \
    player->textures[PLAYER_TAB_ARMOR], sfFalse);
    sfSprite_setTexture(sprites[PLAYER_TAB_LEGS], \
    player->textures[PLAYER_TAB_LEGS], sfFalse);
    sfSprite_setTexture(sprites[PLAYER_TAB_WEAPON], \
    player->textures[PLAYER_TAB_WEAPON], sfFalse);
}

sfSprite **player_sprites_init(player_t *player)
{
    sfSprite **sprites = malloc(sizeof(*sprites) * 6);

    if (!sprites)
        return (NULL);
    sprites[5] = NULL;
    for (int i = 0; i < 5; i++) {
        sprites[i] = sfSprite_create();
        sfSprite_setTextureRect(sprites[i], player->anim_rect);
        sfSprite_setPosition(sprites[i], \
        (sfVector2f){PLAYER_SPRITE_BASIC_POS_X, PLAYER_SPRITE_BASIC_POS_Y});
        sfSprite_scale(sprites[i], (sfVector2f){2, 2});
    }
    player_sprites_inits(player, sprites);
    return (sprites);
}