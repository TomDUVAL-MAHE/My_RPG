/*
** EPITECH PROJECT, 2021
** world_edit_list_button
** File description:
** desc
*/

#include "my_world_edit.h"
#include "my.h"

list_button_t *new_list_button(list_button_t *l_button)
{
    list_button_t *new_button = malloc(sizeof(list_button_t));

    if (new_button == NULL)
        return (NULL);
    new_button->next = l_button;
    new_button->path = NULL;
    new_button->button = NULL;
    l_button = new_button;
    return (l_button);
}

list_button_t *first_list_button(void)
{
    list_button_t *l_button = malloc(sizeof(list_button_t));

    if (l_button == NULL)
        return (NULL);
    l_button->next = NULL;
    l_button->button = NULL;
    l_button->path = NULL;
    return (l_button);
}

list_button_t *create_list(list_button_t *l_button, \
sfIntRect *area, load_t *load)
{
    if (l_button == NULL) {
        l_button = first_list_button();
    } else {
        l_button = new_list_button(l_button);
    }
    l_button->button = we_new_button(*area, load->dir->d_name, 20);
    l_button->path = malloc(sizeof(char) * (my_strlen(load->path) + 1));
    my_strcpy(l_button->path, load->path);
    my_putstrerr(l_button->path);
    my_putstrerr("\n");
    area->top += 50;
    return (l_button);
}