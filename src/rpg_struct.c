/*
** EPITECH PROJECT, 2021
** RPG-TESTS
** File description:
** rpg_struct.c
*/

#include "my_game.h"
#include <time.h>
#include "option.h"

int init_rpg(my_game_t *rpg)
{
    srand(time(NULL));
    init_rpg_window(&(rpg->window), 1920, 1080);
    if (create_main_menu(rpg, &(rpg->main_menu)) == -1) {
        sfRenderWindow_destroy(rpg->window.window);
        return (-1);
    }
    option_init(rpg);
    rpg->main_clock = sfClock_create();
    rpg->actual_time = sfClock_getElapsedTime(rpg->main_clock);
    rpg->last_time = rpg->actual_time;
    rpg->mouse_pressed = false;
    rpg->scene = MAIN_MENU;
    rpg->game = NULL;
    return (0);
}

void destroy_rpg(my_game_t *rpg)
{
    game_scene_destroy(rpg->game);
    destroy_main_menu(&(rpg->main_menu));
    sfRenderWindow_destroy(rpg->window.window);
}