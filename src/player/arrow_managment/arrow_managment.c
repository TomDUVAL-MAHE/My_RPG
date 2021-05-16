/*
** EPITECH PROJECT, 2021
** arrow_managment
** File description:
** for my_rpg
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stddef.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include "arrow.h"
#include "my_player.h"
#include "my_game.h"

void change_pos_of_arrow(int elapsed_microsecond, arrow_t *arrow, \
orientation direction)
{
    if (direction == 0) {
        arrow->pos.y -= arrow->power.speed * (elapsed_microsecond / 10000);
        arrow->hitbox.top -= arrow->power.speed * (elapsed_microsecond / 10000);
    }
    if (direction == 3) {
        arrow->pos.x += arrow->power.speed * (elapsed_microsecond / 10000);
        arrow->hitbox.left += arrow->power.speed * \
        (elapsed_microsecond / 10000);
    }
    if (direction == 1) {
        arrow->pos.y += arrow->power.speed * (elapsed_microsecond / 10000);
        arrow->hitbox.top += arrow->power.speed * (elapsed_microsecond / 10000);
    }
    if (direction == 2) {
        arrow->pos.x -= arrow->power.speed * (elapsed_microsecond / 10000);
        arrow->hitbox.left -= arrow->power.speed * \
        (elapsed_microsecond / 10000);
    }
    sfSprite_setPosition(arrow->sprite, arrow->pos);
}

bool is_arrow_hit_enemy(my_game_t *rpg, player_t *player, enemy_list_t *e_list)
{
    arrow_t *arrow = player->arrow;
    enemy_node_t *ptr;

    if (!e_list || !e_list->first || !arrow)
        return (false);
    ptr = e_list->first;
    while (ptr) {
        if (sfFloatRect_intersects(&arrow->hitbox, &ptr->enemy->hitbox, NULL)) {
            ptr->enemy->stats.pv -= player->stats.attack;
            player_is_killing_enemy(ptr->enemy, player, rpg);
            return (true);
        }
        ptr = ptr->next;
    }
    return (false);
}

void manage_arrow(my_game_t *rpg, player_t *player, enemy_list_t *e_list)
{
    if (!player->arrow)
        return;
    if (player->arrow->count != 0) {
        change_pos_of_arrow(rpg->elapsed_microsecond, player->arrow, \
        player->arrow->direction);
        player->arrow->count--;
    }
    if (is_arrow_hit_enemy(rpg, player, e_list) || player->arrow->count == 0) {
        destroy_arrow(player);
    }
}

void arrow_display(my_game_t *rpg, player_t *player)
{
    if (player->arrow == NULL)
        return;
    else {
        manage_arrow(rpg, player, rpg->game->enemy_list);
        if (player->arrow != NULL)
            sfRenderWindow_drawSprite(rpg->window.window, \
            player->arrow->sprite, NULL);
    }
}
