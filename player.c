/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tukaraca <tukaraca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 18:01:54 by tugcemiraya       #+#    #+#             */
/*   Updated: 2025/04/09 22:38:23 by tukaraca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	update_position(t_game *game, int new_x, int new_y)
{
	int		old_x;
	int		old_y;
	char	*old_c;

	old_x = game->player_x;
	old_y = game->player_y;
	if (game->map[old_y][old_x] == 'E')
		old_c = game->exit;
	else
		old_c = game->floor;
	mlx_put_image_to_window(game->mlx, game->win, old_c,
		old_x * 64, old_y * 64);
	game->player_x = new_x;
	game->player_y = new_y;
	mlx_put_image_to_window(game->mlx, game->win, game->player,
		new_x * 64, new_y * 64);
	game->moves++;
	ft_putnbr_fd(game->moves, 1);
	ft_putchar_fd('\n', 1);
}

void	move_player(t_game *game, int dx, int dy)
{
	int		new_x;
	int		new_y;
	char	c;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	c = game->map[new_y][new_x];
	if (c == '1')
		return ;
	if (c == 'C' && game->fish--)
		game->map[new_y][new_x] = '0';
	else if (c == 'E' && game->fish == 0)
		end(game);
	update_position(game, new_x, new_y);
}


