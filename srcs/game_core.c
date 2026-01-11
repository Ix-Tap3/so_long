/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_core.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcaplat <pcaplat@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 15:32:23 by pcaplat           #+#    #+#             */
/*   Updated: 2026/01/11 20:08:16 by pcaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_player(t_data *data, int dir_x, int dir_y)
{
	t_pos	p_pos;
	char	next_cell;
	char	curr_cell;

	p_pos = data->map.player_pos;
	curr_cell = data->map.grid[p_pos.y][p_pos.x];
	p_pos.x += dir_x;
	p_pos.y += dir_y;
	next_cell = data->map.grid[p_pos.y][p_pos.x];
	if (next_cell == '1')
		return ;
	ft_printf("number of moves : %d\n", data->moves++);
	if (next_cell == 'C')
	{
		data->map.nb_coins--;
		data->map.grid[p_pos.y][p_pos.x] = '0';
		if (data->map.nb_coins == 0)
			draw_open_exit(data);
	}
	else if (next_cell == 'E' && data->map.nb_coins != 0)
	{
		draw_player_on_exit(data, p_pos.x, p_pos.y);
		return ;
	}
	else if (next_cell == 'E' && data->map.nb_coins == 0)
	{
		ft_freestrar(data->map.grid);
		quit_game(data);
	}
	draw_player(data, p_pos.x, p_pos.y);
	if (curr_cell == 'E')
		draw_exit(data);
}
