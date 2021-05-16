/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** enemy_init_type
*/

#include "my_enemy.h"
#include <stdlib.h>

void setup_orc_enemy_stats(enemy_t *enemy, int lvl, enemy_type type)
{
    int bonus = 0;

    if (type == ORC_SPEAR)
        bonus = 1;
    if (type == ORC_LONGSWORD)
        bonus = 2;
    enemy->stats.level = lvl;
    enemy->stats.attack = (1 + bonus) * lvl;
    enemy->stats.pv_max = (3 + bonus) * lvl;
    enemy->stats.pv = enemy->stats.pv_max;
    enemy->stats.xp_max = 5 * lvl + bonus;
}

void setup_wolf_enemy_stats(enemy_t *enemy, int lvl)
{
    enemy->stats.level = lvl;
    enemy->stats.attack = 3 * lvl;
    enemy->stats.pv_max = 5 * lvl;
    enemy->stats.pv = enemy->stats.pv_max;
    enemy->stats.xp_max = 10 * lvl;
    enemy->weapon_type = SWORD;
}

void setup_boss_enemy_stats(enemy_t *enemy, int lvl)
{
    enemy->stats.level = lvl;
    enemy->stats.attack = 5 * lvl * 2;
    enemy->stats.pv_max = 10 * lvl * 2;
    enemy->stats.pv = enemy->stats.pv_max;
    enemy->stats.xp_max = 15 * lvl;
}

void setup_enemy_caracteristique_from_type(enemy_t *enemy, \
enemy_type type, int lvl)
{
    if (type == ORC_LONGSWORD)
        setup_orc_enemy_stats(enemy, lvl, type);
    if (type == ORC_SCYTHE)
        setup_orc_enemy_stats(enemy, lvl, type);
    if (type == ORC_SPEAR)
        setup_orc_enemy_stats(enemy, lvl, type);
    if (type == WOLF)
        setup_wolf_enemy_stats(enemy, lvl);
    if (type == BOSS)
        setup_boss_enemy_stats(enemy, lvl);
}