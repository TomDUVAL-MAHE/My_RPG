/*
** EPITECH PROJECT, 2021
** my_world_edit
** File description:
** desc
*/

#ifndef MY_WORLD_EDIT_H_
#define MY_WORLD_EDIT_H_

//--INCLUDE--------------------------------------------

#include <SFML/Graphics.h>
#include "my_map.h"

//--DEFINE---------------------------------------------

//--STRUCTURES-----------------------------------------

typedef enum {
    MENU,
    TEXTURE,
    SPRITE,
    SAVE,
    LOAD
} menu_status;

typedef struct we_button_s {
    sfIntRect size;
    sfColor color;
    sfTexture *texture;
    sfRectangleShape *shape;
    sfColor text_color;
    char *str;
    int text_size;
    sfText *text;
    sfFont *font;
    int status;
} we_button_t;

typedef struct list_button_s {
    we_button_t *button;
    char *path;
    void *next;
} list_button_t;

typedef struct world_edit_s {
    sfVector2i tile_selected;
    sfVector2i tile_hover;
    save_t *save;
    load_t *load;
    list_button_t *l_button;
    int texture_selected;
    sfVector2f pos;
    sfVector2f size;
    sfColor color;
    sfRectangleShape *shape;
    int nb_button;
    we_button_t **buttons;
    int menu;
    int status;
    int scroll_texture;
    bool preview;
} world_edit_t;

//--PROTOTYPE------------------------------------------

void world_edit(my_game_t *rpg);
world_edit_t *world_edit_create(sfRenderWindow *window);
void world_edit_destroy(world_edit_t *menu);
void world_edit_display(sfRenderWindow *window, world_edit_t *world_edit, \
map_t *map);
void world_edit_set_color(world_edit_t *menu, sfColor color);
void world_edit_set_position(world_edit_t *menu, sfVector2f pos);
void world_edit_set_size(world_edit_t *menu, sfVector2f size);
void tile_hover_and_click(map_t *map, world_edit_t *menu, \
sfRenderWindow *window);
void draw_hover_and_click(sfRenderWindow *window, map_t *map, \
world_edit_t *menu);

//------BUTTON------//
we_button_t *we_button_create(void);
void we_button_destroy(we_button_t *button);
void we_button_display(sfRenderWindow *window, we_button_t *button);
int we_button_is_click(we_button_t *button, sfRenderWindow *window, \
sfMouseButton mouse);
int we_button_is_hover(we_button_t *button, sfVector2i pos);
void we_button_set_color(we_button_t *button, sfColor color);
void we_button_set_font(we_button_t *button, char *font);
void we_button_set_position(we_button_t *button, sfVector2f pos);
void we_button_set_size(we_button_t *button, sfVector2f size);
void we_button_set_string(we_button_t *button, char *str);
void we_button_set_text_color(we_button_t *button, sfColor color);
void we_button_set_text_size(we_button_t *button, int size);
void we_button_set_texture(we_button_t *button, char *filename);
we_button_t *we_new_button(sfIntRect size, char *str, int tsize);

//------DISPLAY------//
void world_edit_texture(sfRenderWindow *window, world_edit_t *world_edit,  \
map_t *map);
void world_edit_sprite(sfRenderWindow *window, world_edit_t *world_edit, \
map_t *map);
void world_edit_load(sfRenderWindow *window, world_edit_t *world_edit, \
map_t *map);
void world_edit_save(sfRenderWindow *window, world_edit_t *world_edit, \
map_t *map);

//------LOAD_AND_SAVE------//

//LOAD_CREATE.C//

load_t *load_create(world_edit_t *world_edit);

//LOAD_A_FILE.C//

int load_a_file(map_t *map, char *pathname);
void load_the_map(map_t *map, char *pathname);

//SAVE_CREATE.C//

save_t *save_create(void);

void write_map_save(save_t *save, map_t *map);
void write_map_pos(FILE *file, sfVector2i pos);
void write_map_origin(FILE *file, sfVector2f origin);
void write_map_camera(FILE *file, sfVector2i camera);

void world_edit_event(my_game_t *rpg, map_t *map, world_edit_t *world_edit);
void load_map_size(map_t *map, char *line);
int check_tiles_valide(map_t *map, char *line);
int check_origin_valide(char *line);
int check_camera_valide(char *line);
int check_size_valide(char *line);
void select_load_map(map_t *map, char *line, int nb_line);
void load_map_tiles(map_t *map, char *line);
char *load_map_one_tile(map_t *map, char *line, int i, int j);
void load_map_camera(map_t *map, char *line);
void load_map_origin(map_t *map, char *line);

list_button_t *new_list_button(list_button_t *l_button);
list_button_t *first_list_button(void);
list_button_t *create_list(list_button_t *l_button, \
sfIntRect *area, load_t *load);

void set_tile_preview(map_t *map, int zoom, sfVector2f origin);
void draw_preview(sfRenderWindow *window, map_t *map);
void draw_build_preview(sfRenderWindow *window, map_t *map, int i, int j);
void select_build_preview(sfRectangleShape *shape, int building, \
sfVector2f pos);
void draw_convex_shape_preview(sfRenderWindow *window, map_t *map, \
int i, int j);

int is_num(char a);

#endif /* !MY_WORLD_EDIT_H_ */