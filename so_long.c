/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tugcemirayalgan <tugcemirayalgan@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 22:11:58 by tugcemiraya       #+#    #+#             */
/*   Updated: 2025/04/09 17:58:45 by tugcemiraya      ###   ########.fr       */
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
	if (!str || ft_strncmp(s, ".ber", 5))
		err_msg(WRN_FILE);
}

void	fill_values(t_game *game)
{
	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		err_msg(WRN_MEM);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		error_message(WRN_ARG);
	cntl_map_arg(argv[1]);
	game = malloc(sizeof(t_game));
	if (!game)
		err_msg(WRN_MEM);
	fill_values(game);
	read_map(game, argv[1]);
	map_control(game);
	flood_fill_controller(game);
	window(game);
	mlx_hook(game->win, 17, 0, close_game, game);
	mlx_key_hook(game->win, key_hook, game);
	mlx_loop(game->mlx);
}
