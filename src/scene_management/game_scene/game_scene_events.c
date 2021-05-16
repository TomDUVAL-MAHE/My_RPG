/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** game_events
*/

#include "my_game.h"

void detect_moves_key_pressed(game_scene *game, sfEvent event)
{
    if (event.key.code == sfKeyZ) {
        game->player->move_up = true;
    }
    if (event.key.code == sfKeyQ) {
        game->player->move_left = true;
    }
    if (event.key.code == sfKeyS) {
        game->player->move_down = true;
    }
    if (event.key.code == sfKeyD) {
        game->player->move_right = true;
    }
}

void detect_interaction_key_pressed(my_game_t *rpg, game_scene *game, \
sfEvent event)
{
    if (event.key.code == sfKeyEscape) {
        pause_game(rpg);
        return;
    }
    if (game->pause_menu->displayed)
        return;
    if (event.key.code == sfKeySpace)
        if (!game->player->is_attacking)
            player_attack(game->player, rpg);
    if (event.key.code == sfKeyF)
        player_interaction(rpg);
    if (event.key.code == sfKeyE) {
        go_to_inventory_scene(rpg);
        if (my_strcmp(rpg->inventory_scene.inventory_list_two[1][0], \
            "ARMOR1") == 0)
            quest_end_equip_jacket(rpg);
    }
    if (event.key.code == sfKeyI) {
        go_to_quest_scene(rpg);
    }
}

void detect_moves_key_release(game_scene *game, sfEvent event)
{
    if (event.key.code == sfKeyZ)
        game->player->move_up = false;
    if (event.key.code == sfKeyQ)
        game->player->move_left = false;
    if (event.key.code == sfKeyS)
        game->player->move_down = false;
    if (event.key.code == sfKeyD)
        game->player->move_right = false;
}

void game_scene_events(my_game_t *rpg, game_scene *game, sfEvent event)
{
    while (sfRenderWindow_pollEvent(rpg->window.window, &(event))) {
        if (event.type == sfEvtClosed)
            rpg->scene = EXIT;
        if (event.type == sfEvtKeyPressed) {
            detect_interaction_key_pressed(rpg, game, event);
            detect_moves_key_pressed(game, event);
        }
        if (event.type == sfEvtKeyReleased) {
            detect_moves_key_release(game, event);
        }
        if (game->pause_menu->displayed || rpg->option->menu->displayed)
            game_scene_pause_menu_event(rpg, event);
    }
}