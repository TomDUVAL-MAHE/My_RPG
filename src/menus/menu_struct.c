/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** menu_struct.c
*/

#include "my_game.h"

void draw_a_menu(sfRenderWindow *window, menus_t *menu)
{
    if (menu->displayed == false)
        return;
    for (int i = 0; i < menu->nb_btns; i++) {
        button_display(window, menu->btns[i]);
    }
    for (int i = 0; i < menu->nb_text; i++) {
        text_display(&(menu->text[i]), window);
    }
}

menus_t *destroy_a_menu(menus_t *menu)
{
    if (!menu)
        return NULL;
    if (menu->nb_btns > 0) {
        for (int i = 0; i < menu->nb_btns; i++)
            button_destroy(menu->btns[i]);
        free(menu->btns);
    }
    if (menu->nb_text > 0) {
        free(menu->text);
    }
    return (NULL);
}