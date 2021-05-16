##
## EPITECH PROJECT, 2021
## makefile
## File description:
## desc
##

MAP	=			src/map/my_strtok.c											\
				src/map/readfile.c											\
				src/map/map_create.c										\
				src/map/map_destroy.c										\
				src/map/map_set_name.c										\
				src/map/map_set_size.c										\
				src/map/map_set_origin.c									\
				src/map/map_set_tiles.c										\
				src/map/map_display.c										\
				src/map/display_function/camera.c							\
				src/map/map_move_origin.c									\
				src/map/tile/tile_set.c										\
				src/map/tile/tile_set_color.c								\
				src/map/tile/tile_set_position.c							\
				src/map/tile/tile_set_texture.c								\
				src/map/texture/texture_create.c							\
				src/map/texture/texture_load.c								\
				src/map/display_function/in_tile.c							\
				src/player/arrow_managment/arrow_creation.c					\
				src/player/arrow_managment/arrow_managment.c				\
				src/player/arrow_managment/arrow_hit.c						\
				src/player/arrow_managment/arrow_destroy.c					\

WORLD_EDIT	=	src/world_edit/world_edit.c 								\
				src/world_edit/world_edit_create.c 							\
				src/world_edit/world_edit_destroy.c 						\
				src/world_edit/world_edit_display.c 						\
				src/world_edit/world_edit_set_color.c 						\
				src/world_edit/world_edit_set_position.c 					\
				src/world_edit/world_edit_set_size.c 						\
				src/world_edit/world_edit_hover_and_click.c 				\
				src/world_edit/button/we_button_create.c					\
				src/world_edit/button/we_button_destroy.c 					\
				src/world_edit/button/we_button_display.c 					\
				src/world_edit/button/we_button_is_click.c 					\
				src/world_edit/button/we_button_is_hover.c 					\
				src/world_edit/button/we_button_set_color.c 				\
				src/world_edit/button/we_button_set_font.c 					\
				src/world_edit/button/we_button_set_position.c 				\
				src/world_edit/button/we_button_set_size.c 					\
				src/world_edit/button/we_button_set_string.c 				\
				src/world_edit/button/we_button_set_text_color.c 			\
				src/world_edit/button/we_button_set_text_size.c 			\
				src/world_edit/button/we_button_set_texture.c 				\
				src/world_edit/button/we_new_button.c 						\
				src/world_edit/load_and_save/load_a_file.c 					\
				src/world_edit/load_and_save/load_create.c 					\
				src/world_edit/display/world_edit_texture.c 				\
				src/world_edit/display/world_edit_sprite.c 					\
				src/world_edit/display/world_edit_load.c 					\
				src/world_edit/load_and_save/save_create.c 					\
				src/world_edit/display/world_edit_save.c 					\
				src/world_edit/load_and_save/write_a_save.c 				\
				src/world_edit/world_edit_preview.c 						\
				src/world_edit/world_edit_event.c 							\
				src/world_edit/load_and_save/world_edit_list_button.c 		\
				src/world_edit/load_and_save/load_line.c 					\
				src/world_edit/load_and_save/check.c 						\


ENEMY	=	src/enemies/enemy_init_weapon_type.c							\
			src/enemies/enemy_init_enemy_type.c								\
			src/enemies/enemy_init.c										\
			src/enemies/enemy_list.c										\
			src/enemies/enemy_node.c										\
			src/enemies/enemy_display.c										\
			src/enemies/enemy_display_two.c									\
			src/enemies/enemy_orientation.c									\
			src/enemies/enemy_moves.c										\
			src/enemies/enemy_moves_two.c									\
			src/enemies/enemy_attack.c										\
			src/enemies/enemy_attack_basic.c								\
			src/enemies/enemy_attack_long.c									\
			src/enemies/enemy_ia.c											\
			src/enemies/enemy_give_item.c									\

SRC	=	main.c																\
		src/rpg_struct.c													\
		src/window.c														\
		src/events/events.c													\
		src/menus/menu_struct.c												\
		src/menus/main_menu/main_menu_init.c								\
		src/menus/main_menu/main_menu_manager.c								\
		src/menus/main_menu/main_menu_main_part_buttons.c					\
		src/menus/main_menu/main_menu_play_part_buttons_one.c				\
		src/menus/main_menu/main_menu_play_part_buttons_two.c				\
		src/buttons_functions/button_exit.c									\
		src/buttons_functions/button_main_menu_main_part.c					\
		src/buttons_functions/button_main_menu_play_part.c					\
		src/time/time_manager.c												\
		src/scene_management/scene_manager.c								\
		src/scene_management/scene_display.c								\
		src/scene_management/go_to_a_scene.c								\
		src/scene_management/game_scene/game_scene_events.c					\
		src/scene_management/game_scene/game_scene_init.c					\
		src/scene_management/game_scene/game_scene_pause_init.c				\
		src/scene_management/game_scene/pause_management.c					\
		src/scene_management/inventory_scene/inventory_scene_display.c		\
		src/scene_management/inventory_scene/inventory_scene_event.c		\
		src/scene_management/quest_scene/quest_scene_display.c				\
		src/scene_management/quest_scene/quest_scene_event.c				\
		src/player/player_moves.c											\
		src/player/player_moves_two.c											\
		src/player/player_moves_three.c											\
		src/player/player_init.c											\
		src/player/player_init_sprites.c											\
		src/player/player_orientation.c										\
		src/player/player_display.c											\
		src/player/player_display_two.c											\
		src/player/player_attack_bow.c										\
		src/player/player_attack_crossbow.c									\
		src/player/player_basic_attack.c									\
		src/player/player_attack_longsword.c								\
		src/player/player_attack.c											\
		src/player/player_interaction.c										\
		src/player/player_detect_entities.c 								\
		src/menus/main_menu/main_menu_start.c								\
		src/tools/hitbox_tools.c											\
		src/menus/options/option_init.c 									\
		src/menus/options/init_option_button.c 								\
		src/scene_management/go_to_a_scene_two.c 							\
		src/scene_management/game_scene/game_scene_destroy.c 				\
		src/scene_management/game_scene/game_scene_pause_init_two.c 		\
		src/scene_management/scene_display_two.c 							\
		src/scene_management/scene_display_three.c 							\
		$(wildcard src/menus/load/*.c)										\
		$(wildcard src/inventory_scene/*.c)									\
		$(wildcard src/skill_scene/*.c)										\
		$(wildcard src/weather_engine/*.c)									\
		$(wildcard src/quest/*.c)											\
		$(MAP) 																\
		$(wildcard src/menus/save/*.c)										\
		$(wildcard src/pnj/*.c)												\
		$(wildcard src/cut_scene/*.c)										\
		$(WORLD_EDIT)														\
		$(ENEMY)															\

OBJ	=	$(SRC:.c=.o)

NAME=	my_rpg

CFLAGS	=	-I include/ -L./lib -lmy -lgraphic -lm -lcsfml-graphics -lcsfml-system -lcsfml-window -Wall -Wextra -Wshadow

RM		=	rm -f

CC		=	gcc

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C lib/my
	$(MAKE) -C lib/graphic
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(WFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(MAKE) -C lib/my fclean
	$(MAKE) -C lib/graphic fclean
	$(RM) $(NAME)

re:	fclean all

debug: CFLAGS += -g
debug: re

val: debug
	valgrind ./$(NAME) --leak-check=full 2> val
