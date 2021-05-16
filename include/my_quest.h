/*
** EPITECH PROJECT, 2021
** struct.h
** File description:
** struct.h
*/

#ifndef __QUEST__
#define __QUEST__

//--INCLUDE--------------------------------------------

//--DEFINE---------------------------------------------

#define NOT_ACTIVE 0
#define IN_PROGRESS 1
#define ENDED 2

#define TEST_QUEST 0
#define MOVE_QUEST 1
#define GO_TO_VILLAGE_QUEST 2
#define TALK_TO_MAYOR_QUEST 3
#define TALK_TO_BLACKSMITH_QUEST 4
#define EQUIP_JACKET_QUEST 5
#define GO_TO_PEERAGE_QUEST 6
#define END_FIGHT_ONE_QUEST 7
#define TALK_BACK_TO_BLACKSMITH_QUEST 8
#define TALK_TO_MAGICIAN_QUEST 9
#define UNLOCK_PASSAGE_QUEST 10
#define GO_TO_ICELAND_QUEST 11
#define END_FIGHT_TWO_QUEST 12
#define TALK_BACK_TO_MAGICIAN_QUEST 13
#define TALK_TO_ARCHER_QUEST 14
#define UNLOCK_PASSAGE_TWO_QUEST 15
#define GO_TO_MOUNTAIN_QUEST 16
#define END_FIGHT_THREE_QUEST 17
#define TALK_BACK_TO_ARCHER_QUEST 18
#define TALK_BACK_TO_MAYOR_QUEST 19
#define GO_TO_BEACH_QUEST 20
#define THE_END_QUEST 21
#define THE_CHOICE_QUEST 22
#define ESCAPE 23
#define FIGHT 24

#define VILLAGE_ZONE ((sfIntRect){45, 66, 24, 21})
#define PEERAGE_ZONE ((sfIntRect){10, 56, 8, 17})
#define ICELAND_ZONE ((sfIntRect){6, 6, 19, 23})
#define MOUTAIN_ZONE ((sfIntRect){51, 6, 42, 55})
#define BEACH_ZONE ((sfIntRect){84, 81, 10, 13})
#define VILLAGE 1
#define PEERAGE 2
#define ICELAND 3
#define MOUNTAIN 4
#define NORMAL 0

//--STRUCTURES-----------------------------------------

typedef struct my_game_s my_game_t;
typedef struct quest_s quest_t;

typedef struct quest_content_s {
    char *name;
    int id;
    char *description;
    int state;
} quest_content_t;

typedef struct quest_s {
    quest_content_t content;
    sfRectangleShape *background;
    text_t title;
    text_t description;
    quest_t *next;
    quest_t *prev;
} quest_t;

typedef struct quest_list_s {
    quest_t *first;
    quest_t *end;
} quest_list_t;

typedef struct quest_view_s {
    sfRectangleShape *background;
    text_t title;
    text_t description;
    sfVector2f pos;
    bool is_full;
} quest_view_t;

typedef struct quest_scene_s {
    sfRectangleShape *background;
    sfRectangleShape *title;
    quest_view_t *quest_view;
    int all_quest_number;
    int actual_slide;
} quest_scene_t;

//--PROTOTYPE------------------------------------------

void quest_list_setup(my_game_t *rpg);
quest_t *create_a_quest(quest_content_t content);
void quest_display(my_game_t *rpg);
void quest_list_add_quest_end(my_game_t *rpg, quest_content_t content);
void quest_test(my_game_t *rpg);
void quest_list_delete(my_game_t *rpg, int id);
void quest_display_shortcut(quest_list_t quest_list, my_window_t window);
void quest_list_change_state(my_game_t *rpg, int id, int state);
quest_scene_t quest_scene_setup(my_game_t *rpg);
void quest_scene_display(quest_scene_t *quest_scene, my_window_t window);
void quest_scene_update(quest_scene_t *quest_scene, quest_list_t quest_list, \
my_game_t *rpg);
void quest_list_sort_type_to_end(my_game_t *rpg);
void quest_all_setup(my_game_t *rpg);
int quest_list_return_state_by_id(my_game_t *rpg, int id);

//Quest Game Action//

void quest_end_move(my_game_t *rpg);
bool is_in_zone(sfFloatRect player, sfIntRect zone, my_game_t *rpg);
void enter_a_zone(sfFloatRect player, my_game_t *rpg);
void quest_end_gtv(my_game_t *rpg);
void quest_end_talk_to_mayor(my_game_t *rpg);
void quest_end_talk_to_blacksmith(my_game_t *rpg);
void quest_end_gtp(my_game_t *rpg);
void quest_end_equip_jacket(my_game_t *rpg);
void quest_end_fight_one(my_game_t *rpg);
void quest_end_go_back_blacksmith(my_game_t *rpg);
void quest_end_talk_magician(my_game_t *rpg);
void quest_end_gti(my_game_t *rpg);
void quest_end_unlock_passage(my_game_t *rpg);
void quest_end_equip_jacket(my_game_t *rpg);
void quest_end_fight_two(my_game_t *rpg);
void quest_end_go_back_magician(my_game_t *rpg);
void quest_end_talk_archer(my_game_t *rpg);
void quest_end_gtm(my_game_t *rpg);
void quest_end_unlock_passage_two(my_game_t *rpg);
void quest_end_equip_jacket(my_game_t *rpg);
void quest_end_fight_three(my_game_t *rpg);
void quest_end_go_back_archer(my_game_t *rpg);
void quest_end_talk_back_mayor(my_game_t *rpg);
void quest_end_gtb(my_game_t *rpg);
void zone_clean(sfIntRect zone, my_game_t *rpg, enemy_list_t *e_list);
void quest_end_the_choice(my_game_t *rpg);
void quest_end_escape(my_game_t *rpg);
void quest_end_fight(my_game_t *rpg);
void quest_end_the_end(my_game_t *rpg);
void quest_end_fights(my_game_t *rpg);
void quest_list_add_quest_end(my_game_t *rpg, quest_content_t content);
void quest_delete(quest_t *prev, my_game_t *rpg);
void quest_display_shortcut_loop(sfVector2f actual_pos, int *count, \
my_window_t window, quest_t *save);
void quest_display_shortcut(quest_list_t quest_list, my_window_t window);
void quest_scene_setup_emplacement_two(quest_scene_t *quest_scene, \
int i, my_game_t *rpg, sfVector2f actual_pos);
void quest_scene_setup_emplacement(my_game_t *rpg, quest_scene_t *quest_scene);
quest_scene_t quest_scene_setup(my_game_t *rpg);
void quest_scene_update_three(quest_t *save, quest_scene_t *quest_scene, \
int *count, sfVector2f size);
void quest_scene_update_two(quest_t *save, quest_scene_t *quest_scene, \
int *count, sfVector2f size);
bool is_in_zone(sfFloatRect player, sfIntRect zone, my_game_t *rpg);
void enter_zone_none(sfFloatRect player, my_game_t *rpg);
void enter_zone_village(sfFloatRect player, my_game_t *rpg);
void enemy_creation(my_game_t *rpg, int nb, int lvl, enemy_type e_type);

#endif