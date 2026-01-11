/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcaplat <pcaplat@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:48:04 by pcaplat           #+#    #+#             */
/*   Updated: 2026/01/11 11:38:28 by pcaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static t_pos	get_player_pos(char **grid)
{
	t_pos	pos;

	pos.y = 0;
	while (grid[pos.y])
	{
		pos.x = 0;
		while (grid[pos.y][pos.x])
		{
			if (grid[pos.y][pos.x] == 'P')
				return (pos);
			pos.x++;
		}
		pos.y++;
	}
	return (pos);
}

void	parse(t_data *data, char *arg)
{
	int		fd;

	if (!arg)
		ft_exit_error("Invalid map name.\n");
	if (!ft_strnstr(arg, ".ber", ft_strlen(arg)))
		ft_exit_error("Invalid map format\n");
	fd = open(arg, O_RDONLY);
	if (fd == - 1)
		ft_exit_error(NULL);
	data->map = build_map(arg, fd);
	data->map.player_pos = get_player_pos(data->map.grid);
	data->map.nb_coins = count_component(data->map.grid, 'C');
	close(fd);
	check_map(data);
	check_path(data);
	data->map.height *= TILE_SIZE;
	data->map.width *= TILE_SIZE;
}
