/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcaplat <pcaplat@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 12:26:44 by pcaplat           #+#    #+#             */
/*   Updated: 2026/01/10 15:05:44 by pcaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	check_lines_len(char **grid, int map_width)
{
	int	i;

	i = 0;
	while (grid[i])
	{
		if (ft_strlen_sep(grid[i], '\n') != map_width)
			return (0);
		i++;
	}
	return (1);
}

static int	count_component(char **grid, char cmp)
{
	int	i;
	int	j;
	int	cmp_count;

	i = 0;
	cmp_count = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			if (grid[i][j] == cmp)
				cmp_count++;
			j++;
		}
		i++;
	}
	return (cmp_count);
}

static int	check_map_components(char **grid)
{
	int	i;
	int	j;

	i = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			if (grid[i][j] != 'P' && grid[i][j] != 'C' && grid[i][j] != 'E' &&
				grid[i][j] != '1' && grid[i][j] != '0')
				return (0);
			j++;
		}
		i++;
	}
	if (count_component(grid, 'P') != 1 || count_component(grid, 'E') != 1)
		return (0);
	if (count_component(grid, 'C') <= 0)
		return (0);
	return (1);
}

static int	check_map_border(char **grid)
{
	int	i;
	int	j;

	i = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			if ((i == 0 || !grid[i + 1]) && grid[i][j] != '1')
				return (0);
			else if ((j == 0 || !grid[i][j + 1]) && grid[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	check_map(t_data *data)
{
	if (data->map.width < 4 || data->map.height < 4)
	{
		ft_freestrar(data->map.grid);
		ft_exit_error("Invalid map size.\n");
	}
	if (!check_lines_len(data->map.grid, data->map.width))
	{
		ft_freestrar(data->map.grid);
		ft_exit_error("Invalid map shape.\n");
	}
	if (!check_map_components(data->map.grid))
	{
		ft_freestrar(data->map.grid);
		ft_exit_error("Invalid map content.\n");
	}
	if (!check_map_border(data->map.grid))
	{
		ft_freestrar(data->map.grid);
		ft_exit_error("Map isn't surrounding by walls.\n");
	}
}
