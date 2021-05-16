##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## make file
##

BAR		=	src/bar/progressbar.c \
			src/bar/progressbar_two.c \

BUTTON	=	src/buttons/button_destroy.c \
			src/buttons/button_display.c \
			src/buttons/button_init.c \
			src/buttons/button_is_click.c \
			src/buttons/button_is_hover.c \
			src/buttons/button_launch_action.c \
			src/buttons/button_set_action.c \
			src/buttons/button_set_color.c \
			src/buttons/button_set_font.c \
			src/buttons/button_set_position.c \
			src/buttons/button_set_size.c \
			src/buttons/button_set_status.c \
			src/buttons/button_set_string.c \
			src/buttons/button_set_text_color.c \
			src/buttons/button_set_text_size.c \
			src/buttons/button_set_texture.c \

FRAMEBUFFER	=	src/framebuffer/framebuffer.c \

INVENTORY	=	src/inventory/inventory_case.c \
				src/inventory/inventory_case_change.c \
				src/inventory/inventory_case_change_two.c \
				src/inventory/inventory_case_display.c \
				src/inventory/inventory_case_operation.c \
				src/inventory/inventory_change_case.c \
				src/inventory/inventory_create.c \
				src/inventory/inventory_create_two.c \
				src/inventory/inventory_display.c \
				src/inventory/inventory_fill.c \
				src/inventory/inventory_items_action.c \
				src/inventory/inventory_items_action_two.c \
				src/inventory/inventory_items.c \
				src/inventory/inventory_list_operations.c \
				src/inventory/inventory_list_operations_two.c \
				src/inventory/inventory_save_upload_list.c \
				src/inventory/inventory_sort.c \
				src/inventory/utils.c \

TEXT		=	src/text/text_change_two.c \
				src/text/text_change.c \
				src/text/text.c \
				src/text/textbox_two.c \
				src/text/textbox.c \

SRC		=	$(BAR) \
			$(BUTTON) \
			$(FRAMEBUFFER) \
			$(INVENTORY) \
			$(TEXT) \

OBJ		=	$(SRC:.c=.o)

NAME	=	libgraphic.a

CFLAGS 	=	-I include/ -lmy -lcsfml-graphics -L./lib -lm -lcsfml-system -lcsfml-window -W -Wextra -Wshadow -Wall -Werror

RM		=	rm -f

all:	$(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../
	cp include/*.h ../../include/

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) ../$(NAME)

re: fclean all

all:	$(NAME) clean
