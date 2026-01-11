/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcaplat <pcaplat@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 11:29:15 by pcaplat           #+#    #+#             */
/*   Updated: 2026/01/11 12:39:36 by pcaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	draw_ground(t_data *d, int x, int y, char c)
{
	if (c == 'P' || c == 'E' || c == 'C')
		mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->ground.img, x, y);
}

static void	*select_asset(t_data *data, char c)
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

void	draw_map(t_data *data)
{
	t_pos	tile;
	void	*img;
	int		i;
	int		j;

	tile.y = 0;
	i = 0;
	while (data->map.grid[i])
	{
		tile.x = 0;
		j = 0;
		while (data->map.grid[i][j])
		{
			draw_ground(data, tile.x, tile.y, data->map.grid[i][j]);
			img = select_asset(data, data->map.grid[i][j++]);
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, 
						   img, tile.x, tile.y);
			tile.x += TILE_SIZE;
		}
		tile.y += TILE_SIZE;
		i++;
	}
}
