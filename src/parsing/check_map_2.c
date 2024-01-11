/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:10:58 by bfaure            #+#    #+#             */
/*   Updated: 2024/01/11 17:21:30 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../xenocube.h"

bool	is_player(t_cub_context *cubx, t_uint x, t_uint y)
{
	if ((x <= cubx->map.w && y <= cubx->map.h)
		&& (cubx->map.map[y][x] == 'N' || cubx->map.map[y][x] == 'S'
		|| cubx->map.map[y][x] == 'E' || cubx->map.map[y][x] == 'W'))
		return (true);
	return (false);
}

t_uint	back_tracking_algo(t_cub_context *cubx, t_uint x, t_uint y, t_uint check)
{
	if (x == 0)
	{
		// printf("x = %d\n", x);
		if (is_player(cubx, x + 1, y) || cubx->map.map[y][x + 1] == '0')
		{
			cubx->map.map[y][x + 1] = '*';
			check = 1;
		}
	}
	else
	{
		// printf("x = %d\n", x);
		if ((is_player(cubx, x - 1, y) || cubx->map.map[y][x - 1] == '0'))
		{
			cubx->map.map[y][x - 1] = '*';
			check = 1;
		}
		if (is_player(cubx, x + 1, y) || cubx->map.map[y][x + 1] == '0')
		{
			cubx->map.map[y][x + 1] = '*';
			check = 1;
		}
	}
	if (y == 0)
	{
		// printf("y = %d\n", y);
		if (is_player(cubx, x, y + 1) || cubx->map.map[y + 1][x] == '0')
		{
			cubx->map.map[y + 1][x] = '*';
			check = 1;
		}
	}
	else
	{
		// printf("y = %d\n", y);
		if ((is_player(cubx, x, y - 1) || cubx->map.map[y - 1][x] == '0'))
		{
			cubx->map.map[y - 1][x] = '*';
			check = 1;
		}
		if (is_player(cubx, x, y + 1) || cubx->map.map[y + 1][x] == '0')
		{
			cubx->map.map[y + 1][x] = '*';
			check = 1;
		}
	}
	return (CONTINUE_PROC);
}

t_uint	is_valide(t_cub_context *cubx)
{
	t_uint	x;
	t_uint	y;

	x = cubx->player.x;
	y = cubx->player.y;
	while (cubx->map.map[y] != NULL)
	{
		x = 0;
		while (cubx->map.map[y][x] != '\0')
		{
			if (cubx->map.map[y][x - 1] != '*'
				|| cubx->map.map[y][x + 1] != '*'
				|| cubx->map.map[y - 1][x] != '*'
				|| cubx->map.map[y + 1][x] != '*')
				return (MAP_ERROR);
			x++;
		}
		y++;
	}
	return (CONTINUE_PROC);
}

t_uint	test_map(t_cub_context *cubx)
{
	t_uint	check;
	t_uint	x;
	t_uint	y;

	check = 1;
	x = 0;
	y = 0;
	while (cubx->map.map[y] && y < cubx->map.h)
	{
		x = 0;
		while (cubx->map.map[y][x] && x < cubx->map.w)
		{
			check = back_tracking_algo(cubx, x, y, check);
			x++;
		}
		y++;
	}
	return (is_valide(cubx));
}
