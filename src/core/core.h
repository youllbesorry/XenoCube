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


struct s_cub_player
{
	t_uint					x;
	t_uint					y;
	t_uint					dir;
};

struct s_cub_ray
{
	t_uint					x;
	t_uint					y;
};

struct s_cub_image
{
	void	*img_n;
	void	*img_s;
	void	*img_e;
	void	*img_w;
};

struct s_cub_path
{
	t_str	*path_n;
	t_str	*path_s;
	t_str	*path_e;
	t_str	*path_w;
};

struct s_cub_context
{
	t_garbage_collector		*gc;
	t_cub_player			*player;
	t_cub_ray				*ray;
	t_cub_image				*image;
	t_cub_path				*path;
	t_str					*map;
	void					*mlx_ptr;
	void					*win_ptr;
};

void	init_cub_context(t_cub_context *cubx);

#endif
