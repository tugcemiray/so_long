/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tukaraca <tukaraca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 23:06:49 by tukaraca          #+#    #+#             */
/*   Updated: 2025/04/10 05:56:32 by tukaraca         ###   ########.fr       */
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
		return;
	if (game->map)
		free_map(game->map);
	if (game->exit || game->wall || game->floor
		|| game->player || game->fish)
		free_txt(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free(game);
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
