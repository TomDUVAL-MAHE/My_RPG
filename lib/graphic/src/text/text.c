/*
** EPITECH PROJECT, 2021
** text.c
** File description:
** text.c
*/

#include "my_text.h"

text_t text_create(sfVector2f pos, char *buffer, sfFont* font, bool is_display)
{
    text_t text;

    text.text = sfText_create();
    text.pos = pos;
    sfText_setPosition(text.text, pos);
    text.buffer = buffer;
    sfText_setString(text.text, buffer);
    text.font = font;
    sfText_setFont(text.text, font);
    text.is_display = is_display;
    return (text);
}

void text_display(text_t *text, sfRenderWindow *window)
{
    if (text->is_display == true)
        sfRenderWindow_drawText(window, text->text, NULL);
}

char *my_stncat(char *dest, char const *src, int nb)
{
    int size_dest = 0;
    int size_src = 0;
    int concatenate = 0;

    if (nb < 0)
        return (0);
    while (dest[size_dest] != '\0')
        size_dest++;
    while (dest[size_src] != '\0')
        size_src++;
    for (concatenate = 0; concatenate < nb; concatenate++)
        dest[size_dest + concatenate] = src[concatenate];
    dest[size_dest + concatenate + 1] = '\0';
    return (dest);
}

void convert_rec(int nb, char *str)
{
    char res[2];

    if (nb >= 10)
        convert_rec((nb / 10), str);
    res[0] = (nb % 10) + 48;
    res[1] = '\0';
    my_stncat(str, res, 2);
}

char *text_convert_int_to_char(int nb)
{
    char *str = malloc(sizeof(char) * 1000);

    str[0] = '\0';
    if (nb < 0) {
        nb *= -1;
        str[0] = '-';
        str[1] = '\0';
    }
    convert_rec(nb, str);
    return (str);
}