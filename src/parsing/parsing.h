/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:42:35 by bfaure            #+#    #+#             */
/*   Updated: 2024/01/16 16:22:12 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

t_uint	pars_file(t_cub_context *cubx, t_str path);
t_uint	pars_graphic_path(t_cub_context *cubx, t_str line, int fd);
t_uint	pars_color(t_cub_context *cubx, t_str line, int bg, int fd);
t_uint	check_map(t_cub_context *cubx);
t_uint	add_map_to_lst(t_cub_context *cubx, t_uint fd);
t_uint	find_sizes(t_cub_context *cubx);
t_uint	remplace_tab_space(t_cub_context *cubx);
t_uint  create_tab_map(t_cub_context *cubx);

#endif