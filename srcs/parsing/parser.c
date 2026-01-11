/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcaplat <pcaplat@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:48:04 by pcaplat           #+#    #+#             */
/*   Updated: 2026/01/11 19:37:51 by pcaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

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
	ft_printf("player starting pos : (%d, %d)\n", data->map.player_pos.x, data->map.player_pos.y);
	data->map.nb_coins = count_component(data->map.grid, 'C');
	close(fd);
	check_map(data);
	check_path(data);
	data->map.height *= TILE_SIZE;
	data->map.width *= TILE_SIZE;
	data->moves = 1;
}
