/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** main_menu_init.c
*/

#include "my_game.h"

int init_main_part(my_game_t *rpg, menus_t *main_part)
{
    main_part->displayed = true;
    main_part->nb_btns = 4;
    main_part->nb_text = 0;
    main_part->text = NULL;
    main_part->btns = malloc(sizeof(button_t *) * main_part->nb_btns);
    if (main_part->btns == NULL)
        return (-1);
    main_part->btns[0] = init_main_part_button_zero(rpg);
    main_part->btns[1] = init_main_part_button_one(rpg);
    main_part->btns[2] = init_main_part_button_two(rpg);
    main_part->btns[3] = init_main_part_button_three(rpg);
    return (0);
}

int init_play_part(my_game_t *rpg, menus_t *play_part)
{
    play_part->displayed = false;
    play_part->nb_btns = 7;
    play_part->nb_text = 0;
    play_part->text = NULL;
    play_part->btns = malloc(sizeof(button_t *) * play_part->nb_btns);
    if (play_part->btns == NULL)
        return (-1);
    play_part->btns[0] = init_play_part_button_zero(rpg);
    play_part->btns[1] = init_play_part_button_one(rpg);
    play_part->btns[2] = init_play_part_button_two(rpg);
    play_part->btns[3] = init_play_part_button_three(rpg);
    play_part->btns[4] = init_play_part_button_four(rpg);
    play_part->btns[5] = init_play_part_button_five(rpg);
    play_part->btns[6] = init_play_part_button_six(rpg);
    return (0);
}

void set_up_main_menu_title(text_t *text)
{
    sfFloatRect rect;

    *text = text_create((sfVector2f){1400, 20}, "TITLE",  \
    sfFont_createFromFile("assets/fonts/arial.ttf"), false);
    text_change_buffer(text, "TITLE");
    text_change_char_size(text, 200);
    text_change_fill_color(text, sfBlack);
    rect = sfText_getLocalBounds(text->text);
    text_change_pos(text, \
    (sfVector2f) {960 - rect.width / 2, 300 - rect.height / 2});
}

int create_main_menu(my_game_t *rpg, main_menu_t *main_menu)
{
    if (init_main_part(rpg, &(main_menu->main_part)) == -1)
        return (-1);
    if (init_play_part(rpg, &(main_menu->play_part)) == -1) {
        destroy_a_menu(&(main_menu->main_part));
        return (-1);
    }
    set_up_main_menu_title(&(main_menu->title));
    return (0);
}

void destroy_main_menu(main_menu_t *main_menu)
{
    destroy_a_menu(&(main_menu->main_part));
    destroy_a_menu(&(main_menu->play_part));
}