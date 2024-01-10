/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ctx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 20:10:09 by bfaure            #+#    #+#             */
/*   Updated: 2024/01/08 20:10:09 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../xenocube.h"

t_uint	init_cub_context(t_cub_context *cubx)
{
	if (init_gc(cubx) != CONTINUE_PROC)
		return (MALLOC_FAIL);
	// ft_bzero(cubx, sizeof(t_cub_context));
	// cubx->color_f = (t_cub_textures *)malloc(sizeof(t_cub_color));
	// if (cubx->color_f == NULL)
	// 	return (MALLOC_FAIL);
	// cubx->color_c = (t_cub_textures *)malloc(sizeof(t_cub_color));
	// if (cubx->color_c == NULL)
	// 	return (MALLOC_FAIL);
	// cubx->path = (t_cub_path *)malloc(sizeof(t_cub_path));
	// if (cubx->path == NULL)
	// 	return (MALLOC_FAIL);
	return (CONTINUE_PROC);
}
