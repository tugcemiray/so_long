/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tugcemirayalgan <tugcemirayalgan@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:06:26 by tugcemiraya       #+#    #+#             */
/*   Updated: 2025/04/09 17:21:14 by tugcemiraya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "minilibx-linux/mlx.h"

# define WRN_ARG "Wrong argument\n"
# define WRN_MEM "Memory error\n"
# define WRN_FILE "Wrong file name\n"
# define WRN_MAP "Error: Map error\n"
# define WRN_MAP_READ "Error: Map couldn't read\n"
# define WRN_MAP_CNT "Error: Map contents error\n"
# define WRN_MAP_OPN "Error: Map walls error\n"
# define WRN_MAP_TRG "Error: Map target error\n"
# define END_GAME "Congratulations! Zeytin is happy!\n"

typedef struct s_textures
{
	void	*wall;
	void	*player;
	void	*floor;
	void	*fish;
	void	*exit;
}	t_textures;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	int			height;
	int			width;
	int			player_x;
	int			player_y;
	int			moves;
	int			collectibles;
	int			collected;
	int			count;
	int			exit_reached;
	t_textures	textures;
}	t_game;

void	map_control(t_game *game);
void	fill_values(t_game *game);
void	cntrl_map_arg(char *arg);
void	err_msg(char *msg);
int		key_hook(int keycode, t_game	*game);
void	get_textures(t_game *game);
void	move_player(t_game *game, int dx, int dy);
int		read_map(t_game *game, char *file);
int		map_height(char *file, t_game *game);
void	free_map(char **map);
int		close_game(t_game *game);
void	free_game(t_game *game);
void	free_txt(t_game *game);
int		end(t_game *game);
void	flood_fill_controller(t_game *game);
void	map_control(t_game *game);
#endif
