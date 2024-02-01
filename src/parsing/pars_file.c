/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:29:41 by bfaure            #+#    #+#             */
/*   Updated: 2024/02/01 01:44:44 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../xenocube.h"

t_uint	find_we_no(t_cub_context *cubx, t_str line, int fd)
{
	t_uint	status;

	if (line[0] == 'W' && line[1] == 'E')
	{
		cubx->find.we = 1;
		status = pars_graphic_path(cubx, line, fd, 0);
		if (status != CONTINUE_PROC)
			return (status);
		printf("cubx.img[0].img = %p\n", cubx->img[0].img);
	}
	else if (line[0] == 'N' && line[1] == 'O')
	{
		cubx->find.no = 1;
		status = pars_graphic_path(cubx, line, fd, 1);
		if (status != CONTINUE_PROC)
			return (status);
		printf("cubx.img[1].img = %p\n", cubx->img[1].img);
	}
	return (CONTINUE_PROC);
}

t_uint	find_ea_so(t_cub_context *cubx, t_str line, int fd)
{
	t_uint	status;

	if (line[0] == 'E' && line[1] == 'A')
	{
		cubx->find.ea = 1;
		status = pars_graphic_path(cubx, line, fd, 2);
		if (status != CONTINUE_PROC)
			return (status);
		printf("cubx.img[2].img = %p\n", cubx->img[2].img);
	}
	else if (line[0] == 'S' && line[1] == 'O')
	{
		cubx->find.so = 1;
		status = pars_graphic_path(cubx, line, fd, 3);
		if (status != CONTINUE_PROC)
			return (status);
		printf("cubx.img[3].img = %p\n", cubx->img[3].img);
	}
	return (CONTINUE_PROC);
}

t_uint	find_color(t_cub_context *cubx, t_str line, int fd)
{
	t_uint	status;

	if (line[0] == 'F')
	{
		cubx->find.f = 1;
		status = pars_color(cubx, line, 'F', fd);
		if (status != CONTINUE_PROC)
			return (status);
	}
	else if (line[0] == 'C')
	{
		cubx->find.c = 1;
		status = pars_color(cubx, line, 'C', fd);
		if (status != CONTINUE_PROC)
			return (status);
	}
	return (CONTINUE_PROC);
}

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
		while (line[i] != '\0')
		{
			printf("line[%d] = %c\n", i, line[i]);
			if (ft_isspace(line[i]) == 1)
			{
				i++;
				continue ;
			}
			if (i + 1 < ft_strlen(line))
			{
				if ((line[i] == '1' || line[i] == '0') && (line[i + 1] == '1' || line[i + 1] == '0'))
					return (1);
			}
			i++;
		}
		return (0);
	}
	return (0);
}

t_uint	find_the_path(t_cub_context *cubx, t_str line, int fd)
{
	while (line != NULL)
	{
		printf("find_the_path line = |%s|\n", line);
		if (find_we_no(cubx, line, fd) != CONTINUE_PROC)
			return (free(line), MALLOC_FAIL);
		if (find_ea_so(cubx, line, fd) != CONTINUE_PROC)
			return (free(line), MALLOC_FAIL);
		if (find_color(cubx, line, fd) != CONTINUE_PROC)
			return (free(line), MALLOC_FAIL);
		if (is_finish(cubx, line) == 1)
		{
			if (add_map_to_lst(cubx, fd) != CONTINUE_PROC)
				return (free(line), MALLOC_FAIL);
			break ;
		}
		free(line);
		line = get_next_line(fd);
	}
	if (line != NULL)
		free(line);
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
