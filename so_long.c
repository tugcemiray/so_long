/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tukaraca <tukaraca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 23:05:58 by tukaraca          #+#    #+#             */
/*   Updated: 2025/04/09 23:06:12 by tukaraca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	err_msg(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(1);
}

void	cntrl_map_arg(char *arg)
{
	char	*s;

	s = ft_strrchr(arg, '.');
	if (!s || ft_strncmp(s, ".ber", 5))
		err_msg(WRN_FILE);
}

void	fill_values(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->wall = NULL;
	game->floor = NULL;
	game->exit = NULL;
	game->fish = NULL;
	game->player = NULL;
	game->map = NULL;
	game->moves = 0;
	game->player_count = 0;
	game->exit_count = 0;
	game->collectibles = 0;
	game->count = 0;
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		err_msg(WRN_ARG);
	cntrl_map_arg(argv[1]);
	game = malloc(sizeof(t_game));
	if (!game)
		err_msg(WRN_MEM);
	fill_values(game);
	read_map(game, argv[1]);
	map_control(game);
	flood_fill_controller(game);
	get_textures(game);
	mlx_hook(game->win, 17, 0, close_game, game);
	mlx_key_hook(game->win, key_hook, game);
	mlx_loop(game->mlx);
}

