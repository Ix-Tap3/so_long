/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcaplat <pcaplat@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 09:35:09 by pcaplat           #+#    #+#             */
/*   Updated: 2026/01/11 11:19:14 by pcaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//void	put_pixel(t_img *img, int x, int y, int color)
//{
//	char	*dest;
//
//	dest = img->addr + (y * img->line + x * (img->bpp / 8));
//	*(unsigned int *)dest = color;
//}

static void	init_ground_asset(t_data *d, char *path)
{
	t_img	tmp;

	tmp.img = mlx_xpm_file_to_image(d->mlx_ptr, path, &tmp.width, &tmp.height);
	if (!tmp.img)
	{
		ft_freestrar(d->map.grid);
		ft_putstr_fd("Error\nUnable to open ground asset\n", 2);
		quit_game(d);
	}
	d->ground = tmp;
}

static void	init_coin_asset(t_data *d, char *path)
{
	t_img	tmp;

	tmp.img = mlx_xpm_file_to_image(d->mlx_ptr, path, &tmp.width, &tmp.height);
	if (!tmp.img)
	{
		ft_freestrar(d->map.grid);
		ft_putstr_fd("Error\nUnable to open coin asset\n", 2);
		quit_game(d);
	}
	d->coin = tmp;
}

static void	init_exit_asset(t_data *d, char *path)
{
	t_img	tmp;

	tmp.img = mlx_xpm_file_to_image(d->mlx_ptr, path, &tmp.width, &tmp.height);
	if (!tmp.img)
	{
		ft_freestrar(d->map.grid);
		ft_putstr_fd("Error\nUnable to open exit asset\n", 2);
		quit_game(d);
	}
	d->exit = tmp;
}

static void init_wall_asset(t_data *d, char *path)
{	
	t_img	tmp;

	tmp.img = mlx_xpm_file_to_image(d->mlx_ptr, path, &tmp.width, &tmp.height);
	if (!tmp.img)
	{
		ft_freestrar(d->map.grid);
		ft_putstr_fd("Error\nUnable to open wall asset\n", 2);
		quit_game(d);
	}
	d->wall = tmp;
}

void	init_game_assets(t_data *d, char *path)
{
	t_img	tmp;

	init_imgs(d);
	tmp.img = mlx_xpm_file_to_image(d->mlx_ptr, path, &tmp.width, &tmp.height);
	if (!tmp.img)
	{
		ft_freestrar(d->map.grid);
		ft_putstr_fd("Error\nUnable to open player asset\n", 2);
		quit_game(d);
	}
	d->player = tmp;
	init_coin_asset(d, "./textures/coin.xpm");
	init_exit_asset(d, "./textures/exit.xpm");
	init_wall_asset(d, "./textures/wall.xpm");
	init_ground_asset(d, "./textures/ground.xpm");
}
