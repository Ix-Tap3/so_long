/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_core.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcaplat <pcaplat@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 15:32:23 by pcaplat           #+#    #+#             */
/*   Updated: 2026/01/13 14:31:03 by pcaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	check_win(t_data *data, t_pos p_pos)
{
	if (data->map.nb_coins == 0)
	{
		ft_freestrar(data->map.grid);
		quit_game(data);
	}
	draw_player_on_exit(data, p_pos.x, p_pos.y);
}

static void	take_coin(t_data *data, int x, int y)
{
	data->map.nb_coins--;
	data->map.grid[y][x] = '0';
	if(data->map.nb_coins == 0)
		draw_open_exit(data);
}

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
		take_coin(data, p_pos.x, p_pos.y);
	else if (next_cell == 'E')
	{
		check_win(data, p_pos);
		return ;
	}
	draw_player(data, p_pos.x, p_pos.y);
	if (curr_cell == 'E')
		draw_exit(data);
}
