/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:10:58 by bfaure            #+#    #+#             */
/*   Updated: 2024/01/22 15:48:48 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../xenocube.h"

t_uint  check_valid_map(t_cub_context *cubx)
{
	t_uint	x;
	t_uint	y;

	y = 0;
	while (cubx->map.map[y])
	{
		x = 0;
		while (cubx->map.map[y][x])
		{
			if (cubx->map.map[y][x] == '0')
			{
				if (cubx->map.map[y][x + 1] == ' ' || cubx->map.map[y][x - 1] == ' '
					|| cubx->map.map[y + 1][x] == ' ' || cubx->map.map[y - 1][x] == ' ')
				{
					return (MAP_ERROR);
				}
			}
			x++;
		}
		y++;
	}
	return (CONTINUE_PROC);
}
