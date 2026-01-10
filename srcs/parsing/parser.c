/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcaplat <pcaplat@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:48:04 by pcaplat           #+#    #+#             */
/*   Updated: 2026/01/10 12:00:51 by pcaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include <fcntl.h>

void	parse(t_data *data, char *arg)
{
	int		fd;

	if (!arg)
		quit_game(data);
	if (!ft_strnstr(arg, ".ber", ft_strlen(arg)))
	{
		ft_puterror("Invalid map format\n");
		exit(0);
	}
	fd = open(arg, O_RDONLY);
	if (fd == - 1)
	{
		ft_puterror(NULL);
		exit(0);
	}
	data->map = build_map(arg, fd);
	close(fd);
}
