/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:35:08 by bfaure            #+#    #+#             */
/*   Updated: 2024/02/12 14:59:30 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../xenocube.h"

t_uint	f_color(t_cub_context *cubx, t_str *color, int bg)
{
	if (bg == 'F')
	{
		cubx->color_f.r = ft_atoi(color[0]);
		if (cubx->color_f.r > 255 || cubx->color_f.r < 0)
			return (BAD_COLOR_FORMAT);
		cubx->color_f.g = ft_atoi(color[1]);
		if (cubx->color_f.g > 255 || cubx->color_f.g < 0)
			return (BAD_COLOR_FORMAT);
		cubx->color_f.b = ft_atoi(color[2]);
		if (cubx->color_f.b > 255 || cubx->color_f.b < 0)
			return (BAD_COLOR_FORMAT);
	}
	return (CONTINUE_PROC);
}

t_uint	c_color(t_cub_context *cubx, t_str *color, int bg)
{
	if (bg == 'C')
	{
		cubx->color_c.r = ft_atoi(color[0]);
		if (cubx->color_c.r > 255 || cubx->color_c.r < 0)
			return (BAD_COLOR_FORMAT);
		cubx->color_c.g = ft_atoi(color[1]);
		if (cubx->color_c.g > 255 || cubx->color_c.g < 0)
			return (BAD_COLOR_FORMAT);
		cubx->color_c.b = ft_atoi(color[2]);
		if (cubx->color_c.b > 255 || cubx->color_c.b < 0)
			return (BAD_COLOR_FORMAT);
	}
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
	t_str			*color;

	line++;
	while (ft_isspace((int)*line) && line != NULL)
	{
		if (*line == '\n')
		{
			printf("Error\nMissing color\n");
			ft_clear(cubx);
		}
		line++;
	}
	color = ft_split(cubx, line, ',');
	if (color == NULL)
		return (MALLOC_FAIL);
	if (check_hex_color(color) != CONTINUE_PROC)
		return (BAD_COLOR_FORMAT);
	if (f_color(cubx, color, bg) != CONTINUE_PROC)
		return (BAD_COLOR_FORMAT);
	if (c_color(cubx, color, bg) != CONTINUE_PROC)
		return (BAD_COLOR_FORMAT);
	ft_free_tab(cubx, color);
	return (CONTINUE_PROC);
}
