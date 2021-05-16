/*
** EPITECH PROJECT, 2021
** RPG-TESTS
** File description:
** main_menu_manager.c
*/

#include "my_game.h"

void check_main_menu_button_hover(my_game_t *rpg, sfVector2i pos)
{
    if (rpg->main_menu.main_part.displayed == true) {
        for (int i = 0; i < rpg->main_menu.main_part.nb_btns; i++) {
            button_is_hover(rpg->main_menu.main_part.btns[i], pos);
        }
    }
    if (rpg->main_menu.play_part.displayed == true) {
        for (int i = 0; i < rpg->main_menu.play_part.nb_btns; i++) {
            button_is_hover(rpg->main_menu.play_part.btns[i], pos);
        }
    }
    if (rpg->option->menu->displayed == true) {
        for (int i = 0; i < rpg->option->menu->nb_btns; i++) {
            button_is_hover(rpg->option->menu->btns[i], pos);
        }
    }
}

void check_main_menu_button_pressed(my_game_t *rpg, sfVector2i pos)
{
    if (rpg->main_menu.main_part.displayed == true) {
        for (int i = 0; i < rpg->main_menu.main_part.nb_btns; i++) {
            button_is_click(rpg->main_menu.main_part.btns[i], pos);
        }
    }
    if (rpg->main_menu.play_part.displayed == true) {
        for (int i = 0; i < rpg->main_menu.play_part.nb_btns; i++) {
            button_is_click(rpg->main_menu.play_part.btns[i], pos);
        }
    }
    if (rpg->option->menu->displayed == true) {
        for (int i = 0; i < rpg->option->menu->nb_btns; i++) {
            button_is_click(rpg->option->menu->btns[i], pos);
        }
    }
}

void check_main_menu_buttons(my_game_t *rpg, sfVector2i pos)
{
    int i = 0;

    if (rpg->option->menu->displayed == true) {
        for (i = 0; i < rpg->option->menu->nb_btns \
        && rpg->option->menu->btns[i]->status != CLICK; i++);
        if (i >= rpg->option->menu->nb_btns)
            return;
        if (button_is_hover(rpg->option->menu->btns[i], pos))
            button_launch_action(rpg->option->menu->btns[i], rpg);
    }
}

void check_main_menu_button_release(my_game_t *rpg, sfVector2i pos)
{
    int i = 0;

    if (rpg->main_menu.main_part.displayed == true) {
        for (i = 0; i < rpg->main_menu.main_part.nb_btns \
        && rpg->main_menu.main_part.btns[i]->status != CLICK; i++);
        if (i >= rpg->main_menu.main_part.nb_btns)
            return;
        if (button_is_hover(rpg->main_menu.main_part.btns[i], pos)) {
            button_launch_action(rpg->main_menu.main_part.btns[i], rpg);
        }
    }
    if (rpg->main_menu.play_part.displayed == true) {
        for (i = 0; i < rpg->main_menu.play_part.nb_btns \
        && rpg->main_menu.play_part.btns[i]->status != CLICK; i++);
        if (i >= rpg->main_menu.play_part.nb_btns)
            return;
        if (button_is_hover(rpg->main_menu.play_part.btns[i], pos))
            button_launch_action(rpg->main_menu.play_part.btns[i], rpg);
    }
    check_main_menu_buttons(rpg, pos);
}

void main_menu_event_management(sfRenderWindow *window, sfEvent event, \
my_game_t *rpg)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            rpg->scene = EXIT;
        if (event.type == sfEvtMouseMoved && rpg->mouse_pressed == false) {
            check_main_menu_button_hover(rpg, \
            (sfVector2i){event.mouseMove.x, event.mouseMove.y});
        }
        if (event.type == sfEvtMouseButtonPressed) {
            rpg->mouse_pressed = true;
            check_main_menu_button_pressed(rpg,  \
            (sfVector2i){event.mouseButton.x, event.mouseButton.y});
        }
        if (event.type == sfEvtMouseButtonReleased) {
            rpg->mouse_pressed = false;
            check_main_menu_button_release(rpg,  \
            (sfVector2i){event.mouseButton.x, event.mouseButton.y});
        }
    }
}
