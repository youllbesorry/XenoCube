/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:29:41 by bfaure            #+#    #+#             */
/*   Updated: 2024/02/01 14:31:54 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../xenocube.h"

t_uint	is_finish(t_cub_context *cubx, t_str line)
{
	t_uint	i;

	i = 0;
	if (cubx->find.we == 1 && cubx->find.no == 1 && cubx->find.ea == 1
		&& cubx->find.so == 1 && cubx->find.f == 1 && cubx->find.c == 1)
		return (1);
	if ((cubx->find.we == 0 || cubx->find.no == 0 || cubx->find.ea == 0
			|| cubx->find.so == 0 || cubx->find.f == 0 || cubx->find.c == 0))
	{
		if (line[i] != '\0')
		{
			while (ft_isspace(line[i]) == 1)
				i++;
			if (i + 1 < ft_strlen(line))
			{
				if ((line[i] == '1' || line[i] == '0')
					&& (line[i + 1] == '1' || line[i + 1] == '0'))
					return (1);
			}
		}
		return (0);
	}
	return (0);
}

t_uint	find_the_path(t_cub_context *cubx, t_str line, int fd)
{
	while (line != NULL)
	{
		if (find_we_no(cubx, line, fd) != CONTINUE_PROC)
			return (free(line), MALLOC_FAIL);
		if (find_ea_so(cubx, line, fd) != CONTINUE_PROC)
			return (free(line), MALLOC_FAIL);
		if (find_color(cubx, line, fd) != CONTINUE_PROC)
			return (free(line), MALLOC_FAIL);
		if (is_finish(cubx, line) == 1)
		{
			if (add_map_to_lst(cubx, fd, line) != CONTINUE_PROC)
				return (free(line), MALLOC_FAIL);
			break ;
		}
		free(line);
		line = get_next_line(fd);
	}
	printf("find_the_path end\n");
	printf("cubx->color_f.r = %d\n", cubx->color_f.r);
	printf("cubx->color_f.g = %d\n", cubx->color_f.g);
	printf("cubx->color_f.b = %d\n", cubx->color_f.b);
	printf("cubx->color_c.r = %d\n", cubx->color_c.r);
	printf("cubx->color_c.g = %d\n", cubx->color_c.g);
	printf("cubx->color_c.b = %d\n", cubx->color_c.b);
	printf("cubx->img[0].img = %p\n", cubx->img[0].img);
	printf("cubx->img[1].img = %p\n", cubx->img[1].img);
	printf("cubx->img[2].img = %p\n", cubx->img[2].img);
	printf("cubx->img[3].img = %p\n", cubx->img[3].img);
	return (CONTINUE_PROC);
}

t_uint	pars_file(t_cub_context *cubx, t_str path)
{
	int		fd;
	t_str	line;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (BAD_FD);
	line = get_next_line(fd);
	if (line == NULL)
		return (MALLOC_FAIL);
	if (find_the_path(cubx, line, fd) != CONTINUE_PROC)
		return (MALLOC_FAIL);
	close(fd);
	return (CONTINUE_PROC);
}
