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

//SUD	= dir(0, 1) plan(0.66, 0)
//NORD	= dir(0, -1) plan(-0.66, 0)
//OUEST	= dir(-1, 0) plan(0, 0.66)
//EST	= dir(1, 0) plan(0, -0.66)

static void	init_entity_plan(t_cub_entity *entity)
{
	if (entity->char_dir == 'N')
	{
		init_dvec(&entity->dir, 0, -1);
		init_dvec(&entity->plan, -0.66, 0);
	}
	else if (entity->char_dir == 'S')
	{
		init_dvec(&entity->dir, 0, 1);
		init_dvec(&entity->plan, 0.66, 0);
	}
	else if (entity->char_dir == 'O')
	{
		init_dvec(&entity->dir, -1, 0);
		init_dvec(&entity->plan, 0, 0.66);
	}
	else if (entity->char_dir == 'E')
	{
		init_dvec(&entity->dir, 1, 0);
		init_dvec(&entity->plan, 0, -0.66);
	}
}

void	init_entity(t_cub_entity *entity, double x, double y)
{
	init_dvec(&entity->pos, x + 0.5, y + 0.5);
	entity->w = 16;
	entity->h = 16;
	init_entity_plan(entity);
}

t_uint	init_cub_context(t_cub_context *cubx)
{
	cubx->lst_map = NULL;
	if (init_gc(cubx) != CONTINUE_PROC)
		return (CUB_CONTEXT_INIT_FAIL);
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
