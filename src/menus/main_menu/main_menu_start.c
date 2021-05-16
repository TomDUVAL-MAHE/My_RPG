/*
** EPITECH PROJECT, 2021
** menu
** File description:
** menu
*/

#include "my_game.h"

void draw_main_menu(sfRenderWindow *window, main_menu_t *main_menu)
{
    draw_a_menu(window, &(main_menu->main_part));
    draw_a_menu(window, &(main_menu->play_part));
}

void clear_save_one(my_game_t *rpg)
{
    clear_a_save("1");
    rpg->mouse_pressed = rpg->mouse_pressed;
}

void save_one_launch(my_game_t *rpg)
{
    if (load_a_save(rpg, "1") == 0)
        go_to_game_scene(rpg);
    else
        go_to_a_scene(rpg, EXIT);
}

void save_two_launch(my_game_t *rpg)
{
    if (load_a_save(rpg, "2") == 0)
        go_to_game_scene(rpg);
    else
        go_to_a_scene(rpg, EXIT);
}
