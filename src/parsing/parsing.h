/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:42:35 by bfaure            #+#    #+#             */
/*   Updated: 2024/02/02 15:46:12 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

t_uint	pars_file(t_cub_context *cubx, t_str path);
t_uint	pars_graphic_path(t_cub_context *cubx, t_str line, int fd, t_uint n);
t_uint	check_map(t_cub_context *cubx);
t_uint	add_map_to_lst(t_cub_context *cubx, t_uint fd, t_str line);
t_uint	find_sizes(t_cub_context *cubx);
t_uint	remplace_tab_space(t_cub_context *cubx);
t_uint	create_tab_map(t_cub_context *cubx);
t_uint	check_valid_map(t_cub_context *cubx);
t_uint	back_to_normal_map(t_cub_context *cubx);
t_uint	find_we_no(t_cub_context *cubx, t_str line, int fd);
t_uint	find_ea_so(t_cub_context *cubx, t_str line, int fd);
t_uint	pars_color(t_cub_context *cubx, t_str line, int bg, int fd);
t_uint	find_color(t_cub_context *cubx, t_str line, int fd);

#endif
