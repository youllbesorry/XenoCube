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

t_str	make_path(t_cub_context *cubx, t_str line, int i)
{
	t_str	path;

	path = ft_substr(cubx, line, i, ft_strlen(line));
	if (path == NULL)
		return (NULL);
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
	return (CONTINUE_PROC);
}

