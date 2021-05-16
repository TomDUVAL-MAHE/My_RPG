/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** game_events
*/

#include "my_game.h"
#include "my_quest.h"

void enter_zone_peerage(sfFloatRect player, my_game_t *rpg)
{
    if (rpg->game->player->zone == PEERAGE)
        return;
    if (is_in_zone(player, PEERAGE_ZONE, rpg) == true) {
        weather_engine_start_sun(rpg);
        enemy_creation(rpg, 2, 1, ORC_SCYTHE);
        rpg->game->player->zone = PEERAGE;
    }
}

void enter_zone_iceland(sfFloatRect player, my_game_t *rpg)
{
    if (rpg->game->player->zone == ICELAND)
        return;
    if (is_in_zone(player, ICELAND_ZONE, rpg) == true) {
        weather_engine_start_snow(rpg);
        rpg->game->player->zone = ICELAND;
        enemy_creation(rpg, 4, 2, WOLF);
    }
}

void enter_zone_moutain(sfFloatRect player, my_game_t *rpg)
{
    if (rpg->game->player->zone == MOUNTAIN)
        return;
    if (is_in_zone(player, MOUTAIN_ZONE, rpg) == true) {
        weather_engine_start_sun(rpg);
        rpg->game->player->zone = MOUNTAIN;
        enemy_creation(rpg, 6, 3, ORC_LONGSWORD);
    }
}

void zone_clean(sfIntRect zone, my_game_t *rpg, enemy_list_t *e_list)
{
    enemy_node_t *ptr;

    if (!e_list)
        return;
    ptr = e_list->first;
    while (ptr) {
        if (is_in_zone(ptr->enemy->hitbox, zone, rpg) == true)
            return;
        ptr = ptr->next;
    }
    if (zone.left == 10)
        quest_end_fight_one(rpg);
    if (zone.left == 6)
        quest_end_fight_two(rpg);
    if (zone.left == 51)
        quest_end_fight_three(rpg);
    if (zone.left == 84)
        quest_end_fights(rpg);
}

void enter_a_zone(sfFloatRect player, my_game_t *rpg)
{
    enter_zone_iceland(player, rpg);
    enter_zone_moutain(player, rpg);
    enter_zone_none(player, rpg);
    enter_zone_peerage(player, rpg);
    enter_zone_village(player, rpg);
    zone_clean(PEERAGE_ZONE, rpg, rpg->game->enemy_list);
    zone_clean(ICELAND_ZONE, rpg, rpg->game->enemy_list);
    zone_clean(MOUTAIN_ZONE, rpg, rpg->game->enemy_list);
    zone_clean(BEACH_ZONE, rpg, rpg->game->enemy_list);
}