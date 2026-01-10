/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcaplat <pcaplat@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 18:10:08 by pcaplat           #+#    #+#             */
/*   Updated: 2026/01/10 11:59:34 by pcaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define UP 0
# define DOWN 1
# define RIGHT 2
# define LEFT 3
# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>

typedef struct	s_map
{
	char	**grid;
	int		width;
	int		height;
}			t_map;

typedef struct	s_img
{
	void	*img;
	void	*addr;
	int		bpp;
	int		line;
	int		endian;
}			t_img;

typedef struct	s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_map		map;
}				t_data;
 
/* Parsing */
void	parse(t_data *data, char *arg);
t_map	build_map(char *arg, int fd);

/* Init functions */
void	init_map(t_map *map);

/* IMGS functions */
void	put_pixel(t_img *img, int x, int y, int color);

/* Exit functions */
void	quit_game(t_data *data);
int		close_win(t_data *data);

/* Utils functions */
void	ft_puterror(char *err_msg);

#endif
