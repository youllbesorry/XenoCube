/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:25:42 by jcoquard          #+#    #+#             */
/*   Updated: 2024/01/26 15:31:02 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../xenocube.h"
/*
void	raycast(t_cub_context *cub, t_cub_entity &entity, t_map *map)
{
	int		i;
	int		collision;
	int		side;
	double	distance;
	double	camera;
	double	direction_ray_x;
	double	direction_ray_y;
	double	range_next_x;
	double	range_next_y;
	double	next_x;
	double	next_y;
	int		step_x;
	int		step_y;
	int		map_x;
	int		map_y;
	int		line_h;
	int		start_line;
	int		end_line;

	i = 0;
	while (i < cub->win.w)
	{
		collision = 0;
		camera = 2 * i / (double)cub->win.w - 1;
		map_x = (int)(cub->pl.x);
		map_y = (int)(cub->pl.y);
		direction_ray_x = cub->pl.dir_x + cub->pl.plan_x * camera;
		direction_ray_y = cub->pl.dir_y + cub->pl.plan_y * camera;
		range_next_x = sqrt(1 + (direction_ray_y * direction_ray_y) / (direction_ray_x * direction_ray_x));
		range_next_y = sqrt(1 + (direction_ray_x * direction_ray_x) / (direction_ray_y * direction_ray_y));
		if (direction_ray_x < 0)
		{
			step_x = -1;
			next_x = (cub->pl.x - map_x) * range_next_x;
		}
		else
		{
			step_x = 1;
			next_x = (map_x + 1 - cub->pl.x) * range_next_x;
		}
		if (direction_ray_y < 0)
		{
			step_y = -1;
			next_y = (cub->pl.y - map_y) * range_next_y;
		}
		else
		{
			step_y = 1;
			next_y = (map_y + 1 - cub->pl.y) * range_next_y;
		}
		while (!collision && map_x > 0 && map_x < cub->map.w && map_y > 0 && map_y < cub->map.h)
		{
			if (next_x < next_y)
			{
				next_x += range_next_x;
				map_x += step_x;
				side = 0;
			}
			else
			{
				next_y += range_next_y;
				map_y += step_y;
				side = 1;
			}
			if (get_tile(&(cub->map), map_x, map_y) != '*')
				collision = 1;
		}
		if (collision)
		{
			//correction de l'effet fish-eye
			if (side == 0)
				distance = fabs((map_x - (cub->pl.x) + (1 - step_x) / 2) / direction_ray_x);
			else
				distance = fabs((map_y - (cub->pl.y) + (1 - step_y) / 2) / direction_ray_y);
			line_h = cub->win.h / distance;
			start_line = -line_h / 2 + cub->win.h / 2;
			end_line = line_h / 2 + cub->win.h / 2;
			if(start_line < 0)
				start_line = 0;
			if (end_line >= cub->win.w)
				end_line = cub->win.h - 1;
			if (side)
				line(&cub->win.renderer, (t_vec){.x = cub->win.w - i - 1, .y = start_line}, (t_vec){.x = cub->win.w - i - 1 , .y = end_line}, 0x00FF0000);
			else
				line(&cub->win.renderer, (t_vec){.x = cub->win.w - i - 1, .y = start_line}, (t_vec){.x = cub->win.w - i - 1, .y = end_line}, 0x00A00000);
		}
		i++;
	}
}*/
