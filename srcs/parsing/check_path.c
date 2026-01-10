/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcaplat <pcaplat@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 16:31:04 by pcaplat           #+#    #+#             */
/*   Updated: 2026/01/10 17:49:51 by pcaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static char	**copy_map(t_data *data)
{
	char	**map;
	int		i;

	map = ft_calloc((data->map.height + 1), sizeof(char *));
	if (!map)
		return (NULL);
	i = 0;
	while (data->map.grid[i])
	{
		map[i] = ft_strdup(data->map.grid[i]);
		if (!map[i])
		{
			ft_freestrar(map);
			return (NULL);
		}
		i++;
	}
	map[i] = NULL;
	return (map);
}

void	flood_fill(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'v')
		return ;
	else
		map[y][x] = 'v';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

void	check_path(t_data *data)
{
	char **map_cpy;

	map_cpy = copy_map(data);
	if (!map_cpy)
	{
		ft_freestrar(data->map.grid);
		ft_exit_error(NULL);
	}
	flood_fill(map_cpy, data->map.player_pos.x, data->map.player_pos.y);
	if (count_component(map_cpy, 'C') || count_component(map_cpy, 'E'))
	{
		ft_freestrar(data->map.grid);
		ft_freestrar(map_cpy);
		ft_exit_error("Player cannot reach collectible or exit\n");
	}
	ft_freestrar(map_cpy);
}
