/*
** EPITECH PROJECT, 2021
** my_inventory_scene
** File description:
** desc
*/

#ifndef MY_INVENTORY_SCENE_H_
#define MY_INVENTORY_SCENE_H_

//--INCLUDE--------------------------------------------

#include "my_inventory.h"
#include "my_player.h"

//--DEFINE---------------------------------------------

//--STRUCTURES-----------------------------------------

//--PROTOTYPE------------------------------------------

//INVENTORY_SCENE_SETUP_BAR.C//

void inventory_scene_setup_attack_bar(inventory_scene_t *inventory_scene);
void inventory_scene_setup_health_bar(inventory_scene_t *inventory_scene);
void inventory_scene_setup_level_bar(inventory_scene_t *inventory_scene);

//INVENTORY_SCENE_SETUP_THREE.C//

sfRectangleShape *picture_setup(sfTexture *texture, sfVector2f pos, \
sfVector2f size);
void inventory_scene_picture_list_setup_three(sfVector2u window_size, \
sfRectangleShape **picture_list);
void inventory_scene_picture_list_setup_two(sfVector2u window_size, \
sfRectangleShape **picture_list);
sfRectangleShape **inventory_scene_picture_list_setup(sfVector2u window_size);
void inventory_scene_setup_case_limit(inventory_scene_t *inventory_scene);

//INVENTORY_SCENE_EVENT.C//

void inventory_scene_event_gestion(inventory_scene_t *inventory_scene, \
sfVector2i mouse_pos, stats_t *stats, player_t *player);

//INVENTORY_SCENE_BUTTON_EVENT.C//

bool button_is_touch(sfVector2f pos, sfVector2f size, sfVector2i mouse_pos);
void inventory_scene_change_man_dir(inventory_scene_t *inventory_scene, \
int dir, player_t *player);
void inventory_scene_change_scene(inventory_scene_t *inventory_scene, \
int scene);
void inventory_scene_detect_button(inventory_scene_t *inventory_scene, \
sfVector2i mouse_pos, player_t *player);

//INVENTORY_SCENE_UPDATE_TEXTURE.C//

void inventory_texture_get_path_two(char *name, char *path);
void inventory_texture_get_path(char *name, char *path);
sfIntRect setup_area(int dir);
sfTexture *inventory_texture(char *buffer, int dir);
void inventory_scene_update_picture_sexe(inventory_scene_t *inventory_scene, \
bool is_man);

//INVENTORY_SCENE_DISPLAY.C//

void inventory_scene_display_picture_list(sfRectangleShape **picture_list, \
sfRenderWindow *window, int dir);
void inventory_scene_display_bar(inventory_scene_t *inventory_scene, \
sfRenderWindow *window);
void inventory_scene_display_text(inventory_scene_t *inventory_scene, \
sfRenderWindow *window);
void inventory_scene_display(inventory_scene_t *inventory_scene, \
sfRenderWindow *window);

//INVENTORY_SCENE_SETUP_FOUR.C//

void inventory_scene_setup_empty_picture(inventory_scene_t *inventory_scene);
void inventory_scene_setup_text(inventory_scene_t *inventory_scene);
void inventory_scene_setup_five(inventory_scene_t *inventory_scene);
void inventory_scene_setup_four(inventory_scene_t *inventory_scene);

//INVENTORY_SCENE_UNLOCK_ABILITIES.C//

void inventory_scene_unlock_bow(inventory_scene_t *inventory_scene);
void inventory_scene_unlock_axe(inventory_scene_t *inventory_scene);
void inventory_scene_unlock_pickaxe(inventory_scene_t *inventory_scene);
void inventory_scene_unlock_ring(inventory_scene_t *inventory_scene);

//INVENTORY_SCENE_INVENTORY_EVENT.C//

void inventory_scene_echange_inventory_one(inventory_scene_t *inventory_scene);
void inventory_scene_echange_inventory_two(inventory_scene_t *inventory_scene);

//INVENTORY_SCENE_UPDATE_STATS.C//

void inventory_scene_update_picture_three(inventory_scene_t *inventory_scene, \
bool is_man, player_t *player);
void inventory_scene_udpate_picture_two(inventory_scene_t *inventory_scene, \
bool is_man, player_t *player);
void inventory_scene_update_picture_three(inventory_scene_t *inventory_scene, \
bool is_man, player_t *player);
void update_picture(inventory_scene_t *inventory_scene, \
bool is_man, player_t *player);
void update_stats(inventory_scene_t *inventory_scene, stats_t *stats, \
player_t *player);

//INVENTORY_SCENE_SORTING_ACTION.C//

void sorting_action_two(inventory_scene_t *inventory_scene);
void sorting_action_three(inventory_scene_t *inventory_scene);
void sorting_action(inventory_scene_t *inventory_scene);

//INVENTORY_SCENE_SETUP.C//

char ***create_inventory_list(sfVector2i size, item_t *items);
inventory_t *inventory_scene_create_inv_one(sfRenderWindow *window, \
sfVector2u window_size, item_t *items, char ***inventory_list);
inventory_t *inventory_scene_create_inv_two(sfRenderWindow *window, \
sfVector2u window_size, item_t *items, char ***inventory_list);
void inventory_scene_display_inv_two(inventory_t *inventory_one, \
sfRenderWindow *window);
void inventory_scene_display_inv_one(inventory_t *inventory_one, \
sfRenderWindow *window);

//INVENTORY_SCENE_BAR_EVENT.C//

void inventory_scene_update_attack_bar(inventory_scene_t *inventory_scene, \
int attack);
void inventory_scene_update_health_bar(inventory_scene_t *inventory_scene, \
int actual_health, int max_health);
void inventory_scene_update_level_bar(inventory_scene_t *inventory_scene, \
int actual_xp, int max_xp, int next_level);

//INVENTORY_SCENE_SETUP_TWO.C//

void inventory_scene_setup_three(inventory_scene_t *inventory_scene);
inventory_scene_t inventory_scene_setup(sfRenderWindow *window, \
player_t *player);
void inventory_scene_setup_arrow_button(inventory_scene_t *inventory_scene);
void inventory_scene_setup_two(inventory_scene_t *inventory_scene);

//INVENTORY_SCENE_UPDATE_BAR.C//

void update_attack(inventory_scene_t *inventory_scene, stats_t *stats);
void update_health(inventory_scene_t *inventory_scene, stats_t *stats);
void update_xp(inventory_scene_t *inventory_scene, stats_t *stats);
void change_player_texture(player_t *player, sfTexture *texture, int cases);

void player_update_weapon_type(player_t *player, \
inventory_scene_t *inventory_scene);
#endif /* !MY_INVENTORY_SCENE_H_ */