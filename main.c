/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcaplat <pcaplat@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:35:31 by pcaplat           #+#    #+#             */
/*   Updated: 2026/01/13 15:51:57 by pcaplat          ###   ########.fr       */
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

void	*set_window(t_data data, char *win_name)
{
	int		height;
	int		width;
	void	*win_ptr;

	if (data.screen_h < data.map.height)
		height = data.screen_h;
	else
		height = data.map.height;
	if (data.screen_w < data.map.width)
		width = data.screen_w;
	else
		width = data.map.width;
	win_ptr = mlx_new_window(data.mlx_ptr, width, height, win_name);
	return (win_ptr);
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
	mlx_get_screen_size(data.mlx_ptr, &data.screen_w, &data.screen_h);
	data.win_ptr = set_window(data, "so_long");
	init_game_assets(&data, "./textures/player.xpm");
	ft_printf("screen_h : %d, screen_w : %d\n", data.screen_h, data.screen_w);
	draw_map(&data);
	mlx_hook(data.win_ptr, 2, 1L, key_action, &data);
	mlx_hook(data.win_ptr, 17, 1L << 17, close_win, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
