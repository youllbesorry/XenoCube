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
	t_uint			status;
	int				i;

	status = 0;
	if (argc != 2)
	{
		printf("Error\nWrong number of arguments\n");
		return (0);
	}
	else
	{
		if (win_init(&cubx, 1920, 1080) != CONTINUE_PROC)
		{
			printf("Error\nmlx init fail\n");
			mlx_destroy_display(cubx.win.mlx);
			free(cubx.win.mlx);
			return (0);
		}
		if (init_cub_context(&cubx) != CONTINUE_PROC)
		{
			printf("Error\nCub_context_init fail\n");
			return (gc_free_all(&cubx), 0);
		}
		status = pars_file(&cubx, argv[1]);
		if (status != CONTINUE_PROC)
		{
			if (status == MALLOC_FAIL)
				printf("Error\nMalloc fail\n");
			else if (status == DONT_FUCK_WITH_ME)
				printf("Error\nYou've try to fuck with me");
			else
				printf("Error\n");
			return (ft_clear(&cubx), 0);
		}
		if (check_map(&cubx) != CONTINUE_PROC)
		{
			printf("Error\nMap error\n");
			return (ft_clear(&cubx), 0);
		}
		i = 0;
		printf("\n");
		while (cubx.map.map[i] != NULL)
		{
			printf("|%s|\n", cubx.map.map[i]);
			i++;
		}
		ft_clear(&cubx);
	}
	return (0);
}
