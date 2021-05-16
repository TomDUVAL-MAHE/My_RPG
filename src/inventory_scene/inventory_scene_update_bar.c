/*
** EPITECH PROJECT, 2021
** main
** File description:
** desc
*/

#include "my_inventory_scene.h"

void update_attack(inventory_scene_t *inventory_scene, stats_t *stats)
{
    int attack = item_return_attack(inventory_scene->items, \
    inventory_scene->inventory_list_two[4][0]);

    attack += item_return_attack(inventory_scene->items, \
    inventory_scene->inventory_list_two[3][0]);
    attack += 1;
    stats->attack = attack;
    inventory_scene_update_attack_bar(inventory_scene, stats->attack);
}

void update_health(inventory_scene_t *inventory_scene, stats_t *stats)
{
    int health = 5;
    float a = stats->pv_max;
    float b = stats->pv;
    float coef = b / a;

    health += item_return_health(inventory_scene->items, \
    inventory_scene->inventory_list_two[0][0]);
    health += item_return_health(inventory_scene->items, \
    inventory_scene->inventory_list_two[1][0]);
    health += item_return_health(inventory_scene->items, \
    inventory_scene->inventory_list_two[2][0]);
    health += item_return_health(inventory_scene->items, \
    inventory_scene->inventory_list_two[3][0]);
    stats->pv_max = health;
    stats->pv = stats->pv_max * coef;
    inventory_scene_update_health_bar(inventory_scene, \
    stats->pv, stats->pv_max);
}

void update_xp(inventory_scene_t *inventory_scene, stats_t *stats)
{
    inventory_scene_update_level_bar(inventory_scene, stats->xp, \
    stats->xp_max, stats->level + 1);
}

void change_player_texture(player_t *player, sfTexture *texture, int cases)
{
    sfTexture_destroy(player->textures[cases]);
    player->textures[cases] = texture;
    sfSprite_setTexture(player->sprites[cases], texture, false);
}