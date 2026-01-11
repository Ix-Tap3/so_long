/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcaplat <pcaplat@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 18:06:31 by pcaplat           #+#    #+#             */
/*   Updated: 2026/01/11 11:20:25 by pcaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"



void	destroy_imgs(t_data *data)
{
	if (data->player.img)
		mlx_destroy_image(data->mlx_ptr, data->player.img);
	if (data->coin.img)
		mlx_destroy_image(data->mlx_ptr, data->coin.img);
	if (data->exit.img)
		mlx_destroy_image(data->mlx_ptr, data->exit.img);
	if (data->ground.img)
		mlx_destroy_image(data->mlx_ptr, data->ground.img);
	if (data->wall.img)
		mlx_destroy_image(data->mlx_ptr, data->wall.img);
}

void	quit_game(t_data *data)
{
	destroy_imgs(data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
}

int	close_win(t_data *data)
{
	if (data->map.grid)
		ft_freestrar(data->map.grid);
	quit_game(data);
	return (0);
}
