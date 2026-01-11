/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcaplat <pcaplat@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 11:42:46 by pcaplat           #+#    #+#             */
/*   Updated: 2026/01/11 18:31:03 by pcaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	init_img(t_img *img)
{
	img->img = NULL;
	img->width = 0;
	img->height = 0;
}

void	init_imgs(t_data *data)
{
	init_img(&data->player);
	init_img(&data->coin);
	init_img(&data->exit);
	init_img(&data->wall);
	init_img(&data->ground);
	init_img(&data->p_on_exit);
	init_img(&data->open_exit);
}

void	init_p_on_exit_asset(t_data *d, char *path)
{
	t_img	tmp;

	tmp.img = mlx_xpm_file_to_image(d->mlx_ptr, path, &tmp.width, &tmp.height);
	if (!tmp.img)
	{
		ft_freestrar(d->map.grid);
		ft_putstr_fd("Error\nUnable to open player on exit asset\n", 2);
		quit_game(d);
	}
	d->p_on_exit = tmp;
}

void	init_open_exit_asset(t_data *d, char *path)
{
	t_img	tmp;

	tmp.img = mlx_xpm_file_to_image(d->mlx_ptr, path, &tmp.width, &tmp.height);
	if (!tmp.img)
	{
		ft_freestrar(d->map.grid);
		ft_putstr_fd("Error\nUnable to open \"open exit\" asset\n", 2);
		quit_game(d);
	}
	d->open_exit = tmp;
}
