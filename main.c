/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcaplat <pcaplat@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:35:31 by pcaplat           #+#    #+#             */
/*   Updated: 2026/01/13 16:51:53 by pcaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"
#include "libft/libft.h"
#include "mlx_linux/mlx.h"

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

void	set_window(t_data *d, char *win_name)
{
	mlx_get_screen_size(d->mlx_ptr, &d->screen_w, &d->screen_h);
	d->win_ptr = mlx_new_window(d->mlx_ptr, d->map.width, 
							 d->map.height, win_name);
	if (d->screen_h < d->map.height || d->screen_w < d->map.width)
	{
		ft_freestrar(d->map.grid);
		ft_putstr_fd("Error\nMap is bigger than screen size.\n", 2);
		quit_game(d);
	}
}

int	key_action(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		close_win(data);
	else if (keycode == XK_W || keycode == XK_w)
		move_player(data, 0, -1);
	else if (keycode == XK_S || keycode == XK_s)
		move_player(data, 0, 1);
	else if (keycode == XK_A || keycode == XK_a)
		move_player(data, -1, 0);
	else if (keycode == XK_D || keycode == XK_d)
		move_player(data, 1, 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		ft_exit_error("Invalid number of arguments\n");
	parse(&data, av[1]);
	data.mlx_ptr = mlx_init();
	init_game_assets(&data, "./textures/player.xpm");
	set_window(&data, "so_long");
	draw_map(&data);
	mlx_hook(data.win_ptr, 2, 1L, key_action, &data);
	mlx_hook(data.win_ptr, 17, 1L << 17, close_win, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
