/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:46:19 by bfaure            #+#    #+#             */
/*   Updated: 2024/02/01 12:41:11 by bfaure           ###   ########lyon.fr   */
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
	}
	else if (line[0] == 'N' && line[1] == 'O')
	{
		cubx->find.no = 1;
		status = pars_graphic_path(cubx, line, fd, 1);
		if (status != CONTINUE_PROC)
			return (status);
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
	}
	else if (line[0] == 'S' && line[1] == 'O')
	{
		cubx->find.so = 1;
		status = pars_graphic_path(cubx, line, fd, 3);
		if (status != CONTINUE_PROC)
			return (status);
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
