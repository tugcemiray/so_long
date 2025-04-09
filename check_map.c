/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tukaraca <tukaraca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 23:07:08 by tukaraca          #+#    #+#             */
/*   Updated: 2025/04/09 23:07:14 by tukaraca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_map_rectangular(t_game *game)
{
	int	row_len;
	int	row;

	row = 0;
	if (!game || !game->map || !game->map[0])
		err_msg(WRN_MEM);
	row_len = ft_strlen(game->map[0]);
	while (row < game->height)
	{
		if ((int)ft_strlen(game->map[row]) != row_len)
		{
			free_game(game);
			err_msg(WRN_MAP);
		}
		row++;
	}
}

static void	check_map_char(t_game *game, char c)
{
	if (c == 'P')
		game->player_count++;
	else if (c == 'E')
		game->exit_count++;
	else if (c == 'C')
		game->collectibles++;
	else if (c != '1' && c != '0')
	{
		free_game(game);
		err_msg(WRN_MAP_CNT);
	}
}

static void	map_contents(t_game *game, int i, int j)
{
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
			check_map_char(game, game->map[i][j]);
	}
	if (game->player_count != 1 || game->exit_count != 1 || game->collectibles < 1)
	{
		free_game(game);
		err_msg(WRN_MAP_CNT);
	}
}

static void	check_wall(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->width)
	{
		if (game->map[0][i] != '1' || game->map[game->height - 1][i] != '1')
		{
			free_game(game);
			err_msg(WRN_MAP_OPN);
		}
		i++;
	}
	i = 0;
	while (i < game->height)
	{
		if (game->map[i][0] != '1' || game->map[i][game->width - 1] != '1')
		{
			free_game(game);
			err_msg(WRN_MAP_OPN);
		}
		i++;
	}
}

void	map_control(t_game *game)
{
	check_map_rectangular(game);
	map_contents(game, -1, -1);
	check_wall(game);
}
