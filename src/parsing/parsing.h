/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:42:35 by bfaure            #+#    #+#             */
/*   Updated: 2024/01/13 12:09:17 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

t_uint	pars_file(t_cub_context *cubx, t_str path);
t_uint	pars_graphic_path(t_cub_context *cubx, t_str line, int fd);
t_uint	pars_color(t_cub_context *cubx, t_str line, int bg, int fd);
t_uint	check_map(t_cub_context *cubx);
t_uint	check_hole_map(t_cub_context *cubx);
t_uint	check_map_size(t_cub_context *cubx);
t_uint	back_tracking_algo(t_cub_context *cubx, t_uint x, t_uint y, t_uint check);
bool	is_player(t_cub_context *cubx, t_uint x, t_uint y);
t_uint	test_map(t_cub_context *cubx);
t_uint	is_valide(t_cub_context *cubx);
t_uint	add_map_to_lst(t_cub_context *cubx, t_uint fd);

#endif