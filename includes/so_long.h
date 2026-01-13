/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcaplat <pcaplat@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 18:10:08 by pcaplat           #+#    #+#             */
/*   Updated: 2026/01/13 16:51:21 by pcaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define UP 0
# define DOWN 1
# define RIGHT 2
# define LEFT 3
# define TILE_SIZE 32
# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct	s_pos
{
	int	x;
	int	y;
}		t_pos;

typedef struct	s_map
{
	char	**grid;
	int		width;
	int		height;
	int		nb_coins;
	t_pos	player_pos;
}			t_map;

typedef struct	s_img
{
	void	*img;
	int		width;
	int		height;
}			t_img;

typedef struct	s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		screen_w;
	int		screen_h;
	t_img	player;
	t_img	coin;
	t_img	exit;
	t_img	p_on_exit;
	t_img	open_exit;
	t_img	wall;
	t_img	ground;
	t_map	map;
	int		moves;
}				t_data;
 
/* Parsing */
void	parse(t_data *data, char *arg);
t_map	build_map(char *arg, int fd);
void	check_map(t_data *data);
void	check_path(t_data *data);
int		count_component(char **grid, char cmp);

/* Init functions */
void	init_map(t_map *map);
void	init_imgs(t_data *data);
void	init_game_assets(t_data *data, char *path);
void	init_open_exit_asset(t_data *d, char *path);
void	init_p_on_exit_asset(t_data *d, char *path);

/* Exit functions */
void	quit_game(t_data *data);
int		close_win(t_data *data);
void	destroy_imgs(t_data *data);

/* Utils functions */
void	ft_exit_error(char *err_msg);
void	*select_asset(t_data *data, char c);
t_pos	get_exit_pos(char **map);
t_pos	get_player_pos(char **map);

/* Draw functions */
void	draw_map(t_data *data);
void	draw_player(t_data *data, int dir_x, int dir_y);
void	draw_open_exit(t_data *data);
void	draw_exit(t_data *data);
void	draw_player_on_exit(t_data *data, int x, int y);

/* Game functions */
void	move_player(t_data *data, int dir_x, int dir_y);

/* TO DEL BEFORE PUSH */
void	display_map(char *map_name, t_map map);

#endif
