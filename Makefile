NAME = so_long

SRC = so_long.c map.c mlx_utils.c check_map.c player.c free_funcs.c flood_fill.c \
	  get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \

OBJS = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -Iminilibx-linux -Ilibft -Iget_next_line

MLX_FLAGS = -L minilibx-linux -lminilibx-linux -lXext -lX11 -lm -lz
LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) $(INCLUDES) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	make clean -C libft
	rm -f $(OBJS)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean bonus re
