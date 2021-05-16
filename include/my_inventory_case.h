/*
** EPITECH PROJECT, 2021
** my_inventory_case
** File description:
** my_inventory_case
*/

#ifndef MY_INVENTORY_CASE_H_
#define MY_INVENTORY_CASE_H_

#include <SFML/Graphics.h>
#include <stdbool.h>
#include "my_textbox.h"
#include "my_item.h"

typedef struct inventory_s inventory_t;

typedef struct inventory_scene_s {
    inventory_t *inventory_one;
    char ***inventory_list_one;
    inventory_t *inventory_two;
    char ***inventory_list_two;
    sfTexture *movement_texture;
    item_t *items;
    sfVector2u window_size;
    sfRectangleShape **picture_list;
    sfRectangleShape *sorting_button;
    int actual_sort;
    sfRectangleShape **health_bar;
    sfRectangleShape **level_bar;
    text_t *text;
    sfRectangleShape *attack_bar;
    int dir;
    sfRectangleShape **arrow_button;
    int scene;
} inventory_scene_t;

typedef struct inventory_case {
    sfRectangleShape *sprite;
    sfTexture *texture;
    bool is_display;
    sfVector2f pos;
    sfVector2f size;
    textbox_t info;
    char *name;
    int type_limit;
} inventory_case_t;

//INVENTORY_CASE.C//

inventory_case_t inventory_case_create(sfVector2f pos, sfVector2f size, \
sfTexture *texture);
void inventory_case_create_info(inventory_case_t *cases, int dir, \
sfVector2f size, sfTexture *texture);
void inventory_case_create_info_text(inventory_case_t *cases, int size, \
char *buffer, sfFont *font);
void inventory_case_destroy(inventory_case_t *cases);
void inventory_case_add_type_limit(inventory_t *inventory, \
int type_limit, sfVector2i pos);

//INVENTORY_CASE_DISPLAY.C//

void inventory_case_display(inventory_case_t *cases, sfRenderWindow *window);
void inventory_case_display_info(inventory_case_t *cases, sfRenderWindow \
*window, sfVector2i mouse_pos);

//INVENTORY_CASE_CHANGE.C//

void inventory_case_info_change_dir(inventory_case_t *cases, int dir);
void inventory_case_info_change_size(inventory_case_t *cases, sfVector2f size);
void inventory_case_info_change_texture(inventory_case_t *cases, \
sfTexture *texture);
void inventory_case_info_text_change_size(inventory_case_t *cases, int size);
void inventory_case_info_text_change_buffer(inventory_case_t *cases, \
char *buffer);

//INVENTORY_CHANGE_CASE.C//

sfVector2i inventory_cursor_is_in_case(inventory_t *inventory, \
sfVector2i mouse_pos);
void inventory_detect_case_two(inventory_t *inventory, sfVector2i pos, \
inventory_scene_t *inventory_scene);
bool inventory_check_type(inventory_t *inventory, sfVector2i pos, \
item_t *items);
void inventory_detect_case_three(inventory_t *inventory, sfVector2i pos, \
inventory_scene_t *inventory_scene);
bool inventory_detect_case(inventory_t *inventory, sfVector2i mouse_pos, \
item_t *items, inventory_scene_t *inventory_scene);

//INVENTORY_CASE_CHANGE_TWO.C//

void inventory_case_change_pos(inventory_case_t *cases, sfVector2f pos);
void inventory_case_change_size(inventory_case_t *cases, sfVector2f size);
void inventory_case_change_texture(inventory_case_t *cases, sfTexture *texture);
void inventory_case_change_display(inventory_case_t *cases, bool is_display);
void inventory_case_info_text_change_font(inventory_case_t *cases, \
sfFont *font);

#endif /* !MY_INVENTORY_CASE_H_ */
