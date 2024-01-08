/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 20:17:51 by bfaure            #+#    #+#             */
/*   Updated: 2024/01/08 20:17:51 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H

# include "../../xenocub.h"

typedef unsigned int	t_uint;
typedef char*			t_str;

typedef struct			s_cub_context t_cub_context;
typedef struct			s_cub_map t_cub_map;
typedef struct			s_cub_player t_cub_player;
typedef struct			s_cub_window t_cub_window;
typedef struct			s_cub_image t_cub_image;
typedef struct			s_garbage_collector t_garbage_collector;
typedef struct			s_ptr t_ptr;

#endif