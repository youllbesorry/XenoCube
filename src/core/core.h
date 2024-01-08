/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:58:12 by bfaure            #+#    #+#             */
/*   Updated: 2024/01/08 19:58:12 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

# include "../../xenocub.h"

struct s_cub_context
{
    t_garbage_collector		*gc;
	t_cub_window			*window;
	t_cub_map				*map;
	t_cub_player			*player;
	t_cub_ray				*ray;
	t_cub_image				*image;
};

#endif
