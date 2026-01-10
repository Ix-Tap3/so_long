/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcaplat <pcaplat@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 09:35:09 by pcaplat           #+#    #+#             */
/*   Updated: 2026/01/07 10:25:56 by pcaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dest;

	dest = img->addr + (y * img->line + x * (img->bpp / 8));
	*(unsigned int *)dest = color;
}
