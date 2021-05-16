/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** player_attack
*/

#include "my_game.h"

void player_attack(player_t *player, my_game_t *rpg)
{
    player->is_attacking = true;
    if (player->weapon_type == SWORD || player->weapon_type == AXE \
        || player->weapon_type == PICKAXE)
        player_basic_attack(player, rpg);
    if (player->weapon_type == LONG_SWORD)
        player_long_sword_attack(player, rpg);
    if (player->weapon_type == BOW)
        player_bow_attack(player);
    if (player->weapon_type == CROSSBOW)
        player_crossbow_attack(player);
}
