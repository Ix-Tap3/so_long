/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcaplat <pcaplat@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 12:26:44 by pcaplat           #+#    #+#             */
/*   Updated: 2026/01/08 12:43:17 by pcaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	check_extension(char *arg)
{
	const char	*ext = ".ber";
	int			i;
	int			j;

	i = 0;
	while (arg[i])
	{
		j = 0;
		while (ext[j] && ext[j] == arg[i])
		{
			if (arg[i + 1])
		}
	}
}
