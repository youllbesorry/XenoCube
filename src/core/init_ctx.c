/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ctx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 20:10:09 by bfaure            #+#    #+#             */
/*   Updated: 2024/01/08 20:10:09 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../xenocube.h"

t_uint	init_cub_context(t_cub_context *cubx)
{
	ft_bzero(cubx, sizeof(t_cub_context));
	cubx->lst_map = NULL;
	if (init_gc(cubx) != CONTINUE_PROC)
		return (CUB_CONTEXT_INIT_FAIL);
	cubx->find.we = 0;
	cubx->find.no = 0;
	cubx->find.ea = 0;
	cubx->find.so = 0;
	cubx->find.f = 0;
	cubx->find.c = 0;
	return (CONTINUE_PROC);
}
