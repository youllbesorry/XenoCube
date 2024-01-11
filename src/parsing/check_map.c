/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 23:12:36 by bfaure            #+#    #+#             */
/*   Updated: 2024/01/10 23:12:36 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../xenocube.h"

t_uint	find_player(t_cub_context *cubx)
{
	t_uint	i;
	t_uint	j;

	i = 0;
	j = 0;
	while (cubx->map.map[i] != NULL)
	{
		j = 0;
		while (cubx->map.map[i][j] != '\0')
		{
			if (cubx->map.map[i][j] == 'N' || cubx->map.map[i][j] == 'S'
				|| cubx->map.map[i][j] == 'E' || cubx->map.map[i][j] == 'W')
			{
				cubx->player.x = j;
				cubx->player.y = i;
				printf("x = %d\ny = %d\n", cubx->player.x, cubx->player.y);
				return (CONTINUE_PROC);
			}
			j++;
		}
		i++;
	}
	return (MAP_ERROR);
}

t_uint	check_map_size(t_cub_context *cubx)
{
	t_uint	i;
	t_uint	j;
	t_uint	tmp;

	i = 0;
	j = 0;
	tmp = 0;
	while (cubx->map.map[i])
	{
		j = 0;
		while (cubx->map.map[i][j] != '\0')
			j++;
		if (tmp < j)
			tmp = j;
		i++;
	}
	cubx->map.w = tmp - 1;
	cubx->map.h = i - 1;
	printf("w = %d\nh = %d\n", cubx->map.w, cubx->map.h);
	return (CONTINUE_PROC);
}

t_uint	check_hole_map(t_cub_context *cubx)
{
	t_uint	i;
	t_uint	j;

	i = 0;
	while (cubx->map.map[i] != NULL)
	{
		j = 0;
		while (cubx->map.map[i][j] != '\0')
		{
			if (ft_isspace(cubx->map.map[i][j])
				&& ((j > 0 && cubx->map.map[i][j - 1] != '1')
				|| (cubx->map.map[i][j + 1] && cubx->map.map[i][j + 1] != '1'))
				&& ((j > 0 && cubx->map.map[i][j - 1] == '0')
				|| (cubx->map.map[i][j + 1] && cubx->map.map[i][j + 1] == '0')))
			{
				return (MAP_ERROR);
			}
			j++;
		}
		i++;
	}
	return (CONTINUE_PROC);
}

t_uint	check_map(t_cub_context *cubx)
{
	t_uint	status;
	t_uint	i;

	status = check_hole_map(cubx);
	if (status != CONTINUE_PROC)
		return (status);
	status = check_map_size(cubx);
	if (status != CONTINUE_PROC)
		return (status);
	status = find_player(cubx);
	if (status != CONTINUE_PROC)
		return (status);
	status = back_tracking_algo(cubx, cubx->player.x, cubx->player.y);
	if (status != CONTINUE_PROC)
		return (status);
	i = 0;
	while (cubx->map.map[i] != NULL)
	{
		printf("%s", cubx->map.map[i]);
		i++;
	}
	printf("\n");
	return (CONTINUE_PROC);
}
