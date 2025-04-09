/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tugcemirayalgan <tugcemirayalgan@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 05:58:20 by tugcemiraya       #+#    #+#             */
/*   Updated: 2025/04/09 18:02:37 by tugcemiraya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_height(char *file, t_game *game)
{
	int	fd;
	int	height;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		free_game(game);
		err_msg(WRN_MAP_READ);
	}
	height = count_lines(fd);
	close(fd);
	if (height == 0)
	{
		free_game(game);
		err_msg(WRN_MAP);
	}
	return (height);
}

static int	count_lines(int fd)
{
	int		height;
	char	*line;

	height = 0;
	line = get_next_line(fd, 0);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd, 0);
	}
	return (height);
}

int	read_map(t_game *game, char *file)
{
	int		fd;
	char	**map;

	game->height = map_height(file, game);
	map = malloc(sizeof(char *) * (game->height + 1));
	if (!map)
		return (0);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (free(map), 0);
	fill_map_lines(map, fd, game->height);
	close(fd);
	game->map = map;
	game->width = ft_strlen(map[0]);
	return (1);
}

static void	fill_map_lines(char **map, int fd, int height)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(fd, 0);
	while (line && i < height)
	{
		map[i++] = ft_strtrim(line, "\n");
		free(line);
		line = get_next_line(fd, 0);
	}
	map[i] = NULL;
}
