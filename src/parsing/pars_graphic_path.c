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
		if (line[0] == 'W' && line[1] == 'E')
		{
			status = pars_graphic_path(cubx, line, fd, 0);
			check++;
			if (status != CONTINUE_PROC)
				return (status);
			printf("cubx.img[0].img = %p\n", cubx->img[0].img);
		}
		else if (line[0] == 'N' && line[1] == 'O')
		{
			status = pars_graphic_path(cubx, line, fd, 1);
			check++;
			if (status != CONTINUE_PROC)
				return (status);
			printf("cubx.img[1].img = %p\n", cubx->img[1].img);
		}
		else if (line[0] == 'E' && line[1] == 'A')
		{
			status = pars_graphic_path(cubx, line, fd, 2);
			check++;
			if (status != CONTINUE_PROC)
				return (status);
			printf("cubx.img[2].img = %p\n", cubx->img[2].img);
		}
		else if (line[0] == 'S' && line[1] == 'O')
		{
			status = pars_graphic_path(cubx, line, fd, 3);
			check++;
			if (status != CONTINUE_PROC)
				return (status);
			printf("cubx.img[3].img = %p\n", cubx->img[3].img);
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

t_uint	load_img(t_cub_context *cubx, char *path, t_uint i)
{
	cubx->img[i].img = mlx_xpm_file_to_image(cubx->win.mlx, path, &(cubx->img[i].img_w),
			&(cubx->img[i].img_h));
	if (!cubx->img[i].img)
		return (printf("%s\n", path), 1);
	cubx->img[i].addr = mlx_get_data_addr(cubx->img[i].img, &(cubx->img[i].bits_per_pixel),
			&(cubx->img[i].line_length), &(cubx->img[i].endian));
	if (!cubx->img[i].addr)
		return (printf("%s\n", path), 1);
	printf("load_img img->img = %p\n", cubx->img[i].img);
	return (0);
}

t_uint	pars_graphic_path(t_cub_context *cubx, t_str line, int fd, t_uint n)
{
	t_uint			i;
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
	path = ft_substr(cubx, line, i, ft_strlen(line));
	if (path == NULL)
		return (MALLOC_FAIL);
	printf("path = %s\n", path);
	if (load_img(cubx, path, n) == 1)
		return (cubx->gc->free(cubx, path), MALLOC_FAIL);
	cubx->gc->free(cubx, path);
	printf("pars_graphic_path img.img = %p\n", cubx->img[n].img);
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
