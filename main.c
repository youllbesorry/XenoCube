/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:47:00 by bfaure            #+#    #+#             */
/*   Updated: 2024/01/08 19:47:00 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "xenocube.h"

int	main(int argc, char **argv)
{
	t_cub_context	cubx;
	t_uint 			status;

	status = 0;
	if (argc != 2)
	{
		printf("Error\nWrong number of arguments\n");
		return (0);
	}
	else
	{
		if (init_cub_context(&cubx) != CONTINUE_PROC)
		{
			printf("Error\nMalloc fail\n");
			return (0);
		}
		printf("Path: %s\n", argv[1]);
		status = pars_file(&cubx, argv[1]);
		if (status != CONTINUE_PROC)
		{
			if (status == MALLOC_FAIL)
				printf("Error\nMalloc fail\n");
			else if (status == DONT_FUCK_WITH_ME)
				printf("Error\nYou've try to fuck with me");
			return (0);
		}
		else
		{
			printf("Path NO: %s\n", cubx.path.path_n);
			printf("Path SO: %s\n", cubx.path.path_s);
			printf("Path WE: %s\n", cubx.path.path_w);
			printf("Path EA: %s\n", cubx.path.path_e);
			printf("Color F: %d, %d, %d\n", cubx.color_f.r, cubx.color_f.g, cubx.color_f.b);
			printf("Color C: %d, %d, %d\n", cubx.color_c.r, cubx.color_c.g, cubx.color_c.b);
			// printf("Map: %s\n", cubx.map);
		}
	}	return (0);
}
