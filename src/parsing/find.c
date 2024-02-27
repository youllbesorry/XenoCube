/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:46:19 by bfaure            #+#    #+#             */
/*   Updated: 2024/02/27 18:37:40 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "xenocube.h"

t_uint	find_we_no(t_cub_context *cubx, t_str line)
{
	t_uint	status;

	if (line[0] == 'W' && line[1] == 'E')
	{
		if (cubx->find.we != 0)
			return (TOO_MANY_TX_ID);
		cubx->find.we = 1;
		status = pars_graphic_path(cubx, line, 0);
		if (status != CONTINUE_PROC)
			return (status);
	}
	else if (line[0] == 'N' && line[1] == 'O')
	{
		if (cubx->find.no != 0)
			return (TOO_MANY_TX_ID);
		cubx->find.no = 1;
		status = pars_graphic_path(cubx, line, 1);
		if (status != CONTINUE_PROC)
			return (status);
	}
	else if (line[0] != ' ' && line[0] != 'F' && line[0] != 'C'
		&& !(line[0] == 'E' && line[1] == 'A')
		&& !(line[0] == 'S' && line[1] == 'O') && line[0] != '\n')
		return (BAD_TEXTURE_ID);
	return (CONTINUE_PROC);
}

t_uint	find_ea_so(t_cub_context *cubx, t_str line)
{
	t_uint	status;

	if (line[0] == 'E' && line[1] == 'A')
	{
		if (cubx->find.ea != 0)
			return (TOO_MANY_TX_ID);
		cubx->find.ea = 1;
		status = pars_graphic_path(cubx, line, 2);
		if (status != CONTINUE_PROC)
			return (status);
	}
	else if (line[0] == 'S' && line[1] == 'O')
	{
		if (cubx->find.so != 0)
			return (TOO_MANY_TX_ID);
		cubx->find.so = 1;
		status = pars_graphic_path(cubx, line, 3);
		if (status != CONTINUE_PROC)
			return (status);
	}
	else if (line[0] != ' ' && line[0] != 'F' && line[0] != 'C'
		&& !(line[0] == 'W' && line[1] == 'E')
		&& !(line[0] == 'N' && line[1] == 'O') && line[0] != '\n')
		return (BAD_TEXTURE_ID);
	return (CONTINUE_PROC);
}

t_uint	find_color(t_cub_context *cubx, t_str line)
{
	t_uint	status;

	if (line[0] == 'F')
	{
		if (cubx->find.f != 0)
			return (TOO_MANY_CO_ID);
		cubx->find.f = 1;
		status = pars_color(cubx, line, 'F');
		if (status != CONTINUE_PROC)
			return (status);
	}
	else if (line[0] == 'C')
	{
		if (cubx->find.c != 0)
			return (TOO_MANY_CO_ID);
		cubx->find.c = 1;
		status = pars_color(cubx, line, 'C');
		if (status != CONTINUE_PROC)
			return (status);
	}
	return (CONTINUE_PROC);
}
