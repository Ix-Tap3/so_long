/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcaplat <pcaplat@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 15:36:31 by pcaplat           #+#    #+#             */
/*   Updated: 2026/01/11 19:53:25 by pcaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_player(t_data *d, int x, int y)
{
	t_pos	pos_offset;
	t_pos	player_offset;

	pos_offset.x = x * TILE_SIZE;
	pos_offset.y = y * TILE_SIZE;
	player_offset.x = d->map.player_pos.x * TILE_SIZE;
	player_offset.y = d->map.player_pos.y * TILE_SIZE;
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->ground.img, player_offset.x, player_offset.y);
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->player.img, pos_offset.x, pos_offset.y);
	d->map.player_pos.x = x;
	d->map.player_pos.y = y;
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
			img = select_asset(data, data->map.grid[i][j++]);
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, 
						   img, tile.x, tile.y);
			tile.x += TILE_SIZE;
		}
		tile.y += TILE_SIZE;
		i++;
	}
}

void	draw_open_exit(t_data *d)
{
	t_pos	pos;

	pos = get_exit_pos(d->map.grid);
	pos.x *= TILE_SIZE;
	pos.y *= TILE_SIZE;
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->open_exit.img, 
						 pos.x, pos.y);
}

void	draw_player_on_exit(t_data *d, int x, int y)
{
	t_pos	pos;
	t_pos	p_pos;

	pos = get_exit_pos(d->map.grid);
	pos.x *= TILE_SIZE;
	pos.y *= TILE_SIZE;
	p_pos.x = d->map.player_pos.x * TILE_SIZE;
	p_pos.y = d->map.player_pos.y * TILE_SIZE;
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->p_on_exit.img, 
						 pos.x, pos.y);
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->ground.img, 
						 p_pos.x, p_pos.y);
	d->map.player_pos.x = x;
	d->map.player_pos.y = y;
}

void	draw_exit(t_data *d)
{
	t_pos	pos;

	pos = get_exit_pos(d->map.grid);
	pos.x *= TILE_SIZE;
	pos.y *= TILE_SIZE;
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->exit.img, pos.x, pos.y);
}
