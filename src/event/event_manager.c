/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:01:39 by jcoquard          #+#    #+#             */
/*   Updated: 2024/01/26 16:24:24 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../xenocube.h"

int	key_press(int keycode, t_cub_context *cubx)
{
	//printf("keycode: %d\n", keycode);
	if (keycode == 65307)
		close_window(cubx);
	if ((keycode == 119 || keycode == 65362) && !cubx->keys.down)
		cubx->keys.up = 1;
	if ((keycode == 115 || keycode == 65364) && !cubx->keys.up)
		cubx->keys.down = 1;
	if ((keycode == 97 || keycode == 65361) && !cubx->keys.right)
		cubx->keys.left = 1;
	if ((keycode == 100 || keycode == 65363) && !cubx->keys.left)
		cubx->keys.right = 1;
	if (keycode == 113 && !cubx->keys.r_right)
		cubx->keys.r_left = 1;
	if (keycode == 101 && !cubx->keys.r_left)
		cubx->keys.r_right = 1;
	return (keycode);
}

int	key_release(int keycode, t_cub_context *cubx)
{
	if (keycode == 119 || keycode == 65362)
		cubx->keys.up = 0;
	if (keycode == 115 || keycode == 65364)
		cubx->keys.down = 0;
	if (keycode == 97 || keycode == 65361)
		cubx->keys.left = 0;
	if (keycode == 100 || keycode == 65363)
		cubx->keys.right = 0;
	if (keycode == 113)
		cubx->keys.r_left = 0;
	if (keycode == 101)
		cubx->keys.r_right = 0;
	return (keycode);
}

void	player_manager(t_cub_context *cubx)
{
	if (cubx->keys.r_left)
		rotate_left(&cubx->player);
	if (cubx->keys.r_right)
		rotate_right(&cubx->player);
	if (cubx->keys.up)
		move_forward(&cubx->map, &cubx->player);
	if (cubx->keys.down)
		move_backward(&cubx->map, &cubx->player);
	if (cubx->keys.left)
		move_left(&cubx->map, &cubx->player);
	if (cubx->keys.right)
		move_right(&cubx->map, &cubx->player);
}