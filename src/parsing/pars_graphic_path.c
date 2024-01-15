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
	t_uint	status;
	t_uint	check;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (BAD_FD);
	line = get_next_line(fd);
	if (line == NULL)
		return (MALLOC_FAIL);
	status = CONTINUE_PROC;
	check = 0;
	while (line != NULL)
	{
		if (line[0] == 'N' && line[1] == 'O')
		{
			status = pars_graphic_path(cubx, line, fd);
			check++;
			if (status != CONTINUE_PROC)
				return (status);
		}
		else if (line[0] == 'S' && line[1] == 'O')
		{
			status = pars_graphic_path(cubx, line, fd);
			check++;
			if (status != CONTINUE_PROC)
				return (status);
		}
		else if (line[0] == 'W' && line[1] == 'E')
		{
			status = pars_graphic_path(cubx, line, fd);
			check++;
			if (status != CONTINUE_PROC)
				return (status);
		}
		else if (line[0] == 'E' && line[1] == 'A')
		{
			status = pars_graphic_path(cubx, line, fd);
			check++;
			if (status != CONTINUE_PROC)
				return (status);
		}
		else if (line[0] == 'F')
		{
			status = pars_color(cubx, line, 'F', fd);
			check++;
			if (status != CONTINUE_PROC)
				return (status);
		}
		else if (line[0] == 'C')
		{
			status = pars_color(cubx, line, 'C', fd);
			check++;
			if (status != CONTINUE_PROC)
				return (status);
		}
		if (check == 6)
		{
			status = add_map_to_lst(cubx, fd);
			if (status != CONTINUE_PROC)
				return (status);
			break ;
		}
		free(line);
		line = get_next_line(fd);
	}
	if (line != NULL)
		free(line);
	close(fd);
	return (CONTINUE_PROC);
}

t_uint	pars_graphic_path(t_cub_context *cubx, t_str line, int fd)
{
	t_uint			i;
	static t_uint	flag = 0;
	t_str			path;

	i = 2;
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
	if (flag == 0)
	{
		path = ft_substr(cubx, line, i, ft_strlen(line));
		cubx->textures.img_n.img = mlx_xpm_file_to_image(cubx->win.mlx, path, &(cubx->win.renderer.img_w),
				&(cubx->win.renderer.img_h));
		cubx->gc->free(cubx, path);
		if (cubx->textures.img_n.img == NULL)
			return (IMG_INIT_FAIL);
	}
	else if (flag == 1)
	{
		path = ft_substr(cubx, line, i, ft_strlen(line));
		cubx->textures.img_s.img = mlx_xpm_file_to_image(cubx->win.mlx, path, &(cubx->win.renderer.img_w),
				&(cubx->win.renderer.img_h));
		cubx->gc->free(cubx, path);
		if (cubx->textures.img_s.img == NULL)
			return (IMG_INIT_FAIL);
	}
	else if (flag == 2)
	{
		path = ft_substr(cubx, line, i, ft_strlen(line));
		cubx->textures.img_w.img = mlx_xpm_file_to_image(cubx->win.mlx, path, &(cubx->win.renderer.img_w),
				&(cubx->win.renderer.img_h));
		cubx->gc->free(cubx, path);
		if (cubx->textures.img_w.img == NULL)
			return (IMG_INIT_FAIL);
	}
	else if (flag == 3)
	{
		path = ft_substr(cubx, line, i, ft_strlen(line));
		cubx->textures.img_e.img = mlx_xpm_file_to_image(cubx->win.mlx, path, &(cubx->win.renderer.img_w),
				&(cubx->win.renderer.img_h));
		cubx->gc->free(cubx, path);
		if (cubx->textures.img_e.img == NULL)
			return (IMG_INIT_FAIL);
	}
	flag++;
	return (CONTINUE_PROC);
}

t_uint	pars_color(t_cub_context *cubx, t_str line, int bg, int fd)
{
	t_str			*color;

	line++;
	while (ft_isspace((int)*line) && line != NULL)
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
