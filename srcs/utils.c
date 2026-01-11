/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcaplat <pcaplat@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 19:35:01 by pcaplat           #+#    #+#             */
/*   Updated: 2026/01/11 19:50:35 by pcaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_pos	get_exit_pos(char **map)
{
	t_pos	pos;

	pos.y = 0;
	while (map[pos.y])
	{
		pos.x = 0;
		while (map[pos.y][pos.x])
		{
			if (map[pos.y][pos.x] == 'E')
				return (pos);
			pos.x++;
		}
		pos.y++;
	}
	return (pos);
}

t_pos	get_player_pos(char **map)
{
	t_pos	pos;

	pos.y = 0;
	while (map[pos.y])
	{
		pos.x = 0;
		while (map[pos.y][pos.x])
		{
			if (map[pos.y][pos.x] == 'P')
				return (pos);
			pos.x++;
		}
		pos.y++;
	}
	return (pos);
}

void	ft_exit_error(char *err_msg)
{
	ft_putstr_fd("Error\n", 2);
	if (err_msg)
		ft_putstr_fd(err_msg, 2);
	else
		perror(err_msg);
	exit(0);
}

void	*select_asset(t_data *data, char c)
{
	if (c == '0')
		return (data->ground.img);
	else if (c == '1')
		return (data->wall.img);
	else if (c == 'P')
		return (data->player.img);
	else if (c == 'C')
		return (data->coin.img);
	return (data->exit.img);
}
