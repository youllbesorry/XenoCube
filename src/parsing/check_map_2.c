/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:10:58 by bfaure            #+#    #+#             */
/*   Updated: 2024/01/11 14:33:03 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../xenocube.h"

t_uint	back_tracking_algo(t_cub_context *cubx, t_uint x, t_uint y)
{
	// printf("x = %d\ny = %d\n", x, y);
	cubx->map.map[y][x] = 'X';
	if (cubx->map.map[y][x + 1] == '0')
		back_tracking_algo(cubx, x + 1, y);
	if (cubx->map.map[y][x - 1] == '0')
		back_tracking_algo(cubx, x - 1, y);
	if (cubx->map.map[y + 1][x] == '0')
		back_tracking_algo(cubx, x, y + 1);
	if (cubx->map.map[y - 1][x] == '0')
		back_tracking_algo(cubx, x, y - 1);
	return (CONTINUE_PROC);
}
