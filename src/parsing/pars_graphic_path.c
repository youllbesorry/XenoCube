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

t_uint	load_img(t_cub_context *cubx, char *path, t_uint i)
{
	cubx->img[i].img = mlx_xpm_file_to_image(cubx->win.mlx,
			path, &(cubx->img[i].img_w),
			&(cubx->img[i].img_h));
	if (!cubx->img[i].img)
		return (printf("%s\n", path), CONTINUE_PROC);
	cubx->img[i].addr = mlx_get_data_addr(cubx->img[i].img,
			&(cubx->img[i].bits_per_pixel),
			&(cubx->img[i].line_length), &(cubx->img[i].endian));
	if (!cubx->img[i].addr)
		return (printf("%s\n", path), CONTINUE_PROC);
	printf("load_img img->img = %p\n", cubx->img[i].img);
	return (CONTINUE_PROC);
}

t_str	make_path(t_cub_context *cubx, t_str line, int i)
{
	t_str	path;

	path = ft_substr(cubx, line, i, ft_strlen(line));
	if (path == NULL)
		return (NULL);
	printf("path = |%s|\n", path);
	return (path);
}

int	remove_spaces_path(t_cub_context *cubx, t_str line, int fd, t_uint n)
{
	t_uint			i;

	i = 2;
	(void)n;
	while (ft_isspace(line[i]))
	{
		if (line[i] == '\n')
		{
			line = get_next_line(fd);
			if (line == NULL)
				return (-1);
			find_we_no(cubx, line, fd);
			find_ea_so(cubx, line, fd);
			i = 0;
			continue ;
		}
		i++;
	}
	return (i);
}

t_uint	pars_graphic_path(t_cub_context *cubx, t_str line, int fd, t_uint n)
{
	t_str			path;
	t_uint			i;

	printf("n = %d\n", n);
	i = remove_spaces_path(cubx, line, fd, n);
	path = make_path(cubx, line, i);
	if (path == NULL)
		return (MALLOC_FAIL);
	if (load_img(cubx, path, n) != CONTINUE_PROC)
		return (cubx->gc->free(cubx, path), MALLOC_FAIL);
	if (path)
		cubx->gc->free(cubx, path);
	printf("pars_graphic_path img[%d].img = %p\n", n, cubx->img[n].img);
	return (CONTINUE_PROC);
}

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
	if (f_color(cubx, color, bg) != CONTINUE_PROC)
		return (DONT_FUCK_WITH_ME);
	if (c_color(cubx, color, bg) != CONTINUE_PROC)
		return (DONT_FUCK_WITH_ME);
	ft_free_tab(cubx, color);
	return (CONTINUE_PROC);
}
