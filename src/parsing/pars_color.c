/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:35:08 by bfaure            #+#    #+#             */
/*   Updated: 2024/02/01 17:03:04 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../xenocube.h"

t_uint	f_color(t_cub_context *cubx, t_str *color, int bg)
{
	if (bg == 'F')
	{
		cubx->color_f.r = ft_atoi(color[0]);
		if (cubx->color_f.r > 255 || cubx->color_f.r < 0)
			return (DONT_FUCK_WITH_ME);
		cubx->color_f.g = ft_atoi(color[1]);
		if (cubx->color_f.g > 255 || cubx->color_f.g < 0)
			return (DONT_FUCK_WITH_ME);
		cubx->color_f.b = ft_atoi(color[2]);
		if (cubx->color_f.b > 255 || cubx->color_f.b < 0)
			return (DONT_FUCK_WITH_ME);
	}
	return (CONTINUE_PROC);
}

t_uint	c_color(t_cub_context *cubx, t_str *color, int bg)
{
	if (bg == 'C')
	{
		cubx->color_c.r = ft_atoi(color[0]);
		if (cubx->color_c.r > 255 || cubx->color_c.r < 0)
			return (DONT_FUCK_WITH_ME);
		cubx->color_c.g = ft_atoi(color[1]);
		if (cubx->color_c.g > 255 || cubx->color_c.g < 0)
			return (DONT_FUCK_WITH_ME);
		cubx->color_c.b = ft_atoi(color[2]);
		if (cubx->color_c.b > 255 || cubx->color_c.b < 0)
			return (DONT_FUCK_WITH_ME);
	}
	return (CONTINUE_PROC);
}

t_uint	pars_color(t_cub_context *cubx, t_str line, int bg, int fd)
{
	t_str	*color;
	t_uint	i;

	// line++;
	i = 1;
	while (ft_isspace(line[i]))
	{
		if (line[i] == '\n')
		{
			line = get_next_line(fd);
			if (line == NULL)
				return (MALLOC_FAIL);
			i = 0;
			continue ;
		}
		i++;
	}
	color = ft_split(cubx, line, ',');
	if (color == NULL)
		return (MALLOC_FAIL);
	printf("color[0] = %s\n", color[0]);
	if (f_color(cubx, color, bg) != CONTINUE_PROC)
		return (DONT_FUCK_WITH_ME);
	if (c_color(cubx, color, bg) != CONTINUE_PROC)
		return (DONT_FUCK_WITH_ME);
	ft_free_tab(cubx, color);
	return (CONTINUE_PROC);
}
