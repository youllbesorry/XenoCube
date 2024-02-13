/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liurne <liurne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:35:08 by bfaure            #+#    #+#             */
/*   Updated: 2024/02/13 15:37:13 by liurne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../xenocube.h"

t_uint	f_color(t_cub_context *cubx, t_str *color, int bg)
{
	t_color	floor;

	if (bg == 'F')
	{
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
	printf("color floor (%d, %d, %d)\n", floor.r, floor.g, floor.b);
	return (CONTINUE_PROC);
}

t_uint	c_color(t_cub_context *cubx, t_str *color, int bg)
{
	t_color	ceiling;

	if (bg == 'C')
	{
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
	if (bg == 'F' && f_color(cubx, color, bg) != CONTINUE_PROC)
		return (BAD_COLOR_FORMAT);
	if (bg == 'C' && c_color(cubx, color, bg) != CONTINUE_PROC)
		return (BAD_COLOR_FORMAT);
	ft_free_tab(cubx, color);
	return (CONTINUE_PROC);
}
