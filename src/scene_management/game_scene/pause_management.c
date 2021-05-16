/*
** EPITECH PROJECT, 2021
** rpg_temp
** File description:
** pause_management
*/

#include "my_game_scene.h"
#include "my_game.h"
#include "my_player.h"
#include "my_enemy.h"

void pause_game(my_game_t *rpg)
{
    menus_t *pause_m = rpg->game->pause_menu;

    rpg->option->menu->displayed = false;
    pause_m->displayed = (pause_m->displayed ? false : true);
    if (pause_m->displayed) {
        rpg->elapsed_microsecond = 0;
    } else {
        get_time(rpg);
        rpg->last_time = rpg->actual_time;
        rpg->elapsed_microsecond = 0;
    }
}

void check_pause_menu_button_hover(my_game_t *rpg, sfVector2i pos)
{
    if (rpg->game->pause_menu->displayed)
        for (int i = 0; i < rpg->game->pause_menu->nb_btns; i++)
            button_is_hover(rpg->game->pause_menu->btns[i], pos);
    if (rpg->option->menu->displayed)
        for (int i = 0; i < rpg->option->menu->nb_btns; i++)
            button_is_hover(rpg->option->menu->btns[i], pos);
}

void check_pause_menu_button_pressed(my_game_t *rpg, sfVector2i pos)
{
    if (rpg->game->pause_menu->displayed)
        for (int i = 0; i < rpg->game->pause_menu->nb_btns; i++)
            button_is_click(rpg->game->pause_menu->btns[i], pos);
    if (rpg->option->menu->displayed)
        for (int i = 0; i < rpg->option->menu->nb_btns; i++)
            button_is_click(rpg->option->menu->btns[i], pos);
}

void check_pause_menu_button_release(my_game_t *rpg, sfVector2i pos)
{
    int i = 0;
    if (rpg->game->pause_menu->displayed) {
        for (i = 0; i < rpg->game->pause_menu->nb_btns \
        && rpg->game->pause_menu->btns[i]->status != CLICK; i++);
        if (i >= rpg->game->pause_menu->nb_btns)
            return;
        if (button_is_hover(rpg->game->pause_menu->btns[i], pos)) {
            button_launch_action(rpg->game->pause_menu->btns[i], rpg);
        }
    }
    if (rpg->option->menu->displayed) {
        for (i = 0; i < rpg->option->menu->nb_btns \
        && rpg->option->menu->btns[i]->status != CLICK; i++);
        if (i >= rpg->option->menu->nb_btns)
            return;
        if (button_is_hover(rpg->option->menu->btns[i], pos)) {
            button_launch_action(rpg->option->menu->btns[i], rpg);
        }
    }
}

void game_scene_pause_menu_event(my_game_t *rpg, sfEvent event)
{
    if (event.type == sfEvtMouseMoved && rpg->mouse_pressed == false) {
        check_pause_menu_button_hover(rpg, \
        (sfVector2i){event.mouseMove.x, event.mouseMove.y});
    }
    if (event.type == sfEvtMouseButtonPressed) {
        rpg->mouse_pressed = true;
        check_pause_menu_button_pressed(rpg,  \
        (sfVector2i){event.mouseButton.x, event.mouseButton.y});
    }
    if (event.type == sfEvtMouseButtonReleased) {
        rpg->mouse_pressed = false;
        check_pause_menu_button_release(rpg,  \
        (sfVector2i){event.mouseButton.x, event.mouseButton.y});
    }
}
