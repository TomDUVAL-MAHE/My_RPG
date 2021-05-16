/*
** EPITECH PROJECT, 2021
** scene_display
** File description:
** desc
*/

#include "my_game.h"

void enemys_move(my_game_t *rpg, enemy_list_t *enemy_list)
{
    enemy_node_t *ptr;

    if (!enemy_list)
        return;
    ptr = enemy_list->first;
    while (ptr) {
        enemy_move(ptr->enemy, (sfVector2f){0, 0}, rpg, false);
        ptr = ptr->next;
    }
}

void pnjs_moves(my_game_t *rpg, pnj_node_t *ptr, \
float multiplier)
{
    if (ptr->pnj->hitbox.left <= ptr->pnj->end.x)
        pnj_move(ptr->pnj, (sfVector2f){2.0 * multiplier, 0}, rpg, false);
    else
        pnj_move(ptr->pnj, (sfVector2f){-2.0 * multiplier, 0}, rpg, false);
    if (ptr->pnj->hitbox.top <= ptr->pnj->end.y)
        pnj_move(ptr->pnj, (sfVector2f){0, 2.0 * multiplier}, rpg, false);
    else
        pnj_move(ptr->pnj, (sfVector2f){0, -2.0 * multiplier}, rpg, false);
}

void pnjs_move(my_game_t *rpg, pnj_list_t *pnj_list)
{
    pnj_node_t *ptr;
    float multiplier = (float) {rpg->elapsed_microsecond} / 100000;

    if (!pnj_list)
        return;
    ptr = pnj_list->first;
    while (ptr) {
        pnjs_moves(rpg, ptr, multiplier);
        if (ptr->pnj->hitbox.left >= ptr->pnj->end.x - 1 && \
        ptr->pnj->hitbox.left <= ptr->pnj->end.x + 1 && \
        ptr->pnj->hitbox.top >= ptr->pnj->end.y - 1 && \
        ptr->pnj->hitbox.top <= ptr->pnj->end.y + 1) {
            sfVector2f temp = ptr->pnj->end;
            ptr->pnj->end = ptr->pnj->start;
            ptr->pnj->start = temp;
        }
        ptr = ptr->next;
    }
}

void game_scene_displays(my_game_t *rpg)
{
    enemys_move(rpg, rpg->game->enemy_list);
    game_scene_display_entities(rpg);
    weather_update(rpg);
    quest_display_shortcut(rpg->quest_list, rpg->window);
    life_bar_display(rpg->life_bar, rpg->window.window, rpg);
    level_bar_display(rpg->level_bar, rpg->window.window, rpg);
    draw_a_menu(rpg->window.window, rpg->game->pause_menu);
    draw_a_menu(rpg->window.window, rpg->option->menu);
}

void game_scene_display(my_game_t *rpg)
{
    if (!rpg->game)
        go_to_a_scene(rpg, EXIT);
    enemys_move(rpg, rpg->game->enemy_list);
    pnjs_move(rpg, rpg->game->pnj_list);
    while (rpg->scene == GAME) {
        sfRenderWindow_clear(rpg->window.window, sfBlack);
        game_scene_events(rpg, rpg->game, rpg->window.event);
        if (!rpg->game->pause_menu->displayed || rpg->option->menu->displayed) {
            get_time(rpg);
            enemy_ia_management(rpg, rpg->game->enemy_list);
            player_move(rpg, rpg->game->player);
            pnjs_move(rpg, rpg->game->pnj_list);
        }
        game_scene_displays(rpg);
        sfRenderWindow_display(rpg->window.window);
        if (rpg->game->player->destroyed)
            go_to_main_menu_scene(rpg);
    }
    scene_manager(rpg);
}