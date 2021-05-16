/*
** EPITECH PROJECT, 2021
** world_edit_load
** File description:
** desc
*/

#include "my_world_edit.h"
#include "my.h"

list_button_t *world_edit_load_directory(load_t *load, map_t *map, \
sfIntRect area)
{
    list_button_t *l_button = NULL;
    int len = 0;

    if (!map)
        return (NULL);
    load->directory = opendir("maps/");
    for (load->dir = readdir(load->directory); load->dir != NULL;) {
        len = my_strlen("maps/") + my_strlen(load->dir->d_name);
        load->path = malloc(sizeof(char) * (len + 1));
        my_strcpy(load->path, "maps/");
        my_strcat(load->path, load->dir->d_name);
        load->path[len] = '\0';
        if (load->dir->d_type == DT_REG) {
            l_button = create_list(l_button, &area, load);
        }
        free(load->path);
        load->dir = readdir(load->directory);
    }
    closedir(load->directory);
    load->is_load = true;
    return (l_button);
}

void world_edit_load_map(list_button_t *list, map_t *map)
{
    we_button_set_color(list->button, sfRed);
    if (load_a_file(map, list->path) == 0) {
        load_the_map(map, list->path);
    } else {
        my_putstrerr("Load map : invalide file\n");
    }
}

void world_edit_load(sfRenderWindow *window, world_edit_t *world_edit, \
map_t *map)
{
    sfVector2f pos = {world_edit->pos.x + 10, world_edit->pos.y + 100};
    sfVector2f size = {world_edit->size.x - 20, 30};
    sfIntRect area = {pos.x, pos.y, size.x, size.y};
    load_t *load = world_edit->load;
    list_button_t *list;

    if (load->is_load == false) {
        world_edit->l_button = NULL;
        world_edit->l_button = world_edit_load_directory(load, map, area);
    }
    list = world_edit->l_button;
    for (; list != NULL; list = list->next) {
        we_button_display(window, list->button);
        we_button_is_click(list->button, window, sfMouseLeft);
        if (list->button->status == HOVER)
            we_button_set_color(list->button, sfBlue);
        else if (list->button->status == CLICK)
            world_edit_load_map(list, map);
        else
            we_button_set_color(list->button, sfBlack);
    }
}