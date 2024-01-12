/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cp_map_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:50:41 by bfaure            #+#    #+#             */
/*   Updated: 2024/01/12 16:57:06 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../xenocube.h"

t_uint	add_map_to_lst(t_cub_context *cubx, t_str line, t_uint fd)
{
	t_uint	status;

	status = CONTINUE_PROC;
	while (line != NULL)
	{
		status = lst_add_back(cubx, &cubx->lst_map, line);
		if (status != CONTINUE_PROC)
			return (status);
		free(line);
		line = get_next_line(fd);
	}
	lst_print(&cubx->lst_map, "lst_map");
	return (CONTINUE_PROC);
}
