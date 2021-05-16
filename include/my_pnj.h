/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** my_enemy
*/

#ifndef __MY_PNJ
#define __MY_PNJ
//-----NEEDED-INCLUDES-------
#include "my_player.h"
#include "my_game_scene.h"
#include "my_window.h"
//-----MACROS----------------
//--CREATION--
//hitbox
#define PNJ_HITBOX_WIDTH 85
#define PNJ_HITBOX_HEIGHT 100
//--ANIMATION--
//animation value
#define PNJ_ANIMATION_COOLDOWN 100000
#define PNJ_ANIMATION_RECT_WIDTH 64
#define PNJ_ANIMATION_RECT_HEIGHT 64
#define PNJ_ANIMATION_RECT_X_OFFSET 64
#define PNJ_ANIMATION_RECT_Y_OFFSET 64
#define PNJ_ANIMATION_RECT_LONG_WIDTH 192
#define PNJ_ANIMATION_RECT_LONG_HEIGHT 100
#define PNJ_ANIMATION_RECT_LONG_X_OFFSET 100
#define PNJ_ANIMATION_RECT_LONG_Y_OFFSET 192
//Walk Animation
#define PNJ_WALK_MOVE_RECT 64
#define PNJ_WALK_UP_RECT ((sfIntRect){0, 516, 64, 64})
#define PNJ_WALK_DOWN_RECT ((sfIntRect){0, 646, 64, 64})
#define PNJ_WALK_LEFT_RECT ((sfIntRect){0, 580, 64, 64})
#define PNJ_WALK_RIGHT_RECT ((sfIntRect){0, 708, 64, 64})
#define PNJ_WALK_MAX_RECT 520
//sprite pos
#define PNJ_SPRITE_BASIC_POS_X pnj->hitbox.left + pnj->hitbox.width / 2 - \
128 / 2
#define PNJ_SPRITE_BASIC_POS_Y pnj->hitbox.top + pnj->hitbox.height / 2 - \
128 / 2
#define PNJ_SPRITE_LONG_POS_X pnj->hitbox.left + pnj->hitbox.width / 2 - \
PNJ_ANIMATION_RECT_LONG_WIDTH
#define PNJ_SPRITE_LONG_POS_Y pnj->hitbox.top + pnj->hitbox.height / 2 - \
PNJ_ANIMATION_RECT_LONG_HEIGHT + 6

//-----STRUCTURES------------
typedef struct my_game_s my_game_t;

typedef enum pnj_type {
    HUMAN_BASIC_ONE,
    HUMAN_BASIC_TWO,
    HUMAN_BASIC_THREE,
    WOMAN_ONE,
    WOMAN_TWO,
    WOMAN_THREE,
    CHILD_ONE,
    CHILD_TWO,
    CHILD_THREE,
    FISHERMAN_ONE,
    FISHERMAN_TWO,
    FISHERMAN_THREE,
    GUARDIAN_ONE,
    GUARDIAN_TWO,
    GUARDIAN_THREE
} pnj_type;

typedef struct pnj_s
{
    bool move_up;
    bool move_down;
    bool move_left;
    bool move_right;
    bool is_walking;
    int anim_cooldown;
    char **dialog_list;
    int max_dialog;
    int actual_dialog;
    bool is_quest;
    pnj_type e_type;
    sfVector2i tile;
    pnj_type type;
    orientation orientation;
    sfIntRect anim_rect;
    sfFloatRect hitbox;
    sfFloatRect attack_hitbox;
    sfTexture *texture;
    sfSprite *sprite;
    stats_t stats;
    sfVector2f start;
    sfVector2f end;
} pnj_t;

typedef struct pnj_node_s
{
    pnj_t *pnj;
    struct pnj_node_s *next;
}pnj_node_t;

typedef struct pnj_list_s
{
    pnj_node_t *first;
}pnj_list_t;

//-----PROTOTYPES------------

void pnj_orientate(pnj_t *pnj);
void pnj_chose_orientation(pnj_t *pnj, sfVector2f move);

//PNJ_DISPLAY.C//

void pnj_walk_animation(my_game_t *rpg, pnj_t *pnj);
void pnj_animation(my_game_t *rpg, pnj_t *pnj);
void pnjs_display(my_game_t *rpg, pnj_list_t *pnj_list, int i, int j);

//PNJ_NODE.C//

void pnj_list_destroy_a_node(pnj_node_t *node);
void pnj_list_destroy_a_selected_node_in_list(pnj_list_t *list, \
pnj_node_t *node);

//PNJ_LIST.C//

pnj_list_t *pnj_list_init(void);
void pnj_list_destroy(pnj_list_t *list);
int pnj_list_insert_beginning(pnj_list_t *list, pnj_t *pnj);

//PNJ_INIT_PNJ_TYPE.C//

void check_men(pnj_type e_type, char **path);
void check_woman(pnj_type e_type, char **path);
void check_child(pnj_type e_type, char **path);
void check_fisherman(pnj_type e_type, char **path);
void check_guardian(pnj_type e_type, char **path);
char *get_path_from_pnj_type(pnj_type e_type);

//PNJ_MOVES.C//

bool check_pnj_move(player_t *player, pnj_t *pnj, sfVector2f move);
void pnj_move(pnj_t *pnj, sfVector2f move, my_game_t *rpg, bool force);

//PNJ_INIT.C//

sfSprite *pnj_sprite_init(pnj_t *pnj);
void pnj_init_values(pnj_t *pnj, sfVector2i pos, sfVector2i end);
pnj_t *pnj_create(char *texture_path, sfVector2i pos, sfVector2i end);
void pnj_destroy(pnj_t *pnj);
int create_new_pnj(pnj_list_t *pnj_list, pnj_type e_type, sfVector2i pos, \
sfVector2i end);

//PnjTell//

void pnj_tell(pnj_t *pnj, my_window_t window, my_game_t *rpg);
void define_orientation_with_intersect(sfFloatRect npc, sfFloatRect player, \
pnj_t *pnj);
void pnj_go_to_nex_dialogs(pnj_list_t *pnj_list, int nbr);
void pnj_go_to_new_co(pnj_list_t *pnj_list, int nbr, sfVector2f pos);
void pnj_tell_end(my_window_t window, my_game_t *rpg, int *stop);
void draw_dialog(my_window_t window, char *str);
void check_men(pnj_type e_type, char **path);

#endif