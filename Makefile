NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft
MLX = ./minilibx
FRK = -framework
OPEN = OpenGL
APPK = AppKit

SRC_FOLDER = ./srcs/
OBJ_FOLDER = ./objs/
INC_FOLDERS = ./includes/ ./minilibx/ ./libft/


SRC_FILES = fdf.c map_options.c draw_map.c deal_keys.c draw_segment.c zoom.c\
			color.c rotation.c all_keys.c error.c

OBJ_FILES = $(SRC_FILES:.c=.o)

SRC = $(addprefix $(SRC_FOLDER), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_FOLDER), $(OBJ_FILES))
INC = $(addprefix -I, $(INC_FOLDERS))

.PHONY: all re clean fclean

all : $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(FRK) $(OPEN) $(FRK) $(APPK) -o $(NAME) \
	-L$(LIBFT) -lft -L$(MLX) -lmlx 

$(OBJ) : | $(OBJ_FOLDER)

$(OBJ_FOLDER) :
	@mkdir objs

$(OBJ_FOLDER)%.o: $(SRC_FOLDER)%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	make -C $(LIBFT) clean
	make -C $(MLX) clean
	rm -rf $(OBJ_FOLDER)

fclean: clean
	make -C $(LIBFT) fclean
	rm -rf $(NAME)

re : fclean all
