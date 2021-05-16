/*
** EPITECH PROJECT, 2021
** main
** File description:
** desc
*/

#include "my_inventory_scene.h"

void inventory_scene_update_picture_four(inventory_scene_t *inventory_scene, \
bool is_man, player_t *player)
{
    sfIntRect area = setup_area(inventory_scene->dir);

    if (is_man) {}
    if (my_strcmp(inventory_scene->inventory_list_two[4][0], "EMPTY") != 0) {
        sfRectangleShape_setTexture(inventory_scene->picture_list[7], \
        inventory_texture(inventory_scene->inventory_list_two[4][0], \
        inventory_scene->dir), true);
        change_player_texture(player, inventory_texture\
        (inventory_scene->inventory_list_two[4][0], 4), PLAYER_TAB_WEAPON);
        player_update_weapon_type(player, inventory_scene);
    } else {
        sfRectangleShape_setTexture(inventory_scene->picture_list[7], \
        sfTexture_createFromFile("assets/characters/player/weapons/weapon1.png"\
        , &area), true);
        change_player_texture(player, sfTexture_createFromFile\
        ("assets/characters/player/weapons/weapon1.png", NULL), \
        PLAYER_TAB_WEAPON);
        player->weapon_type = SWORD;
    }
}

void inventory_scene_udpate_picture_two(inventory_scene_t *inventory_scene, \
bool is_man, player_t *player)
{
    sfIntRect area = setup_area(inventory_scene->dir);

    if (my_strcmp(inventory_scene->inventory_list_two[2][0], "EMPTY") != 0) {
        sfRectangleShape_setTexture(inventory_scene->picture_list[6], \
        inventory_texture(inventory_scene->inventory_list_two[2][0], \
        inventory_scene->dir), true);
        change_player_texture(player, inventory_texture\
        (inventory_scene->inventory_list_two[2][0], 4), PLAYER_TAB_LEGS);
    } else {
        sfRectangleShape_setTexture(inventory_scene->picture_list[6], \
        sfTexture_createFromFile("assets/characters/player/legs/legs0.png", \
        &area), true);
        change_player_texture(player, sfTexture_createFromFile\
        ("assets/characters/player/legs/legs0.png", NULL), PLAYER_TAB_LEGS);
    }
    inventory_scene_update_picture_four(inventory_scene, is_man, player);
    inventory_scene_update_picture_sexe(inventory_scene, is_man);
}

void inventory_scene_update_picture_three(inventory_scene_t *inventory_scene, \
bool is_man, player_t *player)
{
    sfIntRect area = setup_area(inventory_scene->dir);

    if (is_man) {}
    if (my_strcmp(inventory_scene->inventory_list_two[0][0], "EMPTY") != 0) {
        sfRectangleShape_setTexture(inventory_scene->picture_list[4], \
        inventory_texture(inventory_scene->inventory_list_two[0][0], \
        inventory_scene->dir), true);
        change_player_texture(player, inventory_texture\
        (inventory_scene->inventory_list_two[0][0], 4), PLAYER_TAB_HAT);
    } else {
        sfRectangleShape_setTexture(inventory_scene->picture_list[4], \
        sfTexture_createFromFile("assets/characters/player/hats/hat0.png", \
        &area), true);
        change_player_texture(player, sfTexture_createFromFile\
        ("assets/characters/player/hats/hat0.png", NULL), PLAYER_TAB_HAT);
    }
}

void update_picture(inventory_scene_t *inventory_scene, \
bool is_man, player_t *player)
{
    sfIntRect area = setup_area(inventory_scene->dir);

    inventory_scene_update_picture_three(inventory_scene, is_man, player);
    if (my_strcmp(inventory_scene->inventory_list_two[1][0], "EMPTY") != 0) {
        sfRectangleShape_setTexture(inventory_scene->picture_list[5], \
        inventory_texture(inventory_scene->inventory_list_two[1][0], \
        inventory_scene->dir), true);
        change_player_texture(player, inventory_texture\
        (inventory_scene->inventory_list_two[1][0], 4), PLAYER_TAB_ARMOR);
    } else {
        sfRectangleShape_setTexture(inventory_scene->picture_list[5], \
        sfTexture_createFromFile("assets/characters/player/armors/armor0.png"\
        , &area), true);
        change_player_texture(player, sfTexture_createFromFile\
        ("assets/characters/player/armors/armor0.png", NULL), PLAYER_TAB_ARMOR);
    }
    inventory_scene_udpate_picture_two(inventory_scene, is_man, player);
}

void update_stats(inventory_scene_t *inventory_scene, stats_t *stats, \
player_t *player)
{
    inventory_update_list(inventory_scene->inventory_two, \
    inventory_scene->items, inventory_scene->inventory_list_two);
    update_picture(inventory_scene, true, player);
    update_attack(inventory_scene, stats);
    update_health(inventory_scene, stats);
    update_xp(inventory_scene, stats);
}