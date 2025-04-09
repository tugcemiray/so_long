/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tugcemirayalgan <tugcemirayalgan@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 05:49:08 by tugcemiraya       #+#    #+#             */
/*   Updated: 2025/04/09 17:34:41 by tugcemiraya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

int	close_game(t_game *game)
{
	free_game(game);
	exit(0);
}

void	free_game(t_game *game)
{
	if (!game)
		free(game);
	if (game->map)
		free_map(game->map);
	if (game->exit || game->wall || game->path
		|| game->player || game->collectible)
		free_txt(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}

void	free_txt(t_game *game)
{
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->player)
		mlx_destroy_image(game->mlx, game->player);
	if (game->fish)
		mlx_destroy_image(game->mlx, game->fish);
	if (game->floor)
		mlx_destroy_image(game->mlx, game->floor);
	if (game->exit)
		mlx_destroy_image(game->mlx, game->exit);
}

int	end(t_game *game)
{
	free_game(game);
	ft_putstr_fd(END_GAME, 1);
	exit(0);
}
