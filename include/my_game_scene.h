/*
** EPITECH PROJECT, 2021
** my_game_scene
** File description:
** desc
*/

#ifndef MY_GAME_SCENE_H_
#define MY_GAME_SCENE_H_

//--INCLUDE--------------------------------------------

#include <SFML/Graphics.h>
#include "my_map.h"
#include "my_player.h"
#include "my_enemy.h"
#include "my_pnj.h"
#include "my_inventory.h"
#include "my_skill_scene.h"
#include "my_menu.h"

typedef struct enemy_list_s enemy_list_t;
typedef struct pnj_list_s pnj_list_t;

typedef enum {
    MAIN_MENU,
    GAME,
    INVENTORY,
    WORLD_EDIT,
    QUEST,
    EXIT
} scene_id;

typedef struct game_scene {
    sfFloatRect cam_area;
    map_t *map;
    player_t *player;
    menus_t *pause_menu;
    enemy_list_t *enemy_list;
    pnj_list_t *pnj_list;

} game_scene;

//--PROTOTYPE------------------------------------------

//SCENE_MANAGER.C//

void scene_manager(my_game_t *rpg);

//GO_TO_A_SCENE.C//

void go_to_a_scene(my_game_t *rpg, scene_id scene);
void go_to_game_scene(my_game_t *rpg);
void go_to_main_menu_scene(my_game_t *rpg);
void go_to_inventory_scene(my_game_t *rpg);
void go_to_world_edit_scene(my_game_t *rpg);
void go_to_quest_scene(my_game_t *rpg);

//SCENE_DISPLAY.C//

void main_menu_scene_display(my_game_t *rpg);
game_scene *poubelle(my_game_t *rpg);
void game_scene_display(my_game_t *rpg);
void inventory_scene_key(my_game_t *rpg, sfEvent event);
void inventory_scene_events(my_game_t *rpg, \
inventory_scene_t *inventory_scene, sfEvent event, \
skill_scene_t *skill_scene);
void q_inventory_scene_display(my_game_t *rpg);
void world_edit(my_game_t *rpg);

//GAME_SCENE_INIT.C//

void game_scene_destroy(game_scene *game);
game_scene *game_scene_init(my_game_t *rpg);

//GAME_SCENE_EVENT.C//

void detect_moves_key_pressed(game_scene *game, sfEvent event);
void detect_interaction_key_pressed(my_game_t *rpg, game_scene *game, \
sfEvent event);
void detect_moves_key_release(game_scene *game, sfEvent event);
void game_scene_events(my_game_t *rpg, game_scene *game, sfEvent event);
void quest_scene_event(my_game_t *rpg, sfEvent event);

void quest_scene_manager(my_game_t *rpg);
void game_scene_display_entities(my_game_t *rpg);
void level_bar_display(sfRectangleShape **levelbar, sfRenderWindow *window, \
my_game_t *rpg);
void life_bar_display(sfRectangleShape **lifebar, sfRenderWindow *window, \
my_game_t *rpg);

//PAUSE//

void game_scene_pause_menu_event(my_game_t *rpg, sfEvent event);
menus_t *game_scene_pause_menu_init(my_game_t *rpg);
void pause_game(my_game_t *rpg);

#endif /* !MY_GAME_SCENE_H_ */