/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** main_menu_play_part_buttons.c
*/

#include "my_game.h"

void event_anim(my_game_t *rpg, bool *anim, int *speed)
{
    while (sfRenderWindow_pollEvent(rpg->window.window, &(rpg->window.event))) {
        if (rpg->window.event.type == sfEvtClosed)
            go_to_a_scene(rpg, EXIT);
        if (rpg->window.event.type == sfEvtKeyPressed)
            event_anim_key(rpg, anim, speed);
        if (rpg->window.event.type == sfEvtKeyReleased && \
            rpg->window.event.key.code == sfKeySpace)
            *speed = 5;
    }
}

void move_anim(my_game_t *rpg, int speed, text_t *text, bool *anim)
{
    sfVector2f pos = text->pos;

    pos.y -= ((float)speed * ((float)rpg->elapsed_microsecond / 100000));
    text_change_pos(text, pos);
    if (text->pos.y < rpg->window.size.y * -0.6)
        *anim = false;
}

void display_anim(my_game_t *rpg, sfRectangleShape *back, text_t text)
{
    sfRenderWindow_clear(rpg->window.window, sfBlack);
    sfRenderWindow_drawRectangleShape(rpg->window.window, back, NULL);
    text_display(&(text), rpg->window.window);
    sfRenderWindow_display(rpg->window.window);
}

void destroy_anim(text_t *text, sfRectangleShape *back)
{
    text_destroy(text);
    sfRectangleShape_destroy(back);
}

int first_cut_scene(my_game_t *rpg)
{
    bool anim = true;
    int speed = 5;
    text_t text;
    sfRectangleShape *background;

    setup_anim(rpg, &text, &background);
    while (anim == true) {
        get_time(rpg);
        event_anim(rpg, &anim, &speed);
        if (rpg->scene == EXIT)
            break;
        move_anim(rpg, speed, &text, &anim);
        display_anim(rpg, background, text);
    }
    destroy_anim(&text, background);
    if (rpg->scene == EXIT)
        return (-1);
    return (0);
}