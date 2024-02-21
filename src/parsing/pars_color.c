/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:35:08 by bfaure            #+#    #+#             */
/*   Updated: 2024/02/21 17:46:21 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "xenocube.h"

t_uint	f_color(t_cub_context *cubx, t_str *color, int bg)
{
	t_color	floor;

	if (bg == 'F')
	{
		if (ft_str_isdigit(color[0]) != 1 || ft_str_isdigit(color[1]) != 1
			|| ft_str_isdigit(color[2]) != 1)
			return (BAD_COLOR_FORMAT);
		floor.r = ft_atoi(color[0]);
		if (floor.r > 255 || floor.r < 0)
			return (BAD_COLOR_FORMAT);
		floor.g = ft_atoi(color[1]);
		if (floor.g > 255 || floor.g < 0)
			return (BAD_COLOR_FORMAT);
		floor.b = ft_atoi(color[2]);
		if (floor.b > 255 || floor.b < 0)
			return (BAD_COLOR_FORMAT);
	}
	cubx->color_f = create_trgb(255, floor.r, floor.g, floor.b);
	return (CONTINUE_PROC);
}

t_uint	c_color(t_cub_context *cubx, t_str *color, int bg)
{
	t_color	ceiling;

	if (bg == 'C')
	{
		if (!ft_str_isdigit(color[0]) || !ft_str_isdigit(color[1])
			|| !ft_str_isdigit(color[2]))
			return (BAD_COLOR_FORMAT);
		ceiling.r = ft_atoi(color[0]);
		if (ceiling.r > 255 || ceiling.r < 0)
			return (BAD_COLOR_FORMAT);
		ceiling.g = ft_atoi(color[1]);
		if (ceiling.g > 255 || ceiling.g < 0)
			return (BAD_COLOR_FORMAT);
		ceiling.b = ft_atoi(color[2]);
		if (ceiling.b > 255 || ceiling.b < 0)
			return (BAD_COLOR_FORMAT);
	}
	cubx->color_c = create_trgb(255, ceiling.r, ceiling.g, ceiling.b);
	return (CONTINUE_PROC);
}

t_uint	check_hex_color(t_str *color)
{
	t_uint	i;

	i = 0;
	while (color[i])
		i++;
	if (i != 3)
		return (BAD_COLOR_FORMAT);
	return (CONTINUE_PROC);
}

t_uint	pars_color(t_cub_context *cubx, t_str line, int bg)
{
	t_str	*color;
	t_str	tmp;
	t_uint	i;

	i = 1;
	while (ft_isspace((int)line[i]) && line[i] != '\0')
	{
		if (line[i] == '\n')
		{
			printf("Error\nMissing color\n");
			return (free(line), ft_clear(cubx));
		}
		i++;
	}
	tmp = ft_substr(cubx, line, i, ft_strlen(line) - i);
	color = ft_split(cubx, tmp, ',');
	if (color == NULL)
		return (MALLOC_FAIL);
	if (check_hex_color(color) != CONTINUE_PROC)
		return (BAD_COLOR_FORMAT);
	if (bg == 'F' && f_color(cubx, color, bg) != CONTINUE_PROC)
		return (BAD_COLOR_FORMAT);
	if (bg == 'C' && c_color(cubx, color, bg) != CONTINUE_PROC)
		return (BAD_COLOR_FORMAT);
	return (ft_free_tab(cubx, color), CONTINUE_PROC);
}
