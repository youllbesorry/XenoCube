/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:58:12 by bfaure            #+#    #+#             */
/*   Updated: 2024/01/08 19:58:12 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

# include "../../xenocube.h"

struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_w;
	int		img_h;
};

struct s_cub_entity
{
	double		x;
	double		y;
	int			w;
	int			h;
	double		dir_x;
	double		dir_y;
	double		plan_x;
	double		plan_y;
	t_img		pl;
	char		char_dir;
};

struct s_vec
{
	t_uint					x;
	t_uint					y;
};


struct s_cub_textures
{
	t_img	img_n;
	t_img	img_s;
	t_img	img_e;
	t_img	img_w;
};

struct s_color
{
	int	a;
	int	r;
	int	g;
	int	b;
};

struct s_cub_path
{
	t_str	path_n;
	t_str	path_s;
	t_str	path_e;
	t_str	path_w;
};


struct s_win
{
	void	*mlx;
	void	*win;
	t_img	renderer;
	int		w;
	int		h;
};

struct s_keyboard
{
	int	up;
	int	down;
	int	left;
	int	right;
	int	r_left;
	int	r_right;
};

struct s_map
{
	t_str	*map;
	t_str	*b_map;
	t_uint	w;
	t_uint	h;
	t_vec	pos;
	t_img	img;
};


struct s_cub_context
{
	t_garbage_collector		*gc;
	t_cub_entity			player;
	t_cub_textures			textures;
	t_win					win;
	t_keyboard				keyboard;
	t_cub_path				path;
	t_color					color_f;
	t_color					color_c;
	t_map					map;
	t_list					*lst_map;
};

t_uint	init_cub_context(t_cub_context *cubx);
t_uint	win_init(t_cub_context *cubx, int win_w, int win_h);

#endif
