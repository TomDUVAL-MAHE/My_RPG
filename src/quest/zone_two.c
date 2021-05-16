/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** game_events
*/

#include "my_game.h"
#include "my_quest.h"

bool is_in_zone(sfFloatRect player, sfIntRect zone, my_game_t *rpg)
{
    sfVector2i tile = return_actual_tile(rpg, (sfVector2f){player.left + \
        player.width / 2 + rpg->game->map->origin.x, player.top + \
        player.height + rpg->game->map->origin.y});

    if (tile.x >= zone.left && tile.x <= zone.left + zone.width && \
        tile.y >= zone.top && tile.y <= zone.top + zone.height)
        return (true);
    return (false);
}

void enter_zone_none(sfFloatRect player, my_game_t *rpg)
{
    if (rpg->game->player->zone == NONE)
        return;
    if (is_in_zone(player, MOUTAIN_ZONE, rpg) == false && is_in_zone\
    (player, ICELAND_ZONE, rpg) == false && is_in_zone\
    (player, BEACH_ZONE, rpg) == false && is_in_zone\
    (player, PEERAGE_ZONE, rpg) == false && is_in_zone\
    (player, VILLAGE_ZONE, rpg) == false) {
        weather_engine_start_sun(rpg);
        rpg->game->player->zone = NONE;
    }
}

void enter_zone_village(sfFloatRect player, my_game_t *rpg)
{
    if (rpg->game->player->zone == VILLAGE)
        return;
    if (is_in_zone(player, VILLAGE_ZONE, rpg) == true) {
        rpg->weather_engine.actual_weather = NONE;
        rpg->game->player->zone = VILLAGE;
    }
}

void enemy_creation(my_game_t *rpg, int nb, int lvl, enemy_type e_type)
{
    for (int i = 0; i < nb; i++) {
        create_new_enemy(rpg->game->enemy_list, e_type, lvl, (sfVector2i)\
        {rpg->game->player->hitbox.left - 200 + (rand() % 100), \
            rpg->game->player->hitbox.top - 300 + (rand() % 100)});
    }
}
