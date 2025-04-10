#include "so_long.h"

int	key_hook(int keycode, t_game	*game)
{
	if (keycode == 65307)
		free_game(game);
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

static void	put_image(t_game	*game, void *img, int row, int col)
{
	mlx_put_image_to_window(game -> mlx, game -> win, img, row * 64, col * 64);
}

static void	put_map_utils(t_game *game, int x, int y)
{
	char	c;

	c = game->map[y][x];
	if (c == '1')
		put_image(game, game->wall, x, y);
	else if (c == 'P')
		put_image(game, game->player, x, y);
	else if (c == 'E')
		put_image(game, game->exit, x, y);
	else if (c == 'C')
		put_image(game, game->fish, x, y);
	else if (c == '0')
		put_image(game, game->floor, x, y);
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

void	get_textures(t_game *game)
{
	int	value;

	value = 64;
	game->mlx = mlx_init();
	game -> floor = mlx_xpm_file_to_image(game -> mlx,
			"textures/floor.xpm", &value, &value);
	game -> player = mlx_xpm_file_to_image(game -> mlx,
			"textures/player.xpm", &value, &value);
	game -> exit = mlx_xpm_file_to_image(game -> mlx,
			"textures/exit.xpm", &value, &value);
	game -> wall = mlx_xpm_file_to_image(game -> mlx,
			"textures/wall.xpm", &value, &value);
	game -> fish = mlx_xpm_file_to_image(game -> mlx,
			"textures/fish.xpm", &value, &value);
	draw_map(game);
}



