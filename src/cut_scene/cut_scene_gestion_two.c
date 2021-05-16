/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** main_menu_play_part_buttons.c
*/

#include "my_game.h"

void setup_anim(my_game_t *rpg, text_t *text, sfRectangleShape **background)
{
    char *str = malloc(sizeof(char) * 300);

    str[0] = '\0';
    my_strcat(str, "       Hello young adventurer.\n");
    my_strcat(str, "  Welcome to the Island of Heroes.\n");
    my_strcat(str, "        You will have to brave,\n");
    my_strcat(str, "           Worlds and Storms,\n");
    my_strcat(str, "    To overcome a terrible monster.\n");
    my_strcat(str, "  Navigate between Quests and Desires,\n");
    my_strcat(str, "         and Peace you will find.");
    *background = sfRectangleShape_create();
    sfRectangleShape_setSize(*background, (sfVector2f)\
    {rpg->window.size.x, rpg->window.size.y});
    sfRectangleShape_setPosition(*background, (sfVector2f){0, 0});
    sfRectangleShape_setTexture(*background, \
    sfTexture_createFromFile("assets/inventory/back.png", NULL), true);
    *text = text_create((sfVector2f){rpg->window.size.x * 0.2, \
        rpg->window.size.y * 1}, str, \
    sfFont_createFromFile("assets/fonts/arial.ttf"), true);
    text_change_char_size(text, (int)(0.041 * rpg->window.size.x));
    text_change_fill_color(text, sfBlack);
}

void event_anim_key(my_game_t *rpg, bool *anim, int *speed)
{
    if (rpg->window.event.key.code == sfKeyEnter)
        *anim = false;
    if (rpg->window.event.key.code == sfKeySpace)
        *speed = 50;
}