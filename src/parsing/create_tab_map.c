/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 23:25:18 by bfaure            #+#    #+#             */
/*   Updated: 2024/01/10 23:25:18 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../xenocube.h"

t_uint	count_lines_len(t_cub_context *cubx, t_str path)
{
	int		fd;
	t_str	line;
	t_uint	i;
	t_uint	tmp;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (BAD_FD);
	tmp = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		i = 0;
		while ((line[i] != '\0') && (line[i] == '0' || line[i] == '1' || ft_isspace(line[i])))
		{
			i++;
			if (tmp < i)
				tmp = i;
		}
		free(line);
		line = get_next_line(fd);
	}
	cubx->map.w = tmp;
	printf("w = %d\n", cubx->map.w);
	close(fd);
	return (CONTINUE_PROC);
}

t_uint	count_map_lines(t_cub_context *cubx, t_str path)
{
	int		fd;
	t_str	line;
	t_uint	count;
	t_uint	i;
	t_uint	tmp;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (BAD_FD);
	count = -1;
	tmp = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		i = 0;
		while (line[i] != '\0')
		{
			if ((line[i] == '0' || line[i] == '1')
				&& (line[i + 1] == '0' || line[i + 1] == '1'))
			{
				count++;
				break ;
			}
			i++;
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	cubx->map.h = count - 1;
	count_lines_len(cubx, path);
	printf("h = %d\n", cubx->map.h);
	cubx->map.map = malloc(sizeof(t_str) * (count + 1)); // rm - 1
	if (cubx->map.map == NULL)
		return (MALLOC_FAIL);
	cubx->map.map[count] = NULL;
	return (CONTINUE_PROC);
}

t_uint	pars_map(t_cub_context *cubx, t_str path)
{
	int		fd;
	t_str	line;
	t_uint	count;
	t_uint	i;

	count_map_lines(cubx, path);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (BAD_FD);
	line = get_next_line(fd);
	i = 0;
	count = 0;
	while (line != NULL)
	{
		i = 0;
		while (line[i] != '\0')
		{
			if ((line[i] == '0' || line[i] == '1')
				&& (line[i + 1] == '0' || line[i + 1] == '1'))
			{
				cubx->map.map[count] = ft_strdup(cubx, line);
				count++;
				break ;
			}
			else if (!ft_isdigit(line[i]) && !ft_isspace(line[i]))
				break ;
			i++;
		}
		free(line);
		line = get_next_line(fd);
	}
	cubx->map.map[count] = NULL;
	close(fd);
	i = 0;
	while (cubx->map.map[i] != NULL)
	{
		printf("|%s|", cubx->map.map[i]);
		i++;
	}
	printf("\n");
	return (CONTINUE_PROC);
}
