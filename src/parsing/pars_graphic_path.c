/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_graphic_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:15:35 by bfaure            #+#    #+#             */
/*   Updated: 2024/01/08 19:15:35 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "../../xenocube.h"

t_uint	pars_file(t_cub_context *cubx, t_str path)
{
	int		fd;
	t_str	line;
	t_uint	ret;
	t_uint	status;

	ret = 0;
	fd = open(path, O_RDONLY);
	printf("fd: %d\n", fd);
	if (fd == -1)
		return (ret);
	line = get_next_line(fd);
	status = CONTINUE_PROC;
	while (line != NULL)
	{
		printf("line: %s\n", line);
		if (line[0] == 'N' && line[1] == 'O')
		{
			if (pars_graphic_path(cubx, line, fd) != CONTINUE_PROC)
				return (MALLOC_FAIL);
		}
		else if (line[0] == 'S' && line[1] == 'O')
		{
			if (pars_graphic_path(cubx, line, fd) != CONTINUE_PROC)
				return (MALLOC_FAIL);
		}
		else if (line[0] == 'W' && line[1] == 'E')
		{
			if (pars_graphic_path(cubx, line, fd) != CONTINUE_PROC)
				return (MALLOC_FAIL);
		}
		else if (line[0] == 'E' && line[1] == 'A')
		{
			if (pars_graphic_path(cubx, line, fd) != CONTINUE_PROC)
				return (MALLOC_FAIL);
		}
		else if (line[0] == 'F')
		{
			status = pars_color(cubx, line, 'F', fd);
			if (status != CONTINUE_PROC)
				return (status);
		}
		else if (line[0] == 'C')
		{
			status = pars_color(cubx, line, 'C', fd);
			if (status != CONTINUE_PROC)
				return (status);
		}
		else if (line[0] == '\0')
			ret++;
		else
			ret = 0;
		free(line);
		line = get_next_line(fd);
	}
	return (ret);
}

t_uint	pars_graphic_path(t_cub_context *cubx, t_str line, int fd)
{
	t_uint			i;
	static t_uint	flag = 0;

	i = 2;
	while (ft_isspace(line[i]))
	{
		if (line[i] == '\n')
		{
			line = get_next_line(fd);
			i = 0;
			continue ;
		}
		i++;
	}
	if (flag == 0)
	{
		cubx->path.path_n = ft_substr(cubx, line, i, ft_strlen(line));
		if (cubx->path.path_n == NULL)
			return (MALLOC_FAIL);
	}
	else if (flag == 1)
	{
		cubx->path.path_s = ft_substr(cubx, line, i, ft_strlen(line));
		if (cubx->path.path_s == NULL)
			return (MALLOC_FAIL);
	}
	else if (flag == 2)
	{
		cubx->path.path_w = ft_substr(cubx, line, i, ft_strlen(line));
		if (cubx->path.path_w == NULL)
			return (MALLOC_FAIL);
	}
	else if (flag == 3)
	{
		cubx->path.path_e = ft_substr(cubx, line, i, ft_strlen(line));
		if (cubx->path.path_e == NULL)
			return (MALLOC_FAIL);
	}
	flag++;
	return (CONTINUE_PROC);
}

t_uint	pars_color(t_cub_context *cubx, t_str line, int bg, int fd)
{
	t_str			*color;

	line++;
	while (ft_isspace((int)*line))
	{
		if (*line == '\n')
		{
			line = get_next_line(fd);
			line++;
			continue ;
		}
		line++;
	}
	color = ft_split(cubx, line, ',');
	if (color == NULL)
		return (MALLOC_FAIL);
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
	else if (bg == 'C')
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
	ft_free_tab(cubx, color);
	return (CONTINUE_PROC);
}
