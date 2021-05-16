/*
** EPITECH PROJECT, 2021
** my_map
** File description:
** desc
*/

#ifndef _MYMAP_
#define _MYMAP_

//--INCLUDE--------------------------------------------

#include <SFML/Graphics.h>
#include <dirent.h>
#include "my_button.h"
#include <stdio.h>

//--DEFINE---------------------------------------------

//--STRUCTURES-----------------------------------------

typedef struct my_game_s my_game_t;

typedef struct save_s {
    char *save_name;
    sfText *text;
    sfFont *font;
    sfRectangleShape *shape;
    int status;
    int rect_pressed;
} save_t;

typedef struct load_s {
    DIR *directory;
    struct dirent *dir;
    sfVector2f pos;
    char *path;
    int res;
    bool is_load;
} load_t;

typedef struct tile_s {
    sfConvexShape *shape;
    sfVector2f *vector;
    sfVector2f pos;
    int ground;
    int building;
} tile_t;

typedef struct textures_s {
    int nb_texture;
    sfTexture **texture;
} textures_t;

typedef struct map_s {
    char *name;
    sfVector2i size;
    sfVector2i camera;
    sfVector2f origin;
    sfVector2f move;
    tile_t *tiles;
    int nb_textures;
    textures_t *textures;
    int status;
    sfClock *clock;
} map_t;

//--PROTOTYPE------------------------------------------

//------DISPLAY_FUNCTION------//

//CAMERA.C//

void cam_in_tile(map_t *map, int i, int j, sfVector2f point);
void find_camera_pos(map_t *map, sfVector2u w_size);
void cam_pos(map_t *map, int i, int j, sfVector2u w_size);

//IN_TILE.C//

int on_right(sfVector2f pos1, sfVector2f pos2, sfVector2f point);
int in_tile(tile_t tile, sfVector2f point);

//------TEXTURE------//

//TEXTURE_CREATE.C//

textures_t *texture_create(void);

//TEXTURE_LOAD.C//
textures_t texture_load(char *pathname);

//------TILE------//

//TILE_SET_COLOR.C//

void tile_set_color(tile_t *tile, sfColor color);

//TILE_SET_POSITION.C//

void tile_set_position(tile_t *tile, sfVector2f pos);

//TILE_SET_TEXTURE.C//

void tile_set_texture(tile_t *tile, sfTexture **ground);

//TILE_SET.C//

sfVector2f iso_projection(int x, int y, int z, int zoom);
tile_t tile_set(int ground, int building, int zoom);

//---------------------//

//MAP_CREATE.C//

map_t *map_create(void);

//MAP_DESTROY.C//

void tile_destroy(tile_t *tiles, int size);
void textures_destroy(textures_t *textures);
void map_destroy(map_t *map);

//MAP_DISPLAY.C//

int in_window(map_t *map, int i, sfVector2u w_size);
void draw_convex_shape(sfRenderWindow *window, map_t *map, int i, int j);
void draw_build(sfRenderWindow *window, map_t *map, int i, int j);
void map_display_move(map_t *map);
void map_display(sfRenderWindow *window, map_t *map);

//MAP_MOVE_ORIGIN.C//

void map_move_origin(map_t *map, sfVector2f move);

//MAP_SET_NAME.C//

int name_len(char *str);
void map_set_name(map_t *map, char *name);

//MAP_SET_ORIGIN.C//

void map_set_origin(map_t *map, sfVector2f origin);

//MAP_SET_SIZE.C//

void map_set_size(map_t *map, sfVector2i size);

//MAP_SET_TILES.C//

void map_set_tiles(map_t *map, int zoom);
void tile_set_origin(tile_t *tile, sfVector2f origin);

//MY_STRTOK.C//

bool is_a_delimiter(char c, char *delimiters);
int how_many_word(char *str, char *delimiters);
char *catch_the_word(char *str, char *delimiters, int begin);
char **my_strtok(char *str, char *delimiters);

//READFILE.C//

char *readfile(char *pathname);

#endif /* !_MYMAP_ */