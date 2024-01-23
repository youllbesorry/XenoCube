/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:52:45 by bfaure            #+#    #+#             */
/*   Updated: 2024/01/23 16:54:35 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../xenocube.h"

t_uint	ft_clear(t_cub_context *cubx)
{
	mlx_destroy_image(cubx->win.mlx, cubx->textures.img_n.img);
	mlx_destroy_image(cubx->win.mlx, cubx->textures.img_s.img);
	mlx_destroy_image(cubx->win.mlx, cubx->textures.img_e.img);
	mlx_destroy_image(cubx->win.mlx, cubx->textures.img_w.img);
	mlx_destroy_display(cubx->win.mlx);
	free(cubx->win.mlx);
	gc_free_all(cubx);
	return (CONTINUE_PROC);
}
