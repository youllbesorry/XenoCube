/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:01:56 by jcoquard          #+#    #+#             */
/*   Updated: 2024/01/26 17:05:54 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../xenocube.h"

void	move_forward(t_map *map, t_cub_entity *entity)
{
	if(get_tile(map, (int)(entity->pos.x + entity->dir.x * SPEED_MOVE), entity->pos.y) == '0')
		entity->pos.x += entity->dir.x * SPEED_MOVE;
	if(get_tile(map, entity->pos.x, (int)(entity->pos.y + entity->dir.y * SPEED_MOVE) ) == '0')
		entity->pos.y += entity->dir.y * SPEED_MOVE;
}

void	move_backward(t_map *map, t_cub_entity *entity)
{
	if(get_tile(map, (int)(entity->pos.x - entity->dir.x * SPEED_MOVE) , (int)(entity->pos.y) ) == '0')
		entity->pos.x -= entity->dir.x * SPEED_MOVE;
	if(get_tile(map, (int)entity->pos.x , (int)(entity->pos.y - entity->dir.y * SPEED_MOVE) ) == '0')
		entity->pos.y -= entity->dir.y * SPEED_MOVE;
	
}

void	move_right(t_map *map, t_cub_entity *entity)
{
	if(get_tile(map, (int)(entity->pos.x - entity->plan.x * SPEED_MOVE) , (int)entity->pos.y ) == '0')
		entity->pos.x -= entity->plan.x * SPEED_MOVE;
	if(get_tile(map, (int)entity->pos.x , (int)(entity->pos.y - entity->plan.y * SPEED_MOVE) ) == '0')
		entity->pos.y -= entity->plan.y * SPEED_MOVE;
}

void	move_left(t_map *map, t_cub_entity *entity)
{
	if(get_tile(map, (int)(entity->pos.x + entity->plan.x * SPEED_MOVE) , (int)entity->pos.y ) == '0')
		entity->pos.x += entity->plan.x * SPEED_MOVE;
	if(get_tile(map, (int)entity->pos.x , (int)(entity->pos.y + entity->plan.y * SPEED_MOVE) ) == '0')
		entity->pos.y += entity->plan.y * SPEED_MOVE;
}
