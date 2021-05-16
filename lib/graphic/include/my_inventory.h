/*
** EPITECH PROJECT, 2021
** my_inventory
** File description:
** desc
*/

#ifndef MY_INVENTORY_H_
#define MY_INVENTORY_H_

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_inventory_case.h"
#include "my_item.h"
#include "my.h"

typedef struct inventory_s {
    sfVector2f pos;
    sfVector2f size;
    sfRectangleShape *background;
    sfVector2i cases_number;
    sfVector2i cases_size;
    sfVector2i cases_espacement;
    bool is_display;
    inventory_case_t **cases;
    sfRectangleShape ***empty_cases;
    bool is_movement;
    sfTexture *movement_texture;
    char *movement_buffer;
    sfVector2i movement_pos;
} inventory_t;

//INVENTORY_LIST_OPERATIONS.C//

void inventory_fill_with_list_two(item_t *items, inventory_t \
*inventory, char ***inventory_list, int i);
void inventory_fill_with_list(inventory_t *inventory, \
item_t *items, char ***inventory_list);
void inventory_update_list_two(inventory_t *inventory, \
item_t *items, char ***inventory_list, int i);
void inventory_update_list(inventory_t *inventory, item_t *items, \
char ***inventory_list);
char ***inventory_create_malloc_list(inventory_t *inventory);

//INVENTORY_CREATE_TWO.C//

void inventory_define_total_size(inventory_t *inventory);

//INVENTORY_CASE_OPERATION.C//

void inventory_unfill_case(inventory_t *inventory, sfVector2i pos);
void inventory_copy_case(inventory_t *inventory, sfVector2i pos2);
void inventory_switch_case(inventory_t *inventory, sfVector2i pos1, \
sfVector2i pos2);

//INVENTORY_FILL.C//

int my_strcmp(char const *s1, char const *s2);
void inventory_fill_cases_two(inventory_case_t *cases, bool is_here, \
sfTexture *texture, char *info);
void inventory_fill_cases(inventory_t *inventory, bool **is_here, \
sfTexture ***texture, char ***info);
void inventory_fill_case(inventory_t *inventory, sfVector2i pos, \
char *info, sfTexture *texture);
sfVector2i inventory_list_get_empty_pos(inventory_t *inventory, \
char ***inventory_list);

//INVENTORY_DISPLAY.C//

void inventory_change_display(inventory_t *inventory, bool is_display);
void inventory_display_two(inventory_t *inventory, int i, \
sfRenderWindow *window);
void inventory_display(inventory_t *inventory, \
sfRenderWindow *window);
void inventory_display_info(inventory_t *inventory, \
sfRenderWindow *window, sfVector2i mouse_pos);
void inventory_destroy(inventory_t *inventory);

//INVENTORY_SAVE_UPLOAD_LIST.C//

void inventory_save_list(inventory_t *inventory, char ***inventory_list, \
char *inventory_save_path, item_t *items);
int inventory_get_length(char *buffer, inventory_t *inventory);
int inventory_upload_list(inventory_t *inventory, char ***inventory_list, \
char *inventory_save_path, item_t *items);

//INVENTORY_LIST_OPERATIONS_TWO.C//

void inventory_convert_inventory_list_to_new_list_two(inventory_t *inventory, \
char ***inventory_list, char **new_list, int *storage);
int inventory_convert_inventory_list_to_new_list(inventory_t *inventory, \
char ***inventory_list, char **new_list);
void inventory_update_list_with_new_list(char ***inventory_list, \
int total, char **new_list, inventory_t *inventory);
void inventory_add_item_to_list(inventory_t *inventory, item_t *items, \
char ***inventory_list, char *item_name);
void inventory_in_changement(inventory_t *inventory, sfVector2i mouse_pos, \
sfRenderWindow *window);

//INVENTORY_CREATE.C//

inventory_t *inventory_create(sfVector2f pos, sfVector2i cases_number, \
sfVector2i cases_size, sfVector2i cases_espacement);
void inventory_background_create(inventory_t *inventory, sfTexture \
*texture, sfColor color, bool have_texture);
void inventory_cases_create_two(inventory_t *inventory, int i, \
sfTexture *texture, sfTexture *info_texture);
void inventory_cases_create_three(inventory_t *inventory, int i, sfFont *font);
void inventory_cases_create(inventory_t *inventory, sfTexture *texture, \
sfTexture *info_texture, sfFont *font);

//INVENTORY_SORT.C//

void inventory_sort_by_name(char **new_list, int total);
void inventory_sort_by_attack(char **new_list, int total, item_t *items);
void inventory_sort_by_health(char **new_list, int total, item_t *items);
void inventory_sort_by_type(char **new_list, int total, item_t *items);
void inventory_sort_list(inventory_t *inventory, item_t *items, \
char ***inventory_list, char *sort_type);

//UTILS.C//

int modif_number(char const *str, int count, int number, int is_neg);
int my_getnbr(char const *str);
char *get_file_buffer(char *path);
sfVector2i inventory_cursor_is_in_cases(inventory_t *inventory, \
sfVector2i mouse_pos, int i);

#endif /* !MY_INVENTORY_H_ */