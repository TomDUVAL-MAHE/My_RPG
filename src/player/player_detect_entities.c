/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** player_detect_entities
*/

#include "my_game.h"

void player_is_killing_enemy(enemy_t *enemy, player_t *player, my_game_t *rpg)
{
    if (!enemy->is_dying && enemy->stats.pv <= 0) {
        enemy->is_dying = true;
        enemy->anim_rect = ENEMY_DIE_RECT;
        player->stats.xp += enemy->stats.xp_max;
        if (player->stats.xp >= player->stats.xp_max) {
            player->stats.level += 1;
            player->stats.xp = 0;
            player->stats.xp_max *= 1.2;
            rpg->skill_scene.remaining_point += 1;
            skill_scene_update_text(&(rpg->skill_scene));
        }
        player->stats.pv += enemy->stats.pv_max * 1.2;
        if (player->stats.pv > player->stats.pv_max)
            player->stats.pv = player->stats.pv_max;
        enemy_give_item(rpg, enemy->stats.level);
        enemy->anim_cooldown = ENEMY_ANIMATION_COOLDOWN * 2;
    }
}

void player_hit_ennemy(player_t *player, enemy_list_t *e_list, my_game_t *rpg)
{
    enemy_node_t *ptr;

    if (!e_list)
        return;
    ptr = e_list->first;
    while (ptr) {
        if (sfFloatRect_intersects(&player->attack_hitbox, \
        &ptr->enemy->hitbox, NULL)) {
            ptr->enemy->stats.pv -= player->stats.attack;
            player_is_killing_enemy(ptr->enemy, player, rpg);
        }
        ptr = ptr->next;
    }
}

void player_cut_tree(my_game_t *rpg, sfFloatRect hitbox)
{
    sfVector2i tile = return_actual_tile(rpg, (sfVector2f)\
    {hitbox.left + hitbox.width / 2 + rpg->game->map->origin.x, \
        hitbox.top + hitbox.height + rpg->game->map->origin.y});

    if (rpg->game->map->tiles[tile.y * \
    rpg->game->map->size.x + tile.x].building == 22) {
        rpg->game->map->tiles[tile.y * \
        rpg->game->map->size.x + tile.x].building = 0;
        quest_end_unlock_passage(rpg);
    }
    if (rpg->game->map->tiles[tile.y * \
    rpg->game->map->size.x + tile.x].building == 23) {
        rpg->game->map->tiles[tile.y * \
        rpg->game->map->size.x + tile.x].building = 0;
        quest_end_unlock_passage(rpg);
    }
}

void player_cut_rock(my_game_t *rpg, sfFloatRect hitbox)
{
    sfVector2i tile = return_actual_tile(rpg, (sfVector2f)\
    {hitbox.left + hitbox.width / 2 + rpg->game->map->origin.x, \
        hitbox.top + hitbox.height + rpg->game->map->origin.y});

    if (rpg->game->map->tiles[tile.y * \
    rpg->game->map->size.x + tile.x].building == 13) {
        rpg->game->map->tiles[tile.y * \
        rpg->game->map->size.x + tile.x].building = 0;
        quest_end_unlock_passage_two(rpg);
    }
}