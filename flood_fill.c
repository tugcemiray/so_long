/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tukaraca <tukaraca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 23:06:57 by tukaraca          #+#    #+#             */
/*   Updated: 2025/04/10 05:00:52 by tukaraca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	player_position(t_game *game)
{
	int	row;
	int	col;

	row = 1;
	while (row < game->height - 1)
	{
		col = 1;
		while (col < game->width - 1)
		{
			if (game->map[row][col] == 'P')
			{
				game->player_x = col;
				game->player_y = row;
				return ;
			}
			col++;
		}
		row++;
	}
}

static char	**copy_map(t_game *game)
{
	int		i;
	char	**cpy;

	cpy = malloc((game->height + 1 ) * sizeof(char *));
	if (!cpy)
		err_msg(WRN_MEM);
	i = 0;
	while (i < game->height)
	{
		cpy[i] = ft_strdup(game->map[i]);
		if (!cpy[i])
		{
			free_game(game);
			err_msg(WRN_MEM);
		}
		i++;
	}
	cpy[i] = NULL;
	return (cpy);
}

static void	flood_fill(t_game *game, char **map, int row, int col)
{
	if (row < 0 || col < 0 || row >= game -> height || col >= game -> width)
		return ;
	else if (map[row][col] == '1' || map[row][col] == 'F')
		return ;
	else if (map[row][col] == 'C')
		game -> count++;
	else if (map[row][col] == 'E')
		game -> exit_reached = 1;
	map[row][col] = 'F';
	flood_fill(game, map, row - 1, col);
	flood_fill(game, map, row + 1, col);
	flood_fill(game, map, row, col - 1);
	flood_fill(game, map, row, col + 1);
}

void	flood_fill_controller(t_game *game)
{
	char	**copy;

	game->count = 0;
	game->exit_reached = 0;
	copy = copy_map(game);
	if (!copy)
	{
		free_game(game);
		err_msg(WRN_MEM);
	}
	player_position(game);
	flood_fill(game, copy, game->player_y, game->player_x);
	if (game->exit_reached != 1 || game->collectibles != game->count)
	{
		free_map(copy);
		free_map(game->map);
		free(game);
		err_msg(WRN_MAP_TRG);
	}
	free_map(copy);
}
