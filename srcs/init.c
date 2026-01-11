/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcaplat <pcaplat@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 11:42:46 by pcaplat           #+#    #+#             */
/*   Updated: 2026/01/11 11:05:38 by pcaplat          ###   ########.fr       */
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

}
