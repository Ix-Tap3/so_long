/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcaplat <pcaplat@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:48:04 by pcaplat           #+#    #+#             */
/*   Updated: 2026/01/10 15:03:40 by pcaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include <fcntl.h>

void	parse(t_data *data, char *arg)
{
	int		fd;

	if (!arg)
		ft_exit_error("Invalid map name.\n");
	if (!ft_strnstr(arg, ".ber", ft_strlen(arg)))
		ft_exit_error("Invalid map format\n");
	fd = open(arg, O_RDONLY);
	if (fd == - 1)
		ft_exit_error(NULL);
	data->map = build_map(arg, fd);
	close(fd);
	check_map(data);
}
