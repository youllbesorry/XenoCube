/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:21:13 by jcoquard          #+#    #+#             */
/*   Updated: 2024/01/26 15:22:42 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../../xenocube.h"

t_vec vec(int x, int y);
void init_vec(t_vec *vec, int x, int y);
t_dvec dvec(double x, double y);
void init_dvec(t_dvec *vec, double x, double y);

#endif