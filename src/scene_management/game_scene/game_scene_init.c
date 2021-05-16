/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** game_scene_init
*/

#include <stdlib.h>
#include "my_game.h"
#include "my_game_scene.h"
#include "my_player.h"
#include "my_enemy.h"

void game_scene_cam_init(my_game_t *rpg, game_scene *game)
{
    game->cam_area.width = rpg->window.size.x * 0.66 - 2 * \
    game->player->hitbox.width;
    game->cam_area.height = rpg->window.size.y * 0.66 - 2 * \
    game->player->hitbox.height;
    game->cam_area.left = (float) {rpg->window.size.x} / 2 - \
    game->cam_area.width / 2;
    game->cam_area.top = (float) {rpg->window.size.y} / 2 - \
    game->cam_area.height / 2;
}

void game_scene_init_lifebar(my_game_t *rpg)
{
    rpg->life_bar = malloc(sizeof(sfRectangleShape *) * 2);
    rpg->life_bar[0] = sfRectangleShape_create();
    sfRectangleShape_setPosition(rpg->life_bar[0], (sfVector2f)\
    {rpg->window.size.x * 0.01, rpg->window.size.y * 0.01});
    sfRectangleShape_setSize(rpg->life_bar[0], (sfVector2f)\
    {rpg->window.size.x * 0.20, rpg->window.size.y * 0.05});
    sfRectangleShape_setOutlineThickness(rpg->life_bar[0], 4);
    sfRectangleShape_setOutlineColor(rpg->life_bar[0], sfBlack);
    sfRectangleShape_setFillColor(rpg->life_bar[0], sfTransparent);
    rpg->life_bar[1] = sfRectangleShape_create();
    sfRectangleShape_setPosition(rpg->life_bar[1], (sfVector2f)\
    {rpg->window.size.x * 0.01, rpg->window.size.y * 0.01});
    sfRectangleShape_setSize(rpg->life_bar[1], (sfVector2f)\
    {rpg->window.size.x * 0.20, rpg->window.size.y * 0.05});
    sfRectangleShape_setOutlineThickness(rpg->life_bar[1], 0);
    sfRectangleShape_setFillColor(rpg->life_bar[1], sfRed);
}

void game_scene_init_levelbar(my_game_t *rpg)
{
    rpg->level_bar = malloc(sizeof(sfRectangleShape *) * 2);
    rpg->level_bar[0] = sfRectangleShape_create();
    sfRectangleShape_setPosition(rpg->level_bar[0], (sfVector2f)\
    {rpg->window.size.x * 0.01, rpg->window.size.y * 0.07});
    sfRectangleShape_setSize(rpg->level_bar[0], (sfVector2f)\
    {rpg->window.size.x * 0.20, rpg->window.size.y * 0.02});
    sfRectangleShape_setOutlineThickness(rpg->level_bar[0], 4);
    sfRectangleShape_setOutlineColor(rpg->level_bar[0], sfBlack);
    sfRectangleShape_setFillColor(rpg->level_bar[0], sfTransparent);
    rpg->level_bar[1] = sfRectangleShape_create();
    sfRectangleShape_setPosition(rpg->level_bar[1], (sfVector2f)\
    {rpg->window.size.x * 0.01, rpg->window.size.y * 0.07});
    sfRectangleShape_setSize(rpg->level_bar[1], (sfVector2f)\
    {rpg->window.size.x * 0.20, rpg->window.size.y * 0.02});
    sfRectangleShape_setOutlineThickness(rpg->level_bar[1], 0);
    sfRectangleShape_setFillColor(rpg->level_bar[1], sfCyan);
}

void game_scene_init_two(my_game_t *rpg, game_scene *game)
{
    game_scene_cam_init(rpg, game);
    map_set_size(game->map, (sfVector2i) {100, 100});
    map_set_tiles(game->map, 130);
    map_set_origin(game->map, (sfVector2f) {250, 250});
    game_scene_init_lifebar(rpg);
    game_scene_init_levelbar(rpg);
}

game_scene *game_scene_init(my_game_t *rpg)
{
    game_scene *game = malloc(sizeof(game_scene));

    if (!game)
        return (NULL);
    game->map = map_create();
    if (!game->map)
        return (NULL);
    game->player = player_create(rpg);
    if (!game->player)
        return (NULL);
    game->enemy_list = enemy_list_init();
    if (!game->enemy_list)
        return (NULL);
    game->pnj_list = pnj_list_init();
    if (!game->pnj_list)
        return (NULL);
    game->pause_menu = game_scene_pause_menu_init(rpg);
    if (!game->pause_menu)
        return (NULL);
    game_scene_init_two(rpg, game);
    return (game);
}