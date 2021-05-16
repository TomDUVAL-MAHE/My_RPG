/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** enemy_display
*/

#include "my_game.h"
#include "my_pnj.h"

void pnj_tell_end(my_window_t window, my_game_t *rpg, int *stop)
{
    while (sfRenderWindow_pollEvent(window.window, &(window.event))) {
        get_time(rpg);
        if (window.event.type == sfEvtClosed) {
            rpg->scene = EXIT;
            *stop = 1;
        }
        if (window.event.type == sfEvtKeyPressed && window.event.key.code \
            == sfKeyEnter)
            *stop = 1;
        if (window.event.type == sfEvtJoystickButtonPressed && \
            window.event.joystickButton.button == 0)
            *stop = 1;
    }
}

void draw_dialog(my_window_t window, char *str)
{
    sfRectangleShape *back = sfRectangleShape_create();
    text_t text = text_create((sfVector2f){window.size.x * 0.38, \
        window.size.y * 0.38}, str, sfFont_createFromFile\
    ("assets/fonts/arial.ttf"), true);

    sfRectangleShape_setPosition(back, (sfVector2f)\
    {window.size.x * 0.35, window.size.y * 0.35});
    sfRectangleShape_setSize(back, (sfVector2f)\
    {window.size.x * 0.30, window.size.y * 0.30});
    sfRectangleShape_setTexture(back, \
    sfTexture_createFromFile("assets/inventory/back.png", NULL), true);
    sfRenderWindow_drawRectangleShape(window.window, back, NULL);
    text_change_fill_color(&text, sfBlack);
    text_display(&text, window.window);
    sfRenderWindow_display(window.window);
    sfRectangleShape_destroy(back);
}