/*
** EPITECH PROJECT, 2021
** button_setString
** File description:
** desc
*/

#include "my_button.h"

int string_len(char *str)
{
    int i = 0;

    while (str[i])
        i++;
    return (i);
}

void button_set_string(button_t *button, char *str)
{
    int len = string_len(str);
    int i = 0;

    if (button->str)
        free(button->str);
    button->str = malloc(sizeof(char) * (len + 1));
    while (str[i]) {
        button->str[i] = str[i];
        i++;
    }
    button->str[i] = '\0';
    sfText_setString(button->text, str);
}