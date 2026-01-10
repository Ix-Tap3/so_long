/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcaplat <pcaplat@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:35:31 by pcaplat           #+#    #+#             */
/*   Updated: 2026/01/10 16:10:32 by pcaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"
#include "libft/libft.h"

void	display_map(char *map_name, t_map map)
{
	int	i;

	ft_printf("%s\nheight : %d\twidth : %d\n", map_name, map.height, map.width);
	i = 0;
	while (map.grid[i])
	{
		ft_printf("%s\n", map.grid[i]);
		i++;
	}
}

void	ft_exit_error(char *err_msg)
{
	ft_putstr_fd("Error\n", 2);
	if (err_msg)
		ft_putstr_fd(err_msg, 2);
	else
		perror(err_msg);
	exit(0);
}

int	key_action(int keycode, t_data *data)
{
	static int	move_count = 0;

	if (keycode == XK_Escape)
		close_win(data);
	else if (keycode == XK_W || keycode == XK_w)
		ft_printf("UP\n");
	else if (keycode == XK_S || keycode == XK_s)
		ft_printf("DOWN\n");
	else if (keycode == XK_A || keycode == XK_a)
		ft_printf("LEFT\n");
	else if (keycode == XK_D || keycode == XK_d)
		ft_printf("RIGHT\n");
	ft_printf("%d moves\n", ++move_count);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		ft_exit_error("Invalid number of arguments\n");
	parse(&data, av[1]);
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, 300, 300, "so_long");
	display_map(av[1], data.map);
	mlx_hook(data.win_ptr, 2, 1L, key_action, &data);
	mlx_hook(data.win_ptr, 17, 1L << 17, close_win, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
