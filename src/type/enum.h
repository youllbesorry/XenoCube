/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:50:37 by bfaure            #+#    #+#             */
/*   Updated: 2024/01/09 13:54:22 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_H
# define ENUM_H

enum e_error
{
	MALLOC_FAIL = 1,
	MLX_INIT_FAIL,
	MLX_NEW_WIN_FAIL,
	MLX_NEW_IMG_FAIL,
	CONTINUE_PROC,
};

#endif
