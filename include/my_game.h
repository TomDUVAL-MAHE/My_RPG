/*
** EPITECH PROJECT, 2021
** my_game
** File description:
** desc
*/

#ifndef MY_GAME_H_
#define MY_GAME_H_

//--INCLUDE--------------------------------------------

#include "my_window.h"
#include "my_main_menu.h"
#include "my_game_scene.h"
#include "my_skill_scene.h"
#include "my_inventory_scene.h"
#include "my_weather.h"
#include "my_quest.h"
#include "load.h"
#include "save.h"
#include "option.h"

//--DEFINE---------------------------------------------
#define BUTTON_SAVE_PATH "assets/buttons/button_menu_save.png"
#define BUTTON_SAVE_HOVER_PATH "assets/buttons/button_menu_save_hover.png"
#define BUTTON_SAVE_CLICK_PATH "assets/buttons/button_menu_save_click.png"
//--STRUCTURES-----------------------------------------

typedef struct my_game_s {
    int elapsed_microsecond;
    bool mouse_pressed;
    char *save_name;
    my_window_t window;
    main_menu_t main_menu;
    sfClock *main_clock;
    sfTime actual_time;
    sfTime last_time;
    scene_id scene;
    game_scene *game;
    inventory_scene_t inventory_scene;
    skill_scene_t skill_scene;
    my_weather_t weather_engine;
    quest_list_t quest_list;
    quest_scene_t quest_scene;
    sfRectangleShape **life_bar;
    sfRectangleShape **level_bar;
    option_t *option;
} my_game_t;

typedef struct my_vector_i {
    int x;
    int y;
    int z;
} vector_i;

//--PROTOTYPE------------------------------------------

//RPG_STRUCT.C//

int init_rpg(my_game_t *rpg);
void destroy_rpg(my_game_t *rpg);

//------BUTTONS_FUNCTION------//

//BUTTON_EXIT.C//

void make_exit(my_game_t *rpg);
void show_play_part(my_game_t *rpg);
void show_main_part(my_game_t *rpg);


//------TIME------//

//TIME_MANAGER.C//

void get_time(my_game_t *rpg);


//------TOOLS------//

void clear_save_one(my_game_t *rpg);
void save_one_launch(my_game_t *rpg);
void save_two_launch(my_game_t *rpg);
void draw_main_menu(sfRenderWindow *window, main_menu_t *main_menu);

//HITBOX_TOOLS.C//

void show_a_hitbox(sfRenderWindow *window, sfFloatRect hitbox);
void show_sprite_outline(sfRenderWindow *window, sfSprite *sprite);
sfVector2i get_current_tile(my_game_t *rpg);

int create_new_save_quest(char *save_name);
int create_new_save_map(char *save_name);
int create_new_save_enemy(char *save_name);
int create_new_save_pnj(char *save_name);
int create_new_save_player(char *save_name);
int create_new_save_two(char *save_name, my_game_t *rpg);
int create_new_save(char *save_name, my_game_t *rpg);
int create_new_save_skill(char *save_name);
int create_new_save_stats(char *save_name);
int create_new_save_inventory_two(char *save_name);
int create_new_save_inventory(char *save_name);
int create_new_save_global(char *save_name);

void game_scene_init_button_two_two(button_t *button, \
sfVector2f pos);
button_t *game_scene_init_button_two(my_game_t *rpg);
void game_scene_init_button_three_three(button_t *button, \
sfVector2f pos);
button_t *game_scene_init_button_three(my_game_t *rpg);
menus_t *game_scene_pause_menu_init(my_game_t *rpg);
void setup_anim(my_game_t *rpg, text_t *text, sfRectangleShape **background);
void event_anim_key(my_game_t *rpg, bool *anim, int *speed);

void game_scene_display_entities(my_game_t *rpg);
void enemys_move(my_game_t *rpg, enemy_list_t *enemy_list);
void pnjs_moves(my_game_t *rpg, pnj_node_t *ptr, \
float multiplier);
void pnjs_move(my_game_t *rpg, pnj_list_t *pnj_list);
void game_scene_displays(my_game_t *rpg);
void game_scene_display(my_game_t *rpg);
void game_scene_display_entitiess(my_game_t *rpg, int *j);
void player_player_display(int i, int j, my_game_t *rpg, sfVector2i pos);
void level_bar_display(sfRectangleShape **levelbar, sfRenderWindow *window, \
my_game_t *rpg);
void life_bar_display(sfRectangleShape **lifebar, sfRenderWindow *window, \
my_game_t *rpg);
void main_menu_scene_display(my_game_t *rpg);
bool my_strchr(char letter, char *list);
int copy_one(char *str, sfVector2i s, char *separators, char *new_str);

button_t *game_scene_init_button_zero(my_game_t *rpg);
button_t *game_scene_init_button_one(my_game_t *rpg);


#endif /* !MY_GAME_H_ */
