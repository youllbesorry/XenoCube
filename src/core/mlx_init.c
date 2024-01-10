/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:29:43 by bfaure            #+#    #+#             */
/*   Updated: 2024/01/10 18:33:50 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../xenocube.h"

t_uint	win_init(t_cub_context *cubx, int win_w, int win_h)
{
	cubx->win.mlx = mlx_init();
	if (!cubx->win.mlx)
		return (MLX_NEW_WIN_FAIL);
	cubx->win.w = win_w;
	cubx->win.h = win_h;
	// cubx->win.win = mlx_new_window(cubx->win.mlx, cubx->win.w, cubx->win.h, "cubx3D");
	// if (!cubx->win.win)
	// 	return (MLX_NEW_WIN_FAIL);
	// new_img(cubx, &(cubx->win.renderer), cubx->win.w, cubx->win.h);
	// if (!cubx->win.renderer.img)
	// 	return (MLX_NEW_WIN_FAIL);
	return (0);
}
