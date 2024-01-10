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
				printf("============================================================\n");
				printf("cubx->map.map[%d][%d - 1] = %c\n", i, j, cubx->map.map[i][j - 1]);
				printf("cubx->map.map[%d][%d + 1] = %c\n", i, j, cubx->map.map[i][j + 1]);
				printf("cubx->map.map[%d][%d] = %c\n", i, j, cubx->map.map[i][j]);
				return (MAP_ERROR);
			}
			j++;
		}
		i++;
	}
	return (CONTINUE_PROC);
}
