/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** scene_display
*/

#include "my_game.h"
#include "my_inventory_scene.h"
#include "my_enemy.h"
#include "my_player.h"

void main_menu_scene_display(my_game_t *rpg)
{
    sfTexture *texture = sfTexture_createFromFile\
    ("assets/menu_background.png", NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfTrue);
    while (rpg->scene == MAIN_MENU) {
        get_time(rpg);
        sfRenderWindow_clear(rpg->window.window, sfBlack);
        sfRenderWindow_drawSprite(rpg->window.window, sprite, NULL);
        main_menu_event_management(rpg->window.window, rpg->window.event, rpg);
        draw_main_menu(rpg->window.window, &(rpg->main_menu));
        draw_a_menu(rpg->window.window, rpg->option->menu);
        sfRenderWindow_display(rpg->window.window);
    }
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
    scene_manager(rpg);
}

void life_bar_display(sfRectangleShape **lifebar, sfRenderWindow *window, \
my_game_t *rpg)
{
    float res = 0.0;
    sfVector2f size = sfRectangleShape_getSize(lifebar[0]);
    float new_size = 0.0;

    res = (float)rpg->game->player->stats.pv / \
    (float)rpg->game->player->stats.pv_max;
    new_size = res * size.x;
    sfRectangleShape_setSize(lifebar[1], (sfVector2f){new_size, size.y});
    sfRenderWindow_drawRectangleShape(window, lifebar[0], NULL);
    sfRenderWindow_drawRectangleShape(window, lifebar[1], NULL);
}

void level_bar_display(sfRectangleShape **levelbar, sfRenderWindow *window, \
my_game_t *rpg)
{
    float res = 0.0;
    sfVector2f size = sfRectangleShape_getSize(levelbar[0]);
    float new_size = 0.0;

    res = (float)rpg->game->player->stats.xp / \
    (float)rpg->game->player->stats.xp_max;
    new_size = res * size.x;
    sfRectangleShape_setSize(levelbar[1], (sfVector2f){new_size, size.y});
    sfRenderWindow_drawRectangleShape(window, levelbar[0], NULL);
    sfRenderWindow_drawRectangleShape(window, levelbar[1], NULL);
}

void player_player_display(int i, int j, my_game_t *rpg, sfVector2i pos)
{
    if (i == pos.y && j == pos.x)
        player_display(rpg, rpg->game->player);
}

void game_scene_display_entitiess(my_game_t *rpg, int *j)
{
    if (rpg->game->map->camera.x - 15 > 0)
        *j = rpg->game->map->camera.x - 15;
    else
        *j = 0;
}