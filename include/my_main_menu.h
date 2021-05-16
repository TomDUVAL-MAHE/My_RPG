/*
** EPITECH PROJECT, 2021
** my_main_menu
** File description:
** desc
*/

#ifndef MY_MAIN_MENU_H_
#define MY_MAIN_MENU_H_

//--INCLUDE--------------------------------------------

#include "my_text.h"
#include "my_menu.h"

//--DEFINE---------------------------------------------

//--STRUCTURES-----------------------------------------

typedef struct main_menu_s {
    text_t title;
    menus_t main_part;
    menus_t play_part;
} main_menu_t;

//--PROTOTYPE------------------------------------------

//MAIN_MENU_INIT.C//

int create_main_menu(my_game_t *rpg, main_menu_t *main_menu);
void destroy_main_menu(main_menu_t *main_menu);
void set_up_main_menu_title(text_t *text);
int init_play_part(my_game_t *rpg, menus_t *play_part);
int init_main_part(my_game_t *rpg, menus_t *main_part);

//MAIN_MENU_MAIN_PART_BUTTONS.C//

button_t *init_main_part_button_zero(my_game_t *rpg);
button_t *init_main_part_button_one(my_game_t *rpg);
button_t *init_main_part_button_two(my_game_t *rpg);
button_t *init_main_part_button_three(my_game_t *rpg);

//MAIN_MENU_PLAY_PART_BUTTONS_ONE.C//

button_t *init_play_part_button_zero(my_game_t *rpg);
button_t *init_play_part_button_one(my_game_t *rpg);
button_t *init_play_part_button_two(my_game_t *rpg);
button_t *init_play_part_button_three(my_game_t *rpg);

//MAIN_MENU_PLAY_PART_BUTTONS_TWO.C//

button_t *init_play_part_button_four(my_game_t *rpg);
button_t *init_play_part_button_five(my_game_t *rpg);
button_t *init_play_part_button_six(my_game_t *rpg);

//MAIN_MENU_MANAGER.C//

void draw_main_menu(sfRenderWindow *window, main_menu_t *main_menu);
void check_main_menu_button_hover(my_game_t *rpg, sfVector2i pos);
void check_main_menu_button_pressed(my_game_t *rpg, sfVector2i pos);
void check_main_menu_button_release(my_game_t *rpg, sfVector2i pos);
void main_menu_event_management(sfRenderWindow *window, sfEvent event, \
my_game_t *rpg);

#endif /* !MY_MAIN_MENU_H_ */