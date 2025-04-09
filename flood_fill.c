/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tugcemirayalgan <tugcemirayalgan@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 07:18:51 by tugcemiraya       #+#    #+#             */
/*   Updated: 2025/04/09 17:35:12 by tugcemiraya      ###   ########.fr       */
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

	cpy = malloc((game->height * sizeof(char *)) + 1);
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
	copy[i] = NULL;
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

	copy = copy_map(game);
	if (copy)
	{
		free_game(game);
		err_msg(WRN_MEM);
	}
	player_position(game);
	flood_fill(game, copy, game->player_x, game->player_y);
	if (game->exit_count != 0 || game->count != game->fish)
	{
		free_map(copy);
		free_map(game->map);
		free(game);
		err_msg(WRN_MAP_TRG);
	}
	free_map(copy, game->height);
}
