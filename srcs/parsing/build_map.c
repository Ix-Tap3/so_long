/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcaplat <pcaplat@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:50:54 by pcaplat           #+#    #+#             */
/*   Updated: 2026/01/10 17:03:02 by pcaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include <fcntl.h>

static int	get_map_height(char *arg)
{
	char	*line;
	int		height;
	int		fd;

	fd = open(arg, O_RDONLY);
	if (fd == - 1)
		return (fd);
	height = 0;
	line = get_next_line(fd);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (height);
}

static char	**fill_grid(int fd, int nb_cells, int *cell_len)
{
	char	**grid;
	char	*cell;
	int		i;

	grid = ft_calloc((nb_cells + 1), sizeof(char *));
	if (!grid)
		return (NULL);
	cell = get_next_line(fd);
	if (!cell)
		return (NULL);
	*cell_len = (int)ft_strlen_sep(cell, '\n');
	i = 0;
	while (cell)
	{
		grid[i] = ft_strdup_sep(cell, '\n');
		if (!grid[i++])
		{
			ft_freestrar(grid);
			return (NULL);
		}
		free(cell);
		cell = get_next_line(fd);
	}
	grid[i] = NULL;
	return (grid);
}

t_map	build_map(char *arg, int fd)
{
	t_map	map;

	map.height = get_map_height(arg);
	if (map.height == 0)
	{
		close(fd);
		ft_exit_error("Empty map.\n");
	}
	map.width = 0;
	map.grid = fill_grid(fd, map.height, &map.width);
	if (!map.grid)
	{
		close(fd);
		ft_exit_error(NULL);
	}
	return (map);
}
