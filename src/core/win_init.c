/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:29:43 by bfaure            #+#    #+#             */
/*   Updated: 2024/02/29 14:55:25 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "xenocube.h"

t_uint	new_img(t_cub_context *cubx, t_img *img, int w, int h)
{
	img->img = mlx_new_image(cubx->win.mlx, w, h);
	img->img_h = h;
	img->img_w = w;
	if (!img->img)
		return (ft_clear(cubx), MALLOC_FAIL);
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel),
			&(img->line_length), &(img->endian));
	return (CONTINUE_PROC);
}

t_uint	load_img(t_cub_context *cubx, char *path, t_uint i)
{
	cubx->img[i].img = mlx_xpm_file_to_image(cubx->win.mlx,
			path, &(cubx->img[i].img_w),
			&(cubx->img[i].img_h));
	if (!cubx->img[i].img)
		return (printf("Error\n%s init fail\n", path), IMG_INIT_FAIL);
	cubx->img[i].addr = mlx_get_data_addr(cubx->img[i].img,
			&(cubx->img[i].bits_per_pixel),
			&(cubx->img[i].line_length), &(cubx->img[i].endian));
	if (!cubx->img[i].addr)
		return (printf("Error\n%s init fail\n", path), IMG_INIT_FAIL);
	return (CONTINUE_PROC);
}

t_uint	win_init(t_cub_context *cubx, int win_w, int win_h)
{
	cubx->win.mlx = mlx_init();
	if (!cubx->win.mlx)
		return (MLX_NEW_WIN_FAIL);
	cubx->win.w = win_w;
	cubx->win.h = win_h;
	cubx->win.win = mlx_new_window(cubx->win.mlx,
			cubx->win.w, cubx->win.h, "cub3D");
	if (!cubx->win.win)
		return (MLX_NEW_WIN_FAIL);
	new_img(cubx, &(cubx->win.renderer), cubx->win.w, cubx->win.h);
	if (!cubx->win.renderer.img)
		return (MLX_NEW_WIN_FAIL);
	return (CONTINUE_PROC);
}
