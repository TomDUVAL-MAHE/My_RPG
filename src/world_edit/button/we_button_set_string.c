/*
** EPITECH PROJECT, 2021
** we_button_set_string
** File description:
** desc
*/

#include "my_world_edit.h"

int we_string_len(char *str)
{
    int i = 0;

    while (str[i])
        i++;
    return (i);
}

void we_button_set_string(we_button_t *button, char *str)
{
    int len = we_string_len(str);
    int i = 0;

    button->str = malloc(sizeof(char) * (len + 1));
    while (str[i]) {
        button->str[i] = str[i];
        i++;
    }
    button->str[i] = '\0';
    sfText_setString(button->text, str);
}