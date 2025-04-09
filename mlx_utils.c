/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tugcemirayalgan <tugcemirayalgan@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 06:03:17 by tugcemiraya       #+#    #+#             */
/*   Updated: 2025/04/09 17:34:09 by tugcemiraya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_game	*game)
{
	if (keycode == 65307)
		exit_game(game);
	else if (keycode == 119)
		move_player(game, 0, -1);
	else if (keycode == 115)
		move_player(game, 0, 1);
	else if (keycode == 97)
		move_player(game, -1, 0);
	else if (keycode == 100)
		move_player(game, 1, 0);
	return (0);
}

void	get_textures(t_game *game)
{
	int	value;

	value = 64;
	game->mlx = mlx_init();
	game -> textures.floor = mlx_xpm_file_to_image(game -> mlx,
			"textures/floor.xpm", &value, &value);
	game -> textures.player = mlx_xpm_file_to_image(game -> mlx,
			"textures/player.xpm", &value, &value);
	game -> textures.exit = mlx_xpm_file_to_image(game -> mlx,
			"textures/exit6.xpm", &ivalue, &value);
	game -> textures.wall = mlx_xpm_file_to_image(game -> mlx,
			"textures/wall5.xpm", &ivalue, &value);
	game -> textures.collect = mlx_xpm_file_to_image(game -> mlx,
			"textures/collectible2.xpm", &value, &value);
	draw_map(game);
}

static void	put_image(t_game	*game, void *img, int col, int row)
{
	mlx_put_image_to_window(game -> mlx, game -> win, img, col * 64, row * 64);
}

static void	put_map_utils(t_game *game, int y, int x)
{
	char	c;

	c = game->map[y][x];
	if (c == '1')
		put_image(game, game->textures.wall, x, y);
	else if (c == 'P')
		put_image(game, game->textures.player, x, y);
	else if (c == 'E')
		put_image(game, game->textures.exit, x, y);
	else if (c == 'C')
		put_image(game, game->textures.fish, x, y);
	else if (c == '0')
		put_image(game, game->textures.floor, x, y);
}

static void	draw_map(t_game *game)
{
	int	row;
	int	col;

	row = -1;
	while (++row < game->height)
	{
		col = -1;
		while (++col < game->width)
			put_map_utils(game, row, col);
	}
}
